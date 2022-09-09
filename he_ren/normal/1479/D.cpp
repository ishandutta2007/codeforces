#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 3e5 + 5;
const int LB = 19 + 2;

inline ll rnd(void){ return ((ll)rand()<<45) | ((ll)rand()<<30) | (rand()<<15) | rand();}

const int MAXP = MAXN * LB;
struct Segment_Tree
{
	ll sum[MAXP];
	int ls[MAXP], rs[MAXP], pcnt;
	#define lson(u) ls[u],l,mid
	#define rson(u) rs[u],mid+1,r
	Segment_Tree(void): pcnt(0) { sum[0] = ls[0] = rs[0] = 0;}
	void update(int &u,int l,int r,int q,ll k)
	{
		++pcnt; sum[pcnt] = sum[u]; ls[pcnt] = ls[u]; rs[pcnt] = rs[u]; u = pcnt;
		sum[u] ^= k;
		if(l == r) return;
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
	}
	ll query(int u,int l,int r,int ql,int qr)
	{
		if(!u) return 0;
		if(ql<=l && r<=qr) return sum[u];
		int mid = (l+r)>>1;
		ll res = 0;
		if(ql<=mid) res ^= query(lson(u),ql,qr);
		if(mid<qr) res ^= query(rson(u),ql,qr);
		return res;
	}
	ll query_fir(int u1,int u2,int u3,int u4,int l,int r,int ql,int qr)
	{
		if(!(sum[u1] ^ sum[u2] ^ sum[u3] ^ sum[u4])) return 0;
		if(l == r) return l;
		int mid = (l+r)>>1, res;
		if(ql<=mid && (res = query_fir(ls[u1],ls[u2],ls[u3],lson(u4),ql,qr))) return res;
		if(mid<qr) return query_fir(rs[u1],rs[u2],rs[u3],rson(u4),ql,qr);
		return 0;
	}
}tree;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int anc[MAXN], siz[MAXN], dep[MAXN], son[MAXN], top[MAXN];
void dfs_siz(int u,int fa)
{
	anc[u] = fa; siz[u] = 1; son[u] = -1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		dfs_siz(v,u);
		siz[u] += siz[v];
		if(son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
	}
}
void dfs_top(int u,int fa)
{
	if(son[u] == -1) return;
	top[son[u]] = top[u]; dfs_top(son[u], u);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa || v == son[u]) continue;
		top[v] = v; dfs_top(v,u);
	}
}

inline int lca(int u,int v)
{
	while(top[u] != top[v])
		dep[top[u]] > dep[top[v]]? u = anc[top[u]]: v = anc[top[v]];
	return dep[u] > dep[v]? v: u;
}

int n;
int a[MAXN];
ll val[MAXN];

int root[MAXN];
void dfs_tree(int u,int fa)
{
	tree.update(root[u] = root[fa], 1, n, a[u], val[a[u]]);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dfs_tree(v,u);
	}
}

int main(void)
{
	srand((unsigned long long)new char);
	
	int Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs_siz(1,0);
	top[1] = 1; dfs_top(1, 0);
	
	for(int i=1; i<=n; ++i) val[i] = rnd();
	dfs_tree(1,0);
	
	while(Q--)
	{
		int u,v,l,r;
		scanf("%d%d%d%d",&u,&v,&l,&r);
		int uv = lca(u,v);
		
		int res = tree.query_fir(root[u], root[v], root[uv], root[anc[uv]], 1, n, l, r);
		printf("%d\n",res? res: -1);
	}
	return 0;
}