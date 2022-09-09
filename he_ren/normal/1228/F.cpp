#include<cstdio>
#include<cstdlib>
#include<algorithm>
const int MAXN = 17;
const int MAXM = (1<<MAXN)+5;
using namespace std;

struct Edge
{
	int next,to;
}e[MAXM*2];
int head[MAXM],deg[MAXM],etot=0;
inline void add(int u,int v)
{
	e[++etot]=(Edge){ head[u],v};
	head[u]=etot;
	++deg[u];
}

int dep[MAXM],pre[MAXM];
void dfs_dep(int u,int fa)
{
	pre[u]=fa;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		dep[v]=dep[u]+1;
		dfs_dep(v,u);
	}
}

inline void error(void){ printf("0"); exit(0);}

int n,m;

int sz[MAXM],spec;

void chk(int u,int fa)
{
	if(u==spec) sz[u]=1;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		chk(v,u);
		sz[u]+=sz[v];
	}
	if(sz[u]&1) error();
	
	int f1=0,f2=0;
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		if(sz[v]==(sz[u]>>1)) ++f1;
		if(sz[v]==(sz[u]>>2)) ++f2;
	}
	
	if(u==spec)
	{
		if((f1==1 && f2==2) || (f1==1 && !f2));
		else error();
	}
	else if(deg[u])
	{
		if(f1!=2)error();
	}
	++sz[u];
}

inline void solve1(int u)
{
	for(int i=1; i<=m; ++i)
		if(i!=u) --deg[i];
	
	for(int i=1; i<=m; ++i)
	{
		if(deg[i]>3) error();
		if(deg[i]==1 || deg[i]==3)
		{
			if(spec) error();
			spec=i;
		}
	}
	if(!spec) error();
	
	chk(u,0);
	printf("1\n%d",spec);
}

inline void solve2(int u,int v)
{
	if(u>v) swap(u,v);
	for(int i=1; i<=m; ++i)
		--deg[i];
	
	for(int i=1; i<=m; ++i)
		if(deg[i]!=0 && deg[i]!=2) error();
	
	chk(u,v); chk(v,u);
	if(sz[u]!=sz[v]) error();
	printf("2\n%d %d",u,v);
}

int main(void)
{
	scanf("%d",&n);
	m = (1<<n)-2;
	for(int i=1; i<m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	for(int i=1; i<=m; ++i)
		if(deg[i]>4) error();
	
	dep[1]=0;
	dfs_dep(1,0);
	int u=1;
	for(int i=1; i<=m; ++i)
		if(dep[i]>dep[u]) u=i;
	
	dep[u]=0;
	dfs_dep(u,0);
	int v=u;
	for(int i=1; i<=m; ++i)
		if(dep[i]>dep[v]) v=i;
	
	int md=dep[v]>>1;
	if(dep[v]&1)
	{
		for(int i=v; i; i=pre[i])
			if(dep[i]==md || dep[i]==md+1)
			{
				solve2(i,pre[i]);
				break;
			}
		return 0;
	}
	
	for(int i=v; i; i=pre[i])
		if(dep[i]==md)
		{
			solve1(i);
			break;
		}
	return 0;
}