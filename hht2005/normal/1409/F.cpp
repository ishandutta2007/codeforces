#include<bits/stdc++.h>
using namespace std;
char s[210],t[210];
int dp[210][210][210];
int main() {
	int n,k;
	scanf("%d%d%s%s",&n,&k,s+1,t+1);
	if(t[1]==t[2]) {
		int c=0;
		for(int i=1;i<=n;i++)
			if(s[i]==t[1])c++;//sdf
		c=min(c+k,n);
		printf("%d\n",c*(c-1)/2);
	} else {
		memset(dp,0xc0,sizeof(dp));
		dp[0][0][0]=0;
		for(int i=1;i<=n;i++)
			for(int j=0;j<=k&&j<=i;j++)
				for(int l=0;l<=i;l++) {
					if(j-(s[i]!=t[1])>=0)dp[i][j][l]=max(dp[i][j][l],dp[i-1][j-(s[i]!=t[1])][l-1]);
					if(j-(s[i]!=t[2])>=0)dp[i][j][l]=max(dp[i][j][l],dp[i-1][j-(s[i]!=t[2])][l]+l);
					dp[i][j][l]=max(dp[i][j][l],dp[i-1][j][l]);
				}
		int ans=0;
		for(int i=0;i<=k;i++)
			for(int j=0;j<=n;j++)
				ans=max(ans,dp[n][i][j]);
		printf("%d\n",ans);
	}
	return 0;
}