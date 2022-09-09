#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 10;

vector<pii> g[MAXN];
array<int,2> es[MAXN];

vector<int> vec;
int anc[MAXN], dep[MAXN], res[MAXN];
bool vis[MAXN];
void dfs_tree(int u,int fa)
{
	anc[u] = fa; vis[u] = 1;
	for(auto it: g[u])
	{
		int v,id; tie(v,id) = it;
		if(v == fa) continue;
		if(vis[v]) vec.emplace_back(id);
		else
		{
			dep[v] = dep[u] + 1;
			res[id] = dep[v] & 1;
			dfs_tree(v, u);
		}
	}
}

int fa[MAXN];
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}

void solve(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) g[i].clear();
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		es[i] = {u, v};
		g[u].emplace_back(v, i);
		g[v].emplace_back(u, i);
	}
	
	vec.clear();
	memset(vis, 0, n+1);
	anc[1] = 0; dep[1] = 0;
	dfs_tree(1, 0);
	
	auto chk = [&] (int t) -> bool
	{
		iota(fa+1, fa+n+1, 1);
		for(int i=1; i<=m; ++i) if(res[i] == t)
		{
			int u = es[i][0], v = es[i][1];
			if(find(u) == find(v)) return 0;
			fa[find(u)] = find(v);
		}
		return 1;
	};
	
	int all = (1<<(int)vec.size())-1;
	for(int mask=0; mask<=all; ++mask)
	{
		for(int i=0; i<(int)vec.size(); ++i)
			res[vec[i]] = (mask>>i)&1;
		if(!chk(0)) continue;
		if(!chk(1)) continue;
		for(int i=1; i<=m; ++i)
			putchar(res[i] + '0');
		printf("\n");
		return;
	}
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}