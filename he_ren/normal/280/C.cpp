#include<cstdio>
#include<algorithm>
using namespace std;
typedef long double ldb;
const int MAXN = 1e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN*2];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

int dep[MAXN];
void dfs(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dep[1]=1;
	dfs(1,0);
	
	ldb ans=0;
	for(int i=1; i<=n; ++i) ans+=(ldb)1/dep[i];
	printf("%.15lf",(double)ans);
	return 0;
}