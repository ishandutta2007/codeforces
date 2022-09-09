#include<cstdio>
const int MAXN = 5e5 + 5;

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

struct Node
{
	int lst,nxt;
}p[MAXN<<1];

inline void putlst(int v,int u)
{
	p[v].lst = p[u].lst;
	p[p[u].lst].nxt = v;
	p[v].nxt = u;
	p[u].lst = v;
}

inline void putnxt(int v,int u)
{
	p[v].nxt = p[u].nxt;
	p[p[u].nxt].lst = v;
	p[v].lst = u;
	p[u].nxt = v;
}

int n;

void dfs(int u,int fa)
{
	for(int i=head[u]; i; i=e[i].next)
	{
		int v=e[i].to;
		if(v==fa) continue;
		putlst(v,u+n);
		putnxt(v+n,u+n);
		dfs(v,u);
	}
}

int pos[MAXN*2];

int main(void)
{
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	p[1].nxt = p[0].lst = n+1;
	p[n+1].lst = p[0].nxt = 1;
	dfs(1,0);
	
	int now=0;
	for(int i=1; i; i=p[i].nxt)
		pos[i]=++now;
	for(int i=1; i<=n; ++i)
		printf("%d %d\n",pos[i],pos[i+n]);
	return 0;
}