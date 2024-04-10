#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 4e5 + 5;

vector<int> g[MAXN];

int anc[MAXN], dep[MAXN];
void dfs_dep(int u,int fa)
{
	anc[u] = fa; dep[u] = dep[fa] + 1;
	for(int v: g[u]) if(v != fa)
		dfs_dep(v, u);
}

int f[MAXN];
void dfs_f(int u,int fa)
{
	f[u] = 0;
	for(int v: g[u]) if(v != fa)
	{
		dfs_f(v,u);
		f[u] = max(f[u], f[v] + 1);
	}
}

void solve(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<=n; ++i) g[i].clear();
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v);
		g[v].push_back(u);
	}
	
	dep[0] = -1;
	dfs_dep(1,0);
	int u1 = max_element(dep+1,dep+n+1) - dep;
	dfs_dep(u1,0);
	int u2 = max_element(dep+1,dep+n+1) - dep;
	int len = dep[u2], rt = u2;
	
	int save = n;
	while(dep[rt] != (len + 1) / 2) rt = anc[rt];
	if(len & 1)
	{
		++n;
		int u = rt, v = anc[rt];
		g[n] = {u,v};
		g[u].erase(find(g[u].begin(), g[u].end(), v));
		g[v].erase(find(g[v].begin(), g[v].end(), u));
		g[u].push_back(n);
		g[v].push_back(n);
		rt = n;
	}
	
	dfs_f(rt,0);
	
	int cnt = 0;
	for(int i=1; i<=save; ++i)
		if(f[i] < d) ++cnt;
	printf("%d\n",max(0, save - cnt));
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}