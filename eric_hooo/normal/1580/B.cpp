#include <bits/stdc++.h>
using namespace std;

int n, m, k, mod;

int dp[110][110][110];
int C[110][110];

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int main() {
	cin >> n >> m >> k >> mod;
	for (int i = 0; i <= 105; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			ADD(C[i][j] = C[i - 1][j - 1], C[i - 1][j]);
		}
	}
	for (int i = 1; i <= m; i++) {
		dp[0][i][0] = 1;
	}
	dp[1][1][1] = 1 % mod;
	for (int i = 2; i <= n; i++) {
		dp[i][1][1] = 1ll * dp[i - 1][1][1] * i % mod;
	}
	for (int i = 1; i <= n; i++) {
		// cerr << " i:" << i << endl;
		for (int j = 2; j <= i + 1; j++) {
			for (int p = 0; p <= (i + 1 >> 1); p++) {
				unsigned long long tmp = 0;
				for (int ni = 0; ni < i; ni++) {
					int v1 = min(j - 1, ni + 1), v2 = min(j - 1, i - ni);
					int up = min(p, ni + 1 >> 1), dw = max(0, p - (i - ni) >> 1);
					int *L = &dp[ni][v1][dw], *R = &dp[i - ni - 1][v2][p - dw];
					for (int np = dw; np <= up; np++) {
						tmp += 1ll * *L * *R % mod * C[i - 1][ni];
						if (!(np & 15)) tmp %= mod;
						L++, R--;
					}
					tmp %= mod;
				}
				dp[i][j][p] = tmp % mod;
			}
		}
	}
	// for (int i = 0; i <= n; i++) {
	// 	for (int j = 1; j <= i; j++) {
	// 		for (int p = 0; p <= i; p++) {
	// 			if (!dp[i][j][p]) continue;
	// 			cerr << "           dp:" << i << " " << j << " " << p << " : " << dp[i][j][p] << endl;
	// 			for (int ni = 0; ni <= i && ni + i + 1 <= n; ni++) {
	// 				for (int np = 0; np <= ni; np++) {
	// 					if (!dp[ni][j][np]) continue;
	// 					ADD(dp[i + ni + 1][j + 1][p + np], 1ll * dp[i][j][p] * dp[ni][j][np] % mod);
	// 				}
	// 			}
	// 		}
	// 	}
	// }
	cout << dp[n][m][k] << endl;
	return 0;
}