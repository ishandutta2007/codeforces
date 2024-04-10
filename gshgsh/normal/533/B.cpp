#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define pb push_back
#define MAXN 200001
int N,a[MAXN];ll f[MAXN][2];vector<int>E[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
void dfs(int u){f[u][1]=-1e12;for(auto v:E[u]){dfs(v);ll g[2]={f[u][0],f[u][1]};f[u][0]=max(g[0]+f[v][0],g[1]+f[v][1]),f[u][1]=max(g[0]+f[v][1],g[1]+f[v][0]);}f[u][1]=max(f[u][1],f[u][0]+a[u]);}
int main(){N=get();get(),a[1]=get();For(i,2,N)E[get()].pb(i),a[i]=get();dfs(1);cout<<f[1][1]<<endl;return 0;}