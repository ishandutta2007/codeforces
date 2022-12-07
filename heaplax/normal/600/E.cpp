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
LL sum,ans[N];
int n,mx,skip,ctt[N],c[N],siz[N],son[N];
int cnt,head[N],nxt[N+N],to[N+N];
void pfs(int u,int fa=0)
{
	siz[u]=1;
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i]) != fa)
		{
			pfs(v,u);
			siz[u]+=siz[v];
			if(siz[son[u]]<siz[v])son[u]=v;
		}
}
void edt(int u,int fa,bool type)
{
	if(!type)
	{
		++ctt[c[u]];
		if(ctt[c[u]]>mx)
			mx=ctt[c[u]],sum=c[u];
		else if(ctt[c[u]]==mx)
			sum+=c[u];
	}
	else --ctt[c[u]];
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i])!=fa && v!=skip)	
			edt(v,u,type);
}
void dfs(int u,int fa=0,bool keep=0)
{
	for(int i=head[u],v;i;i=nxt[i])
		if((v=to[i])!=fa && v!=son[u])
			dfs(v,u);
	if(son[u])
		dfs(son[u],u,1),skip=son[u];
	edt(u,fa,0);
	ans[u]=sum;
	skip=0;
	if(!keep)
		edt(u,fa,1),mx=sum=0;
}
int main()
{
	re(n);
	for(int i=1;i<=n;++i)re(c[i]);
	for(int i=1,u,v;i<n;++i)
	{
		re(u),re(v);
		add_edge(u,v);
		add_edge(v,u);
	}
	pfs(1);	
	dfs(1);
	for(int i=1;i<=n;++i)
		printf("%lld ",ans[i]);
}