#include<cstdio>
#include<algorithm>
#include<vector>
#include<stack>
using namespace std;
const int MAXN = 2e3 + 5;
const int MAXM = 1e5 + 5;

struct Graph
{
	struct Edge
	{
		int next,to;
	}e[MAXM<<1];
	int head[MAXN],etot;
	inline void add(int u,int v)
	{
		e[++etot]=(Edge){ head[u],v};
		head[u]=etot;
	}
	Graph(void): etot(0) {}
	inline Edge& operator [] (const int x){ return e[x];}
	inline Edge operator [] (const int x) const { return e[x];}
}g, h;

int dfn[MAXN], low[MAXN], cur=0;
int clr[MAXN], ccnt=0;
void tarjan(int u,int fa)
{
	dfn[u] = low[u] = ++cur;
	static stack<int> sta;
	static bool insta[MAXN];
	
	sta.push(u); insta[u]=1;
	for(int i=g.head[u]; i; i=g[i].next)
	{
		int v=g[i].to;
		if(v==fa) continue;
		if(!dfn[v])
			tarjan(v, u),
			low[u] = min(low[u], low[v]);
		else if(insta[v])
			low[u] = min(low[u], dfn[v]);
	}
	
	if(dfn[u] == low[u])
	{
		++ccnt;
		while(sta.top() != u)
			clr[sta.top()] = ccnt,
			insta[sta.top()] = 0,
			sta.pop();
		clr[u] = ccnt;
		insta[u] = 0;
		sta.pop();
	}
}

int deg[MAXN];

int mxl = 0;
int f[MAXN];
void dfs_f(int u,int fa)
{
	f[u] = 1;
	for(int i=h.head[u]; i; i=h[i].next)
	{
		int v=h[i].to;
		if(v==fa) continue;
		dfs_f(v,u);
		
		mxl = max(mxl, f[u] + f[v]);
		f[u] = max(f[u], f[v] + 1);
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
		if(u==v) continue;
		g.add(u,v); g.add(v,u);
	}
	
	int ans = 0;
	
	for(int i=1; i<=n; ++i)
		if(!dfn[i]) tarjan(i, 0), ++ans;
	--ans;
	
	static int size[MAXN];
	for(int i=1; i<=n; ++i)
		++size[clr[i]];
	for(int i=1; i<=ccnt; ++i)
		ans += size[i]-1;
	
	for(int u=1; u<=n; ++u)
		for(int i=g.head[u]; i; i=g[i].next)
		{
			int v=g[i].to;
			if(clr[v] == clr[u]) continue;
			h.add(clr[u], clr[v]);
			++deg[clr[v]];
		}
	
	for(int i=1; i<=ccnt; ++i)
		if(deg[i] > 1) ++ans;
	
	for(int i=1; i<=ccnt; ++i) if(!f[i])
	{
		if(deg[i] == 0) continue;
		mxl = 0;
		dfs_f(i,0);
		ans -= mxl - 2;
	}
	
	printf("%d",ans);
	return 0;
}