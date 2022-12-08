#include<bits/stdc++.h>
using namespace std;
#define rep(i,a,b) for(int i=a;i<b;++i)
#define repeq(i,a,b) for(int i=a;i<=b;++i)
#define debug(x) cerr<<#x<<": "<<x<<endl;
const int sz = 1e5;
int n, ui[sz], vi[sz], dsu[sz], anc[sz], p[sz], pairs, diff[sz], sum[sz];
vector<vector<int> > g, pset;
bool black[sz];
int find(int i)
{
	if(dsu[i]<0)
		return i;
	dsu[i] = find(dsu[i]);
	return dsu[i];
}
void merge(int x, int y)
{
	x = find(x), y = find(y);
	if(x==y)
		return;
	if(dsu[x]>dsu[y])
		swap(x,y);
	dsu[x]+=dsu[y];
	dsu[y] = x;
}
void dfs(int u)
{
	for(int v:g[u])
		if(v!=p[u])
		{
			p[v] = u;
			dfs(v);
		}
}
void lca(int u)
{
	dsu[u] = -1;
	anc[u] = u;
	for(int v:g[u])
		if(v!=p[u])
		{
			lca(v);
			merge(u,v);
			anc[find(u)]=u;
		}
	black[u] = true;
	for(int v:pset[u])
		if(black[v])
		{
			diff[anc[find(v)]]-=2;
		}
}
void dfs2(int u)
{
	sum[u] = diff[u];
	for(int v:g[u])
		if(v!=p[u])
		{
			dfs2(v);
			sum[u]+=sum[v];
		}
}
int main()
{
	scanf("%d",&n);
	g.resize(n), pset.resize(n);
	rep(i,0,n-1)
	{
		scanf("%d%d",&ui[i],&vi[i]);
		--ui[i], --vi[i];
		g[ui[i]].push_back(vi[i]);
		g[vi[i]].push_back(ui[i]);
	}
	p[0] = -1;
	dfs(0);
	rep(i,0,n)
		diff[i]=0;
	scanf("%d",&pairs);
	rep(i,0,pairs)
	{
		int a, b;
		scanf("%d%d",&a,&b);
		if(a!=b)
		{
			--a, --b;
			pset[a].push_back(b);
			pset[b].push_back(a);
			++diff[a], ++diff[b];
		}
	}
	rep(i,0,n)
		black[i] = false;
	lca(0);
	dfs2(0);
	rep(i,0,n-1)
	{
		int x;
		if(ui[i]==p[vi[i]])
			x = vi[i];
		else
			x = ui[i];
		printf("%d\n",sum[x]);
	}
}