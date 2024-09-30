#include <iostream>
#include <iomanip>
using namespace std;

// создание матрицы 
// mas - указатель на матрицу
// n - количество строк 
// m - количество столбцов
void createMatrix(int*** mas, unsigned n, unsigned m) {
	if ((n > 0) && (m > 0)) {
		(*mas) = new int* [n];
		for (unsigned i = 0; i < n; i++) {
			(*mas)[i] = new int[m];
			for (unsigned j = 0; j < m; j++)
				(*mas)[i][j] = 0;
		}
	}
}

// ввод матрицы с клавиатуры 
// mas -  указатель на матрицу
// n - количество строк 
// m - количество столбцов
void inputMatrix(int *** mas, unsigned n, unsigned m) {
	if (mas == nullptr) createMatrix(mas, n, m);
	cout << "enter matrix, line count = " << n << ", column count = "<< m << endl;
	for (unsigned i = 0; i < n; i++) {
		cout << "enter line number " << i << endl;
		for (unsigned j = 0; j < m; j++)
			cin >> (*mas)[i][j];
	}
}

// вывод матрицы на экран 
// mas - матрица
// n - количество строк 
// m - количество столбцов
void outputMatrix(int** mas, unsigned n, unsigned m) {
	if (mas == nullptr) return;
	cout << setw(5);
	for (unsigned i = 0; i < n; i++) {
		for (unsigned j = 0; j < m; j++)
			cout << setw(5) << mas[i][j];
		cout << endl;
	}
}

// удаление матрицы
// mas -  указатель на матрицу
// n - количество строк 
void deleteMatrix(int*** mas, unsigned n) {
	if (mas!=nullptr) 
		for (unsigned i = 0; i < n; i++)
		delete[] (*mas)[i];
	
	mas = nullptr;
}

// основная программа
int main()
{
	int** mas = nullptr, n = 3, m = 3;

	createMatrix(&mas, n, m);
	inputMatrix(&mas, n, m);
	outputMatrix(mas, n, m);
	deleteMatrix(&mas, n);
}
