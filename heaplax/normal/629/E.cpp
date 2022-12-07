#include<map>
#include<set>
#include<cmath>
#include<cstdio>
#include<cstdlib>
#include<cstring>
#include<iostream>
#include<algorithm>
#define N 222222
#define LL long long
char temp[1<<24],*S=temp,*T=temp;
char get()
{
	return getchar();
	if(S == T)T+=fread(temp,1,1<<24,stdin);
	return *S++;
}
char ch;void re(LL& x)
{
	while(ch=get(),ch<'!');x=ch-48;
	while(ch=get(),ch>'!')x=x*10+ch-48;
}
using namespace std;
LL n,m,fa[N],zl[N],dep[N],far[N],siz[N],son[N],all[N];
LL cnt,to[N],head[N],nxt[N];
void add_edge(LL u,LL v)
{
	nxt[++cnt]=head[u];head[u]=cnt;to[cnt]=v;
}
void dfs1(LL u)
{
	siz[u]=1;
	for(LL i=head[u];i;i=nxt[i])
	{
		LL v=to[i];
		if(v != fa[u])
		{
			fa[v]=u;
			dep[v]=dep[u]+1;
			dfs1(v);
			siz[u]+=siz[v];
			if(siz[son[u]] < siz[v])
				son[u]=v;
			far[u]+=far[v]+siz[v];
		}
	}
}
void dfs2(LL u,LL p)
{
	zl[u]=p;
	if(!son[u])return;
	all[son[u]]=all[u]-siz[son[u]]+(n-siz[son[u]]);
	dfs2(son[u],p);
	for(LL i=head[u];i;i=nxt[i])
	{
		LL v=to[i];
		if(v!=son[u] && v!=fa[u])
		{
			all[v]=all[u]-siz[v]+(n-siz[v]);
			dfs2(v,v);
		}
	}
}
LL lca(LL u,LL v)
{
	while(zl[u] != zl[v])
	{
		if(dep[zl[u]] < dep[zl[v]])swap(u,v);
		u=fa[zl[u]];
	}
	if(dep[u] < dep[v])return u;
	else return v;
}
LL lca2(LL u,LL v)
{
	while(1)
	{
		if(dep[fa[zl[u]]] > dep[v])
			u=fa[zl[u]];
		else 
		if(fa[zl[u]] == v)
			return zl[u];
		else return son[v];		
	}
}
int main()
{
	//freopen("happy.in","r",stdin);
	//freopen("happy.out","w",stdout);
	re(n),re(m);
	for(LL i=1,u,v;i<n;++i)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	dfs1(1);
	all[1]=far[1];
	dfs2(1,1);
	for(LL u,v;m--;)
	{
		re(u),re(v);
		if(dep[u]<dep[v])swap(u,v);
		LL t=lca(u,v);
		if(t == v)
		{
			LL dis=dep[u]-dep[v];
			LL f=lca2(u,v);
			LL sv=n-siz[f],fv=all[v]-far[f]-siz[f];
			double ans=siz[u]*fv+sv*far[u];
			printf("%.7lf\n",ans/(sv*siz[u])+dis+1);
		}
		else
		{
			double ans=siz[u]*far[v]+siz[v]*far[u];
			printf("%.7lf\n",ans/(siz[v]*siz[u])+dep[u]+dep[v]-2*dep[t]+1);
		}
	}
}