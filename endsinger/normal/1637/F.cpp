#include<bits/stdc++.h>
using namespace std;
const int N=200005;
int n,a[N],r,dp[N],mx[N];
long long s;
vector<int>e[N];
void dfs(int u,int f)
{
	for(auto v:e[u])
	{
		if(v!=f)
		{
			dfs(v,u);
			if(dp[v]>dp[mx[u]])
				mx[u]=v;
		}
	}
	dp[u]=max(a[u],dp[mx[u]]);
	if(f)
	{
		for(auto v:e[u])
			if(v!=f&&v!=mx[u])
				s+=dp[v];
		return;
	}
	if(e[u].size()==1)
	{
		s+=(a[u]<<1);
		return;
	}
	int w=0,cw=0;
	for(auto v:e[u])
	{
		s+=dp[v];
		if(dp[v]>w)
			cw=w,w=dp[v];
		else if(dp[v]>cw)
			cw=dp[v];
	}
	s+=(dp[u]<<1);
	s-=w+cw;
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
		scanf("%d",&a[i]);
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	for(int i=1;i<=n;i++)
		if(a[i]>a[r])
			r=i;
	dfs(r,0);
	printf("%lld\n",s);
	return 0;
}