#include<cstdio>
#include<cstring>
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;
using namespace std;

struct Edge
{
	int next,to;
}e[MAXM*2];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	++etot;
	e[etot]=(Edge){head[u],v};
	head[u]=etot;
}

int ans;
bool vis[MAXN];
void dfs(int u)
{
	vis[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(!vis[v]) dfs(v), --ans;
	}
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	ans=m;
	for(int i=1; i<=n; ++i)
		if(!vis[i]) dfs(i);
	
	printf("%d",ans);
	return 0;
}