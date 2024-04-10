/*input
3
1 5 2
1 1 1
1 2 3
*/
#include <bits/stdc++.h>

using namespace std;

int main () {
	int n;
	cin >> n;
	int mas[n][n];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++)
			cin >> mas[i][j];
	}

	bool ar = true;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (mas[i][j] == 1)
				continue;

			bool a = false;

			for (int k = 0; k < n; k++) {
				for (int l = 0; l < n; l++) {
					if (mas[k][j] + mas[i][l] == mas[i][j])
						a = true;
				}
			}

			ar = ar and a;
		}
	}

	cout << (ar ? "Yes" : "No");


	return 0;
}