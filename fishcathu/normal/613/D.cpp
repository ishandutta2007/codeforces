#include<bits/stdc++.h>
typedef long long ll;
using namespace std;
const int N=1E5+1;
int read()
{
    int a=0;char b=1,c;
    do if((c=getchar())==45)b=-1;while(c<48||c>57);
    do a=(a<<3)+(a<<1)+(c&15);while((c=getchar())>47&&c<58);
    return a*b;
}
void write(int x)
{
    if(x<0)putchar('-'),x=-x;
    char a[10],s=0;
    do a[s++]=x%10|48;while(x/=10);
    do putchar(a[--s]);while(s);
}
int head[N],nex[N<<1],to[N<<1],fa[N],son[N],size[N],dfn[N],dep[N],top[N],low[N],p[N<<1],vc[N],a1[N],cnt;bool b[N],a2[N];
void add(int u,int v,int i){nex[i]=head[u],to[head[u]=i]=v;}
void dfs1(int x)
{
	size[x]=1;
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(t==fa[x])continue;
		fa[t]=x,dep[t]=dep[x]+1,dfs1(t),size[x]+=size[t];
		if(size[t]>size[son[x]])son[x]=t;	
	}
}
void dfs2(int x,int tp)
{
	dfn[x]=++cnt,top[x]=tp;
	if(son[x])dfs2(son[x],tp);
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		if(t==fa[x]||t==son[x])continue;
		dfs2(t,t);
	}
	low[x]=cnt;
}
bool cmp(int l,int r){return dfn[l]<dfn[r];}
int lca(int l,int r)
{
	while(top[l]!=top[r])dep[top[l]]<dep[top[r]]?r=fa[top[r]]:l=fa[top[l]];
	return dep[l]<dep[r]?l:r;
}
void dp(int x)
{
	int s=0;
	for(int i=head[x];i;i=nex[i])
	{
		int t=to[i];
		dp(t),s+=a2[t],a1[x]+=a1[t];
	}
	if(b[x])a2[x]=1,a1[x]+=s;
	else
	{
		if(s>1)++a1[x];
		else a2[x]=s;
	}
}
int main()
{
	int n=read();
	for(int i=1,u,v;i<n;++i)u=read(),v=read(),add(u,v,i<<1),add(v,u,i<<1|1);
	dfs1(1),dfs2(1,1),memset(head,0,sizeof head);
	for(int x=read();x--;)
	{
		int m=read(),k=0;
		for(int i=1;i<=m;++i)b[p[i]=read()]=1;
		for(int i=1;i<=m;++i)if(b[fa[p[i]]])k=1;
		sort(p+1,p+1+m,cmp);
		for(int i=1;i<m;++i)p[m+i]=lca(p[i],p[i+1]);
		sort(p+1,p+(m<<1),cmp),m=unique(p+1,p+(m<<1))-p-1,vc[0]=p[1];
		for(int i=2,j=0;i<=m;++i)
		{
			while(low[vc[j]]<dfn[p[i]])--j;
			add(vc[j],p[i],i),vc[++j]=p[i];
		}
		dp(p[1]),write(k?-1:a1[p[1]]),putchar('\n');
		for(int i=1;i<=m;++i)b[p[i]]=head[p[i]]=a1[p[i]]=a2[p[i]]=0;
	}
	return 0;
}