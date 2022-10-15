#include <iostream>
#include <bitset>

using namespace std;

int main() {
	ios_base::sync_with_stdio(false);
	static bitset<500> g[62][2][500] = {};
	static int64_t dp[62][2][500] = {};
	int n, m; cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c; cin >> a >> b >> c; a--; b--;
		g[0][c][a][b] = true;
		dp[0][c][a] |= 1;
	}
	for (int q = 0; q < 61; q++) {
		for (int i = 0; i < n; i++) {
			dp[q+1][0][i] = dp[q][0][i];
			dp[q+1][1][i] = dp[q][1][i];
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[q][0][i][j]) {
					g[q+1][0][i] |= g[q][1][j];
				}
				if (g[q][1][i][j]) {
					g[q+1][1][i] |= g[q][0][j];
				}
			}
		}	
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (g[q+1][0][i][j]) {
					dp[q+1][0][i] = max(dp[q+1][0][i], ((int64_t)1 << (q+1)) + dp[q][1][j]);
				}
				if (g[q+1][1][i][j]) {
					dp[q+1][1][i] = max(dp[q+1][1][i], ((int64_t)1 << (q+1)) + dp[q][0][j]);
				}
			}
		}
	}
	if (dp[60][0][0] > (int64_t)1e18) {
		cout << -1 << endl;
	} else {
		cout << dp[60][0][0];
	}
	return 0;
}