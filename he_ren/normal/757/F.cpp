#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int LB = 17 + 2;

int lb[MAXN];

int n;
vector<pii> og[MAXN];
vector<int> g[MAXN], rg[MAXN], h[MAXN];

namespace Dij
{
	void solve(int beg)
	{
		static ll dis[MAXN];
		static bool vis[MAXN];
		
		priority_queue< pair<ll,int> > q;
		memset(dis, 0x3f, sizeof(dis));
		dis[beg] = 0; q.emplace(0, beg);
		while(q.size())
		{
			int u = q.top().second; q.pop();
			if(vis[u]) continue;
			vis[u] = 1;
			for(auto it: og[u])
			{
				int v = it.first; ll nxt = dis[u] + it.second;
				if(nxt < dis[v])
					dis[v] = nxt, q.emplace(-dis[v], v);
			}
		}
		
		for(int u=1; u<=n; ++u)
			for(auto it: og[u])
			{
				int v = it.first;
				if(dis[v] != dis[u] + it.second) continue;
				g[u].emplace_back(v); rg[v].emplace_back(u);
			}
	}
}

namespace DSU
{
	int fa[MAXN];
	pii mn[MAXN];
	int find(int u)
	{
		if(fa[u] == u) return u;
		int v = fa[u]; fa[u] = find(fa[u]);
		mn[u] = min(mn[u], mn[v]);
		return fa[u];
	}
}

namespace Dom_Tree
{
	int dfn[MAXN], seq[MAXN], curdfn = 0;
	void dfs_dfn(int u)
	{
		dfn[u] = ++curdfn; seq[curdfn] = u;
		for(int v: g[u]) if(!dfn[v])
			dfs_dfn(v);
	}
	
	void solve(int beg)
	{
		dfs_dfn(beg);
		
		static vector<int> sdom_qry[MAXN];
		static int sdom[MAXN], key[MAXN];
		for(int ut=curdfn; ut>=1; --ut)
		{
			int u = seq[ut];
			DSU::fa[u] = u;
			int cur = dfn[u];
			if(u != beg)
			{
				for(int v: rg[u])
				{
					if(dfn[v] < dfn[u]) cur = min(cur, dfn[v]);
					else DSU::find(v), cur = min(cur, DSU::mn[v].first);
				}
				sdom_qry[seq[cur]].emplace_back(u);
			}
			sdom[u] = seq[cur];
			DSU::mn[u] = {cur, u};
			
			for(int v: sdom_qry[u])
			{
				DSU::find(v);
				key[v] = DSU::mn[v].second;
			}
			for(int v: g[u]) if(dfn[v] > dfn[u])
				DSU::fa[DSU::find(v)] = u;
		}
		
		static int idom[MAXN];
		for(int ut=2; ut<=n; ++ut)
		{
			int u = seq[ut];
			if(sdom[key[u]] == sdom[u])
				idom[u] = sdom[u];
			else
				idom[u] = idom[key[u]];
			h[idom[u]].emplace_back(u);
		}
	}
}

int dfs_siz(int u)
{
	int res=1;
	for(int v: h[u]) res += dfs_siz(v);
	return res;
}

int main(void)
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	
	lb[0] = -1;
	for(int i=1; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	int m,beg;
	cin >> n >> m >> beg;
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		cin >> u >> v >> w;
		og[u].emplace_back(v,w);
		og[v].emplace_back(u,w);
	}
	
	Dij::solve(beg);
	Dom_Tree::solve(beg);
	
	int ans = 0;
	for(int v: h[beg]) ans = max(ans, dfs_siz(v));
	printf("%d",ans);
	return 0;
}