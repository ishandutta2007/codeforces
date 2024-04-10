#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 5e5 + 5;
const int MAXM = 5e5 + 5;
const int inf = 0x3f3f3f3f;

struct Edge
{
	int next,to,w;
}e[MAXM];
int head[MAXN], etot=0;
inline void add(int u,int v,int w)
{
	e[++etot] = (Edge){ head[u],v,w};
	head[u] = etot;
}

int clr[MAXN], dis[MAXN];;

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(v,u,w);
	}
	
	memset(clr,-1,sizeof(clr));
	memset(dis,0x3f,sizeof(dis));
	
	queue<int> q;
	q.push(n);
	dis[n] = 0;
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			if(dis[v] != inf) continue;
			
			if(clr[v] == -1) clr[v] = !e[i].w;
			else if(clr[v] == e[i].w)
				dis[v] = dis[u] + 1, q.push(v);
		}
	}
	
	if(dis[1] == inf) printf("-1\n");
	else printf("%d\n",dis[1]);
	for(int i=1; i<=n; ++i)
	{
		if(clr[i] == -1) putchar('0');
		else putchar(clr[i] + '0');
	}
	return 0;
}