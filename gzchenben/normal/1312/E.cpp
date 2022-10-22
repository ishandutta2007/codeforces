#include<cstdio>
#include<algorithm>
using namespace std;
int n,a[505],f[505][505],dp[505];
int main()
{
	scanf("%d",&n); 
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		f[i][i]=a[i];
	}
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			for(int k=l;k<r;k++)
			{
				if(f[l][k]==f[k+1][r] && f[l][k])
				{
					f[l][r]=f[l][k]+1;
					break;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		dp[i]=1e9;
		for(int j=0;j<i;j++)
		{
			if(f[j+1][i]) dp[i]=min(dp[i],dp[j]+1);
		}
	}
	printf("%d\n",dp[n]);
}