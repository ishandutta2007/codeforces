#include<bits/stdc++.h>
using namespace std;
const int N=400005,inf=1e9;
int n,d[N],a[N],q[N],bg,ed,dp[N];
vector<int>e[N],p[N];
void sol(int x)
{
	for(int i=1;i<=n;i++)
		dp[i]=inf;
	bg=ed=0;
	for(auto i:p[x])
	{
		dp[i]=0;
		q[ed++]=i;
	}
	while(bg<ed)
	{
		int u=q[bg++];
		for(auto v:e[u])
		{
			if(d[v]<d[u])
				continue;
			int w=max(0,dp[u]+(d[u]==d[v]?1:-1));
			if(w<dp[v])
			{
				dp[v]=w;
				q[ed++]=v;
			}
		}
	}
	for(int i=1;i<=n;i++)
		if(!dp[i])
			a[i]=min(a[i],x);
}
int main()
{
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&d[i]);
		if(d[i])
		{
			d[i]=0;
			q[ed++]=i;
		}
		else
			d[i]=inf;
		
	}
	for(int i=1;i<n;i++)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		e[u].push_back(v);
		e[v].push_back(u);
	}
	while(bg<ed)
	{
		int u=q[bg++];
		for(auto v:e[u])
		{
			if(d[v]>d[u]+1)
			{
				d[v]=d[u]+1;
				q[ed++]=v;
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		a[i]=d[i];
		int f=0;
		for(auto j:e[i])
			if(d[i]==d[j])
				f=1;
		if(f)
			p[d[i]].push_back(i);
	}
	for(int i=0;i<=n;i++)
		if(p[i].size())
			sol(i);
	for(int i=1;i<=n;i++)
		printf("%d ",d[i]*2-a[i]);
	return 0;
}