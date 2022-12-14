#include<iostream>
#include<cstring>
#include<cstdio>
#define MN 200000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,Q,f[MN+5],t[MN+5],head[MN+5],dfn[MN+5],low[MN+5];
int s[MN+5],bel[MN+5],dn,cnt=1,cut[MN+5],tot;
struct edge{int to,next;}e[MN*2+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;	
}

void Tarjan(int x,int fa)
{
	dfn[x]=low[x]=++dn;
	for(int i=head[x];i;i=e[i].next)
		if(i!=fa) 
		{
			if(!dfn[e[i].to]) 
			{
				Tarjan(e[i].to,i^1);
				low[x]=min(low[x],low[e[i].to]);
				if(low[e[i].to]>dfn[x]) cut[i>>1]=1;
			}
			else low[x]=min(low[x],dfn[e[i].to]);	
		}
}

void Dfs(int x)
{
	bel[x]=tot;
	for(int i=head[x];i;i=e[i].next)
		if(!cut[i>>1]&&!bel[e[i].to]) Dfs(e[i].to);
}
int mx[MN+5],size[MN+5],top[MN+5],dep[MN+5],fa[MN+5];
void Pre(int x,int f)
{
	size[x]=1;mx[x]=0;fa[x]=f;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=f) 
		{
			dep[e[i].to]=dep[x]+1;Pre(e[i].to,x);
			size[x]+=size[e[i].to];
			if(size[e[i].to]>size[mx[x]]) mx[x]=e[i].to;	
		}
}
void dfs(int x,int tp)
{
	top[x]=tp;dfn[x]=++dn;
	if(mx[x]) dfs(mx[x],tp);
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=fa[x]&&e[i].to!=mx[x]) dfs(e[i].to,e[i].to);
}
struct Tree{int l,r,num[2],tag,val;}T[MN*4+5];
void Mark(int x,int v)
{
	T[x].tag=1;T[x].val=v;
	T[x].num[v]=T[x].r-T[x].l+1;	
}
void pushdown(int x){Mark(x<<1,T[x].val);Mark(x<<1|1,T[x].val);T[x].tag=0;}
void Build(int x,int l,int r)
{
	if((T[x].l=l)==(T[x].r=r))return;	
	int mid=l+r>>1;
	Build(x<<1,l,mid);Build(x<<1|1,mid+1,r);	
}
int Query(int x,int l,int r,int v)
{
//	cout<<x<<" "<<l<<" "<<r<<" "<<v<<endl;
	if(T[x].l==l&&T[x].r==r) return T[x].num[v];
	int mid=T[x].l+T[x].r>>1;if(T[x].tag) pushdown(x);
	if(r<=mid) return Query(x<<1,l,r,v);
	else if(l>mid) return Query(x<<1|1,l,r,v);
	else return Query(x<<1,l,mid,v)+Query(x<<1|1,mid+1,r,v); 
}
void Modify(int x,int l,int r,int v)
{
	if(T[x].l==l&&T[x].r==r){Mark(x,v);return;}
	int mid=T[x].l+T[x].r>>1;if(T[x].tag) pushdown(x);
	if(r<=mid) Modify(x<<1,l,r,v);
	else if(l>mid) Modify(x<<1|1,l,r,v);
	else Modify(x<<1,l,mid,v),Modify(x<<1|1,mid+1,r,v);
	T[x].num[0]=T[x<<1].num[0]+T[x<<1|1].num[0];
	T[x].num[1]=T[x<<1].num[1]+T[x<<1|1].num[1]; 
}
inline int gf(int x){return s[x]?s[x]=gf(s[x]):x;}
int main()
{
	n=read();m=read();Q=read(); 
	for(int i=1;i<=m;++i) ins(f[i]=read(),t[i]=read());
	for(int i=1;i<=n;++i) if(!dfn[i]) Tarjan(i,0);
	for(int i=1;i<=n;++i) if(!bel[i]) ++tot,Dfs(i);
	cnt=dn=0;memset(head,0,sizeof(head));memset(dfn,0,sizeof(dfn));
	for(int i=1;i<=m;++i) if(gf(bel[f[i]])!=gf(bel[t[i]])) ins(bel[f[i]],bel[t[i]]),s[gf(bel[f[i]])]=gf(bel[t[i]]);
	for(int i=1;i<=n;++i) if(!dep[i]) dep[i]=1,Pre(i,0),dfs(i,i);
	Build(1,1,tot);
	for(int i=1;i<=Q;++i)
	{
		int x=read(),y=read();
		if(gf(bel[x])!=gf(bel[y])) return 0*puts("No");
		x=bel[x];y=bel[y];
		while(top[x]!=top[y])		
		{
			if(dep[top[x]]>dep[top[y]])	
			{
				if(Query(1,dfn[top[x]],dfn[x],1)) return 0*puts("No");
				else Modify(1,dfn[top[x]],dfn[x],0);
				x=fa[top[x]];
			}
			else 
			{
				if(Query(1,dfn[top[y]],dfn[y],0)) return 0*puts("No");
				else Modify(1,dfn[top[y]],dfn[y],1);
				y=fa[top[y]];
			}
		//	cout<<x<<" "<<y<<endl;
		}	
	//	cout<<x<<" "<<y<<" ok"<<endl;
		if(x==y) continue;
		if(dfn[x]<dfn[y])
		{
			if(Query(1,dfn[x]+1,dfn[y],0)) return 0*puts("No");
			else Modify(1,dfn[x]+1,dfn[y],1);
		}
		else 
		{
			if(Query(1,dfn[y]+1,dfn[x],1)) return 0*puts("No");	
			else Modify(1,dfn[y]+1,dfn[x],0);
		}
	}
	puts("Yes");
	return 0;
}