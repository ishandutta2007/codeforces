#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u,f) for(int i=fst[u];i;i=nxt[i])if(to[i]!=f)
#define lowbit(x) x&-x
#define P 998244353
#define MAXN 150001
int N,M,inv,fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],fa[MAXN],dep[MAXN],siz[MAXN],son[MAXN],tot,dfn[MAXN],top[MAXN],c[MAXN],tg[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}void put(int x){if(x>=10)put(x/10);putchar(x%10+'0');}
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}
void dfs1(int u,int f){fa[u]=f,dep[u]=dep[f]+1;siz[u]=1;FOR(i,u,f)dfs1(to[i],u),siz[u]+=siz[to[i]],siz[to[i]]>siz[son[u]]?son[u]=to[i]:0;}
void dfs2(int u,int t){dfn[u]=++tot,top[u]=t;if(son[u])dfs2(son[u],t);FOR(i,u,fa[u])if(to[i]!=son[u])dfs2(to[i],to[i]);}
void upd(int x,int v){for(int i=x;i<=N;i+=lowbit(i))c[i]=(c[i]+v)%P;}void UPD(int l,int r,int v){if(l>r)return;upd(l,v),upd(r+1,P-v);}int ask(int x){int ans=0;for(int i=x;i;i-=lowbit(i))ans=(ans+c[i])%P;return ans;}
void Upd(int u,int v){UPD(1,N,1ll*v*N%P);UPD(1,dfn[u]-1,P-1ll*v*(N-siz[u])%P);UPD(dfn[u]+siz[u],N,P-1ll*v*(N-siz[u])%P);UPD(dfn[son[u]],dfn[son[u]]+siz[son[u]]-1,P-1ll*v*siz[son[u]]%P);tg[u]=(tg[u]+P-v)%P;}
int Ask(int u){int ans=ask(dfn[u]);while(u)ans=(ans+1ll*tg[fa[top[u]]]*siz[top[u]])%P,u=fa[top[u]];return 1ll*ans*inv%P;}
int main(){N=get(),M=get(),inv=pow(N,P-2);For(i,1,N-1)add(get(),get());dfs1(1,0);dfs2(1,1);For(i,1,M){int opt=get(),u=get();opt&1?Upd(u,get()),0:(put(Ask(u)),putchar('\n'),0);}return 0;}