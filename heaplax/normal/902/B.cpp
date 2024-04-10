#include<cstdio>
#define N 20001
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
char ch;void re(int& x)
{
	while(ch=getchar(),ch<33);x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
}
using namespace std;
int n,ans,c[N];
int cnt,head[N],nxt[N],to[N];
void dfs(int u,int fa,int col)
{
	if(col != c[u])	
		col=c[u],++ans;
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i]) != fa)
			dfs(v,u,col);
}
int main()
{
	re(n);
	for(int i=2,x;i<=n;++i)
	{
		re(x);
		add_edge(i,x);
		add_edge(x,i);
	}
	for(int i=1;i<=n;++i)re(c[i]);
	dfs(1,0,0);
	printf("%d\n",ans);
}