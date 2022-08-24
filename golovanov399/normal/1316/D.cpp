#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

void panic() {
	puts("INVALID");
	exit(0);
}

const string letter = "LURD";
const int xx[4] = {0, -1, 0, 1};
const int yy[4] = {-1, 0, 1, 0};

void solve() {
	int n = nxt();
	vector<vector<pair<int, int>>> a(n, vector<pair<int, int>>(n));
	for (auto& v : a) {
		for (auto& p : v) {
			p.first = nxt();
			p.second = nxt();
			if (p.first != -1) {
				--p.first;
				--p.second;
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j].first == -1) {
				continue;
			}
			if (a[a[i][j].first][a[i][j].second] != a[i][j]) {
				panic();
			}
		}
	}

	vector<vector<char>> used(n, vector<char>(n, 0));
	vector<string> ans(n, string(n, '.'));

	function<void(int, int)> dfs = [&](int x, int y) {
		used[x][y] = 1;
		for (int t = 0; t < 4; ++t) {
			int dx = xx[t], dy = yy[t];
			if (abs(dx) + abs(dy) != 1) {
				continue;
			}
			if (x + dx < 0 || x + dx >= n || y + dy < 0 || y + dy >= n) {
				continue;
			}
			if (used[x + dx][y + dy] || a[x + dx][y + dy] != a[x][y]) {
				continue;
			}
			ans[x + dx][y + dy] = letter[t ^ 2];
			dfs(x + dx, y + dy);
		}
	};

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (a[i][j] == pair{i, j}) {
				dfs(i, j);
				ans[i][j] = 'X';
			}
		}
	}
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < n; ++j) {
			if (!used[i][j]) {
				if (a[i][j] != pair{-1, -1}) {
					panic();
				}
				int idx = 0;
				while (idx < 4) {
					int x = i + xx[idx];
					int y = j + yy[idx];
					if (x < 0 || x >= n || y < 0 || y >= n) {
						++idx;
						continue;
					}
					if (a[x][y] == pair{-1, -1}) {
						break;
					} else {
						++idx;
					}
				}
				if (idx == 4) {
					panic();
				}
				dfs(i, j);
				ans[i][j] = letter[idx];
			}
		}
	}
	cout << "VALID\n";
	for (auto s : ans) {
		cout << s << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	int t = 1;
	while (t--) {
		solve();
	}

	return 0;
}