#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u,f) for(int i=fst[u];i;i=nxt[i])if(to[i]!=f)
#define ls(x) x<<1
#define rs(x) x<<1|1
#define R (l+r>>1)
#define L (l+r>>1)+1
#define lowbit(x) x&-x
#define MAXN 400001
int N,M,fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],tot,dfn[MAXN],id[MAXN],siz[MAXN];ll a[MAXN],tr[MAXN*4],tg[MAXN*4];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}
void dfs(int u,int f){dfn[u]=++tot,id[tot]=u,siz[u]=1;FOR(i,u,f)dfs(to[i],u),siz[u]+=siz[to[i]];}
void build(int k,int l,int r){l!=r?build(ls(k),l,R),build(rs(k),L,r),tr[k]=tr[ls(k)]|tr[rs(k)]:tr[k]=a[id[l]];}
void pt(int k,ll v){tr[k]=v,tg[k]=v;}void dwn(int k){if(tg[k])pt(ls(k),tg[k]),pt(rs(k),tg[k]),tg[k]=0;}
void upd(int k,int l,int r,int x,int y,ll v){l<=y&&r>=x?l<x||r>y?dwn(k),upd(ls(k),l,R,x,y,v),upd(rs(k),L,r,x,y,v),tr[k]=tr[ls(k)]|tr[rs(k)]:(pt(k,v),0):0;}
ll ask(int k,int l,int r,int x,int y){return l<=y&&r>=x?l<x||r>y?dwn(k),ask(ls(k),l,R,x,y)|ask(rs(k),L,r,x,y):tr[k]:0;}
int getcnt(ll x){int cnt=0;while(x)x-=lowbit(x),cnt++;return cnt;}
int main(){N=get(),M=get();For(i,1,N)a[i]=1ll<<get()-1;For(i,1,N-1)add(get(),get());dfs(1,0);build(1,1,N);For(i,1,M){int opt=get(),x=get();opt==1?upd(1,1,N,dfn[x],dfn[x]+siz[x]-1,1ll<<get()-1),0:(put(getcnt(ask(1,1,N,dfn[x],dfn[x]+siz[x]-1))),putchar('\n'));}return 0;}