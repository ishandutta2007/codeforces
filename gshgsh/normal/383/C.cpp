#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u,f) for(int i=fst[u];i;i=nxt[i])if(to[i]!=f)
#define lowbit(x) x&-x
#define MAXN 200001
int N,M,a[MAXN],fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],tot,dfn[MAXN],siz[MAXN],id[MAXN],dep[MAXN],c[MAXN][2];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void put(int x){if(x<0)return putchar('-'),put(-x);if(x>=10)put(x/10);putchar(x%10+'0');}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}
void dfs(int u,int f){dep[u]=dep[f]+1,dfn[u]=++tot,id[tot]=u,siz[u]=1;FOR(i,u,f)dfs(to[i],u),siz[u]+=siz[to[i]];}
void upd(int x,int t,int v){for(int i=x;i<=N;i+=lowbit(i))c[i][t]+=v;}
int ask(int x,int t){int ans=0;for(int i=x;i;i-=lowbit(i))ans+=c[i][t];return ans;}
void Upd(int u,int v){upd(dfn[u],dep[u]&1,v),upd(dfn[u]+siz[u],dep[u]&1,-v),upd(dfn[u],dep[u]+1&1,-v),upd(dfn[u]+siz[u],dep[u]+1&1,v);}
int main(){N=get(),M=get();For(i,1,N)a[i]=get();For(i,1,N-1)add(get(),get());dfs(1,0);For(i,1,N)For(j,0,1)upd(i,j,a[id[i]]-a[id[i-1]]);For(i,1,M){int opt=get(),u=get();opt==1?Upd(u,get()),0:(put(ask(dfn[u],dep[u]&1)),putchar('\n'),0);}return 0;}