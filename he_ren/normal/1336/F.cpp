#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1.5e5 + 5;
const int MAXM = 1.5e5 + 5;
const int LB = 17 + 2;

#define lowbit(x) ((x)&-(x))

int lb[MAXN];

struct BIT
{
	int tree[MAXN],n;
	inline void update(int x,int k)
	{
		while(x<=n)
			tree[x] += k,
			x += lowbit(x);
	}
	inline void update(int l,int r,int k){ update(l,k); update(r+1,-k);}
	inline int query(int x)
	{
		int res = 0;
		while(x)
			res += tree[x],
			x ^= lowbit(x);
		return res;
	}
};

const int MAXSIZ = 2e7 + 5;
namespace Segment_Tree
{
	int n, sum[MAXSIZ], ls[MAXSIZ], rs[MAXSIZ], pcnt = 0;
	#define lson(u) ls[u],l,mid
	#define rson(u) rs[u],mid+1,r
	void update(int &u,int l,int r,int q,int k)
	{
		if(!u) u = ++pcnt;
		sum[u] += k;
		if(l == r) return;
		int mid = (l+r)>>1;
		if(q<=mid) update(lson(u),q,k);
		else update(rson(u),q,k);
	}
	inline void update(int &u,int q,int k){ update(u,1,n,q,k);}
	int query(int u,int l,int r,int ql,int qr)
	{
		if(!u || (ql<=l && r<=qr)) return sum[u];
		int mid = (l+r)>>1, res = 0;
		if(ql<=mid) res += query(lson(u),ql,qr);
		if(mid<qr) res += query(rson(u),ql,qr);
		return res;
	}
	inline int query(int u,int ql,int qr){ return query(u,1,n,ql,qr);}
	void merge(int &u,int v,int l,int r)
	{
		if(!(u && v)){ u |= v; return;}
		sum[u] += sum[v];
		if(l == r) return;
		int mid = (l+r)>>1;
		merge(ls[u],lson(v)); merge(rs[u],rson(v));
	}
	inline void merge(int &u,int v){ merge(u,v,1,n);}
	
	vector<pii> val;
	void dfs_val(int u,int l,int r)
	{
		if(!u) return;
		if(l == r){ val.push_back(make_pair(l, sum[u])); return;}
		int mid = (l+r)>>1;
		dfs_val(lson(u)); dfs_val(rson(u));
	}
	inline vector<pii> expand(int u){ val.clear(); dfs_val(u,1,n); return val;}
}

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

int siz[MAXN], dep[MAXN], anc[MAXN][LB], dfn[MAXN], seq[MAXN], cur_dfn = 0;
inline void dfs_tree(int u,int fa)
{
	dfn[u] = ++cur_dfn; seq[dfn[u]] = u;
	for(int i=1; i<=lb[dep[u]]; ++i)
		anc[u][i] = anc[anc[u][i-1]][i-1];
	siz[u] = 1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v == fa) continue;
		dep[v] = dep[u] + 1;
		anc[v][0] = u;
		dfs_tree(v,u);
		siz[u] += siz[v];
	}
}

inline int to_dep(int u,int d)
{
	for(int t=dep[u]-d; t; t &= t-1)
		u = anc[u][lb[lowbit(t)]];
	return u;
}

inline int lca(int u,int v)
{
	if(dep[u] < dep[v]) swap(u,v);
	u = to_dep(u, dep[v]);
	if(u == v) return u;
	for(int i=lb[dep[u]]; anc[u][0] != anc[v][0]; --i)
		if(i <= lb[dep[u]] && anc[u][i] != anc[v][i])
			u = anc[u][i], v = anc[v][i];
	return anc[u][0];
}

struct Query
{
	int u,v,uv;
	Query(void){}
	Query(int _u,int _v,int _uv): u(_u), v(_v), uv(_uv) {}
}qry[MAXM];

int n,m,d;
ll ans = 0;

namespace Part1
{
	BIT tree;
	vector<Query> qrys[MAXN];
	
	void dfs_ans(int u,int fa)
	{
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			if(v == fa) continue;
			dfs_ans(v,u);
		}
		
		vector<Query> &vec = qrys[u];
		for(int i=0; i<(int)vec.size(); ++i)
			ans += tree.query(dfn[vec[i].u]) + tree.query(dfn[vec[i].v]);
		
		for(int i=0; i<(int)vec.size(); ++i)
		{
			int v = vec[i].u, v2 = vec[i].v;
			for(int T=1; T<=2; ++T, swap(v,v2))
				if(dep[v] >= dep[u] + d)
				{
					v = to_dep(v, dep[u] + d);
					tree.update(dfn[v], dfn[v] + siz[v] - 1, 1);
				}
		}
	}
	
	void solve(void)
	{
		for(int i=1; i<=m; ++i) qrys[qry[i].uv].push_back(qry[i]);
		tree.n = n;
		dfs_ans(1,0);
	}
}

namespace Part2
{
	inline ll chs2(int x){ return (ll)x * (x-1) / 2;}
	
	int at;
	vector<Query> qrys[MAXN];
	vector<int> oth[MAXN];
	
	int root[MAXN];
	inline void merge(int u,int v)
	{
		{
			using namespace Segment_Tree;
			
			int ru = root[u], rv = root[v];
			int need = dep[at] + d - (dep[u] - dep[at]);
			if(sum[ru] > sum[rv]) swap(ru, rv);
			
//			printf("need = %d  ",need);
			
			vector<pii> res = expand(ru);
			for(int i=0; i<(int)res.size(); ++i)
			{
				int kt = res[i].first, cnt = res[i].second;
				if(dep[seq[kt]] < need) continue;
				int k = to_dep(seq[kt], need);
				ans += (ll)cnt * query(rv, dfn[k], dfn[k] + siz[k] - 1);
//				printf("ans += %lld  ",(ll)cnt * query(rv, dfn[k], dfn[k] + siz[k] - 1));
			}
		}
		Segment_Tree::merge(root[u], root[v]);
	}
	
