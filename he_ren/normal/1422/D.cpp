#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = MAXN * 4;

struct Edge
{
	int next,to,w;
}e[MAXM];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	e[++etot] = (Edge){ head[u],v,w};
	head[u] = etot;
}

inline ll Abs(ll x){ return x<0? -x: x;}

struct Node
{
	int x,y,id;
}p[MAXN];

inline bool cmp_x(const Node &p,const Node &q){ return p.x < q.x;}
inline bool cmp_y(const Node &p,const Node &q){ return p.y < q.y;}
inline bool cmp_id(const Node &p,const Node &q){ return p.id < q.id;}

int sx,sy,ex,ey;

struct Data
{
	int id;
	ll dis;
};
inline bool operator < (const Data &p,const Data &q){ return p.dis > q.dis;}

ll dis[MAXN];
bool vis[MAXN];
priority_queue<Data> q;

int main(void)
{
	int len,n;
	scanf("%d%d",&len,&n);
	scanf("%d%d%d%d",&sx,&sy,&ex,&ey);
	for(int i=1; i<=n; ++i)
		scanf("%d%d",&p[i].x,&p[i].y), p[i].id = i;
	
	sort(p+1,p+n+1,cmp_x);
	for(int i=1; i<=n; ++i)
	{
		if(i>1) add(p[i].id, p[i-1].id, p[i].x - p[i-1].x);
		if(i<n) add(p[i].id, p[i+1].id, p[i+1].x - p[i].x);
	}
	
	sort(p+1,p+n+1,cmp_y);
	for(int i=1; i<=n; ++i)
	{
		if(i>1) add(p[i].id, p[i-1].id, p[i].y - p[i-1].y);
		if(i<n) add(p[i].id, p[i+1].id, p[i+1].y - p[i].y);
	}
	
	sort(p+1,p+n+1,cmp_id);
	
	for(int i=1; i<=n; ++i)
	{
		dis[i] = min(Abs(sx - p[i].x), Abs(sy - p[i].y));
		q.push((Data){ i,dis[i]});
	}
	
	while(!q.empty())
	{
		int u=q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u] = 1;
		
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			if(dis[v] > dis[u] + e[i].w)
			{
				dis[v] = dis[u] + e[i].w;
				q.push((Data){ v,dis[v]});
			}
		}
	}
	
	ll ans = Abs(sx-ex) + Abs(sy-ey);
	
	for(int i=1; i<=n; ++i)
		ans = min(ans, dis[i] + Abs(p[i].x - ex) + Abs(p[i].y - ey));
	
	printf("%lld",ans);
	return 0;
}