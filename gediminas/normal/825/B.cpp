/*input
..........
..........
..........
..........
..........
.........X
........X.
.......X..
......X...
..........

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	char matr[10][10];

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 10; j++)
			cin >> matr[i][j];
	}

	bool ar = false;

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j + 4 < 10; j++) {
			int x = 0, tu = 0;

			for (int k = 0; k < 5; k++) {
				if (matr[i][j + k] == 'X')
					x++;
				else if (matr[i][j + k] == '.')
					tu++;
			}

			if (x == 4 and tu == 1)
				ar = true;
		}
	}

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j + 4 < 10; j++) {
			int x = 0, tu = 0;

			for (int k = 0; k < 5; k++) {
				if (matr[j + k][i] == 'X')
					x++;
				else if (matr[j + k][i] == '.')
					tu++;
			}

			if (x == 4 and tu == 1)
				ar = true;
		}
	}

	for (int i = 0; i + 4 < 10; i++) {
		for (int j = 0; j + 4 < 10; j++) {
			int x = 0, tu = 0;

			for (int k = 0; k < 5; k++) {
				if (matr[j + k][i + k] == 'X')
					x++;
				else if (matr[j + k][i + k] == '.')
					tu++;
			}

			if (x == 4 and tu == 1)
				ar = true;
		}
	}

	for (int i = 0; i + 4 < 10; i++) {
		for (int j = 0; j + 4 < 10; j++) {
			int x = 0, tu = 0;

			for (int k = 0; k < 5; k++) {
				if (matr[j + k][i + 4 - k] == 'X')
					x++;
				else if (matr[j + k][i + 4 - k] == '.')
					tu++;
			}

			if (x == 4 and tu == 1)
				ar = true;
		}
	}

	cout << (ar ? "YES" : "NO");
	return 0;
}