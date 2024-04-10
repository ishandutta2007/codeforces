#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOr(i,l,r) for(int i=l;i>=r;i--)
#define FOR(i,u,f) for(int i=fst[u];i;i=nxt[i])if(to[i]!=f)
#define MAXN 400001
int N,M,K,Q,tot,fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],f[MAXN],dep[MAXN],fa[MAXN][20],dis[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
void dfs(int u,int f){dep[u]=dep[f]+1;fa[u][0]=f;For(i,1,19)fa[u][i]=fa[fa[u][i-1]][i-1];FOR(i,u,f)dfs(to[i],u);}
int lca(int x,int y){if(dep[x]<dep[y])swap(x,y);FOr(i,19,0)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];if(x==y)return x;FOr(i,19,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];return fa[x][0];}
int go(int x,int k){FOr(i,19,0)if((1<<i)<=k)x=fa[x][i],k-=1<<i;return x;}
bool check(int x,int y){int z=lca(x,y),l=dep[x]+dep[y]-dep[z]*2;if(l<=M*2)return 1;int X=dep[x]-dep[z]>=M?go(x,M):go(y,l-M),Y=dep[y]-dep[z]>=M?go(y,M):go(x,l-M);return getf(X)==getf(Y);}
int main()
{
	N=get(),M=get(),K=get(),tot=N;For(i,1,N-1)add(get(),++tot),add(tot,get());dfs(1,0);memset(dis,-1,sizeof(dis));For(i,1,tot)f[i]=i;queue<int>q;For(i,1,K){int x=get();q.push(x),dis[x]=0;}
	while(!q.empty()){int u=q.front();q.pop();if(dis[u]==M)break;FOR(i,u,0){f[getf(u)]=getf(to[i]);if(dis[to[i]]==-1)dis[to[i]]=dis[u]+1,q.push(to[i]);}}
	Q=get();For(i,1,Q)cout<<(check(get(),get())?"YES\n":"NO\n");return 0;
}