#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

int Abs(int x){ return x<0? -x: x;}
int gcd(int a,int b){ return b? gcd(b,a%b): a;}

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

int ans = 0;

bool vis[MAXN];
int dis[MAXN];
void dfs(int u,int cur)
{
	vis[u] = 1; dis[u] = cur;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v = e[i].to;
		if(vis[v])
			ans = gcd(ans, Abs(cur + e[i].w - dis[v]));
		else dfs(v, cur + e[i].w);
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
		add(u,v,1); add(v,u,-1);
	}
	
	for(int i=1; i<=n; ++i)
		if(!vis[i]) dfs(i,0);
	
	if(!ans) ans = n;
	printf("%d",ans);
	return 0;
}