#include <bits/stdc++.h>

int n,dp[105][105];
char s[105];

void solve() {
	std::memset(dp,0,sizeof(dp));
	scanf("%s",s+1);
	n = std::strlen(s+1);
	dp[1][0] = 1;
	for (int i = 1; i <= n; ++ i) {
		for (int j = 0; j <= i; ++ j) {
			if (s[i] != ')') dp[i+1][j+1] |= dp[i][j];
			if (j && (s[i] != '(')) dp[i+1][j-1] |= dp[i][j];
		}
	} if (dp[n+1][0]) puts("YES");
	else puts("NO");
}

int main() {
	int t;scanf("%d",&t);while(t--)solve();
	return 0;
}