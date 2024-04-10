#include <iostream>
#include <vector>

using namespace std;

int main() {
	int n, m, mod; cin >> n >> m >> mod;
	vector<int> kolon(n, 0);
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		for (int j = 0; j < n; j++) {
			if (s[j] == '1') {
				kolon[j]++;
			}
		}
	}
	int k0 = 0, k1 = 0;
	for (int j = 0; j < n; j++) {
		if (kolon[j] == 0) {
			k0++;
		} else if (kolon[j] == 1) {
			k1++;
		}
	}
	static int pdp[501][501] = {};
	static int dp[501][501] = {};
	dp[k0][k1] = 1;
	for (int i = m; i < n; i++) {
		for (int j = 0; j <= n; j++) {
			for (int k = 0; j + k <= n; k++) {
				pdp[j][k] = dp[j][k];
				dp[j][k] = 0;
			}
		}
		for (int j = 0; j <= n; j++) {
			for (int k = 0; j + k <= n; k++) {
				if (!pdp[j][k]) {
					continue;
				}
				if (j >= 2) {
					int64_t addJ = ((int64_t)j * (j-1) / 2 * pdp[j][k]) % mod;
					dp[j-2][k+2] += addJ;
					dp[j-2][k+2] %= mod;
				}
				if (k >= 2) {
					int64_t addK = ((int64_t)k * (k-1) / 2 * pdp[j][k]) % mod;
					dp[j][k-2] += addK;
					dp[j][k-2] %= mod;
				}
				if (j >= 1 && k >= 1) {
					int64_t addJK = ((int64_t)j * k * pdp[j][k]) % mod;
					dp[j-1][k] += addJK;
					dp[j-1][k] %= mod;
				}
			}
		}
	}
	cout << dp[0][0] % mod << endl;
	return 0;
}