#include<cstdio>
#include<stack>
using namespace std;
typedef long long ll;
#define for_Graph(g,u,i) for(int i=g.head[u]; i; i=g.e[i].next)
const int MAXN = 2e5 + 5;
const int MAXM = 5e5 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

struct Edge
{
	int next,to;
}e[MAXM*2];
int head[MAXN],etot;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

int n,m,a,b;
bool del[MAXN],vis[MAXN];
void dfs1(int u)
{
	vis[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(vis[v] || del[v]) continue;
		dfs1(v);
	}
}

int chk(int u)
{
	for(int i=1; i<=n; ++i) vis[i]=del[i]=0;
	del[u]=1;
	if(u!=1) dfs1(1);
	else dfs1(2);
	for(int i=1; i<=n; ++i)
		if(!vis[i] && !del[i]) return 1;
	return 0;
}

bool can[MAXN][2];
void dfs2(int u,bool clr)
{
	vis[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(can[v][clr] || v==a || v==b) continue;
		can[v][clr]=1;
		dfs2(v,clr);
	}
}

int dfs3(int u)
{
	int res=1;
	vis[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(vis[v]) continue;
		if(can[v][0]^can[v][1])
			res += dfs3(v);
	}
	return res;
}

void solve(void)
{
	scanf("%d%d%d%d",&n,&m,&a,&b);
	etot=0;
	for(int i=1; i<=n; ++i) head[i]=0;
	
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	for(int i=1; i<=n; ++i) del[i]=0;
	if(!chk(a) || !chk(b)){ printf("0\n"); return;}
	
	for(int i=1; i<=n; ++i)
		can[i][0]=can[i][1]=0;
	dfs2(a,0); dfs2(b,1);
	
	for(int i=1; i<=n; ++i) vis[i]=0;
	ll x=dfs3(a)-1, y=dfs3(b)-1;
	printf("%lld\n",x*y);
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}