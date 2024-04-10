#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<stack>
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;
using namespace std;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

struct Edge
{
	int next,from,to,w;
}e[MAXM*2];
int head[MAXN],etot=0;
inline void add(int u,int v,int w)
{
	++etot;
	e[etot]=(Edge){ head[u],u,v,w};
	head[u] = etot;
}

stack<int> s;
int dfn[MAXN],low[MAXN],cnt=0;
bool vis[MAXN];
int clr[MAXN],ccnt=0;
void tarjan(int u,int fa)
{
	dfn[u]=low[u]=++cnt;
	s.push(u); vis[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		if(!dfn[v])
		{
			tarjan(v,u);
			chk_min(low[u],low[v]);
		}
		else if(vis[v]) chk_min(low[u], low[v]);
	}
	
	if(dfn[u]==low[u])
	{
		clr[u]=++ccnt;
		while(s.top()!=u)
		{
			clr[s.top()]=ccnt;
			vis[s.top()]=0;
			s.pop();
		}
		s.pop(); vis[u]=0;
	}
}

bool can[MAXN];

int to;
bool pas[MAXN];
void dfs(int u,bool f)
{
	if(can[u]) f=1;
	if(u==to)
	{
		if(f) printf("YES");
		else printf("NO");
		exit(0);
	}
	pas[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(!pas[v]) dfs(v,f|e[i].w);
	}
}

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
	tarjan(1,0);
	for(int i=1; i<=etot; i+=2)
	{
		if(clr[e[i].from] == clr[e[i].to] && e[i].w)
			can[clr[e[i].from]]=1;
	}
	
	//for(int i=1; i<=n; ++i) printf("clr[%d]: %d\n",i,clr[i]);
	
	memset(head,0,sizeof(head));
	etot=0;
	for(int i=1; i<=m*2; ++i)
	{
		if(clr[e[i].from] != clr[e[i].to])
			add(clr[e[i].from],clr[e[i].to],e[i].w);
	}
	
	int start;
	scanf("%d%d",&start,&to);
	start=clr[start]; to=clr[to];
	dfs(start,0);
	return 0;
}