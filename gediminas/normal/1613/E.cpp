#include <bits/stdc++.h>

using namespace std;
/*input
4
3 3
...
.L.
...
4 5
#....
..##L
...#.
.....
1 1
L
1 9
....L..#.

*/
/*input
2
3 5
.....
.#.#.
..L..
5 5
.....
.#.#.
.....
.#.#.
..L..
*/
/*input
1
3 6
......
.#.#.#
..L...
*/
vector<string> a;
vector<string> b[4];
int n, m;
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
int dk[4] = {1, 0, 3, 2};
char res(int i, int j, int k) {
	if (i < 0 or j < 0 or i >= n or j >= m or a[i][j] == '#') {
		return '#';
	}

	if (a[i][j] == 'L') {
		return 'L';
	}

	if (b[k][i][j] == 'S') {
		return 'x';
	}

	if (b[k][i][j] != '.') {
		return b[k][i][j];
	}

	b[k][i][j] = 'S';

	int lab = 0;

	for (int o = 0; o < 4; ++o) {
		if (k == o) {
			continue;
		}

		char t = res(i + dx[o], j + dy[o], dk[o]);

		if (t == 'x') {
			lab = 0;
			break;
		}
		else if (t == 'L') {
			lab++;
		}
	}

	b[k][i][j] = lab == 0 ? 'x' : 'L';

	return b[k][i][j];
}
int main() {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int t;
	cin >> t;

	while (t--) {
		cin >> n >> m;
		a.resize(n);

		for (int i = 0; i < n; ++i) {
			cin >> a[i];
		}

		for (int i = 0; i < 4; ++i) {
			b[i] = a;
		}

		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				if (a[i][j] != '.') {
					cout << a[i][j];
				}
				else {
					int kaim = 0;
					int vis = 0;

					for (int o = 0; o < 4; ++o) {
						char t = res(i + dx[o], j + dy[o], dk[o]);

						if (t == 'x') {
							vis++;
						}
						else if (t == 'L') {
							kaim++, vis++;
						}
					}

					cout << (kaim and kaim + 1 >= vis ? '+' : '.');
				}
			}

			cout << "\n";
		}
	}
}