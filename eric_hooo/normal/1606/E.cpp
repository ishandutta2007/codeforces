#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int dp[510][510];
long long pw[510][510];
int C[510][510];
int n, x;

int dfs(int n, int x) {
	if (n == 1) return 0;
	if (n == 0) return 1;
	if (x < 1) return 0;
	if (~dp[n][x]) return dp[n][x];
	int &res = dp[n][x] = 0;
	for (int i = 0; i <= n; i++) {
		res = (res + 1ll * dfs(n - i, x - n + 1) * pw[min(n - 1, x)][i] % mod * C[n][i]) % mod;
	}
	return res;
}

int main() {
	for (int i = 0; i <= 505; i++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j++) {
			C[i][j] = C[i - 1][j - 1] + C[i - 1][j];
			if (C[i][j] >= mod) C[i][j] -= mod;
		}
	}
	for (int i = 0; i <= 505; i++) {
		pw[i][0] = 1;
		for (int j = 1; j <= 505; j++) {
			pw[i][j] = pw[i][j - 1] * i % mod;
		}
	}
	memset(dp, -1, sizeof(dp));
	scanf("%d%d", &n, &x);
	printf("%d\n", dfs(n, x));
	return 0;
}