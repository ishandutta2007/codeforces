#include<bits/stdc++.h>
using namespace std;
int n,mni;
bool used[1111];
double p[1111][1111],dp[1111],lazy[1111],mn,ans;
int main()
{
	scanf("%d",&n);
	for (int i=1;i<=n;i++)
	{
		for (int j=1;j<=n;j++)
		{
			scanf("%lf",&p[i][j]);
			p[i][j]/=100.00;
		}
	}
	for (int i=1;i<n;i++)
	{
		dp[i]=1.00;
		lazy[i]=1-p[i][n];
	}
	used[n]=1;
	for (int i=1;i<n;i++)
	{
		mn=1e18;
		for (int j=1;j<=n;j++)
		{
			if (used[j]) continue;
			if (dp[j]/(1.00-lazy[j])<mn)
			{
				mn=dp[j]/(1.00-lazy[j]);
				mni=j;
			}
		}
		used[mni]=1;dp[mni]/=(1.00-lazy[mni]);
		if (mni==1) 
		{
			ans=dp[mni];
			break;
		}
		for (int j=1;j<=n;j++)
		{
			if (!used[j])
			{
				dp[j]+=(dp[mni]*p[j][mni]*lazy[j]);
				lazy[j]*=(1.00-p[j][mni]);
			}
		}
	}
	printf("%.9lf\n",ans);
	return 0;
}