#include <bits/stdc++.h>
using namespace std;

#define EDEBUG
#if defined(LOCAL) && defined(EDEBUG)
#include "includes/debug.cpp"
#else
#define debug(...)
#define dbgarr(...)
#define dbgline
#endif

/*input
6
2
1 5
5 1
4
1 14 8 9
3 1 5 9
4 13 11 1
1 15 4 11
4
2 4 1 6
3 7 3 10
15 9 4 2
12 7 15 1
6
2 4 1 6 1 6
3 7 3 10 1 6
15 9 4 2 1 6
12 7 15 1 1 6
12 7 15 1 1 6
12 7 15 1 1 6
8
2 4 1 6 1 6 1 6
3 7 3 10 1 6 1 6
15 9 4 2 1 6 1 6
12 7 15 1 1 6 1 6
12 7 15 1 1 6 1 6
12 7 15 1 1 6 1 6
12 7 15 1 1 6 1 6
12 7 15 1 1 6 1 6
10
2 4 1 6 1 6 1 6 1 6
3 7 3 10 1 6 1 6 1 6
15 9 4 2 1 6 1 6 1 6
12 7 15 1 1 6 1 6 1 6
12 7 15 1 1 6 1 6 1 6
12 7 15 1 1 6 1 6 1 6
12 7 15 1 1 6 1 6 1 6
12 7 15 1 1 6 1 6 1 6
12 7 15 1 1 6 1 6 1 6
12 7 15 1 1 6 1 6 1 6
*/

int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int TESTS;
	cin >> TESTS;

	for (int TESTT = 0; TESTT < TESTS; ++TESTT) {
		int n;
		cin >> n;
		vector<int> val[n] = {};

		for (int i = 0; i < n; ++i) {
			val[i].resize(n);

			for (int j = 0; j < n; ++j) {
				cin >> val[i][j];
			}
		}

		if (n == 2) {
			cout << (val[0][0] ^ val[0][1]) << "\n";
			continue;
		}

		vector<int> matr[n] = {};
		vector<bool> isok[n] = {};

		for (int i = 0; i < n; ++i) {
			matr[i].resize(n, 0);
			isok[i].resize(n, false);
		}

		queue<pair<int, int> > eil;

		auto addn = [&](int i, int j) -> void {
			if (i > 0) {
				if (!isok[i - 1][j])
					eil.push({i - 1, j});
			}

			if (j > 0) {
				if (!isok[i][j - 1])
					eil.push({i, j - 1});
			}

			if (j + 1 < n) {
				if (!isok[i][j + 1])
					eil.push({i, j + 1});
			}

			if (i + 1 < n) {
				if (!isok[i + 1][j])
					eil.push({i + 1, j});
			}
		};

		matr[0][0] = 2;
		matr[0][1] = 1;
		matr[0][2] = 2;

		for (int i = 3; i < n; ++i) {
			matr[0][i] = 2;
			matr[1][i] = 1;
		}

		matr[1][0] = 2;
		matr[1][1] = 1;
		matr[1][2] = 2;
		matr[2][1] = 2;
		matr[2][2] = 1;

		for (int i = 0; i < n; ++i) {
			eil.push({0, i});
			eil.push({1, i});
		}

		for (int j = 0; j < 4; ++j) {
			eil.push({2, j});
			eil.push({3, j});
		}

		while (!eil.empty()) {
			int i = eil.front().first;
			int j = eil.front().second;
			eil.pop();

			if (isok[i][j]) {
				continue;
			}

			int cnt[3] = {};

			int ni = 0, nj = 0;

			if (i > 0) {
				cnt[matr[i - 1][j]]++;

				if (matr[i - 1][j] == 0) {
					ni = i - 1;
					nj = j;
				}
			}

			if (j > 0) {
				cnt[matr[i][j - 1]]++;

				if (matr[i][j - 1] == 0) {
					ni = i;
					nj = j - 1;
				}
			}

			if (j + 1 < n) {
				cnt[matr[i][j + 1]]++;

				if (matr[i][j + 1] == 0) {
					ni = i;
					nj = j + 1;
				}
			}

			if (i + 1 < n) {
				cnt[matr[i + 1][j]]++;

				if (matr[i + 1][j] == 0) {
					ni = i + 1;
					nj = j;
				}
			}

			if (cnt[0] == 0) {
				assert(cnt[1] % 2 == 1);
				isok[i][j] = true;
			}
			else if (cnt[0] == 1) {
				if (cnt[1] % 2 == 0) {
					matr[ni][nj] = 1;
				}
				else {
					matr[ni][nj] = 2;
				}

				isok[i][j] = true;
				addn(ni, nj);
			}
		}

		long long ans = 0;

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < n; ++j) {
				if (matr[i][j] == 1) {
					ans ^= val[i][j];
				}
				else {
					// debug(i, j, matr[i][j]);
					assert(matr[i][j] == 2);
				}
			}
		}

		cout << ans << "\n";
	}
}