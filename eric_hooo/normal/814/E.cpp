#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
const int inv2 = 500000004;

int a[1010], s1[1010], s2[1010];
int dp[1010][1010];
int f[1010][1010];
int C[1010][1010];
long long fac[1010], pwi2[1010];

void add(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int main() {
	fac[0] = 1; for (int i = 1; i <= 1005; i++) fac[i] = fac[i - 1] * i % mod;
	pwi2[0] = 1; for (int i = 1; i <= 1005; i++) pwi2[i] = pwi2[i - 1] * inv2 % mod;
	for (int i = 0; i <= 1005; i++) {
		C[i][0] = 1; for (int j = 1; j <= i; j++) C[i][j] = C[i - 1][j - 1], add(C[i][j], C[i - 1][j]);
	}
	int n; cin >> n;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int i = 1; i <= n; i++) s1[i] = s1[i - 1] + (a[i] == 2), s2[i] = s2[i - 1] + (a[i] == 3);
	f[0][0] = 1;
	for (int T = 1; T <= n; T++) {
		for (int i = 0; i <= T; i++) {
			int j = T - i;
			if (i) {
				if (j) add(f[i][j], 1ll * j * f[i][j - 1] % mod);
				if (i > 1) add(f[i][j], 1ll * (i - 1) * f[i - 2][j] % mod);
			} else {
				if (j > 2) add(f[i][j], 1ll * (j - 1) * (j - 2) / 2 * f[i + 2][j - 3] % mod);
			}
		}
	}
	dp[2][1 + a[1]] = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = i; j <= n; j++) {
			if (!dp[i][j]) continue;
			int c1 = s1[j] - s1[i - 1], c2 = s2[j] - s2[i - 1];
//			cerr << "    dp:" << i << " " << j << " " << dp[i][j] << endl;
			for (int q = 0; q <= c2; q++) {
				long long m1 = 1ll * dp[i][j] * C[c2][q] % mod;
				for (int p2 = 0; p2 + q <= c2; p2++) {
					long long m2 = m1 * C[c2 - q][p2] % mod * pwi2[c2 - q - p2] % mod;
					for (int p1 = p2 & 1; p1 <= c1; p1 += 2) {
						int p = p1 + p2, nxt = c1 + c2 * 2 - q * 2 - p;
						if (j + nxt > n) continue;
						long long mul = m2 * C[c1][p1] % mod * f[p][q] % mod;
						add(dp[j + 1][j + nxt], mul * fac[nxt] % mod);
					}
				}
			}
		}
	}
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		int c1 = s1[n] - s1[i - 1], c2 = s2[n] - s2[i - 1];
		add(ans, 1ll * dp[i][n] * f[c1][c2] % mod);
	}
	cout << ans << endl;
	return 0;
}