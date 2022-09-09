#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2200 + 5;
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
	inline void add_edge(int u,int v,int flow,int w)
	{
		add_one(u,v,flow,w); add_one(v,u,0,-w);
	}
	
	int n,s,t;
	int h[MAXN], dis[MAXN], pre[MAXN], fl[MAXN];
	bool vis[MAXN];
	inline void clear(void){ etot=-1; memset(head,-1,sizeof(head));}
	inline void init(int _n,int _s,int _t){ n = _n; s = _s; t = _t;}
	MCMF(void){ clear();}
	inline bool dijkstra(void)
	{
		memset(dis, 0x3f, (n+1)<<2); memset(vis, 0, n+1);
		priority_queue<pii> q;
		dis[s] = 0; fl[s] = inf; q.emplace(0, s);
		while(q.size())
		{
			int u = q.top().second; q.pop();
			if(vis[u]) continue;
			vis[u] = 1;
			for(int i=head[u]; ~i; i=e[i].next) if(e[i].flow)
			{
				int v = e[i].to, nxt = dis[u] + e[i].w + h[u] - h[v];
				if(nxt < dis[v])
				{
					dis[v] = nxt; pre[v] = i; fl[v] = min(fl[u], e[i].flow);
					q.emplace(-dis[v], v);
				}
			}
		}
		return vis[t];
	}
	inline pii build(void)
	{
		memset(h, 0, (n+1)<<2);
		int resf = 0, resc = 0;
		while(dijkstra())
		{
			for(int i=1; i<=n; ++i)
				h[i] = min(inf, h[i] + dis[i]);
			resf += fl[t]; resc += fl[t] * h[t];
			for(int u=t; u!=s; u=e[pre[u]^1].to)
				e[pre[u]].flow -= fl[t], e[pre[u]^1].flow += fl[t];
		}
		return {resf, resc};
	}
};

int n;
int a[MAXN * 2], b[MAXN * 2];

int f[MAXN]; ll g[MAXN];
void build_fg(ll t)
{
	for(int i=1; i<=n; ++i)
		f[i] = b[i];
	memset(g, 0, (n+1)<<3);
	
	sort(f+1, f+n+1);
	for(int i=1; i<=2*n; ++i)
	{
		int pos = lower_bound(f+1, f+n+1, b[i]) - f;
		if(pos <= n)
			g[pos] = max(g[pos], a[i] * t + b[i]);
	}
	for(int i=2; i<=n; ++i)
		g[i] = max(g[i], g[i-1]);
}

bool check(ll t)
{
	build_fg(t);
	static int cnt[MAXN];
	memset(cnt, 0, (n+1)<<2);
	for(int i=n+1; i<=2*n; ++i)
	{
		int pos1 = lower_bound(f+1, f+n+1, b[i]) - f;
		int pos2 = lower_bound(g+1, g+n+1, a[i] * t + b[i]) - g;
		int pos = min(pos1, pos2);
		if(pos <= n) ++cnt[pos];
	}
	
	int cur = 0;
	for(int i=1; i<=n; ++i)
	{
		cur += cnt[i];
		if(cur == 0) return 0;
		--cur;
	}
	return 1;
}

int f2[MAXN]; ll g2[MAXN];
MCMF<MAXN * 4, MAXN * 10> mcmf;

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<=2*n; ++i)
		scanf("%d%d",&a[i],&b[i]);
	
	ll l = 0, r = 1.5e9;
	if(!check(r))
	{
		printf("-1\n");
		return 0;
	}
	while(l<r)
	{
		ll mid = (l+r)>>1;
		if(check(mid)) r = mid;
		else l = mid + 1;
	}
	
	build_fg(l);
	for(int i=1; i<=n; ++i)
		f2[i] = b[n+i], g2[i] = a[n+i] * l + b[n+i];
	sort(f2+1, f2+n+1);
	sort(g2+1, g2+n+1);
	
	int S = 4 * n + 1, T = 4 * n + 2;
	
	mcmf.init(T, S, T);
	for(int i=2; i<=n; ++i)
	{
		mcmf.add_edge(2*n+i, 2*n+i-1, inf, 0);
		mcmf.add_edge(3*n+i, 3*n+i-1, inf, 0);
	}
	for(int i=1; i<=n; ++i)
	{
		int posf = lower_bound(f+1, f+n+1, b[i]) - f;
		
		int u1 = upper_bound(f2+1, f2+n+1, b[i]) - f2 - 1;
		int u2 = upper_bound(g2+1, g2+n+1, a[i] * l + b[i]) - g2 - 1;
		int u3 = upper_bound(g2+1, g2+n+1, g[posf]) - g2 - 1;
		
		mcmf.add_edge(S, i, 1, 0);
		if(u1) mcmf.add_edge(i, 2*n+u1, 1, 0);
		if(u2) mcmf.add_edge(i, 3*n+u2, 1, 0);
		if(u3) mcmf.add_edge(i, 3*n+u3, 1, 1);
	}
	for(int i=n+1; i<=2*n; ++i)
	{
		int u1 = lower_bound(f2+1, f2+n+1, b[i]) - f2;
		int u2 = lower_bound(g2+1, g2+n+1, a[i] * l + b[i]) - g2;
		
		mcmf.add_edge(i, T, 1, 0);
		mcmf.add_edge(2*n+u1, i, 1, 0);
		mcmf.add_edge(3*n+u2, i, 1, 0);
	}
	
	pii ans = mcmf.build();
	printf("%lld %d\n",l,ans.second + n);
	return 0;
}