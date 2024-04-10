#include<cstdio>
#include<algorithm>
#include<vector>
using namespace std;
typedef long long ll;
typedef unsigned int uint;
const int MAXN = 3e5 + 5;

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

struct Oper
{
	int d,x;
};
vector<Oper> q[MAXN];

int n;
ll tree[MAXN];
#define lowbit(x) ((x)&-(x))
inline void update(int x,int k)
{
	while(x<=n)
		tree[x]+=k,
		x+=lowbit(x);
}
inline ll query(int x)
{
	ll res=0;
	while(x)
		res += tree[x],
		x^=lowbit(x);
	return res;
}

int dep[MAXN];
ll ans[MAXN];
void dfs(int u,int fa)
{
	for(uint i=0; i<q[u].size(); ++i)
	{
		int d=q[u][i].d, x=q[u][i].x;
		update(dep[u],x); update(dep[u]+d+1,-x);
	}
	ans[u] = query(dep[u]);
	
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs(v,u);
	}
	
	for(uint i=0; i<q[u].size(); ++i)
	{
		int d=q[u][i].d, x=q[u][i].x;
		update(dep[u],-x); update(dep[u]+d+1,x);
	}
}

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	int m;
	scanf("%d",&m);
	for(int i=1; i<=m; ++i)
	{
		int u,d,x;
		scanf("%d%d%d",&u,&d,&x);
		q[u].push_back((Oper){d,x});
	}
	
	dep[1]=1;
	dfs(1,0);
	for(int i=1; i<=n; ++i) printf("%lld ",ans[i]);
	return 0;
}