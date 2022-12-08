#include<bits/stdc++.h>
using namespace std;
const int N=5010;
char s[N];
int f[N][N],dp[N],n;
int calc(int x,int y) {
	if(s[x+f[x][y]]>s[y+f[x][y]])return 0;
	return dp[x]+n-y+1-f[x][y];
}
int main() {
	int T;
	scanf("%d",&T);
	while(T--) {
		scanf("%d",&n);
		scanf("%s",s+1);
		int ans=0;
		for(int i=0;i<=n;i++)
			for(int j=0;j<=n;j++)
				f[i][j]=0;
		for(int i=n;i>=1;i--)
			for(int j=n;j>=1;j--)
				f[i][j]=(s[i]==s[j])?f[i+1][j+1]+1:0;
		dp[1]=ans=n;
		for(int i=2;i<=n;i++) {
			dp[i]=n-i+1;
			for(int j=1;j<i;j++)
				dp[i]=max(dp[i],calc(j,i)); 
			ans=max(ans,dp[i]);
		}
		printf("%d\n",ans);
	}
	return 0;
}