#include<cstdio>
#include<cstring>
#include<cstdlib>
typedef long long ll;
const int MAXN = 3e5 + 5;
const int MAXM = 3e5 + 5;

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

int n,c[MAXN];
ll cnt[4];
bool vis[MAXN];
inline void gao(int u,int clr)
{
	memset(vis,0,sizeof(vis));
	for(int i=head[u]; i; i=e[i].next)
		vis[e[i].to]=1;
	
	for(int i=1; i<=n; ++i)
		if(!vis[i])
		{
			if(c[i])
			{
				printf("-1");
				exit(0);
			}
			c[i]=clr;
			++cnt[clr];
		}
}

int main(void)
{
	int m;
	scanf("%d%d",&n,&m);
	for(int i=1; i<=m; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	gao(1,1);
	for(int i=1; i<=n; ++i)
	{
		if(!c[i])
		{
			gao(i,2);
			break;
		}
	}
	for(int i=1; i<=n; ++i)
	{
		if(!c[i])
		{
			gao(i,3);
			break;
		}
	}
	
	for(int u=1; u<=n; ++u)
	{
		if(!c[u])
		{
			printf("-1");
			return 0;
		}
		for(int i=head[u]; i; i=e[i].next)
		{
			int v=e[i].to;
			if(c[u]==c[v])
			{
				printf("-1");
				return 0;
			}
		}
	}
	if(!cnt[1] || !cnt[2] || !cnt[3])
	{
		printf("-1");
		return 0;
	}
	if((ll)m != cnt[1]*cnt[2]+cnt[2]*cnt[3]+cnt[3]*cnt[1])
	{
		printf("-1");
		return 0;
	}
	
	for(int i=1; i<=n; ++i) printf("%d ",c[i]);
	return 0;
}