#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int n,x,y,t,a[100005];
long long dp[10][100005];
int main()
{
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d%d%d",&n,&x,&y);
		for(int i=0;i<=y+1;i++) for(int j=0;j<=n+1;j++) dp[i][j]=0;
		for(int i=1;i<=n;i++)
		{
			scanf("%d",&a[i]);
			dp[0][i]=dp[0][i-1]+a[i];
		}
		long long ans=0;
		for(int k=1;k<=y;k++)
		{
			for(int i=1;i<=n;i++)
			{
				dp[k][i]=max(dp[k][i-1],dp[k-1][i+1])+a[i];
			}
			ans=max(ans,dp[k][x+1-2*k]);
		}
		printf("%lld\n",max(ans,dp[0][x+1]));
	}
}