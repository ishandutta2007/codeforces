#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 2e5 + 5;
const int MAXW = 50 + 5;
const ll linf = 0x3f3f3f3f3f3f3f3f;

struct Edge
{
	int next,to,w;
}e[MAXM<<1];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	e[++etot]=(Edge){ head[u],v,w};
	head[u] = etot;
}

ll dis[MAXN][MAXW], res[MAXN];
bool vis[MAXN][MAXW];
inline pair<ll,pii> make_state(int u,int w){ return make_pair(-dis[u][w], make_pair(u,w));}

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
	memset(res,0x3f,sizeof(res));
	priority_queue< pair<ll,pii> > q;
	dis[1][0] = res[1] = 0; q.push(make_state(1, 0));
	while(q.size())
	{
		pii cur = q.top().second; q.pop();
		int u = cur.first, lw = cur.second;
		if(vis[u][lw]) continue;
		vis[u][lw] = 1;
		if(!lw) res[u] = min(res[u], dis[u][lw]);
		
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to, nw = lw? 0: e[i].w;
			ll ndis = dis[u][lw] + (lw? (lw + e[i].w) * (lw + e[i].w): 0);
			if(dis[v][nw] > ndis)
				dis[v][nw] = ndis, q.push(make_state(v, nw));
		}
	}
	
	for(int i=1; i<=n; ++i)
		printf("%lld ",res[i] == linf? -1: res[i]);
	return 0;
}