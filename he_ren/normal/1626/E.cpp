#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;

int c[MAXN];
vector<int> g[MAXN];

int valid[MAXN];

int f[MAXN], tot[MAXN], ch[MAXN];
void dfs_up(int u,int fa)
{
	tot[u] = ch[u] = c[u];
	for(int v: g[u]) if(v != fa)
	{
		dfs_up(v, u);
		tot[u] += tot[v];
		ch[u] += c[v];
		f[u] |= f[v];
	}
	f[u] |= ch[u] && tot[u] >= 2;
}

int ff[MAXN];
void dfs_down(int u,int fa)
{
	valid[u] |= f[u] | ff[u];
	int cnt = ff[u];
	for(int v: g[u]) if(v != fa)
		cnt += f[v];
	for(int v: g[u]) if(v != fa)
	{
		ff[v] = cnt >= 2 || (cnt == 1 && !f[v]);
		ff[v] |= ch[u] + c[fa] - c[v] && tot[1] - tot[v] >= 2;
		dfs_down(v, u);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	for(int u=1; u<=n; ++u)
	{
		valid[u] = c[u];
		for(int v: g[u]) valid[u] |= c[v];
	}
	
	dfs_up(1,0); dfs_down(1,0);
	
	for(int u=1; u<=n; ++u)
		printf("%d ",(int)valid[u]);
	return 0;
}