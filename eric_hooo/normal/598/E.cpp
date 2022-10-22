#include <bits/stdc++.h>
using namespace std;

int dp[40][40][60];

int dfs(int n, int m, int k) {
	if (n * m < k) return 0x3f3f3f3f;
	if (n * m == k) return 0;
	if (k == 0) return 0;
	if (~dp[n][m][k]) return dp[n][m][k];
	int &res = dp[n][m][k] = 0x3f3f3f3f;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= k; j++) {
			res = min(res, dfs(i, m, j) + dfs(n - i, m, k - j) + m * m);
		}
	}
	for (int i = 1; i < m; i++) {
		for (int j = 0; j <= k; j++) {
			res = min(res, dfs(n, i, j) + dfs(n, m - i, k - j) + n * n);
		}
	}
	return res;
}

int main () {
	memset(dp, -1, sizeof(dp));
	int T; scanf("%d", &T);
	while (T--) {
		int n, m, k; scanf("%d%d%d", &n, &m, &k);
		printf("%d\n", dfs(n, m, k));
	}
	return 0;
}