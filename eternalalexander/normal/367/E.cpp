#include <bits/stdc++.h>

using ll = long long;
const int mod = 1e9+7;
const int lim = 1e5;

int n,m,x,fac[lim + 7],ans;

int main() {
	scanf("%d%d%d",&n,&m,&x);
	if (n > m) { puts("0"); return 0; }
	fac[0] = 1;
	for (int i = 1; i <= lim; ++ i) fac[i] = (ll) fac[i-1] * i % mod;
	int dp[m+3][n+3][n+3];
	std::memset(dp,0,sizeof(dp));
	dp[1][0][0] = 1;
	for (int i = 1; i <= m; ++ i) {
		for (int j = 0; j <= n; ++ j)
		for (int k = 0; k <= j; ++ k) {
			if (k && i != x) dp[i+1][j][k-1] = (dp[i+1][j][k-1] + dp[i][j][k]) % mod; //-
			dp[i+1][j+1][k+1] = (dp[i+1][j+1][k+1] + dp[i][j][k]) % mod;
			dp[i+1][j+1][k] = (dp[i+1][j+1][k] + dp[i][j][k]) % mod;
			if (i != x) dp[i+1][j][k] = (dp[i+1][j][k] + dp[i][j][k]) % mod;
		}
	}
	printf("%lld",(ll) dp[m+1][n][0] * fac[n] % mod);
	return 0;
}