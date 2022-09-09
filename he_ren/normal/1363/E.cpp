#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;

inline int Abs(int x){ return x<0? -x: x;}

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

int a[MAXN],b[MAXN],c[MAXN];

int sumb[MAXN], sumc[MAXN], dif[MAXN];

void dfs_sum(int u,int fa)
{
	sumb[u] = b[u];
	sumc[u] = c[u];
	dif[u] = (b[u] != c[u]);
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		
		a[v] = min(a[v], a[u]);
		dfs_sum(v,u);
		
		sumb[u] += sumb[v];
		sumc[u] += sumc[v];
		dif[u] += dif[v];
	}
}

ll ans = 0;
void dfs_ans(int u,int fa)
{
	int tot[2] = {0,0};
	
	if(b[u] != c[u])
		++tot[c[u]];
	
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		
		dfs_ans(v,u);
		tot[ sumc[v]>sumb[v] ] += Abs(sumb[v] - sumc[v]);
	}
	ans += (ll)min(tot[0],tot[1]) * 2 * a[u];
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i)
		scanf("%d%d%d",&a[i],&b[i],&c[i]);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs_sum(1,0);
	if(sumb[1] != sumc[1])
	{
		printf("-1");
		return 0;
	}
	
	dfs_ans(1,0);
	printf("%lld",ans);
	return 0;
}