#include<cstdio>
#include<algorithm>
const int MAXN = 5e5 + 5;
using namespace std;

inline void chk_max(int &a,int b){ if(a<b) a=b;}

struct Edge
{
	int next,to;
}e[MAXN<<1];
int head[MAXN],d[MAXN],etot=0;
inline void add(int u,int v)
{
	++etot;
	e[etot] = (Edge){ head[u],v};
	head[u] = etot;
	++d[v];
}

int q[MAXN],tl=0;
void dfs(int u,int fa,int lvl)
{
	if(d[u]==1)
	{
		q[++tl]=lvl;
		return;
	}
	for(int i=head[u]; i; i=e[i].next)
	{
		if(e[i].to==fa) continue;
		dfs(e[i].to,u,lvl+1);
	}
}

int main(void)
{
	int n;
	scanf("%d",&n);
	for(int i=1; i<n; ++i)
	{
		int u,v;
		scanf("%d%d",&u,&v);
		add(u,v); add(v,u);
	}
	
	int ans=0;
	for(int i=head[1]; i; i=e[i].next)
	{
		int u=e[i].to;
		tl=0;
		dfs(u,1,1);
		sort(q+1,q+tl+1);
		
		int t=0;
		for(int i=1; i<=tl; ++i)
		{
			if(t<q[i]) t=q[i];
			else ++t;
		}
		chk_max(ans,t);
	}
	printf("%d",ans);
	return 0;
}