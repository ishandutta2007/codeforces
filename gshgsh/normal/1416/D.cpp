#include<algorithm>
#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define Pair pair<int,int>
#define Tair pair<int,Pair>
#define F first
#define S second
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 200001
#define MAXM 300001
#define MAXQ 500001
int N,M,Q,p[MAXN*2],q[MAXN],opt[MAXQ],x[MAXQ],t[MAXN*2],f[MAXN*2],fa[MAXN*2][20],ls[MAXN*2],rs[MAXN*2],tot,dfn[MAXN*2],siz[MAXN*2],id[MAXN*2],mx[MAXN*8];Tair E[MAXM];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}void dfs(int u){if(!u)return;dfn[u]=++tot,id[tot]=u;dfs(ls[u]),dfs(rs[u]),siz[u]=siz[ls[u]]+siz[rs[u]]+1;}
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),mx[k]=max(mx[ls(k)],mx[rs(k)]):mx[k]=p[id[l]];}
void upd(int k,int l,int r,int x,int v){l!=r?x<=R?upd(ls(k),l,R,x,v):upd(rs(k),L,r,x,v),mx[k]=max(mx[ls(k)],mx[rs(k)]):mx[k]=v;}
int ask(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?max(ask(ls(k),l,R,x,y),ask(rs(k),L,r,x,y)):mx[k]:0;}
int main()
{
	N=get(),M=get(),Q=get();For(i,1,N)f[i]=i,q[p[i]=get()]=i;For(i,1,M)E[i]={Q+1,{get(),get()}};For(i,1,Q)opt[i]=get(),x[i]=get(),opt[i]==2?E[x[i]].F=i:0;
	sort(E+1,E+M+1,greater<Tair>());int id=N;For(i,1,M){int x=getf(E[i].S.F),y=getf(E[i].S.S);if(x!=y)id++,f[id]=f[x]=f[y]=fa[x][0]=fa[y][0]=id,t[id]=E[i].F,ls[id]=x,rs[id]=y;}
	For(j,1,19)For(i,1,id)fa[i][j]=fa[fa[i][j-1]][j-1];FOR(i,id,1)if(!dfn[i])dfs(i);build(1,1,id);
	For(i,1,Q)if(opt[i]==1){int u=x[i];FOR(j,19,0)if(fa[u][j]&&t[fa[u][j]]>=i)u=fa[u][j];int ans=ask(1,1,id,dfn[u],dfn[u]+siz[u]-1);upd(1,1,id,dfn[q[ans]],0);cout<<ans<<endl;}return 0;
}