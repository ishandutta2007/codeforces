#include<bits/stdc++.h>
#define MN 200000
#define MD 18
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
vector<int> v[MN+5],V[MN+5];
int n,m,Q,fa[MD+1][MN+5],f[MD+1][MN+5],dep[MN+5],rt[MN+5],dfn[MN+5],dn,p[MN+5],nr[MN+5],cnt;
struct Tree{int l,r,x;}T[12000005];
inline int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int k=dep[x]-dep[y],j=0;k;k>>=1,++j)
		if(k&1) x=fa[j][x];
	if(x==y)return x;
	for(int i=MD;~i;--i) if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return fa[0][x];	
}
void dfs(int x)
{
	dfn[x]=++dn;p[dn]=x;
	for(int i=0;i<v[x].size();++i) dfs(v[x][i]);
	nr[x]=dn;
}
int Query(int x,int l,int r,int lt=1,int rt=n)
{
	if(!x||(l==lt&&r==rt))return T[x].x;	
	int mid=lt+rt>>1;
	if(r<=mid) return Query(T[x].l,l,r,lt,mid);
	else if(l>mid) return Query(T[x].r,l,r,mid+1,rt);
	else return Query(T[x].l,l,mid,lt,mid)+Query(T[x].r,mid+1,r,mid+1,rt);
}
inline int newnode(int x){T[++cnt]=T[x];return cnt;}
void Modify(int x,int l,int r,int k)
{
	if(++T[x].x,l==r) return;
	int mid=l+r>>1;
	if(k<=mid) Modify(T[x].l=newnode(T[x].l),l,mid,k);
	else Modify(T[x].r=newnode(T[x].r),mid+1,r,k);
}
inline int Min(int x,int y){return dep[x]<dep[y]?x:y;}
int main()
{
	n=read();
	for(int i=2;i<=n;++i) fa[0][i]=read(),dep[i]=dep[fa[0][i]]+1,v[fa[0][i]].push_back(i);
	for(int i=1;i<=n;++i) f[0][i]=i;dfs(1);
	for(int i=1;i<=MD;++i) for(int j=1;j<=n;++j) fa[i][j]=fa[i-1][fa[i-1][j]];
	m=read();
	for(int i=1;i<=m;++i)
	{
		int x=read(),y=read(),z=lca(x,y);
		f[0][x]=Min(f[0][x],z);
		f[0][y]=Min(f[0][y],z);
		if(dfn[x]>dfn[y]) swap(x,y);
		V[y].push_back(x);
	}
	for(int i=1;i<=n;++i)
	{
		rt[i]=newnode(rt[i-1]);
		for(int j=0;j<V[p[i]].size();++j)
			Modify(rt[i],1,n,dfn[V[p[i]][j]]);	
	}
	for(int i=n;i;--i) f[0][fa[0][i]]=Min(f[0][fa[0][i]],f[0][i]);
	for(int i=1;i<=MD;++i) for(int j=1;j<=n;++j) f[i][j]=f[i-1][f[i-1][j]];
	Q=read();
	for(int i=1;i<=Q;++i)
	{
		int x=read(),y=read(),z=lca(x,y),ans=0;
		for(int j=MD;~j;--j)
		{
			if(dep[f[j][x]]>dep[z]) ans+=1<<j,x=f[j][x];
			if(dep[f[j][y]]>dep[z]) ans+=1<<j,y=f[j][y];
		}
		if(ans>n) {puts("-1");continue;}
		if(x==z||y==z) {printf("%d\n",ans+1);continue;}
		if(dfn[x]>dfn[y]) swap(x,y); 
		printf("%d\n",ans+2-bool(Query(rt[nr[y]],dfn[x],nr[x])-Query(rt[dfn[y]-1],dfn[x],nr[x])));
	}
	return 0;
}