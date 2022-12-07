#include<cstdio>
#define N 222222
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
using namespace std;
int n,t[2];
int cnt,head[N],nxt[N],to[N];
void dfs(int u,int fa,bool f)
{
	++t[f];
	for(int i=head[u];i;i=nxt[i])
		if(to[i]!=fa)
			dfs(to[i],u,f^1);
}
int main()
{
	scanf("%d",&n);
	for(int i=1,u,v;i<n;++i)
	{
		scanf("%d%d",&u,&v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs(1,0,0);
	printf("%I64d\n",1ll*t[0]*t[1]-n+1);
}