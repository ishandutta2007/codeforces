#include<map>
#include<set>
#include<queue>
#include<stack>
#include<cmath>
#include<ctime>
#include<bitset>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<complex>
#include<iostream>
#include<algorithm>
#define N 300001
#define LL long long
#define add_edge(u,v) nxt[++cnt]=head[u],head[u]=cnt,to[cnt]=v
#define open(x) freopen(#x".in","r",stdin),freopen(#x".out","w",stdout)
char ch;bool fs;void re(int& x)
{
	while(ch=getchar(),ch<33);
	if(ch=='-')fs=1,x=0;else fs=0,x=ch-48;
	while(ch=getchar(),ch>33)x=x*10+ch-48;
	if(fs)x=-x;	
}
using namespace std;
int n,m,siz,d[N],dis[N],top,st[N],p[N],pre[N];
int cnt,head[N],nxt[N+N],to[N+N];
bool vis[N];
void dfs(int u)
{
	vis[u]=1;
	st[++siz]=u;
	for(int i=head[u],v;i;i=nxt[i])
		if(!vis[v=to[i]])
			dfs(v);
}
int main()
{
	re(n),re(m);
	for(int i=1,u,v;i<=m;++i)
	{
		re(u),re(v);
		++d[u],++d[v];
		add_edge(u,v);
		add_edge(v,u);
	}
	memset(dis,-1,sizeof dis);
	dis[1]=1;
	st[++top]=1;
	for(int i=1;i<=top;++i)
		for(int u=st[i],j=head[u],v;j;j=nxt[j])
			if(!~dis[v=to[j]])
			{
				dis[v]=dis[u]+1;
				pre[v]=u;
				st[++top]=v;
			}
	if(~dis[n] && dis[n]<=5)
	{
		printf("%d\n",dis[n]-1);
		top=0;
		for(int i=n;i!=1;i=pre[i])st[++top]=i;
		st[++top]=1;
		for(int i=top;i;--i)
			printf("%d ",st[i]);
		return 0;
	}
	p[1]=top;
	if(d[1]+1<p[1])
	{
		vis[1]=1;
		for(int i=head[1];i;i=nxt[i])vis[to[i]]=1;
		for(int i=head[1];i;i=nxt[i])	
			for(int j=head[to[i]];j;j=nxt[j])
				if(!vis[to[j]])
				{
					puts("4");
					printf("%d %d %d %d %d\n",1,to[i],to[j],1,n);
					return 0;
				}
	}
	else 
	{
		if(~dis[n] && dis[n]<=6)
		{
			printf("%d\n",dis[n]-1);
			top=0;
			for(int i=n;i!=1;i=pre[i])st[++top]=i;
			st[++top]=1;
			for(int i=top;i;--i)
				printf("%d ",st[i]);
			return 0;
		}
		vis[1]=1;
		for(int i=head[1],v;i;i=nxt[i])
			if(!vis[v=to[i]])
			{
				siz=0;
				dfs(v);
				for(int j=1;j<=siz;++j)
					if(d[v=st[j]]-1+1<siz)
					{
						memset(vis,0,sizeof vis);
						vis[v]=1;
						for(int k=head[v];k;k=nxt[k])vis[to[k]]=1;
						for(int k=head[v];k;k=nxt[k])	
							for(int l=head[to[k]];l;l=nxt[l])
								if(!vis[to[l]])
								{
									puts("5");
									printf("%d %d %d %d %d %d\n",1,v,to[k],to[l],v,n);
									return 0;
								}
					}
			}
	}
	puts("-1");
}