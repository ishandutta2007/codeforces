#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 1000001
int N,u[MAXN],v[MAXN],a[MAXN],f[MAXN],g[MAXN][2],ans;vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int getf(int x){return f[x]==x?x:f[x]=getf(f[x]);}void mrg(int x,int y){x=getf(x),y=getf(y);f[x]=y;}
void dfs(int u,int f){for(auto v:E[u])if(v!=f)dfs(v,u),g[v][0]+1>g[u][0]?g[u][1]=g[u][0],g[u][0]=g[v][0]+1:g[u][1]=max(g[u][1],g[v][0]+1);ans=max(ans,g[u][0]+g[u][1]);}
int main()
{
	N=get();For(i,1,N)a[i]=get(),f[i]=i;For(i,1,N-1)u[i]=get(),v[i]=get(),a[u[i]]==a[v[i]]&&(mrg(u[i],v[i]),0);
	For(i,1,N-1)if(getf(u[i])!=getf(v[i]))E[getf(u[i])].push_back(getf(v[i])),E[getf(v[i])].push_back(getf(u[i]));
	dfs(getf(1),0);cout<<(ans+1>>1)<<'\n';return 0;
}