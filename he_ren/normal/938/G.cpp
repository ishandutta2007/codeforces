#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;
const int MAXM = 4e5 + 5;
const int MAXQ = 2e5 + 5;
const int lb = 30;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)

struct Linear_Basis
{
	int a[lb];
	Linear_Basis(void){ memset(a,0,sizeof(a));}
	inline bool insert(int x)
	{
		for(int i=lb-1; i>=0; --i) if(bdig(x,i))
		{
			if(a[i]){ x ^= a[i]; continue;}
			a[i] = x;
			for(int j=i-1; j>=0; --j) if(bdig(a[i], j)) a[i] ^= a[j];
			for(int j=i+1; j<lb; ++j) if(bdig(a[j], i)) a[j] ^= a[i];
			return 1;
		}
		return 0;
	}
	inline int tomin(int x)
	{
		for(int i=lb-1; i>=0; --i)
			if(bdig(x,i)) x ^= a[i];
		return x;
	}
};

namespace DSU
{
	int fa[MAXN], siz[MAXN], val[MAXN];
	int sta_tm[MAXN], curtm = 0;
	inline void init(int _n)
	{
		for(int i=1; i<=_n; ++i)
		{
			fa[i] = i; siz[i] = 1;
			val[i] = 0;
		}
	}
	int find(int u){ return fa[u] == u? u: find(fa[u]);}
	int getval(int u){ return fa[u] == u? 0: val[u] ^ getval(fa[u]);}
	inline int connect(int u,int v,int k)
	{
		k ^= getval(u) ^ getval(v);
		u = find(u); v = find(v);
		if(u == v) return k;
		if(siz[u] > siz[v]) swap(u, v);
		sta_tm[++curtm] = u;
		fa[u] = v; siz[v] += siz[u]; val[u] = k;
		return -1;
	}
	inline void roll_back(int t)
	{
		while(curtm > t)
		{
			int u = sta_tm[curtm--], v = fa[u];
			fa[u] = u; siz[v] -= siz[u]; val[u] = 0;
		}
	}
}

pii qry[MAXQ];
int res[MAXQ];

namespace SegT
{
	vector< array<int,3> > eff[MAXQ<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	void add_edge(int u,int l,int r,int ql,int qr,array<int,3> k)
	{
		if(ql<=l && r<=qr){ eff[u].push_back(k); return;}
		int mid = (l+r)>>1;
		if(ql<=mid) add_edge(lson(u),ql,qr,k);
		if(mid<qr) add_edge(rson(u),ql,qr,k);
	}
	void dfs(int u,int l,int r,Linear_Basis bas)
	{
		using namespace DSU;
		int savetm = curtm;
		for(auto x: eff[u])
		{
			int k = connect(x[0], x[1], x[2]);
			if(k != -1) bas.insert(k);
		}
		if(l == r)
		{
			int qu = qry[l].first, qv = qry[l].second;
			if(qu != -1 && qv != -1)
				res[l] = bas.tomin(getval(qu) ^ getval(qv));
		}
		else
		{
			int mid = (l+r)>>1;
			dfs(lson(u),bas); dfs(rson(u),bas);
		}
		roll_back(savetm);
	}
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	static map<int,pii> lst[MAXN];
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		lst[u][v] = {w, 1};
	}
	
	int Q;
	scanf("%d",&Q);
	for(int i=1; i<=Q; ++i)
	{
		int type,u,v;
		scanf("%d%d%d",&type,&u,&v);
		qry[i] = {-1,-1};
		if(type == 1)
		{
			int w;
			scanf("%d",&w);
			lst[u][v] = {w, i};
		}
		else if(type == 2)
		{
			auto it = lst[u].find(v);
			int w = it -> second.first;
			int ql = it -> second.second;
			SegT::add_edge(1,1,Q, ql, i, {u, v, w});
			lst[u].erase(it);
		}
		else
		{
			qry[i] = {u,v};
		}
	}
	
	for(int u=1; u<=n; ++u)
		for(auto it: lst[u])
		{
			int v = it.first;
			int w = it.second.first;
			int ql = it.second.second;
			SegT::add_edge(1,1,Q, ql, Q, {u, v, w});
		}
	
	DSU::init(n);
	SegT::dfs(1,1,Q, Linear_Basis());
	
	for(int i=1; i<=Q; ++i)
		if(qry[i] != make_pair(-1,-1))
			printf("%d\n",res[i]);
	return 0;
}