#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXQ = 2e5 + 5;

struct Data
{
	ll k,b;
	Data(void){}
	Data(ll _k,ll _b): k(_k), b(_b) {}
	inline ll get(ll x) const { return k * x + b;}
	inline void clear(void){ k = b = 0;}
};

inline Data operator + (const Data &p,const Data &q){ return Data(p.k + q.k, p.b + q.b);}
inline Data& operator += (Data &p,const Data &q){ return p = p + q;}

struct Segment_Tree
{
	Data tag[MAXN<<2];
	bool clr[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void upd_clr(int u){ clr[u] = 1; tag[u].clear();}
	inline void push_down(int u)
	{
		if(clr[u])
		{
			upd_clr(ls(u)); upd_clr(rs(u));
			clr[u] = 0;
		}
		tag[ls(u)] += tag[u]; tag[rs(u)] += tag[u];
		tag[u].clear();
	}
	void build(int u,int l,int r)
	{
		tag[u].clear(); clr[u] = 0;
		if(l == r) return;
		int mid = (l+r)>>1;
		build(lson(u)); build(rson(u));
	}
	void update_add(int u,int l,int r,int ql,int qr,Data k)
	{
		if(ql<=l && r<=qr){ tag[u] += k; return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update_add(lson(u),ql,qr,k);
		if(mid<qr) update_add(rson(u),ql,qr,k);
	}
	void update_clr(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr){ upd_clr(u); return;}
		push_down(u);
		int mid = (l+r)>>1;
		if(ql<=mid) update_clr(lson(u),ql,qr);
		if(mid<qr) update_clr(rson(u),ql,qr);
	}
	Data query(int u,int l,int r,int q)
	{
		if(l == r) return tag[u];
		push_down(u);
		int mid = (l+r)>>1;
		return q<=mid? query(lson(u),q): query(rson(u),q);
	}
	
	int n;
	inline void build(int _n){ n = _n; build(1,1,n);}
	inline void update_add(int ql,int qr,Data k){ if(ql<=qr) update_add(1,1,n,ql,qr,k);}
	inline void update_add(int q,Data k){ update_add(1,1,n,q,q,k);}
	inline void update_clr(int ql,int qr){ if(ql<=qr) update_clr(1,1,n,ql,qr);}
	inline Data query(int q){ return query(1,1,n,q);}
}tree;

vector<int> g[MAXN];
int qv[MAXQ], qk[MAXQ];
ll res[MAXQ];
vector<int> qs[MAXN];

int siz[MAXN], son[MAXN];
void dfs_tree(int u,int fa)
{
	siz[u] = 1; son[u] = -1;
	if(fa) g[u].erase(find(g[u].begin(), g[u].end(), fa));
	for(int v: g[u])
	{
		dfs_tree(v, u);
		siz[u] += siz[v];
		if(son[u] == -1 || siz[v] > siz[son[u]]) son[u] = v;
	}
}

int dfn[MAXN], seq[MAXN], cur_dfn = 0;
int dfnl[MAXN];
inline ll query(int u,int i)
{
	return tree.query(dfnl[u] + i).get(i);
}

void dfs_f(int u)
{
	dfnl[u] = cur_dfn + 1;
	if(son[u] != -1)
	{
		int v = son[u];
		dfs_f(v);
		int l = 0, r = siz[v];
		while(l<r)
		{
			int mid = (l+r)>>1;
			if(query(v, mid) >= (ll)siz[v] * mid + 1)
				l = mid+1;
			else
				r = mid;
		}
		tree.update_clr(dfnl[v] + l, dfnl[v] + siz[v] - 1);
		tree.update_add(dfnl[v] + l, dfnl[v] + siz[v] - 1, Data(siz[v], 1));
	}
	for(int v: g[u]) if(v != son[u])
	{
		dfs_f(v);
		for(int i=0; i<siz[v]; ++i)
		{
			ll cur = query(v, i);
			tree.update_add(dfnl[u] + i, Data(0, max(cur, (ll)siz[v] * i + 1)));
		}
	}
	dfn[u] = ++cur_dfn; seq[cur_dfn] = u;
	
	if(son[u] != -1)
		tree.update_clr(dfn[son[u]] + 1, dfn[u]);
	for(int v: g[u])
		tree.update_add(dfnl[u] + siz[v], dfn[u], Data(siz[v], 1));
	
	for(int id: qs[u])
	{
		int k = qk[id];
		if(k >= siz[u]) res[id] = (ll)(siz[u] - 1) * k + (int)g[u].size();
		else res[id] = query(u, k);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g[u].push_back(v); g[v].push_back(u);
	}
	
	int Q;
	scanf("%d",&Q);
	for(int i=1; i<=Q; ++i)
	{
		int v,k;
		scanf("%d%d",&v,&k);
		qv[i] = v; qk[i] = k;
		qs[v].push_back(i);
	}
	
	tree.build(n);
	dfs_tree(1,0); dfs_f(1);
	
	for(int i=1; i<=Q; ++i)
	{
		int v = qv[i], k = qk[i];
		res[i] += -(ll)siz[v] * k + k;
		printf("%lld\n",res[i]);
	}
	return 0;
}