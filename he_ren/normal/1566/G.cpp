#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct Segment_Tree
{
	multiset<int> t[MAXN];
	int mn[MAXN<<2], n;
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	inline void clear(int _n){ n = _n; memset(mn, 0x3f, sizeof(mn));}
	inline void push_up(int u){ mn[u] = min(mn[ls(u)], mn[rs(u)]);}
	void update(int u,int l,int r,int q,int k,bool tag)
	{
		if(l == r)
		{
			if(tag) t[l].insert(k);
			else t[l].erase(t[l].find(k));
			mn[u] = t[l].size()? *t[l].begin(): inf;
			return;
		}
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k,tag);
		else update(rson(u),q,k,tag);
		push_up(u);
	}
	inline void update(int q,int k,int tag){ update(1,1,n,q,k,tag);}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(ql<=l && r<=qr) return mn[u];
		int mid = (l+r)>>1, res = inf;
		if(ql<=mid) res = min(res, query(lson(u),ql,qr));
		if(mid<qr) res = min(res, query(rson(u),ql,qr));
		return res;
	}
	inline int query(int ql,int qr){ return ql <= qr? query(1,1,n,ql,qr): inf;}
}tree;

struct Edge
{
	int u,v,w,id;
};

inline bool operator < (const Edge &p,const Edge &q)
{
	return p.w == q.w? p.id < q.id: p.w < q.w;
}

set<Edge> tall;
set<pii> tn[MAXN];

int deg[MAXN];
ll val[MAXN];
pii vmn[MAXN][3];
inline int get_kth(int u,int k){ return vmn[u][k].first;}

inline void upd_vmn(int u,bool tag)
{
	for(int i=0; i<3 && vmn[u][i].first != inf; ++i)
		tree.update(vmn[u][i].second, get_kth(u, i), tag);
}

multiset<ll> tval;
inline void upd_val(int u)
{
	if(val[u] != linf) tval.erase(tval.find(val[u]));
	upd_vmn(u, 0);
	
	auto it = tn[u].begin();
	for(int i=0; i<3; ++i)
		vmn[u][i] = make_pair(inf, inf);
	for(int i=0; i<3 && it != tn[u].end(); ++i, ++it)
		vmn[u][i] = *it;
	
	val[u] = deg[u] < 3? linf: (ll)get_kth(u,0) + get_kth(u,1) + get_kth(u,2);
	if(val[u] != linf) tval.insert(val[u]);
	upd_vmn(u, 1);
}

inline ll calc1(int u,int v)
{
	if(u > v) swap(u, v);
	upd_vmn(u, 0); upd_vmn(v, 0);
	int mn = min(tree.query(1, u - 1), tree.query(v + 1, tree.n));
	mn = min(mn, tree.query(u + 1, v - 1));
	upd_vmn(u, 1); upd_vmn(v, 1);
	if(mn != inf) return mn + tall.begin() -> w;
	return linf;
}

inline ll calc2(int u,int v)
{
	if(deg[u] < 2 || deg[v] < 2) return linf;
	if(vmn[u][1].second != vmn[v][1].second)
		return (ll)get_kth(u, 1) + get_kth(v, 1);
	ll res = linf;
	if(deg[v] >= 3 && vmn[u][1].second != vmn[v][2].second)
		res = min(res, (ll)get_kth(u, 1) + get_kth(v, 2));
	if(deg[u] >= 3 && vmn[u][2].second != vmn[v][1].second)
		res = min(res, (ll)get_kth(u, 2) + get_kth(v, 1));
	return res;
}

int etot = 0;
map<pii, Edge> mem;
inline void add_edge(int u,int v,int w)
{
	if(u > v) swap(u, v);
	++etot;
	++deg[u]; ++deg[v];
	Edge cur = (Edge){ u, v, w, etot};
	mem[make_pair(u, v)] = cur;
	tall.insert(cur);
	
	tn[u].insert(make_pair(w, v));
	tn[v].insert(make_pair(w, u));
	upd_val(u); upd_val(v);
}

inline void del_edge(int u,int v)
{
	if(u > v) swap(u, v);
	--deg[u]; --deg[v];
	Edge cur = mem[make_pair(u, v)];
	mem.erase(make_pair(u, v));
	tall.erase(cur);
	int w = cur.w;
	
	tn[u].erase(make_pair(w, v));
	tn[v].erase(make_pair(w, u));
	upd_val(u); upd_val(v);
}

inline ll get_ans(void)
{
	Edge cur = *tall.begin();
	int u = cur.u, v = cur.v;
	ll ans = min(calc1(u, v), calc2(u, v));
	if(tval.size()) ans = min(ans, *tval.begin());
	return ans;
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	tree.clear(n);
	memset(val, 0x3f, sizeof(val));
	for(int i=1; i<=n; ++i)
		for(int j=0; j<3; ++j)
			vmn[i][j] = make_pair(inf, inf);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add_edge(u,v,w);
	}
	
	printf("%lld\n",get_ans());
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int oper,u,v;
		scanf("%d%d%d",&oper,&u,&v);
		if(oper == 1)
		{
			int w;
			scanf("%d",&w);
			add_edge(u, v, w);
		}
		else
		{
			del_edge(u, v);
		}
		
		printf("%lld\n",get_ans());
	}
	return 0;
}