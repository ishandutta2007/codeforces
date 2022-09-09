#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;
const int MAXD = 1e3 + 5;
const int inf = 0x3f3f3f3f;

struct Edge
{
	int next,to,w;
}e[MAXM<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	e[++etot] = (Edge){ head[u],v,w};
	head[u] = etot;
}

struct Edge_uvw
{
	int u,v,w;
}ee[MAXM];

struct Node
{
	int id,dis;
	inline friend bool operator < (const Node &p,const Node &q){ return p.dis > q.dis;}
};
int dis[MAXN];
bool vis[MAXN];
void dijkstra(int s)
{
	memset(dis,0x3f,sizeof(dis));
	memset(vis,0,sizeof(vis));
	priority_queue<Node> q;
	dis[s] = 0;
	q.push((Node){s,0});
	while(!q.empty())
	{
		int u = q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].w)
				dis[v] = dis[u] + e[i].w,
				q.push((Node){v,dis[v]});
		}
	}
}

int diss[MAXN][MAXN];
pii p[MAXD];
int f[MAXD];

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
		ee[i] = (Edge_uvw){ u,v,w};
	}
	for(int i=1; i<=d; ++i)
		scanf("%d%d",&p[i].first,&p[i].second);
	
	for(int i=1; i<=n; ++i)
	{
		dijkstra(i);
		for(int j=1; j<=n; ++j)
			diss[i][j] = dis[j];
	}
	
	ll ans = 0;
	for(int i=1; i<=d; ++i)
		f[i] = diss[p[i].first][p[i].second],
		ans += f[i];
	
	for(int i=1; i<=m; ++i)
	{
		int u = ee[i].u, v = ee[i].v;
		
		ll res = 0;
		for(int j=1; j<=d; ++j)
		{
			int l = min(diss[p[j].first][u] + diss[p[j].second][v], diss[p[j].first][v] + diss[p[j].second][u]);
			
			res += min(f[j], l);
		}
		
		ans = min(ans, res);
	}
	
	printf("%lld",ans);
	return 0;
}