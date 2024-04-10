#include<iostream>
#include<cstdio>
#include<vector>
#define MN 200000
#define N 262144
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int head[MN+5],cnt=0,n,m,dep[MN+5],f[MN+5],w[MN+5],W[MN+5],dn=0;
int dfn[MN+5],fa[MN+5],size[MN+5],mx[MN+5],T[N*2+5],top[MN+5];
struct edge{int to,next,w;}e[MN+5];
struct data{int l,r,x;};
vector<data> v[MN+5];
inline void ins(int f,int t){e[++cnt]=(edge){t,head[f]};head[f]=cnt;}

void Pre(int x)
{
	size[x]=1;mx[x]=0;
	for(int i=head[x];i;i=e[i].next)
	{
		Pre(e[i].to);
		size[x]+=size[e[i].to];
		if(size[e[i].to]>size[mx[x]]) mx[x]=e[i].to;
	}
}

void Dfs(int x,int tp)
{
	top[x]=tp;dfn[x]=++dn;	
	if(mx[x]) Dfs(mx[x],tp);
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=mx[x]) Dfs(e[i].to,e[i].to);
}

int lca(int x,int y)
{
	while(top[x]!=top[y])
	{
		if(dep[top[x]]<dep[top[y]]) swap(x,y);
		x=fa[top[x]];
	}
	return dep[x]<dep[y]?x:y;
}

void Renew(int x,int v){for(T[x+=N]=v;x>>=1;)T[x]=T[x<<1]+T[x<<1|1];}
int Query(int l,int r)
{
	int sum=0;
	for(l+=N-1,r+=N+1;l^r^1;l>>=1,r>>=1)
	{
		if(~l&1) sum+=T[l+1];
		if( r&1) sum+=T[r-1];
	}	
	return sum;
}

int Solve(int x,int y,int lca)
{
	int sum=0;
	if(x==lca||y==lca)
	{
		if(x==lca) swap(x,y);sum+=W[x];
		for(;top[x]!=top[lca];sum-=f[top[x]],x=fa[top[x]],sum+=W[x]) sum+=Query(dfn[top[x]],dfn[x]);
		sum+=Query(dfn[lca],dfn[x]);
	}
	else 
	{
		sum+=W[x]+W[y];
		for(;top[x]!=top[lca];sum-=f[top[x]],x=fa[top[x]],sum+=W[x]) sum+=Query(dfn[top[x]],dfn[x]);
		for(;top[y]!=top[lca];sum-=f[top[y]],y=fa[top[y]],sum+=W[y]) sum+=Query(dfn[top[y]],dfn[y]);
		if(dfn[x]>dfn[y]) swap(x,y);sum+=Query(dfn[x],dfn[y]);sum-=W[lca];
	}
	return sum;
}

void DP(int x)
{
	for(int i=head[x];i;i=e[i].next)
	{
		DP(e[i].to);
		if(e[i].to==mx[x]) W[x]=f[e[i].to];
		else w[x]+=f[e[i].to];
	}
	f[x]=W[x]+w[x];Renew(dfn[x],w[x]);
	for(int i=0;i<v[x].size();++i) f[x]=max(f[x],Solve(v[x][i].l,v[x][i].r,x)+v[x][i].x);
}

int main()
{	
	n=read();m=read();
	for(int i=2;i<=n;++i) ins(fa[i]=read(),i),dep[i]=dep[fa[i]]+1;
	Pre(1);Dfs(1,1);
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read(),w=read(),l=lca(x,y);
		v[l].push_back((data){x,y,w});	
	}
	DP(1);printf("%d\n",f[1]);
	return 0;
}