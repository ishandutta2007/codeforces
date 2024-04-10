#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int n,k,a[1111],dp[1111][1111],lef[1111],x,sum[1111][1111],ans[111111],res;
int main()
{
	scanf("%d%d",&n,&k);
	for (int i=1;i<=n;i++) scanf("%d",&a[i]);
	sort(a+1,a+n+1);
	for (int i=0;i<=a[n]/(k-1);i++)
	{
		for (int j=0;j<=n;j++)
		{
			for (int h=0;h<=k;h++)
			{
				sum[j][h]=dp[j][h]=0;
			}
		}
		x=1;
		for (int j=1;j<=n;j++)
		{
			while(x<j && a[j]-a[x]>=i) x++;
			lef[j]=x-1;
		}
	//	for (int j=1;j<=n;j++) cout<<lef[j]<<" ";
	//	cout<<endl;
		for (int j=1;j<=n;j++)
		{
			dp[j][1]=1;sum[j][1]=(sum[j-1][1]+dp[j][1])%mod;
			for (int h=2;h<=k;h++)
			{
				dp[j][h]=sum[lef[j]][h-1];
				sum[j][h]=(sum[j-1][h]+dp[j][h])%mod;
			}
		}
		for (int j=1;j<=n;j++)
		{
			ans[i]=(ans[i]+dp[j][k])%mod;
		}
	}
	for (int j=1;j<=a[n]/(k-1);j++)
	{
		ans[j]=(ans[j]-ans[j+1])%mod;
	}
	for (int i=1;i<=a[n]/(k-1);i++)
	{
		res=(1ll*ans[i]*i+res)%mod;
	}
	printf("%d\n",(res+mod)%mod);
	return 0;
}