	inline void solve2(vector<int> &node)
	{
		stack<int> sta;
//		printf("\nbuilding...\n");
		for(int i=0; i<(int)node.size(); ++i)
		{
			int u = node[i];
//			printf("inserting %d...\n",u);
			if(sta.size())
			{
				int uv = lca(u, sta.top()), lst = 0;
//				printf("v = %d, lca = %d\n",sta.top(),uv);
				while(sta.size() && dep[sta.top()] >= dep[uv])
				{
//					if(lst) printf("\tmerge %d ==> %d  ",lst,sta.top()), merge(sta.top(), lst), printf("\n");
					if(lst) merge(sta.top(), lst);
					lst = sta.top(); sta.pop();
//					printf("\tpop %d\n",lst);
				}
				if(i == (int)node.size() - 1) return;
				root[uv] = root[lst]; sta.push(uv);
//				printf("push %d\n",uv);
			}
//			else printf("v = empty.\n");
			
			sta.push(u);
//			printf("push %d\n",u);
		}
	}
	
	inline void get_inside(int u)
	{
		root[u] = 0;
		int need = dep[at] + d - (dep[u] - dep[at]), cur = 0;
		for(int i=0; i<(int)oth[u].size(); ++i)
		{
			int k = oth[u][i];
			if(i && dep[lca(seq[k], seq[oth[u][i-1]])] >= need) ++cur;
			else ans += chs2(cur), cur = 1;
			Segment_Tree::update(root[u], k, 1);
//			printf("root[%d] = %d  upd %d\n",u,root[u],k);
		}
		ans += chs2(cur);
	}
	
	inline bool cmp_dfn(int x,int y){ return dfn[x] < dfn[y];}
	
	void solve(void)
	{
		Segment_Tree::n = n;
		
		for(int i=1; i<=m; ++i) qrys[qry[i].uv].push_back(qry[i]);
		
		for(int &k=at=1; k<=n; ++k) if((int)qrys[k].size() > 1)
		{
//			printf("k = %d\n",k);
//			for(int i=0; i<(int)qrys[k].size(); ++i)
//				printf("(%d, %d)\n",qrys[k][i].u,qrys[k][i].v);
			
			vector<Query> &vec = qrys[k];
			vector<int> node(1, k);
			for(int i=0; i<(int)vec.size(); ++i)
			{
				int u = vec[i].u, v = vec[i].v;
//				if(u == k || v == k) continue;
				if(dep[u] > dep[k] + d) u = to_dep(u, dep[k] + d);
				if(dep[v] > dep[k] + d) v = to_dep(v, dep[k] + d);
				oth[u].push_back(dfn[v]);
				node.push_back(u);
			}
			if((int)node.size() > 1)
			{
				sort(node.begin(), node.end(), cmp_dfn);
				node.erase(unique(node.begin(), node.end()), node.end());
				
				for(int i=0; i<(int)node.size(); ++i)
				{
//					printf("node: %d\n",node[i]);
					sort(oth[node[i]].begin(), oth[node[i]].end());
					get_inside(node[i]);
				}
				
				node.push_back(k);
				solve2(node);
				
				for(int i=0; i<(int)node.size(); ++i)
					oth[node[i]].clear();
			}
			
			static int tag[MAXN];
			vector<int> chg;
			for(int i=0; i<(int)vec.size(); ++i)
			{
				int v = vec[i].v;
				if(dep[v] >= dep[k] + d) v = to_dep(v, dep[k] + d), ++tag[v], chg.push_back(v);
			}
			for(int i=0; i<(int)vec.size(); ++i)
			{
				int u = vec[i].u;
				if(dep[u] >= dep[k] + d) u = to_dep(u, dep[k] + d), ans += tag[u];
			}
			for(int i=0; i<(int)chg.size(); ++i) tag[chg[i]] = 0;
			
//			for(int i=0; i<(int)vec.size(); ++i)
//			{
//				int u = vec[i].u, v = vec[i].v;
//				if(u == k || v == k) continue;
//				if(dep[u] >= dep[k] + d) u = to_dep(u, dep[k] + d), chg.push_back(u), ++tag[u];
//				if(dep[v] >= dep[k] + d) v = to_dep(v, dep[k] + d), chg.push_back(v), ++tag[v];
//			}
//			for(int i=0; i<(int)vec.size(); ++i)
//			{
//				int u = vec[i].u, v = vec[i].v;
//				if(u != k && v != k) continue;
//				if(u == k) swap(u,v);
//				
//				u = to_dep(u, dep[k] + d);
//				ans += tag[u];
//				++tag[u]; chg.push_back(u);
//			}
//			for(int i=0; i<(int)chg.size(); ++i) tag[chg[i]] = 0;
		}
	}
}

int main(void)
{
	lb[0] = -1;
	for(int i=2; i<MAXN; ++i) lb[i] = lb[i>>1] + 1;
	
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	dfs_tree(1,0);
	int curm = 0;
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		int uv = lca(u,v);
		if(dep[u] + dep[v] - dep[uv] * 2 < d) continue;
		if(dfn[u] > dfn[v]) swap(u,v);
		qry[++curm] = Query(u,v,uv);
	}
	m = curm;
	
//	printf("seq: ");
//	for(int i=1; i<=n; ++i) printf("%d ",seq[i]);
//	printf("\n");
	
	Part1::solve();
	Part2::solve();
	
	printf("%lld",ans);
	return 0;
}

/*
5 3 2
1 2
1 3
3 4
1 5

2 3
4 5
2 4

*/