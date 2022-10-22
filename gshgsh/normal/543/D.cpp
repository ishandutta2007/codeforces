#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 200001
int N,p[MAXN];int f[MAXN],g[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
void dfs1(int u){f[u]=1;for(auto v:E[u])dfs1(v),f[u]=1ll*f[u]*(f[v]+1)%P;}
void dfs2(int u){int mul=1;for(auto v:E[u])g[v]=1ll*g[u]*mul%P,mul=1ll*mul*(f[v]+1)%P;mul=1;FOR(i,int(E[u].size())-1,0)g[E[u][i]]=(1ll*g[E[u][i]]*mul+1)%P,mul=1ll*mul*(f[E[u][i]]+1)%P,dfs2(E[u][i]);}
int main(){N=get();For(i,2,N)E[get()].push_back(i);dfs1(1);g[1]=1;dfs2(1);For(i,1,N)cout<<1ll*f[i]*g[i]%P<<" \n"[i==N];return 0;}