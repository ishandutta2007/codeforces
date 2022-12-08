#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl;
const int sz= 1e5;
int n, m, d;
int pre[sz], ord[sz];
bool aff[sz];
vector<vector<int> > g;
int par[sz];
int up[sz], down[sz];
int main()
{
	scanf("%d%d%d",&n,&m,&d);
	rep(i,0,n)
		aff[i]=false;
	rep(i,0,m)
	{
		int u;
		scanf("%d",&u), --u;
		aff[u]=true;
	}
	g.resize(n);
	rep(i,0,n-1)
	{
		int u, v;
		scanf("%d%d",&u,&v), --u, --v;
		g[u].push_back(v);
		g[v].push_back(u);
	}
	int k=1;
	pre[0]=0, ord[0]=0, par[0]=0;
	rep(i,1,n)
		ord[i]=-1;
	rep(i,0,n)
	{
		int u = pre[i];
		for(int v:g[u])
			if(v!=par[u])
			{
				par[v]=u;
				ord[v]=k;
				pre[k]=v;
				++k;
			}
	}
	for(int i=n-1;i>=0;--i)
	{
		int u = pre[i];
		if(aff[u])
			up[i]=0, down[i]=0;
		else
			up[i]=-n, down[i]=-n;
		for(int v:g[u])
			if(v!=par[u])
				up[i]=max(up[i],1+up[ord[v]]);
	}
	int ans=0;
	for(int i=0;i<n;++i)
	{
		int u = pre[i];
		int best=down[i];
		for(int j=0;j<g[u].size();++j)
		{
			int v = g[u][j];
			if(v!=par[u])
			{
				down[ord[v]]=max(down[ord[v]],best+1);
				best = max(best,1+up[ord[v]]);
			}
		}
		best = down[i];
		for(int j=g[u].size()-1;j>=0;--j)
		{
			int v = g[u][j];
			if(v!=par[u])
			{
				down[ord[v]]=max(down[ord[v]],best+1);
				best = max(best,1+up[ord[v]]);
			}
		}
		int f = max(up[i],down[i]);
		if(f<0)
			ans = 0;
		else if(f<=d)
			++ans;
	}
	printf("%d\n",ans);
}