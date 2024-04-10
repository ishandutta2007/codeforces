#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int MAXN = 2e5 + 5;

struct Edge
{
	int next,to;
}e[MAXN];
int head[MAXN],etot=0, deg[MAXN];
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
	++deg[v];
}

ll a[MAXN];
int b[MAXN];
int in[MAXN];

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<=n; ++i) scanf("%lld",&a[i]);
	for(int i=1; i<=n; ++i) scanf("%d",&b[i]);
	
	for(int i=1; i<=n; ++i)
		if(b[i] != -1) ++in[b[i]];
	
	queue<int> q;
	for(int i=1; i<=n; ++i)
		if(!in[i]) q.push(i);
	
	ll ans = 0;
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		ans += a[u];
		
		if(b[u] == -1) continue;
		if(a[u] >= 0)
			a[b[u]] += a[u],
			add(u, b[u]);
		else
			add(b[u], u);
		
		--in[b[u]];
		if(!in[b[u]]) q.push(b[u]);
	}
	
	printf("%lld\n",ans);
	for(int i=1; i<=n; ++i)
		if(!deg[i]) q.push(i);
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		printf("%d ",u);
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].to;
			--deg[v];
			if(!deg[v]) q.push(v);
		}
	}
	return 0;
}