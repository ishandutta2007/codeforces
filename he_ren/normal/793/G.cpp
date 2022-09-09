#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e4 + 5;
const int MAXQ = 1e4 + 5;
const int inf = 0x3f3f3f3f;

template<const int MAXN,const int MAXM>
struct Max_Flow
{
	struct Edge
	{
		int next,to,flow;
	}e[MAXM<<1];
	int head[MAXN], etot;
	inline void add_one(int u,int v,int flow)
	{
		e[++etot] = (Edge){ head[u],v,flow};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int flow)
	{
		add_one(u,v,flow); add_one(v,u,0);
	}
	
	int n,s,t;
	int dep[MAXN], cur[MAXN];
	void clear(void){ etot = -1; memset(head,-1,sizeof(head));}
	void init(int _n,int _s,int _t){ n = _n; s = _s; t = _t;}
	Max_Flow(void){ clear();}
	inline bool bfs(void)
	{
		memset(dep,-1,(n+1)<<2); memcpy(cur,head,(n+1)<<2);
		queue<int> q;
		dep[s] = 1; q.emplace(s);
		while(q.size())
		{
			int u = q.front(); q.pop();
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
				if(dep[v] == -1)
				{
					dep[v] = dep[u] + 1; q.emplace(v);
					if(v == t) return 1;
				}
			}
		}
		return 0;
	}
	inline int dfs(int u,int maxf)
	{
		if(u == s || !maxf) return maxf;
		int res = 0, f;
		for(int &i=cur[u]; ~i; i=e[i].next)
			if(e[i^1].flow && dep[e[i].to] == dep[u]-1 && (f = dfs(e[i].to, min(maxf, e[i^1].flow))))
			{
				e[i].flow += f; e[i^1].flow -= f;
				res += f; maxf -= f;
				if(!maxf) return res;
			}
		return res;
	}
	inline int dinic(void)
	{
		int res = 0;
		while(bfs()) res += dfs(t, inf);
		return res;
	}
};

Max_Flow< MAXN * 4 + MAXQ * 3, MAXN * 6 + MAXQ * 150 > mf;
int pcnt;

struct Segment_Tree
{
	int id[MAXN<<2];
	#define ls(u) ((u)<<1)
	#define rs(u) ((u)<<1|1)
	#define lson(u) ls(u),l,mid
	#define rson(u) rs(u),mid+1,r
	void build(int u,int l,int r,int type)
	{
		id[u] = ++pcnt;
		if(l == r)
		{
			if(type == 0) mf.add_edge(1, id[u], 1);
			else mf.add_edge(id[u], 2, 1);
			return;
		}
		int mid = (l+r)>>1;
		build(lson(u),type); build(rson(u),type);
		if(type == 0)
		{
			mf.add_edge(id[ls(u)], id[u], inf);
			mf.add_edge(id[rs(u)], id[u], inf);
		}
		else
		{
			mf.add_edge(id[u], id[ls(u)], inf);
			mf.add_edge(id[u], id[rs(u)], inf);
		}
	}
	void add_edge(int u,int l,int r,int ql,int qr,int v,int type)
	{
		if(ql<=l && r<=qr)
		{
			if(type == 0) mf.add_edge(id[u], v, inf);
			else mf.add_edge(v, id[u], inf);
			return;
		}
		int mid = (l+r)>>1;
		if(ql<=mid) add_edge(lson(u), ql,qr,v,type);
		if(mid<qr) add_edge(rson(u), ql,qr,v,type);
	}
}tlef, trig;

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	vector< tuple<int,int,int> > eff;
	for(int i=1; i<=Q; ++i)
	{
		int xl, yl, xr, yr;
		scanf("%d%d%d%d",&xl,&yl,&xr,&yr);
		
		eff.emplace_back(xl << 1 | 1, yl, yr);
		eff.emplace_back((xr+1) << 1, yl, yr);
	}
	
	pcnt = 2;
	tlef.build(1,1,n,0);
	trig.build(1,1,n,1);
	auto addrec = [&] (int xl,int xr,int yl,int yr)
	{
		if(xl > xr || yl > yr) return;
		int u = ++pcnt;
		tlef.add_edge(1,1,n, xl,xr,u,0);
		trig.add_edge(1,1,n, yl,yr,u,1);
	};
	
	sort(eff.begin(), eff.end());
	set< tuple<int,int,int> > st;
	st.emplace(1, n, 1);
	for(auto cure: eff)
	{
		int x, yl, yr; tie(x,yl,yr) = cure;
		if(x & 1)
		{
			x >>= 1;
			int l = yl, r = yr;
			auto it = prev(st.lower_bound(make_tuple(yl+1, -inf, -inf)));
			while(it != st.end() && get<0>(*it) <= yr)
			{
				l = min(l, get<0>(*it));
				r = max(r, get<1>(*it));
				addrec(get<2>(*it), x-1, get<0>(*it), get<1>(*it));
				st.erase(it++);
			}
			if(l < yl) st.emplace(l, yl-1, x);
			if(yr < r) st.emplace(yr+1, r, x);
		}
		else
		{
			x >>= 1;
			st.emplace(yl, yr, x);
		}
	}
	for(auto t: st)
		addrec(get<2>(t), n, get<0>(t), get<1>(t));
	
	mf.init(pcnt, 1, 2);
	printf("%d",mf.dinic());
	return 0;
}