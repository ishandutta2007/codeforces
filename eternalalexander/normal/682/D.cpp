#include <bits/stdc++.h>
#define maxn 1005
int dp[1005][1005][12][2]={0},n,m,s1;
char s[maxn],t[maxn];

int main(){
	scanf("%d%d%d",&n,&m,&s1);
	scanf("%s%s",s+1,t+1);
	for(int i=0;i<=n;++i)for(int j=0;j<=m;++j)for(int k=1;k<=s1;++k)dp[i][j][k][0]=dp[i][j][k][1]=-1e8;
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j)
			for(int k=0;k<=s1;++k){
				dp[i][j][k][0]=std::max(dp[i-1][j-1][k-1][1],
				std::max(dp[i][j-1][k-1][1],std::max(dp[i-1][j][k-1][1],std::max(dp[i-1][j][k][0],dp[i][j-1][k][0]))));
				if (s[i]==t[j])dp[i][j][k][1]=std::max(std::max(dp[i-1][j-1][k-1][1],dp[i-1][j-1][k][1]),dp[i-1][j-1][k][0])+1;
			}
//	printf("%d %d\n",dp[1][1][1][1],dp[2][2][2][1]);
	printf("%d",std::max(dp[n][m][s1][0],dp[n][m][s1-1][1]));
	return 0;
}