#include<bits/stdc++.h>
#define Accepted 0
using namespace std;
const int mod=998244353;
int n,m,dp[555][555],sum1[555][555],sum2[555][555],pos,a[555],l,r,ans,mn,mnp;
int main()
{
	scanf("%d%d",&n,&m);
	ans=1;
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	for (int i=1;i<=n;i++)
	{
		dp[i][i]=1;dp[i][i-1]=1;
		sum1[i][i]=sum2[i][i]=1;
	}
    dp[n+1][n]=1;
	for (int i=1;i<n;i++)
	{
		for (int j=1;j+i<=n;j++)
		{
			l=j;r=i+j;mn=1e9;mnp=0;
			for (int k=l;k<=r;k++)
			{
				sum1[l][r]=(1ll*dp[l][k-1]*dp[k][r-1]+sum1[l][r])%mod;
			}
			for (int k=l;k<=r;k++)
			{
				sum2[l][r]=(1ll*dp[l+1][k]*dp[k+1][r]+sum2[l][r])%mod;
			}
			for (int k=l;k<=r;k++)
			{
				if (a[k]<mn)
				{
					mn=a[k];
					mnp=k;
				}
			}
			dp[l][r]=1ll*sum1[l][mnp]*sum2[mnp][r]%mod;
		}
	}
	printf("%d\n",dp[1][n]);
	return Accepted;
}