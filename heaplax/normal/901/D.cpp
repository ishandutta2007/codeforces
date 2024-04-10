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
#define N 100001
#define int long long
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
int top,cir[N],from[N],sum[N],sy[N];
int n,m,c[N],add[N],mark[N],ans[N];
int cnt=1,head[N],nxt[N+N],to[N+N];
void dfs(int u)
{
	for(int i=head[u],v;i;i=nxt[i])
		if(!~mark[v=to[i]])
		{
			mark[v]=mark[u]^1,from[v]=u,dfs(v);
			if(top)return;
		}
		else if(mark[v]==mark[u])
		{
			for(;u!=v;u=from[u])
				cir[++top]=u,sy[u]=top;
			cir[++top]=u;sy[u]=top;
			return;
		}
}
void solve(int u)
{
	mark[u]=1;
	for(int i=head[u],v;i;i=nxt[i])
		if(!mark[v=to[i]])
		{
			solve(v);
			sum[u]+=c[v]-sum[v];
			ans[i/2]+=c[v]-sum[v];
		}
}
void deal(int u,int val)
{
	mark[u]=1;
	for(int i=head[u],v;i;i=nxt[i])
		if(!mark[v=to[i]] && sy[v] && sy[v]-sy[u]==1)
		{
			ans[i/2]+=val;
			deal(v,-val);
		}
	if(sy[u]==1)
	{
		for(int i=head[u],v;i;i=nxt[i])
			if(sy[v=to[i]]==top)
				ans[i/2]+=val;
	}
}
main()
{
	re(n),re(m);
	for(int i=1;i<=n;++i)re(c[i]);
	for(int i=1,u,v;i<=m;++i)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	memset(mark,-1,sizeof mark);
	mark[1]=0;dfs(1);
	memset(mark,0,sizeof mark);
	if(top)
	{
		solve(cir[1]);
		memset(mark,0,sizeof mark);
		deal(cir[1],(c[cir[1]]-sum[cir[1]])/2);
	}
	else
	{
		solve(1);
		if(sum[1]!=c[1])
		{
			puts("NO");
			return 0;
		}
	}
	puts("YES");
	for(int i=1;i<=m;++i)
		printf("%lld\n",ans[i]);
}