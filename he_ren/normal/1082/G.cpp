#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

template<const int MAXN,const int MAXM>
struct Max_Flow
{
	struct Edge
	{
		int next,to;
		ll flow;
	}e[MAXM<<1];
	int head[MAXN],etot;
	inline void add_one(int u,int v,ll flow)
	{
		e[++etot] = (Edge){ head[u],v,flow};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,ll flow1,ll flow2=0){ add_one(u,v,flow1); add_one(v,u,flow2);}
	
	int n,s,t;
	inline void clear(void){ etot = -1; memset(head,-1,sizeof(head));}
	inline void init(int _n,int _s,int _t){ n=_n; s=_s; t=_t;}
	Max_Flow(void){ clear();}
	int dep[MAXN], cur[MAXN];
	inline bool bfs(void)
	{
		for(int i=1; i<=n; ++i) cur[i] = head[i], dep[i] = -1;
		queue<int> q;
		dep[s] = 0; q.push(s);
		while(q.size())
		{
			int u=q.front(); q.pop();
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
				if(dep[v] == -1) dep[v] = dep[u] + 1, q.push(v);
			}
		}
		return ~dep[t];
	}
	ll dfs(int u,ll maxf)
	{
		if(u == t || !maxf) return maxf;
		ll res = 0, f;
		for(int &i=cur[u]; ~i; i=e[i].next)
			if(e[i].flow && dep[e[i].to] == dep[u] + 1 && (f = dfs(e[i].to, min(maxf, e[i].flow))))
			{
				e[i].flow -= f; e[i^1].flow += f;
				res += f; maxf -= f;
				if(!maxf) return res;
			}
		return res;
	}
	inline ll dinic(void)
	{
		ll res = 0;
		while(bfs()) res += dfs(s,linf);
		return res;
	}
};

ll p[MAXN];
int a[MAXM], b[MAXM], c[MAXM];

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%lld",&p[i]);
	for(int i=1; i<=m; ++i) scanf("%d%d%d",&a[i],&b[i],&c[i]);
	
	for(int i=1; i<=n; ++i) p[i] = -2 * p[i];
	for(int i=1; i<=m; ++i)
		p[a[i]] += c[i], p[b[i]] += c[i];
	for(int i=1; i<=n; ++i) p[i] = -p[i];
	
	static Max_Flow<MAXN, MAXM + 2 * MAXN> mf;
	int s = n+1, t = n+2;
	mf.init(t, s, t);
	
	const ll C = 1e14;
	for(int i=1; i<=n; ++i)
		mf.add_edge(s, i, C), mf.add_edge(i, t, C + p[i]);
	for(int i=1; i<=m; ++i)
		mf.add_edge(a[i], b[i], c[i], c[i]);
	
	ll res = mf.dinic();
	printf("%lld",-(res - n * C)/2);
	return 0;
}