#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN = 1e3 + 5;
const int MAXM = 1e3 + 5;

inline int Abs(int x){ return x<0? -x: x;}

struct Edge
{
	int next,to;
}e[MAXM*2];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}
int g[MAXN][MAXN],diss[MAXN],dist[MAXN];
queue<int> q;

void bfs(int dis[],int s)
{
	dis[s]=0;
	q.push(s);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].to;
			if(dis[v]==-1)
				dis[v]=dis[u]+1, q.push(v);
		}
	}
}

int main(void)
{
	int n,m,s,t;
	scanf("%d%d%d%d",&n,&m,&s,&t);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
		g[u][v]=g[v][u]=1;
	}
	for(int i=1; i<=n; ++i) g[i][i]=1;
	
	memset(diss,-1,sizeof(diss));
	memset(dist,-1,sizeof(dist));
	bfs(diss,s); bfs(dist,t);
	
	int ans=0;
	for(int i=1; i<=n; ++i)
		for(int j=1; j<i; ++j)
		{
			if(!g[i][j] && diss[j]>=diss[i] && diss[i]+dist[j]+1 >= diss[t])
				++ans;
			if(!g[i][j] && diss[j]<diss[i] && diss[j]+dist[i]+1 >= diss[t])
				++ans;
		}
	printf("%d",ans);
	return 0;
}