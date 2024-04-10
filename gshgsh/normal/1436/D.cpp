#include<iostream>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=nxt[i])
#define MAXN 200001
int N,fst[MAXN],cnt,to[MAXN],nxt[MAXN],a[MAXN],siz[MAXN];ll f[MAXN],sum[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;}
void dfs(int u){if(siz[u])f[u]=a[u];sum[u]=a[u];FOR(i,u)dfs(to[i]),siz[u]+=siz[to[i]],f[u]=max(f[u],f[to[i]]),sum[u]+=sum[to[i]];f[u]=max(f[u],(sum[u]+siz[u]-1)/siz[u]);}
int main(){N=get();For(i,2,N)add(get(),i);For(i,1,N)a[i]=get(),siz[i]=!fst[i];dfs(1);cout<<f[1]<<endl;return 0;}