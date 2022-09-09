#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXM = 5e5 + 5;

struct BIT
{
	int tree[MAXN], n;
	#define lowbit(x) ((x)&-(x))
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline void update(int l,int r,int k){ update(l,k); update(r+1,-k);}
	inline int query(int x)
	{
		int res=0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
}tree;

vector<int> g[MAXN], gw[MAXN];
inline void add_edge(int u,int v,int w)
{
	g[u].push_back(v); gw[u].push_back(w);
}

int anc[MAXN], dep[MAXN], sum[MAXN], siz[MAXN], son[MAXN];
void dfs_tree(int u,int fa)
{
	anc[u] = fa;
	siz[u] = 1; son[u] = -1;
	for(int i=0; i<(int)g[u].size(); ++i)
	{
		int v = g[u][i], w = gw[u][i];
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		sum[v] = sum[u] ^ w;
		dfs_tree(v, u);
		
		siz[u] += siz[v];
		if(son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
	}
}

int dfnl[MAXN], dfnr[MAXN], seq[MAXN], top[MAXN], cur_dfn = 0;
void dfs_dfn(int u,int fa,int tp)
{
	top[u] = tp;
	dfnl[u] = ++cur_dfn; seq[cur_dfn] = u;
	if(son[u] != -1) dfs_dfn(son[u], u, tp);
	for(int v: g[u]) if(v != fa && v != son[u])
		dfs_dfn(v, u, v);
	dfnr[u] = cur_dfn;
}

inline int lca(int u,int v)
{
	while(top[u] != top[v]) dep[top[u]] > dep[top[v]]? u = anc[top[u]]: v = anc[top[v]];
	return dep[u] > dep[v]? v: u;
}

int fa[MAXN];
inline void init(int _n){ for(int i=1; i<=_n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

int a[MAXM], b[MAXM], c[MAXM];
bool in_tree[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	
	init(n);
	for(int i=1; i<=m; ++i)
	{
		int u = a[i], v = b[i];
		if(find(u) == find(v)) continue;
		in_tree[i] = 1;
		connect(u, v);
		add_edge(u, v, c[i]);
		add_edge(v, u, c[i]);
	}
	
	for(int i=1; i<=n; ++i) if(!dfnl[i])
		dfs_tree(i, 0), dfs_dfn(i, 0, i);
	
	tree.n = n;
	for(int k=1; k<=m; ++k)
	{
		if(in_tree[k])
		{
			printf("YES\n");
			continue;
		}
		
		int u = a[k], v = b[k];
		int uv = lca(u, v);
		int t = tree.query(dfnl[u]) + tree.query(dfnl[v]) - 2 * tree.query(dfnl[uv]);
		if(t != 0)
		{
			printf("NO\n");
			continue;
		}
		
		int val = sum[u] ^ sum[v] ^ c[k];
		if(val != 1)
		{
			printf("NO\n");
			continue;
		}
		
		printf("YES\n");
		for(int i=u; i!=uv; i=anc[i]) tree.update(dfnl[i], dfnr[i], 1);
		for(int i=v; i!=uv; i=anc[i]) tree.update(dfnl[i], dfnr[i], 1);
	}
	return 0;
}