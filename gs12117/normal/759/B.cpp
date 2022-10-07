#include<stdio.h>
int n;
int a[100100];
int ans[100100];
int dp[100100][15];
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	a[0] = -99999999;
	for (int i = 0; i <= 12; i++) {
		dp[0][i] = -9999999;
	}
	ans[0] = 0;
	for (int i = 1; i <= n; i++) {
		if (dp[i - 1][0] >= a[i])ans[i] = ans[i - 1];
		else if (dp[i - 1][1] >= a[i])ans[i] = ans[i - 1] + 1;
		else ans[i] = ans[i - 1] + 2;
		for (int j = 0; j <= 12; j++) {
			dp[i][j] = -99999999;
			if (ans[i] - ans[i - 1] + j <= 12 && dp[i][j] < dp[i - 1][ans[i] - ans[i - 1] + j])dp[i][j] = dp[i - 1][ans[i] - ans[i - 1] + j];
		}
		if (dp[i][ans[i - 1] + 2 - ans[i]] < a[i])dp[i][ans[i - 1] + 2 - ans[i]] = a[i];
		if (dp[i][ans[i - 1] + 5 - ans[i]] < a[i] + 89)dp[i][ans[i - 1] + 5 - ans[i]] = a[i] + 89;
		if (dp[i][ans[i - 1] + 12 - ans[i]] < a[i] + 1439)dp[i][ans[i - 1] + 12 - ans[i]] = a[i] + 1439;
		printf("%d\n", (ans[i] - ans[i - 1]) * 10);
	}
	return 0;
}