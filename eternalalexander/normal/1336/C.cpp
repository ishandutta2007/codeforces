#include <bits/stdc++.h>
int dp[3006][3006],n,m,ans=0,ouuan=998244353;
char s[3006],t[3006];
int main() {
	scanf("%s%s",s+1,t+1);
	n=std::strlen(s+1);m=std::strlen(t+1);
	for (int i=1;i<=m+1;++i) dp[0][i]=1;
	for (int i=1;i<=n;++i) dp[i][m+1]=(dp[i-1][m+1]*2)%ouuan;
	for (int i=1;i<=n;++i) {
		for (int j=1;j<=m;++j) {
			if (i+j-1>m||s[i]==t[i+j-1]) dp[i][j]=(dp[i][j]+dp[i-1][j])%ouuan;
			if (s[i]==t[j]) dp[i][j]=(dp[i][j]+dp[i-1][j+1])%ouuan;
		}
	} for (int i=m;i<=n;++i) ans=(ans+dp[i][1])%ouuan;
	printf("%d",ans); return 0;
}