#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;
const int inf = 0x3f3f3f3f;

template<const int MAXN,const int MAXM>
struct MCMF
{
	struct Edge
	{
		int next,to,flow,w;
	}e[MAXM<<1];
	int head[MAXN], etot;
	inline void add_one(int u,int v,int flow,int w)
	{
		e[++etot] = (Edge){ head[u],v,flow,w};
		head[u] = etot;
	}
	inline void add_edge(int u,int v,int flow,int w){ add_one(u,v,flow,w); add_one(v,u,0,-w);}
	
	int n,s,t;
	int h[MAXN], dis[MAXN], pre[MAXN], mnf[MAXN];
	inline void clear(void){ etot = -1; memset(head,-1,sizeof(head));}
	inline void init(int _n,int _s,int _t){ n = _n; s = _s; t = _t;}
	inline bool dijkstra(void)
	{
		static bool vis[MAXN];
		priority_queue<pii> q;
		memset(vis,0,n+1); memset(dis,0x3f,(n+1)<<2);
		dis[s] = 0; q.emplace(0, s);
		mnf[s] = inf; pre[s] = -1;
		while(q.size())
		{
			int u = q.top().second; q.pop();
			if(vis[u]) continue;
			vis[u] = 1;
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to, nxt = dis[u] + e[i].w + h[u] - h[v];
				if(dis[v] > nxt)
				{
					dis[v] = nxt; q.emplace(-dis[v], v);
					mnf[v] = min(mnf[u], e[i].flow); pre[v] = i;
				}
			}
		}
		return vis[t];
	}
	pii build(void)
	{
		int resf = 0, resc = 0;
		memset(h, 0, (n+1)<<2);
		while(dijkstra())
		{
			for(int i=1; i<=n; ++i) h[i] = min(inf, h[i] + dis[i]);
			resf += mnf[t]; resc += mnf[t] * h[t];
			for(int u=t; u!=s; u=e[pre[u]^1].to)
				e[pre[u]].flow -= mnf[t],
				e[pre[u]^1].flow += mnf[t];
		}
		return make_pair(resf, resc);
	}
};

MCMF<MAXN * 2, MAXN * MAXN * 2 + MAXN> mcmf;

int lef[MAXN], rig[MAXN];

int main(void)
{
	int n,Q;
	scanf("%d%d",&n,&Q);
	for(int i=1; i<=n; ++i) lef[i] = 1, rig[i] = n;
	while(Q--)
	{
		int type,l,r,k;
		scanf("%d%d%d%d",&type,&l,&r,&k);
		for(int i=l; i<=r; ++i)
		{
			if(type == 1) lef[i] = max(lef[i], k);
			else rig[i] = min(rig[i], k);
		}
	}
	
	int S = n * 2 + 1, T = n * 2 + 2;
	mcmf.clear();
	mcmf.init(n * 2 + 2, S, T);
	for(int i=1; i<=n; ++i)
		for(int j=1; j<=n; ++j)
			mcmf.add_edge(S, n+i, 1, j * j - (j-1) * (j-1));
	for(int i=1; i<=n; ++i)
	{
		if(lef[i] > rig[i])
		{
			printf("-1");
			return 0;
		}
		mcmf.add_edge(i, T, 1, 0);
		for(int j=lef[i]; j<=rig[i]; ++j)
			mcmf.add_edge(n+j, i, 1, 0);
	}
	
	printf("%d",mcmf.build().second);
	return 0;
}