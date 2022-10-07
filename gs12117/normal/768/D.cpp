#include<stdio.h>
int n, q;
double dp[10100][1010];
int ans[1010];
int main() {
	scanf("%d%d", &n, &q);
	int p = 0;
	dp[0][0] = 1;
	for (int i = 0; p < 1005; i++) {
		while (p < 1008 && p*0.0005+0.00000000001 < dp[i][n]) {
			ans[p] = i;
			p++;
		}
		for (int j = 0; j <= n; j++) {
			dp[i + 1][j + 1] += dp[i][j] * (n - j) / n;
			dp[i + 1][j] += dp[i][j] * j / n;
		}
	}
	for (int i = 0; i < q; i++) {
		int t = 0;
		scanf("%d", &t);
		printf("%d\n", ans[t]);
	}
	return 0;
}