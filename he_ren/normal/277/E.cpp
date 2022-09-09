#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef long double ldb;
typedef pair<int,int> pii;
const int MAXN = 4e2 + 5;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

template<const int MAXN,const int MAXM>
struct MCMF
{
	struct Edge
	{
		int next,to,flow;
		ldb w;
	}e[MAXM<<1];
	int head[MAXN],etot;
	inline void add_one(int u,int v,int flow,ldb w)
	{
		e[++etot] = (Edge){ head[u],v,flow,w};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int flow,ldb w){ add_one(u,v,flow,w); add_one(v,u,0,-w);}
	
	int n,s,t, flow[MAXN], pre[MAXN];
	ldb dis[MAXN];
	inline void clear(void){ etot=-1; memset(head,-1,sizeof(head));}
	inline void init(int _n,int _s,int _t){ n=_n; s=_s; t=_t;}
	bool spfa(void)
	{
		for(int i=1; i<=n; ++i)
			dis[i] = linf;
		static bool vis[MAXN];
		queue<int> q;
		flow[s] = inf; dis[s] = 0;
		q.push(s); vis[s] = 1;
		while(q.size())
		{
			int u = q.front(); q.pop(); vis[u] = 0;
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
				if(dis[v] > dis[u] + e[i].w)
				{
					dis[v] = dis[u] + e[i].w; pre[v] = i;
					flow[v] = min(flow[u], e[i].flow);
					if(!vis[v]) q.push(v), vis[v] = 1;
				}
			}
		}
		return dis[t] < linf;
	}
	pair<int,ldb> solve(void)
	{
		int resf = 0;
		ldb resc = 0;
		while(spfa())
		{
			resf += flow[t]; resc += flow[t] * dis[t];
			int u = t;
			while(u != s)
				e[pre[u]].flow -= flow[t],
				e[pre[u]^1].flow += flow[t],
				u = e[pre[u]^1].to;
		}
		return make_pair(resf, resc);
	}
};

inline ldb dist(pii p,pii q){ return sqrtl((p.first - q.first) * (p.first - q.first) + (p.second - q.second) * (p.second - q.second));}

pii p[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%d%d",&p[i].first, &p[i].second);
	
	static MCMF<MAXN * 2, MAXN * MAXN> mcmf;
	mcmf.clear();
	
	int s = 1, t = (n<<1) + 2;
	mcmf.init(t, s, t);
	for(int i=1; i<=n; ++i)
	{
		mcmf.add_edge(i<<1, t, 1, 0);
		mcmf.add_edge(s, i<<1|1, 2, 0);
		for(int j=1; j<=n; ++j) if(p[j].second < p[i].second)
			mcmf.add_edge(i<<1|1, j<<1, 1, dist(p[i], p[j]));
	}
	
	pair<int,ldb> res = mcmf.solve();
	if(res.first != n-1) printf("-1");
	else printf("%.20lf",(double)res.second);
	return 0;
}