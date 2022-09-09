#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;
const int MAXQ = 3e5 + 5;

vector<int> g[MAXN];

int anc[MAXN], dep[MAXN], tag[MAXN];
void dfs_tag(int u,int fa)
{
	anc[u] = fa; dep[u] = dep[fa] + 1;
	for(int v: g[u]) if(v != fa)
	{
		dfs_tag(v, u);
		tag[u] ^= tag[v];
	}
}

int f[MAXN], gg[MAXN];
void dfs_f(int u,int fa)
{
	f[u] = tag[u];
	for(int v: g[u]) if(v != fa)
	{
		dfs_f(v, u);
		f[u] ^= gg[v] ^ f[v];
		gg[u] ^= gg[v] ^ f[v];
	}
}

inline int lca(int u,int v)
{
	if(dep[u] < dep[v]) swap(u,v);
	while(dep[u] > dep[v]) u = anc[u];
	while(u != v) u = anc[u], v = anc[v];
	return u;
}

int fa[MAXN];
inline void init(int n){ for(int i=1; i<=n; ++i) fa[i] = i;}
int find(int u){ return fa[u] == u? u: fa[u] = find(fa[u]);}
inline void connect(int u,int v){ fa[find(u)] = find(v);}

int a[MAXQ], b[MAXQ];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	init(n);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		if(find(u) == find(v)) continue;
		g[u].push_back(v); g[v].push_back(u);
		connect(u,v);
	}
	
	int Q;
	scanf("%d",&Q);
	for(int i=1; i<=Q; ++i)
	{
		scanf("%d%d",&a[i],&b[i]);
		tag[a[i]] ^= 1;
		tag[b[i]] ^= 1;
	}
	
	dfs_tag(1,0);
	if(*max_element(tag+1,tag+n+1) == 0)
	{
		printf("YES\n");
		for(int i=1; i<=Q; ++i)
		{
			int u = a[i], v = b[i];
			int uv = lca(u, v);
			vector<int> p,q;
			while(u != uv) p.push_back(u), u = anc[u];
			while(v != uv) q.push_back(v), v = anc[v];
			p.push_back(uv);
			p.insert(p.end(), q.rbegin(), q.rend());
			
			printf("%d\n",(int)p.size());
			for(int x: p) printf("%d ",x);
			printf("\n");
		}
		return 0;
	}
	
	printf("NO\n");
	
	dfs_f(1,0);
	printf("%d",((int)count(f+1,f+n+1,1) + 1) / 2);
	return 0;
}