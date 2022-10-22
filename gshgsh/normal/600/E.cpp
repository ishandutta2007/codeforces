#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define MAXN 100001
int N,a[MAXN],siz[MAXN],son[MAXN],mx[MAXN*4];ll sum[MAXN*4],ans[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),sum[k]=sum[ls(k)]+sum[rs(k)]:sum[k]=l;}
void dfs0(int u,int f){siz[u]=1;for(auto v:E[u])if(v!=f)dfs0(v,u),siz[u]+=siz[v],siz[v]>siz[son[u]]&&(son[u]=v);}
void upd(int k,int l,int r,int x,int v){l!=r?x<=R?upd(ls(k),l,R,x,v):upd(rs(k),L,r,x,v),mx[k]=max(mx[ls(k)],mx[rs(k)]),sum[k]=(mx[k]==mx[ls(k)])*sum[ls(k)]+(mx[k]==mx[rs(k)])*sum[rs(k)]:mx[k]+=v;}
void clear(int u,int f){upd(1,1,N,a[u],-1);for(auto v:E[u])if(v!=f)clear(v,u);}
void mrg(int u,int f){upd(1,1,N,a[u],1);for(auto v:E[u])if(v!=f)mrg(v,u);}
void dfs(int u,int f)
{
	for(auto v:E[u])if(v!=f&&v!=son[u])dfs(v,u),clear(v,u);if(son[u])dfs(son[u],u);
	for(auto v:E[u])if(v!=f&&v!=son[u])mrg(v,u);upd(1,1,N,a[u],1);ans[u]=sum[1];
}
int main()
{
	N=get();For(i,1,N)a[i]=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
	build(1,1,N);dfs0(1,0);dfs(1,0);For(i,1,N)cout<<ans[i]<<" \n"[i==N];return 0;
}