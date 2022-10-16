/*input


*/
#include <bits/stdc++.h>

using namespace std;

#ifdef LOCAL
#define cin in
ifstream cin("50.in");
#endif

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0);
	int n;
	cin >> n;
	bool matr2[n + 4][n + 4] = {};
	short matr[n + 4][n + 4] = {};

	for (int i = 2; i <= n+1; i++) {
		for (int j = 2; j <= n+1; j++)
			cin >> matr2[i][j];
	}

	for (int i = 2; i <= n+1; i++) {
		for (int j = 2; j <= n+1; j++){
			matr[i][j] = int(matr2[i][j]);
#define bang(x,y) matr[i][j] += matr2[x][y];
			bang(i + 1, j);
			bang(i, j + 1);
			bang(i - 1, j);
			bang(i, j - 1);
			bang(i + 1, j + 1);
			bang(i - 1, j - 1);
			bang(i - 1, j + 1);
			bang(i + 1, j - 1);
			bang(i + 2, j);
			bang(i, j + 2);
			bang(i - 2, j);
			bang(i, j - 2);
#undef bang
		}
	}

	int kvad = 0, skrit = 0;

#define constanta 5

	for (int i = 2; i <= n+1; i++) {
		for (int j = 2; j <= n+1; j++) {
			if (matr[i][j] > constanta) {
				queue<pair<int, int> > eil;
				int k = 0;
				long long tol = 0;
				eil.push(make_pair(i, j));
				matr[i][j] = 0;

				while (!eil.empty()) {
					int di = eil.front().first, dj = eil.front().second;
					tol = max(tol, (long long)(di - i) * (di - i) + (dj - j) * (dj - j));
					eil.pop();
#define bang(x,y) if(matr[x][y ] > constanta) {\
					eil.push(make_pair(x,y)); \
					matr[x][y]=0;k++;  }
					bang(di + 1, dj);
					bang(di, dj + 1);
					bang(di - 1, dj);
					bang(di, dj - 1);
					bang(di + 1, dj + 1);
					bang(di - 1, dj - 1);
					bang(di - 1, dj + 1);
					bang(di + 1, dj - 1);
#undef bang
				}

				if (k < 45)
					continue;

				//cout << tol << " " << k << endl;

				long long paklk = abs(tol / 2 - k);
				long long pakls = abs(tol * 3.1415 / 4 - k);

				//cout << paklk << " " << pakls << endl;

				if (abs(paklk) < pakls)
					kvad++;
				else
					skrit++;
			}
		}
	}

	cout << skrit << " " << kvad << endl;

	return 0;
}