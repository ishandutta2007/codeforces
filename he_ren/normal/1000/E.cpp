#include<cstdio>
#include<cstring>
#include<stack>
using namespace std;
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;
#define for_Graph(g,u,i) for(int i=g.head[u]; i; i=g.e[i].next)

inline void chk_min(int &a,int b){ if(a>b) a=b;}

struct Edge
{
	int next,to;
};

struct Graph
{
	Edge e[MAXM*2];
	int head[MAXN],etot;
	Graph()
	{
		memset(head,0,sizeof(head));
		etot=0;
	}
	inline Edge operator [](const int &i){ return e[i];}
	
	inline void add(int u,int v)
	{
		e[++etot]=(Edge){ head[u],v};
		head[u]=etot;
	}
}g,h;

int n;

int clr[MAXN],ccnt=0;
int dfn[MAXN],low[MAXN],cur;
stack<int> sta;
bool vis[MAXN];
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cur;
	sta.push(u); vis[u]=1;
	for_Graph(g,u,i)
	{
		int v=g[i].to;
		if(v==fa) continue;
		if(!dfn[v])
		{
			tarjan(v,u);
			chk_min(low[u], low[v]);
		}
		else if(vis[v])
			chk_min(low[u], dfn[v]);
	}
	
	if(dfn[u]==low[u])
	{
		++ccnt;
		while(sta.top()!=u)
		{
			int v=sta.top();
			clr[v]=ccnt;
			vis[v]=0;
			sta.pop();
		}
		clr[u]=ccnt;
		vis[u]=0;
		sta.pop();
	}
}

int dis[MAXN];
void dfs(int u,int fa)
{
	for_Graph(h,u,i)
	{
		int v=h[i].to;
		if(v==fa) continue;
		dis[v]=dis[u]+1;
		dfs(v,u);
	}
}

int fnd(int u)
{
	dis[u]=0;
	dfs(u,0);
	int v=u;
	for(int i=1; i<=n; ++i)
		if(dis[i]>dis[v]) v=i;
	return v;
}

int main(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		g.add(u,v); g.add(v,u);
	}
	
	tarjan(1,0);
	for(int u=1; u<=n; ++u)
		for_Graph(g,u,i)
		{
			int v=g[i].to;
			if(clr[u]!=clr[v]) h.add(clr[u],clr[v]);
		}
	
	int u=fnd(1);
	int v=fnd(u);
	printf("%d",dis[v]);
	return 0;
}