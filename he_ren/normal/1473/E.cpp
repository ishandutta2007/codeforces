#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,int> pli;
const int MAXN = 2e5 + 5;
const int MAXM = 2e5 + 5;

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

ll dis[MAXN][2][2];
bool vis[MAXN][2][2];
inline pli make_state(int u,int x,int y,ll d){ return make_pair(-d, (u << 2) | (x << 1) | y);}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	
	memset(dis,0x3f,sizeof(dis));
	priority_queue<pli> q;
	dis[1][0][0] = 0; q.push(make_state(1,0,0,0));
	while(q.size())
	{
		int cur=q.top().second; q.pop();
		int u = cur>>2, x = (cur>>1)&1, y = cur&1;
		if(vis[u][x][y]) continue;
		vis[u][x][y] = 1;
		
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			for(int xx=x; xx<=1; ++xx)
				for(int yy=y; yy<=1; ++yy)
				{
					ll nxt = dis[u][x][y] + ((xx^x)? 0: e[i].w) + ((yy^y)? e[i].w: 0);
					if(dis[v][xx][yy] > nxt)
						dis[v][xx][yy] = nxt, q.push(make_state(v,xx,yy,nxt));
				}
		}
	}
	
	for(int i=2; i<=n; ++i)
		printf("%lld ",dis[i][1][1]);
	return 0;
}