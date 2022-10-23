#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

struct BIT
{
	ll tree[MAXN]; int n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,ll k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline ll query(int x)
	{
		ll res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
	inline ll query(int l,int r)
	{
		return query(r) - query(l-1);
	}
};

vector<int> g[MAXN];

int anc[MAXN], dep[MAXN], siz[MAXN], son[MAXN];
int dfnl[MAXN], dfnr[MAXN], top[MAXN], curdfn = 0;
void dfs_tree(int u,int fa)
{
	anc[u] = fa; siz[u] = 1; son[u] = 0;
	for(int v: g[u]) if(v != fa)
	{
		dep[v] = dep[u] + 1;
		dfs_tree(v,u);
		siz[u] += siz[v];
		if(siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs_dfn(int u,int fa,int tp)
{
	top[u] = tp;
	dfnl[u] = ++curdfn;
	if(son[u]) dfs_dfn(son[u], u, tp);
	for(int v: g[u]) if(v != fa && v != son[u])
		dfs_dfn(v, u, v);
	dfnr[u] = curdfn;
}
inline int lca(int u,int v)
{
	while(top[u] != top[v]) dep[top[u]] > dep[top[v]]? u = anc[top[u]]: v = anc[top[v]];
	return dep[u] < dep[v]? u: v;
}

const int D = 20;

BIT tree[D+1];

void update(int t,int u,int v,ll k)
{
	tree[t].update(dfnl[u], k);
	if(anc[v]) tree[t].update(dfnl[anc[v]], -k);
}
ll query(int t,int u)
{
	return tree[t].query(dfnl[u], dfnr[u]);
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].emplace_back(v); g[v].emplace_back(u);
	}
	
	dfs_tree(1,0); dfs_dfn(1,0,1);
	for(int i=0; i<=D; ++i)
		tree[i].n = n;
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int type;
		scanf("%d",&type);
		if(type == 1)
		{
			int u;
			scanf("%d",&u);
			ll res = 0;
			for(int v = u, t=0; v && t<=D; v=anc[v], ++t)
				res += query(t, v);
			printf("%lld\n",res);
		}
		else
		{
			int u, v, k, lim;
			scanf("%d%d%d%d",&u,&v,&k,&lim);
			
			int uv = lca(u, v);
			tree[lim].update(dfnl[u], k);
			tree[lim].update(dfnl[v], k);
			tree[lim].update(dfnl[uv], -2 * k);
			
			int x = uv, t = lim;
			while(x != 1 && t >= 1)
			{
				update(t, x, x, k);
				update(t-1, x, x, k);
				x = anc[x]; --t;
			}
			for(int i=0; i<=t; ++i)
				update(i, x, x, k);
		}
	}
	return 0;
}