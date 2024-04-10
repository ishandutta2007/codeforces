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
#define N 200004
#define M 400004
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
bool vis[N];
int n,m,now,a[N],b[N],c[N];
int cnt=1,head[N],nxt[M],to[M];
bool use[M];
void dfs(int u,int from=0)
{
	int w=0;
	vis[u]=1;
	for(int i=head[u],v;i;i=nxt[i])
		if(i != (from^1))
		{
			if(!vis[v=to[i]])dfs(v,i);
			if(!use[i])
			{
				use[i]=use[i^1]=1;
				if(!w)w=v;
				else
				{
					++cnt;
					a[cnt]=w;b[cnt]=u;c[cnt]=v;
					w=0;
				}
			}
		}
	if(w && u!=now)
	{
		++cnt;
		a[cnt]=w;b[cnt]=u;c[cnt]=to[from^1];
		use[from]=use[from^1]=1;
	}
}
int main()
{
	re(n),re(m);
	for(int i=1,u,v;i<=m;++i)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	cnt=0;
	for(now=1;now<=n;++now)
		if(!vis[now])
			dfs(now);
	printf("%d\n",cnt);
	for(int i=1;i<=cnt;++i)
		printf("%d %d %d\n",a[i],b[i],c[i]);
}