#include<cstdio>
#include<cstring>
#include<algorithm>
#include<vector>
#include<queue>
using namespace std;
typedef long long ll;
const int MAXN = 2e5 + 5;
const int MAXM = MAXN * 2;

struct Edge
{
	int next,to;
}e[MAXM];
int head[MAXN],etot=0, deg[MAXN];
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u] = etot;
	++deg[v];
}

void solve(void)
{
	int n, m;
	scanf("%d%d",&n,&m);
	etot=0;
	for(int i=1; i<=n; ++i)
		head[i] = deg[i] = 0;
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v);
	}
	
	static int clr[MAXN];
	static vector<int> fa[MAXN];
	static queue<int> q;
	
	for(int i=1; i<=n; ++i)
		fa[i].clear();
	
	for(int i=1; i<=n; ++i)
		if(!deg[i]) q.push(i);
	
	while(!q.empty())
	{
		int u=q.front(); q.pop();
		
		clr[u]=1;
		for(int i=0; i<(int)fa[u].size(); ++i)
		{
			if(fa[u][i] == 2){ clr[u] = 0; break;}
			if(fa[u][i] == 1) clr[u] = 2;
		}
		
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].to;
			--deg[v];
			fa[v].push_back(clr[u]);
			if(!deg[v]) q.push(v);
		}
	}
	
	int ans = 0;
	for(int i=1; i<=n; ++i)
		if(!clr[i]) ++ans;
	
	printf("%d\n",ans);
	for(int i=1; i<=n; ++i)
		if(!clr[i]) printf("%d ",i);
	putchar('\n');
}

int main(void)
{
	int T;
	scanf("%d",&T);
	while(T--) solve();
	return 0;
}