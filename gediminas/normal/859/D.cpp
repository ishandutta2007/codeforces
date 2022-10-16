/*input

2
0 21 41 26
79 0 97 33
59 3 0 91
74 67 9 0
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int c = 1 << n;
	int tik[c][c];

	for (int i = 0; i < c; i++) {
		for (int j = 0; j < c; j++)
			cin >> tik[i][j];
	}

	long double din[n + 1][c] = {};
	long double tikk[n + 1][c] = {};

	for (int i = 0; i < c; i++)
		tikk[0][i] = 1;

	for (int i = 0; i < n; i++) {
		//int cc = (1 << (i + 1));
		int cc1 = (1 << i);

		for (int j = 0; j < c; j++) {
			int fr;

			if ((j / cc1) % 2 == 0)
				fr = (j / cc1) * cc1 + cc1;
			else
				fr = (j / cc1) * cc1 - cc1;

			for (int k = fr; k < fr + cc1; k++)
				din[i + 1][j] = max(din[i][k], din[i + 1][j]);

			din[i + 1][j] += din[i][j];

			for (int k = fr; k < fr + cc1; k++)
				din[i + 1][j] += tikk[i][k] * tikk[i][j] * (tik[j][k] / 100.0l * cc1);

			for (int k = fr; k < fr + cc1; k++)
				tikk[i + 1][j] += tikk[i][j] * tikk[i][k] * tik[j][k] / 100.0l;


			//cout << din[i + 1][j] << "(" << tikk[i + 1][j] << ") ";
		}

		//cout << endl;
	}

	long double ma = 0;

	for (int i = 0; i < c; i++)
		ma = max(ma, din[n][i]);

	cout << fixed << setprecision(10) << ma;


	return 0;
}