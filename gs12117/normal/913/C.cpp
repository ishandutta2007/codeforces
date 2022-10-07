#include<cstdio>
int n,m;
int c[100100];
long long int dp[100100][2];
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	dp[0][0] = (m % 2)*c[0];
	dp[0][1] = 2 * c[0];
	for (int i = 1; i < 31; i++) {
		dp[i][0] = dp[i - 1][0] + ((m >> i) % 2)*dp[i - 1][1];
		if (i<n&&dp[i][0] > dp[i - 1][0] + ((m >> i) % 2)*c[i])dp[i][0] = dp[i - 1][0] + ((m >> i) % 2)*c[i];
		if (i<n&&dp[i][0] > c[i] + ((m >> i) % 2)*c[i])dp[i][0] = c[i] + ((m >> i) % 2)*c[i];
		dp[i][1] = dp[i - 1][1] * 2;
		if (i < n&&dp[i][1] > 2 * c[i])dp[i][1] = 2 * c[i];
	}
	printf("%lld\n", dp[30][0]);
	return 0;
}