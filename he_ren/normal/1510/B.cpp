#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int MAXD = 10 + 5;
const int ALL = (1<<10) + 5;
const int MAXN = ALL;
const int inf = 0x3f3f3f3f;
const ll linf = 0x3f3f3f3f3f3f3f3f;

#define bbit(i) (1<<(i))
#define bdig(x,i) (((x)>>(i))&1)
#define lowbit(x) ((x)&-(x))

int lb[ALL], num1[ALL];

template<const int MAXN,const int MAXM>
struct MCMF
{
	struct Edge
	{
		int next,to,flow,w;
	}e[MAXM<<1];
	int head[MAXN],etot;
	inline void add_one(int u,int v,int flow,int w)
	{
		e[++etot] = (Edge){ head[u],v,flow,w};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int flow,int w){ add_one(u,v,flow,w); add_one(v,u,0,-w);}
	
	int n,s,t;
	ll dis[MAXN], h[MAXN];
	int flow[MAXN], pre[MAXN];
	bool vis[MAXN];
	inline void clear(void){ memset(head,-1,sizeof(head)); etot = -1; memset(h,0,sizeof(h));}
	inline void init(int _n,int _s,int _t){ n=_n; s=_s; t=_t;}
	MCMF(void){ clear();}
	inline bool spfa(void)
	{
		for(int i=1; i<=n; ++i) dis[i] = linf, vis[i] = 0;
		queue<int> q;
		dis[s] = 0; flow[s] = inf;
		q.push(s); vis[s] = 1;
		while(q.size())
		{
			int u=q.front(); q.pop(); vis[u] = 0;
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
				ll nxt = dis[u] + e[i].w + h[u] - h[v];
				if(dis[v] > nxt)
				{
					flow[v] = min(flow[u], e[i].flow); pre[v] = i;
					dis[v] = nxt;
					if(!vis[v]) q.push(v), vis[v] = 1;
				}
			}
		}
		return dis[t] < linf;
	}
	inline bool dijkstra(void)
	{
		for(int i=1; i<=n; ++i) dis[i] = linf, vis[i] = 0;
		priority_queue<pli> q;
		dis[s] = 0; flow[s] = inf;
		q.push(make_pair(0, s));
		while(q.size())
		{
			int u = q.top().second; q.pop();
			if(vis[u]) continue;
			vis[u] = 1;
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to;
				ll nxt = dis[u] + e[i].w + h[u] - h[v];
				if(dis[v] > nxt)
				{
					flow[v] = min(flow[u], e[i].flow); pre[v] = i;
					dis[v] = nxt; q.push(make_pair(-dis[v], v));
				}
			}
		}
		return dis[t] < linf;
	}
	inline pii build(void)
	{
		int resf = 0, resc = 0;
		if(spfa()) do
		{
			resf += flow[t]; resc += flow[t] * (dis[t] - h[s] + h[t]);
			for(int u = t; u != s; u = e[pre[u]^1].to)
				e[pre[u]].flow -= flow[t],
				e[pre[u]^1].flow += flow[t];
			for(int i=1; i<=n; ++i) h[i] = min(linf, h[i] + dis[i]);
		}while(dijkstra());
		return make_pair(resf, resc);
	}
	
	inline int get_nxt(int u)
	{
		for(int i=head[u]; ~i; i=e[i].next)
			if(e[i].to != s && !e[i].flow)
				return e[i].to;
		return -1;
	}
};

int a[MAXN], nxt[MAXN];

int main(void)
{
	for(int i=2; i<ALL; ++i) lb[i] = lb[i>>1] + 1;
	for(int i=1; i<ALL; ++i) num1[i] = num1[i^lowbit(i)] + 1;
	
	int d,n;
	scanf("%d%d",&d,&n);
	for(int i=1; i<=n; ++i)
	{
		static char _a[MAXD];
		scanf("%s",_a);
		for(int j=0; j<d; ++j) a[i] |= (_a[j] - '0') << j;
	}
	
	static MCMF<MAXN * 3, MAXN * MAXN + MAXN * 4> mcmf;
	mcmf.clear();
	int s = n * 3 + 1, t = s + 1;
	mcmf.init(t, s, t);
	
	for(int i=1; i<=n; ++i)
	{
		mcmf.add_edge(s, i, 1, 0);
		mcmf.add_edge(i + n, t, 1, 0);
		mcmf.add_edge(i + n + n, t, 1, 0);
		mcmf.add_edge(i, i + n + n, 1, num1[a[i]] + 1);
	}
	
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j) if(num1[a[j]] > num1[a[i]] && (a[j] & a[i]) == a[i])
			mcmf.add_edge(i, j + n, 1, 0);
	
	pii res = mcmf.build();
	for(int i=1; i<=n; ++i)
	{
		nxt[i] = mcmf.get_nxt(i);
		if(nxt[i] > n + n) nxt[i] = 0;
		else nxt[i] -= n;
	}
	
	static vector<int> nodes[MAXD];
	for(int i=1; i<=n; ++i)
		nodes[num1[a[i]]].push_back(i);
	
	static bool vis[MAXN];
	
	printf("%d\n",res.second - 1);
	bool fir = 1;
	for(int i=1; i<=d; ++i)
		for(int j=0; j<(int)nodes[i].size(); ++j) if(!vis[nodes[i][j]])
		{
			if(!fir) printf("R ");
			int u = nodes[i][j], lst = 0;
			while(u)
			{
				vis[u] = 1;
				int cur = a[u] ^ lst;
				while(cur)
					printf("%d ",lb[lowbit(cur)]), cur ^= lowbit(cur);
				lst = a[u]; u = nxt[u];
			}
			fir = 0;
		}
	return 0;
}