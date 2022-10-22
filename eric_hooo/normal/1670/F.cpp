#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

int n;
long long l, r, z;
int C[1010][1010];

long long Solve(long long A) {
	static int dp[61][1010][3];
	memset(dp, 0, sizeof(dp));
	dp[0][0][1] = 1;
	for (int i = 0; i < 60; i++) {
		for (int j = 0; j <= n; j++) {
			for (int p = 0; p < 3; p++) {
				for (int k = 0; k <= n; k++) if (k % 2 == (z >> i & 1)) {
					int cur = j + k & 1, nj = j + k >> 1;
					ADD(dp[i + 1][nj][cur == (A >> i & 1) ? p : cur < (A >> i & 1) ? 0 : 2], 1ll * dp[i][j][p] * C[n][k] % mod);
				}
			}
		}
	}
	return (dp[60][0][0] + dp[60][0][1]) % mod;
}

int main() {
	for (int i = 0; i < 1005; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			ADD(C[i][j] = C[i - 1][j], C[i - 1][j - 1]);
		}
	}
	cin >> n >> l >> r >> z;
	cout << (Solve(r) - Solve(l - 1) + mod) % mod << endl;
	return 0;
}