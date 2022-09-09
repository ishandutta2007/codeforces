#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 3e5 + 5;

struct Edge
{
	int next,to,w;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	e[++etot]=(Edge){ head[u],v,w};
	head[u]=etot;
}

struct Node
{
	int id;
	ll dis;
	inline friend bool operator < (const Node &u,const Node &v){ return u.dis>v.dis;}
};
ll dis[MAXN];
int pre[MAXN];
void dijstra(void)
{
	static priority_queue<Node> q;
	static bool vis[MAXN];
	memset(dis,0x3f,sizeof(dis));
	
	dis[1]=0;
	q.push((Node){1,0});
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
				pre[v]=i;
				q.push((Node){v,dis[v]});
			}
		}
	} 
}

bool ndel[MAXN];
int son[MAXN];
queue<int> q;

int main(void)
{
	int n,m,d;
	scanf("%d%d%d",&n,&m,&d);
	d=min(d,n-1);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	
	dijstra();
	for(int i=2; i<=n; ++i)
	{
		ndel[(pre[i]+1)>>1]=1;
		if(pre[i]&1) ++pre[i];
		else --pre[i];
		++son[ e[pre[i]].to ];
	}
	
	printf("%d\n",d);
	d-=n-1;
	for(int i=1; i<=n; ++i)
		if(!son[i]) q.push(i);
	while(d)
	{
		int u=q.front(); q.pop();
		int v = e[pre[u]].to;
		--son[v]; ++d;
		ndel[(pre[u]+1)>>1]=0;
		if(!son[v]) q.push(v);
	}
	for(int i=1; i<=m; ++i)
		if(ndel[i]) printf("%d ",i);
	return 0;
}