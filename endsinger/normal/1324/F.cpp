#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],dp[N],ans[N];
vector<int>e[N];
void dfs1(int u,int f)
{
	dp[u]=a[u];
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		dfs1(v,u);
		if(dp[v]>=0)
			dp[u]+=dp[v];
	}
}
void dfs2(int u,int f)
{
	for(auto v:e[u])
	{
		if(v==f)
			continue;
		if(ans[u]<dp[v]||ans[u]<0)
			ans[v]=dp[v];
		else
		{
			if(dp[v]>=0)
				ans[v]=ans[u];
			else
				ans[v]=dp[v]+ans[u];
		}
		dfs2(v,u);
	}
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&a[i]);
		a[i]=2*a[i]-1;
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	dfs1(1,0);
	ans[1]=dp[1];
	dfs2(1,0);
	for(int i=1;i<=n;i++)
		printf("%d ",ans[i]);
	return 0;
}