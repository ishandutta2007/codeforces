#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,u) for(int i=fst[u];i;i=fst[u])
#define MAXN 1048576
int N,a[MAXN],b[MAXN],fst[MAXN],cnt,to[MAXN],x[MAXN],y[MAXN],nxt[MAXN],deg[MAXN],f[MAXN];vector<int>ans;bool vis[MAXN];int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void add(int u,int v,int a,int b){to[++cnt]=v,x[cnt]=a,y[cnt]=b,nxt[cnt]=fst[u],fst[u]=cnt;to[++cnt]=u,x[cnt]=b,y[cnt]=a,nxt[cnt]=fst[v],fst[v]=cnt;}
void upd(int M){For(i,0,M)fst[i]=deg[i]=0,f[i]=i;cnt=0;For(i,1,N)vis[i]=0,a[i]&=M,b[i]&=M,deg[a[i]]++,deg[b[i]]++,f[getf(a[i])]=getf(b[i]);}
int check(int M){int x=getf(a[1]&M);For(i,1,N)if((deg[a[i]]&1)||(deg[b[i]]&1)||getf(a[i])!=x||getf(b[i])!=x)return 0;return 1;}
void dfs(int u){FOR(i,u){fst[u]=nxt[i];if(!vis[x[i]+1>>1])vis[x[i]+1>>1]=1,dfs(to[i]),ans.push_back(y[i]),ans.push_back(x[i]);}}
void sol(int M){int cnt=0;while(M>=(1<<cnt))cnt++;cout<<cnt<<endl;For(i,1,N)add(a[i],b[i],i*2-1,i*2);dfs(a[1]);for(auto i:ans)cout<<i<<' ';}
int main(){N=get();For(i,1,N)a[i]=get(),b[i]=get();int i=(1<<20)-1;while(1){upd(i);if(check(i)){sol(i);return 0;}i>>=1;}return 0;}