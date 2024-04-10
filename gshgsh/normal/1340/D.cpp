#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u,f) for(int i=fst[u];i;i=nxt[i])if(to[i]!=f)
#define Pair pair<int,int>
#define F first
#define S second
#define MAXN 100001
int N,M,fst[MAXN],cnt,to[MAXN*2],nxt[MAXN*2],deg[MAXN];vector<Pair>ans;
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v){to[++cnt]=v,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,nxt[cnt]=fst[v],fst[v]=cnt;M=max(M,max(++deg[u],++deg[v]));}
void opt(int u,int t){ans.push_back({u,t});}
void dfs(int u,int f,int t){int now=t;opt(u,t);FOR(i,u,f){if(now==M)opt(u,now-=deg[u]);dfs(to[i],u,++now);opt(u,now);}if(u!=1&&now!=t-1)opt(u,t-1);}
int main(){N=get();For(i,1,N-1)add(get(),get());dfs(1,0,0);cout<<ans.size()<<endl;for(auto i:ans)cout<<i.F<<' '<<i.S<<endl;return 0;}