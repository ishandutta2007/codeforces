#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

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

ll ff[MAXN],gg[MAXN];

void dfs_ff(int u,int fa)
{
	ff[u] = gg[u] = 1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dfs_ff(v,u);
		
		int w=e[i].w;
		if(w==0) ff[u] += ff[v];
		else ff[u] += gg[v], gg[u] += gg[v];
	}
}

int f[MAXN], g[MAXN];
void dfs_f(int u,int fa)
{
	f[u] += ff[u]; g[u] += gg[u];
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(v==fa) continue;
		
		int w = e[i].w;
		ll tmpf = f[u], tmpg = g[u];
		if(w==0) tmpf -= ff[v];
		else tmpf -= gg[v], tmpg -= gg[v];
		
		if(w==0) f[v] += tmpf;
		else f[v] += tmpg, g[v] += tmpg;
		
		dfs_f(v,u);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v,w;
		scanf("%d%d%d",&u,&v,&w);
		add(u,v,w); add(v,u,w);
	}
	
	dfs_ff(1,0);
	dfs_f(1,0);
	
	ll ans = 0;
	for(int i=1; i<=n; ++i)
		ans += f[i] - 1;
	printf("%lld",ans);
	return 0;
}