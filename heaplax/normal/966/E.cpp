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
#define B 333
#define mp(a,b) make_pair(a,b)
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
vector<int> s[N],ss[N];
bool mark[N],go[N];
int top,st[N];
int ans,sum[N],ff[N],tag[N],now[N];
int n,m,dfn[N],fa[N],t[N],dep[N],q[N],p[N][18],e[N];
int cnt,head[N],nxt[N],to[N];
bool cmp(int a,int b)
{
	return dfn[a]<dfn[b];
}
void dfs(int u)
{
	dfn[u]=++cnt;
	for(int i=1;(1<<i)<=dep[u];++i)
		p[u][i]=p[p[u][i-1]][i-1];
	for(int i=head[u],v;i;i=nxt[i])
	{
		dep[v=to[i]]=dep[u]+1;
		p[v][0]=u;
		dfs(v);
	}
}
int lca(int u,int v)
{
	if(dep[u]<dep[v])swap(u,v);
	for(int i=17;i>=0;--i)
		if(dep[u]-(1<<i)>=dep[v])
			u=p[u][i];
	if(u==v)return u;
	for(int i=17;i>=0;--i)
		if(p[u][i] != p[v][i])
			u=p[u][i],v=p[v][i];
	return p[u][0];
}
int calc(int u)
{
	return !go[u] && t[u]<sum[u];
}
void pre(int u)
{
	go[u]=sum[u];
	for(int i=head[u],v;i;i=nxt[i])
	{
		pre(v=to[i]);
		sum[u]+=sum[v];
	}
	ans+=calc(u);
}
void add(int u)
{
	ans-=calc(u);
	++sum[u];
	ans+=calc(u);
	++tag[u];
	if(now[u]<s[u].size() && s[u][now[u]]<tag[u])
		ans+=ss[u][now[u]++];
	if(u==1)return;
	add(ff[u]);
}
void dec(int u)
{
	ans-=calc(u);
	--sum[u];
	ans+=calc(u);
	--tag[u];
	if(now[u] && s[u][now[u]-1]>=tag[u])
		ans-=ss[u][--now[u]];
	if(u==1)return;
	dec(ff[u]);
}
int main()
{
	re(n),re(m);
	for(int i=2;i<=n;++i)
	{
		re(fa[i]);
		add_edge(fa[i],i);
	}
	for(int i=1;i<=n;++i)re(t[i]);
	cnt=0;
	dfs(1);
	cnt=0;
	for(int i=1;i<=m;++i)
	{
		re(q[i]);
		e[++cnt]=abs(q[i]);
		if(i==m||cnt==B)
		{
			ans=0;
			memset(sum,0,sizeof sum);
			memset(mark,0,sizeof mark);
			memset(tag,0,sizeof tag);
			sort(e+1,e+cnt+1,cmp);
			for(int j=1;j<=n;++j)s[j].clear(),ss[j].clear();
			for(int j=1;j<=cnt;++j)
				mark[e[j]]=1;
			for(int j=1;j<cnt;++j)
				mark[lca(e[j],e[j+1])]=1;
			mark[1]=1;
			for(int j=1;j<=i-cnt;++j)
				if(q[j]>0)++sum[q[j]];
				else --sum[-q[j]];
			pre(1);
			// cerr<<ans<<endl;
			for(int j=1;j<=n;++j)
				if(mark[j])
				{
					ff[j]=fa[j];
					top=0;
					while(ff[j] && !mark[ff[j]])
					{
						if(!go[ff[j]])st[++top]=t[ff[j]]-sum[ff[j]];
						ff[j]=fa[ff[j]];
					}
					sort(st+1,st+top+1);
					for(int k=1;k<=top;++k)
						if(k==1 || st[k]!=st[k-1])
							s[j].push_back(st[k]),
							ss[j].push_back(1);
						else
							++ss[j][ss[j].size()-1];
					now[j]=s[j].size();
					while(now[j] && s[j][now[j]-1]>=0)--now[j];
				}
			for(int j=i-cnt+1;j<=i;++j)
			{
				if(q[j]>0)ans-=calc(q[j]),go[q[j]]=1,add(q[j]);
				else dec(-q[j]),go[-q[j]]=0,ans+=calc(-q[j]);
				printf("%d ",ans);
			}
			cnt=0;
		}
	}
}
/*
5 3
1 2 3 4
4 0 0 1 0
1 5 2
*/