#include<bits/stdc++.h>
using namespace std;
const int N=55;
int n,a[N];
long long k,dp[N][2][2];
long long dfs(int p,int x,int y)
{
	if(p<n-p+1)
		return 1;
	if(dp[p][x][y]!=-1)
		return dp[p][x][y];
	long long ans=0;
	for(int i=0;i<=1;i++)
	{
		if(a[p]==-1||a[p]==i)
		{
			for(int j=0;j<=1;j++)
			{
				if(a[n-p+1]==-1||a[n-p+1]==j)
				{
					if(x&&(i>j)||y&&(i>!j)||p==n-p+1&&(i!=j))
						continue;
					ans+=dfs(p-1,x&&(i==j),y&&(i!=j));
				}
			}
		}
	}
	return dp[p][x][y]=ans;
}
int main()
{
	scanf("%d%I64d",&n,&k);
	k++;
	memset(a,-1,sizeof(a));
	memset(dp,-1,sizeof(dp));
	a[n]=0;
	if(dfs(n,1,1)<k)
	{
		printf("-1");
		return 0;
	}
	for(int i=n-1;i>=1;i--)
	{
		a[i]=0;
		memset(dp,-1,sizeof(dp));
		long long x=dfs(n,1,1);
		if(k>x)
		{
			k-=x;
			a[i]=1;
		}
	}
	for(int i=n;i>=1;i--)
		printf("%d",a[i]);
	return 0;
}