#include<cstdio>
#include<algorithm>
using namespace std;
long long n,a[1005],dp[1005][2],b[1005],c[1005];
int main()
{
	scanf("%lld",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%lld",&a[i]);
		b[i]=c[i]=a[i];
	}
	for(int i=1;i<=n;i++)
	{
		dp[i][0]=dp[i-1][0];
		for(int j=i;j>=1;j--)
		{
			if(c[j]>c[i])
			{
				dp[i][0]+=c[j]-c[i];
				c[j]=c[i];
			}
		}
	}
	for(int i=n;i>=1;i--)
	{
		dp[i][1]=dp[i+1][1];
		for(int j=i;j<=n;j++)
		{
			if(b[j]>b[i])
			{
				dp[i][1]+=b[j]-b[i];
				b[j]=b[i];
			}
		}
	}
	long long ans=1e16,minx=0;
	for(int i=1;i<=n;i++)
	{
		if(ans>dp[i][0]+dp[i][1])
		{
			ans=dp[i][0]+dp[i][1];
			minx=i;
		}
	}
	for(int i=1;i<=minx;i++)
	{
		long long now=1e16;
		for(int j=i;j<=minx;j++)
		{
			now=min(now,a[j]);
		}
		printf("%lld ",now);
	}
	for(int i=minx+1;i<=n;i++)
	{
		long long now=1e16;
		for(int j=i;j>=minx;j--)
		{
			now=min(now,a[j]);
		}
		printf("%lld ",now);
	}
	printf("\n");
}