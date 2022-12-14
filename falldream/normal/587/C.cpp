#include<iostream>
#include<cstdio>
#include<vector> 
#define MD 17
#define MN 100000
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
struct edge{int to,next;}e[MN*2+5];
struct Tree{int l,r,x;}T[MN*25+5];
int n,m,Q,head[MN+5],cnt=0,rt[MN+5],fa[MD+1][MN+5],dep[MN+5];
vector<int> v[MN+5];
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
inline int newnode(int x){T[++cnt]=T[x];return cnt;}
void Modify(int x,int l,int r,int k)
{
	++T[x].x;
	if(l==r) return;
	else 
	{
		int mid=l+r>>1;
		if(k<=mid) Modify(T[x].l=newnode(T[x].l),l,mid,k);
		else Modify(T[x].r=newnode(T[x].r),mid+1,r,k);
	}
}

void Dfs(int x,int f)
{
	rt[x]=rt[fa[0][x]=f];
	for(int i=0;i<v[x].size();++i) Modify(rt[x]=newnode(rt[x]),1,m,v[x][i]); 
	for(int i=head[x];i;i=e[i].next)
		if(e[i].to!=f) dep[e[i].to]=dep[x]+1,Dfs(e[i].to,x);
}

int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int k=dep[x]-dep[y],j=0;k;k>>=1,++j) if(k&1) x=fa[j][x];
	if(x==y) return x;
	for(int i=MD;~i;--i) if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return fa[0][x];	
}
#define Sz(a) (T[T[(a)].l].x)
int main()
{
	n=read();m=read();Q=read();
	for(int i=1;i<n;++i) ins(read(),read());cnt=0;
	for(int i=1;i<=m;++i) v[read()].push_back(i);
	Dfs(1,0);
	for(int i=1;i<=MD;++i)for(int j=1;j<=n;++j)
		fa[i][j]=fa[i-1][fa[i-1][j]];
	for(int i=1;i<=Q;++i)
	{
		int X=read(),Y=read(),zz=lca(X,Y),ZZ=fa[0][zz],k=read(),x,y,z,Z;
		x=rt[X],y=rt[Y],Z=rt[ZZ],z=rt[zz];
		printf("%d",k=min(k,T[x].x+T[y].x-T[z].x-T[Z].x));
		for(int j=1;j<=k;++j)
		{
			int l=1,r=m,mid,K=j;
			x=rt[X],y=rt[Y],Z=rt[ZZ],z=rt[zz];
			while(l<r)
			{
				int sz=Sz(x)+Sz(y)-Sz(z)-Sz(Z),mid=l+r>>1;
				if(sz>=K) x=T[x].l,y=T[y].l,z=T[z].l,Z=T[Z].l,r=mid;
				else K-=sz,x=T[x].r,y=T[y].r,z=T[z].r,Z=T[Z].r,l=mid+1; 
			}
			printf(" %d",l);
		}
		puts("");
	}
	return 0;
}