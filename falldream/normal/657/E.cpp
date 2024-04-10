#include<algorithm>
#include<iostream>
#include<cstring>
#include<cstdio>
#include<map>
#define MN 300000
#define MD 18
using namespace std;
inline int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,m,Q,dfn[MN+5],low[MN+5],head[MN+5],cnt=1,R=0,belong[MN+5],dn=0,dep[MN+5],cc,num,a[MN*3+5];
int q[MN+5],top,s[MN+5],X[MN+5],Y[MN+5],fa[MD+1][MN+5],vis[MN+5],Dfn[MN+5],Belong[MN+5],b[MN+5],bnum=0;
bool cmp(int x,int y){return Dfn[x]<Dfn[y];}
struct edge{int to,next;}e[MN*4+5];
inline int Read(){return Belong[(read()+R-1)%n+1];}
inline void ins(int f,int t)
{
	e[++cnt]=(edge){t,head[f]};head[f]=cnt;	
	e[++cnt]=(edge){f,head[t]};head[t]=cnt;
}
void Tarjan(int x,int fa)
{
	dfn[x]=low[x]=++dn;q[++top]=x;b[++bnum]=x;
	for(int i=head[x];i;i=e[i].next) if(i!=fa) 
	{
		if(dfn[e[i].to]) low[x]=min(low[x],dfn[e[i].to]);
		else Tarjan(e[i].to,i^1),low[x]=min(low[x],low[e[i].to]);	
	}
	if(dfn[x]==low[x]) for(++cc,q[top+1]=0;q[top+1]!=x;--top) belong[q[top]]=cc;
}
void Pre(int x,int f)
{
	dfn[x]=++dn;fa[0][x]=f;
	for(int i=head[x];i;i=e[i].next)
		if(!dfn[e[i].to]) vis[e[i].to]=vis[x],dep[e[i].to]=dep[x]+1,Pre(e[i].to,x);
}
int lca(int x,int y)
{
	if(dep[x]<dep[y]) swap(x,y);
	for(int k=dep[x]-dep[y],j=0;k;k>>=1,++j) if(k&1) x=fa[j][x];
	if(x==y) return x;
	for(int i=MD;~i;--i) if(fa[i][x]!=fa[i][y]) x=fa[i][x],y=fa[i][y];
	return fa[0][x];	
}
void Build_Tree()
{
	for(int i=1,j;i<=num;i=j+1)
	{
		for(j=i;j<=num&&vis[a[j]]==vis[a[i]];++j);--j;
		top=0;
		for(int k=i;k<=j;++k)
		{ 
			if(top)
			{
				int x=lca(q[top],a[k]);
				while(top>1&&dep[q[top-1]]>=dep[x]) ins(q[top-1],q[top]),--top;
				if(dep[q[top]]>dep[x]) ins(x,q[top]),q[top]=x;
			}
			q[++top]=a[k];
		}	
		for(;top>1;--top) ins(q[top-1],q[top]); 
	}	
}
int main()
{
	n=read();m=read();Q=read();
	for(int i=1;i<=m;++i) X[i]=read(),Y[i]=read(),ins(X[i],Y[i]);
	for(int i=1;i<=n;++i) if(!dfn[i]) Tarjan(i,0); 
	cnt=1;dn=0;memset(head,0,sizeof(head));
	memset(dfn,0,sizeof(dfn));memset(low,0,sizeof(low));
	for(int i=1;i<=m;++i) if(belong[X[i]]!=belong[Y[i]]) ins(belong[X[i]],belong[Y[i]]);
	for(int i=1;i<=cc;++i) if(!dfn[i]) Pre(vis[i]=i,0);
	for(int i=1;i<=MD;++i) for(int j=1;j<=cc;++j) fa[i][j]=fa[i-1][fa[i-1][j]];
	memcpy(Dfn,dfn,sizeof(dfn));memset(dfn,0,sizeof(dfn));
	memcpy(Belong,belong,sizeof(belong));memset(belong,0,sizeof(belong));
	memset(head,0,sizeof(head));
	for(int q=1;q<=Q;++q)
	{
		int N=read(),M=read();dn=cc=num=bnum=0;cnt=1;
		for(int i=1;i<=N;++i) a[++num]=s[i]=Read();
		for(int i=1;i<=M;++i) a[++num]=X[i]=Read(),a[++num]=Y[i]=Read();
		sort(a+1,a+num+1,cmp);num=unique(a+1,a+num+1)-a-1; 
		Build_Tree();
		for(int i=1;i<=M;++i) ins(X[i],Y[i]);
		for(int i=1;i<=num;++i) if(!dfn[a[i]]) top=0,Tarjan(a[i],0);
		int flag=1;
		for(int i=2;i<=N;++i) if(belong[s[i]]!=belong[s[i-1]]) flag=0;
		if(flag) puts("YES"),R=(R+q)%n; else puts("NO");
		for(int i=1;i<=bnum;++i) dfn[b[i]]=low[b[i]]=head[b[i]]=belong[b[i]]=0;
	} 
	return 0;
}