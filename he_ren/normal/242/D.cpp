#include<cstdio>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

struct Edge
{
	int next,to;
}e[MAXM<<1];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot] = (Edge){ head[u],v};
	head[u] = etot;
}

int a[MAXN], b[MAXN];
bool vis[MAXN];

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
	for(int i=1; i<=n; ++i) scanf("%d",&a[i]);
	
	queue<int> q;
	for(int i=1; i<=n; ++i)
		if(!a[i]) q.push(i);
	
	while(!q.empty())
	{
		int u = q.front(); q.pop();
		vis[u] = 1; ++b[u];
		for(int i=head[u]; i; i=e[i].next)
		{
			int v = e[i].to;
			++b[v];
			if(b[v] == a[v]) q.push(v);
		}
	}
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		if(vis[i]) ++ans;
	
	printf("%d\n",ans);
	for(int i=1; i<=n; ++i)
		if(vis[i]) printf("%d ",i);
	return 0;
}