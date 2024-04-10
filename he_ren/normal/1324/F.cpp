#include<cstdio>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

int a[MAXN];

int f[MAXN];
void dfs_f(int u,int fa)
{
	f[u] = a[u];
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs_f(v,u);
		if(f[v]>0) f[u]+=f[v];
	}
}

int g[MAXN];
void dfs_g(int u,int fa)
{
	g[u] += f[u];
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		
		if(f[v]>0) g[v] = g[u]-f[v];
		else g[v] = g[u];
		if(g[v]<0) g[v]=0;
		
		dfs_g(v,u);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d",&a[i]),
		a[i] = a[i]? 1: -1;
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs_f(1,0);
	dfs_g(1,0);
	
	for(int i=1; i<=n; ++i) printf("%d ",g[i]);
	return 0;
}