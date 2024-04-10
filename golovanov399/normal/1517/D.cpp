#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int N = 505;
int a[N][N][4];
int ans[N][N];

const int K = 24;
int dp[K][K];
const int off = K / 2;

void remin(int& x, int y) {
	x = min(x, y);
}

const vector<pair<int, int>> dir = {{-1, 0}, {0, 1}, {1, 0}, {0, -1}};

void solve() {
	int n = nxt(), m = nxt();
	int k = nxt();
	if (k % 2) {
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				cout << "-1 ";
			}
			cout << "\n";
		}
		return;
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int k = 0; k < 4; ++k) {
				a[i][j][k] = 1e9;
			}
		}
	}

	k /= 2;
	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m - 1; ++j) {
			a[i][j][1] = a[i][j + 1][3] = nxt();
		}
	}
	for (int i = 0; i < n - 1; ++i) {
		for (int j = 0; j < m; ++j) {
			a[i + 1][j][0] = a[i][j][2] = nxt();
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			for (int x = 0; x < K; ++x) {
				for (int y = 0; y < K; ++y) {
					dp[x][y] = 1e9;
				}
			}
			dp[off][off] = 0;
			for (int t = 1; t <= k; ++t) {
				// if (i == 0 && j == 1) {
				// 	for (int x = 0; x < K; ++x) {
				// 		for (int y = 0; y < K; ++y) {
				// 			cerr << (dp[x][y] > 1e8 ? "inf" : to_string(dp[x][y])) << " ";
				// 		}
				// 		cerr << "\n";
				// 	}
				// 	cerr << "\n";
				// }
				for (int xx = 0; xx <= t; ++xx) {
					for (int yy = 0; yy <= t; ++yy) {
						int x = -xx + yy, y = t - xx - yy;
						if (i + x < 0 || i + x >= n || j + y < 0 || j + y >= m) {
							continue;
						}
						dp[off + x][off + y] = 1e9;
						for (int d = 0; d < 4; ++d) {
							const auto& [dx, dy] = dir[d];
							remin(dp[off + x][off + y], dp[off + x + dx][off + y + dy] + a[i + x][j + y][d]);
						}
					}
				}
			}
			ans[i][j] = 1e9;
			for (int x = -k; x <= k; ++x) {
				for (int y = -k; y <= k; ++y) {
					if ((abs(x) + abs(y)) % 2 == k % 2) {
						remin(ans[i][j], dp[off + x][off + y]);
					}
				}
			}
		}
	}

	for (int i = 0; i < n; ++i) {
		for (int j = 0; j < m; ++j) {
			cout << ans[i][j] * 2 << " ";
		}
		cout << "\n";
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}