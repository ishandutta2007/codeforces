#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 50 + 5;
const int MAXM = MAXN * MAXN;
const int inf = 0x3f3f3f3f;

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
	inline void add_edge(int u,int v,int flow,int w)
	{
		add_one(u,v,flow,w); add_one(v,u,0,-w);
	}
	
	int n,s,t;
	int dis[MAXN], h[MAXN], pre[MAXN];
	bool vis[MAXN];
	void clear(void){ etot = -1; memset(head,-1,sizeof(head));}
	void init(int _n,int _s,int _t){ n = _n; s = _s; t = _t;}
	MCMF(void){ clear();}
	bool dijkstra(void)
	{
		memset(dis,0x3f,(n+1)<<2); memset(vis,0,n+1);
		priority_queue<pii> q;
		dis[s] = 0; q.emplace(0, s);
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
					dis[v] = nxt; pre[v] = i;
					q.emplace(-dis[v], v);
				}
			}
		}
		return vis[t];
	}
	vector<int> build(void)
	{
		vector<int> res;
		memset(h,0,(n+1)<<2);
		while(dijkstra())
		{
			for(int i=1; i<=n; ++i)
				h[i] = min(inf, h[i] + dis[i]);
			res.push_back(h[t]);
			for(int u=t; u!=s; u=e[pre[u]^1].to)
				--e[pre[u]].flow,
				++e[pre[u]^1].flow;
		}
		return res;
	}
}mcmf;

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		mcmf.add_edge(u,v,1,w);
	}
	
	mcmf.init(n,1,n);
	auto val = mcmf.build();
	
	int d = (int)val.size();
	val.insert(val.begin(), 0);
	vector<ll> sum(d+1);
	for(int i=1; i<=d; ++i)
		sum[i] = sum[i-1] + val[i];
	
	int Q;
	scanf("%d",&Q);
	while(Q--)
	{
		int x;
		scanf("%d",&x);
		
		int l = 0, r = d;
		while(l<r)
		{
			int mid = (l+r+1)>>1;
			if((ll)val[mid] * mid - sum[mid] <= x) l = mid;
			else r = mid-1;
		}
		
		printf("%.20lf\n",(double)(x + sum[l]) / l);	
	}
	return 0;
}