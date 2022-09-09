#include<cstdio>
#include<iostream>
using namespace std;
typedef long long ll;
const int MAXN = 1e5 + 5;
const int MAXM = 1e5 + 5;

inline void chk_min(int &a,int b){ if(a>b) a=b;}

struct Edge
{
	int next,to;
}e[MAXM*2];
int head[MAXN],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
}

int c[MAXN];
bool vis[MAXN];

int dfs(int u)
{
	int res=c[u];
	vis[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(vis[v]) continue;
		chk_min(res, dfs(v));
	}
	return res;
}

int main(void)
{
	int n,m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=n; ++i) scanf("%d",&c[i]);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	ll ans=0;
	for(int i=1; i<=n; ++i)
		if(!vis[i]) ans += (ll)dfs(i);
	cout<<ans;
	return 0;
}