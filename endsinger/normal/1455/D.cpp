#include<bits/stdc++.h>
using namespace std;
const int N=505,inf=1e9;
int n,a[N],dp[N][N][N],ans;
void sol()
{
	scanf("%d",&n);
	for(int i=0;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=0;i<=n;i++)
		for(int j=0;j<=n;j++)
			for(int k=0;k<=n;k++)
				dp[i][j][k]=inf;
	ans=inf;
	dp[1][1][0]=0,dp[1][0][1]=1;
	for(int i=1;i<n;i++)
	{
		for(int j=0;j<=i;j++)
		{
			for(int k=0;k<=i;k++)
			{
				if(dp[i][j][k]>=inf)
					continue;
				if(a[i+1]>=a[j])
					dp[i+1][i+1][k]=min(dp[i+1][i+1][k],dp[i][j][k]);
				if(a[i+1]>=a[k]&&a[k]>=a[j])
					dp[i+1][k][i+1]=min(dp[i+1][k][i+1],dp[i][j][k]+1);
			}
		}
	}
	for(int j=0;j<=n;j++)
		for(int k=0;k<=n;k++)
			ans=min(ans,dp[n][j][k]);
	if(ans>=inf)
		ans=-1;
	printf("%d\n",ans);
}
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
		sol();
	return 0;
}