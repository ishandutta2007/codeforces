/*input
4 3 2
0 1 0
1 0 1
0 1 0
1 1 1

*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n, m, k;
	cin >> n >> m >> k;
	bool mas[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++)
			cin >> mas[i][j];
	}

	long long sum = 0;
	long long ats2 = 0;

	for (int i = 0; i < m; i++) {
		int vie = 0;
		int ma = -1;
		int tada = -1, bendr = 0;

		for (int j = n - 1; j >= 0; j--) {
			vie += mas[j][i];
			bendr += mas[j][i];

			if (j + k < n)
				vie -= mas[j + k][i];

			if (vie >= ma) {
				ma = vie;
				tada = bendr;
			}
		}

		sum += ma;
		ats2 += bendr - tada;
	}

	cout << sum << " " << ats2; 

	return 0;
}