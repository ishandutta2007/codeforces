#include<cstdio>
#include<algorithm>
#include<queue>
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

int dep[MAXN],size[MAXN];
void dfs(int u,int fa)
{
	size[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dep[v] = dep[u]+1;
		dfs(v,u);
		size[u] += size[v];
	}
}

priority_queue<int> q;

int main(void)
{
	int n,d;
	scanf("%d%d",&n,&d);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	dfs(1,0);
	for(int i=1; i<=n; ++i) q.push(dep[i] - (size[i]-1));
	
	ll ans=0;
	while(d--) ans += q.top(), q.pop();
	printf("%lld",ans);
	return 0;
}