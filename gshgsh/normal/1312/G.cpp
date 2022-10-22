#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define MAXN 1200001
int N,fa[MAXN],son[MAXN][26],tot,dfn[MAXN],rk[MAXN],f[MAXN],K,id[MAXN];bool vis[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getc(){char c=getchar();while(c<'a'||c>'z')c=getchar();return c-'a';}
void dfs(int u){dfn[u]=++tot;rk[tot]=rk[tot-1]+vis[u];For(i,0,25)if(son[u][i])dfs(son[u][i]);}
void dfs1(int u,int mn){For(j,0,25)if(son[u][j]){int v=son[u][j];f[v]=f[u]+1;if(vis[v])f[v]=min(f[v],mn+rk[dfn[v]]);dfs1(v,min(mn,f[v]-rk[dfn[v]-1]));}}
int main(){N=get();For(i,1,N)fa[i]=get(),son[fa[i]][getc()]=i;K=get();For(i,1,K)vis[id[i]=get()]=1;dfs(0);dfs1(0,0);For(i,1,K)cout<<f[id[i]]<<" \n"[i==K];}