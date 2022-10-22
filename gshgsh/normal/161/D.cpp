#include<iostream>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u,f) for(int i=fst[u];i;i=nxt[i])if(to[i]!=f)
#define MAXN 50001
#define MAXM 501
int N,K,fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],f[MAXN][MAXM];ll ans;
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;}
void dfs(int u,int fa){FOR(i,u,fa)dfs(to[i],u);f[u][0]=1;FOR(i,u,fa)For(j,1,K)f[u][j]+=f[to[i]][j-1];ans+=f[u][K];FOR(i,u,fa)For(j,1,K)ans+=f[to[i]][j-1]*(f[u][K-j]-(j!=K?f[to[i]][K-j-1]:0));}
int main(){cin>>N>>K;For(i,1,N-1){int u,v;cin>>u>>v;add(u,v);}dfs(1,0);cout<<ans/2<<endl;return 0;}