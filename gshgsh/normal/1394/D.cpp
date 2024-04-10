#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 200001
int N,a[MAXN],b[MAXN];ll f[MAXN][2];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int p)
{
	vector<ll>val;for(auto v:E[u])if(v!=p){dfs(v,u);if(b[u]==b[v])val.push_back(f[v][0]-f[v][1]);}sort(val.begin(),val.end());
	int x=0,y=0;ll sum=0;for(auto v:E[u])if(v!=p)b[v]<=b[u]?x++,sum+=f[v][1]:(y++,sum+=f[v][0]);
	f[u][0]=sum+1ll*max(x+(u!=1),y)*a[u];f[u][1]=sum+1ll*max(x,y+(u!=1))*a[u];for(auto i:val)x--,y++,sum+=i,f[u][0]=min(f[u][0],sum+1ll*max(x+(u!=1),y)*a[u]),f[u][1]=min(f[u][1],sum+1ll*max(x,y+(u!=1))*a[u]);
}
int main()
{
	N=get();For(i,1,N)a[i]=get();For(i,1,N)b[i]=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
	dfs(1,0);cout<<min(f[1][0],f[1][1])<<'\n';
}