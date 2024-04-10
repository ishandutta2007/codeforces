#include<bits/stdc++.h>
using namespace std;
const int N=405;
char s[N],t[N];
int dp[N][N],n,m,T;
void chmax(int &a,int b){if(a<b)a=b;}
int solve(int p)
{
	for(int i=0;i<=n+1;i++)
		for(int j=0;j<=m+1;j++)
			dp[i][j]=0;
	dp[1][1]=p;
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=p+1;j++)
		{
			//printf("%d %d %d\n",i,j,dp[i][j]);
			chmax(dp[i+1][j],dp[i][j]);
			if(s[i]==t[j])
				chmax(dp[i+1][j+1],dp[i][j]);
			if(s[i]==t[dp[i][j]])
				chmax(dp[i+1][j],dp[i][j]+1);
		}
	}
	return dp[n+1][p]>m;
}
int main()
{
	scanf("%d",&T);
	while(T--)
	{
		scanf("%s%s",s+1,t+1);
		n=strlen(s+1),m=strlen(t+1);
		int ok=0;
		for(int i=1;i<=m;i++)
			if(solve(i))
				ok=1;
		puts(ok?"YES":"NO");
	}
	return 0;
}