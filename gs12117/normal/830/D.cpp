#include<cstdio>
const int mod = 1000000007;
int n;
long long int dp[410][410];
long long int comb[410][410];
int main() {
	scanf("%d", &n);
	comb[0][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = 0; j <= i; j++) {
			comb[i][j] %= mod;
			comb[i + 1][j] += comb[i][j];
			comb[i + 1][j + 1] += comb[i][j];
		}
	}
	for (int i = 0; i <= n; i++) {
		dp[1][0] = 0;
	}
	dp[1][0] = 1;
	dp[1][1] = 1;
	for (int i = 1; i < n; i++) {
		for (int j = 0; j <= n - i; j++) {
			dp[i + 1][j] = 0;
			for (int k = 0; k <= j; k++) {
				dp[i + 1][j] += dp[i][k] * dp[i][j - k] % mod * comb[j][k] % mod*(1 + 2 * j);
				dp[i + 1][j] %= mod;
			}
			for (int k = 1; k <= j; k++) {
				dp[i + 1][j] += dp[i][k] * dp[i][j - k + 1] % mod * comb[j - 1][k - 1] % mod * 2 * j;
				dp[i + 1][j] %= mod;
			}
			for (int k = 2; k <= j + 1; k++) {
				dp[i + 1][j] += dp[i][k] * dp[i][j - k + 1] % mod * comb[j - 1][k - 2] % mod * 2 * j;
				dp[i + 1][j] %= mod;
			}
			for (int k = 0; k <= j - 1; k++) {
				dp[i + 1][j] += dp[i][k] * dp[i][j - 1 - k] % mod * comb[j - 1][k] % mod*j;
				dp[i + 1][j] %= mod;
			}
		}
	}
	printf("%I64d", dp[n][1]);
	return 0;
}