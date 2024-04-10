#include<cstdio>
#include<cstdlib>
#include<algorithm>
using namespace std;
typedef long long ll;
const int MAXN = 1e3 + 5;

int ask(int u,int v)
{
	printf("? %d %d\n",u,v);
	fflush(stdout);
	int res;
	scanf("%d",&res);
	return res;
}

void answer(int u)
{
	printf("! %d\n",u);
	fflush(stdout);
}

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

int n,remain;
bool del[MAXN];
int neib[MAXN];

void dfs(int u,int fa)
{
	neib[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(del[v] || v==fa) continue;
		dfs(v,u);
		++neib[u];
	}
}

void dfs_del(int u,int fa)
{
	del[u]=1;
	--remain;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(del[v] || v==fa) continue;
		dfs_del(v,u);
	}
}

void solve(void)
{
	int root;
	for(int i=1; i<=n; ++i)
		if(!del[i]){ root=i; break;}
	
	dfs(root,0);
	--neib[root];
	
	int u=root;
	for(int i=1; i<=n; ++i)
		if(!del[i] && neib[i]>=2){ u=i; break;}
	
	int uu=-1,vv=-1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(del[v]) continue;
		if(uu==-1) uu=v;
		else{ vv=v; break;}
	}
	
	if(vv==-1)
		answer(ask(uu,u)),
		exit(0);
	
	int res=ask(uu,vv);
	if(res!=u) dfs_del(u,res);
	else dfs_del(uu,u), dfs_del(vv,u);
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
	
	remain=n;
	while(remain>1)
		solve();
	
	for(int i=1; i<=n; ++i)
		if(!del[i])
		{
			answer(i);
			return 0;
		}
	return 0;
}