#include<bits/stdc++.h>

#define int long long

using namespace std;

inline int read()
{
	int res=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while(c>='0'&&c<='9'){res=res*10+c-'0';c=getchar();}
	return res*f;
}

const int N=3e5+5;
int n,m,x,st,ed,a[N],fa[N],vis[N],ans[N],all;

struct Edge
{
	int v,ne,id;
}e[N*2];
int head[N],tot;

inline void add(int u,int v,int id);
inline int find(int x);
void dfs(int u);

signed main()
{
	n=read();m=read();x=read();
	for(int i=1;i<=n;++i)
		a[i]=read(),all+=a[i],fa[i]=i;
	if(all<x*(n-1))
	{
		printf("NO\n");
		return 0;
	}
	for(int i=1;i<=m;++i)
	{
		int u=read(),v=read();
		if(find(u)==find(v)) continue;
		fa[find(u)]=find(v);
		add(u,v,i);add(v,u,i);
	}
	st=1;ed=n-1;
	dfs(1);
	printf("YES\n");
	for(int i=1;i<=n-1;++i)
		printf("%lld\n",ans[i]);
	return 0;
}

inline void add(int u,int v,int id)
{
	e[++tot]=(Edge){v,head[u],id};
	head[u]=tot;
}

inline int find(int x)
{
	return fa[x]==x?x:fa[x]=find(fa[x]);
}

void dfs(int u)
{
	vis[u]=1;
	for(int i=head[u];i;i=e[i].ne)
	{
		int v=e[i].v;
		if(vis[v]) continue;
		dfs(v);
		if(a[u]+a[v]>=x)
		{
			ans[st++]=e[i].id;
			a[u]+=a[v]-x;
		}
		else ans[ed--]=e[i].id;
	}
}