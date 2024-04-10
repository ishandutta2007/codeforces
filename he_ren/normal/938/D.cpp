#include<cstdio>
#include<cstring>
#include<iostream>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

struct Edge
{
	int next,to;
	ll w;
}e[MAXM*2 + MAXN];
int head[MAXN],etot=0;
inline void add(int u,int v,ll w)
{
	e[++etot] = (Edge){head[u],v,w};
	head[u]=etot;
}

struct Node
{
	int id;
	ll dis;
	inline friend bool operator < (const Node &p,const Node &q){ return p.dis>q.dis;}
};
ll dis[MAXN];
bool vis[MAXN];
priority_queue<Node> q;
void dij(void)
{
	memset(dis,0x3f,sizeof(dis));
	dis[0]=0;
	q.push((Node){0,0});
	while(!q.empty())
	{
		int u=q.top().id; q.pop();
		if(vis[u]) continue;
		vis[u]=1;
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].to;
			if(dis[v] > dis[u]+e[i].w)
			{
				dis[v]=dis[u]+e[i].w;
				q.push((Node){v,dis[v]});
			}
		}
	}
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		ll w;
		cin>>u>>v>>w;
		w<<=1ll;
		add(u,v,w); add(v,u,w);
	}
	for(int i=1; i<=n; ++i)
	{
		ll a;
		cin>>a;
		add(0,i,a);
	}
	
	dij();
	for(int i=1; i<=n; ++i) cout<<dis[i]<<' ';
	return 0;
}