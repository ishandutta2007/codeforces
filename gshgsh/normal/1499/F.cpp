#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 5001
int N,M,f[MAXN][MAXN],mx[MAXN],son[MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs0(int u,int f){for(auto v:E[u])if(v!=f)dfs0(v,u),mx[u]<mx[v]+1&&(mx[u]=mx[v]+1,son[u]=v);}
void dfs(int u,int p)
{
	if(!son[u])return void(f[u][0]=1);dfs(son[u],u);For(i,1,M)f[u][i]=f[son[u]][i-1];For(i,0,M)f[u][0]=(f[u][0]+f[son[u]][i])%P;
	for(auto v:E[u])if(v!=p&&v!=son[u])
	{
		dfs(v,u);int*g=new int[M+1]();
		For(i,0,M)For(j,0,mx[v])if(i+j+1<=M)g[max(i,j+1)]=(g[max(i,j+1)]+1ll*f[u][i]*f[v][j])%P;
		For(i,0,M)For(j,0,min(mx[v],M))g[i]=(g[i]+1ll*f[u][i]*f[v][j])%P;
		For(i,0,M)f[u][i]=g[i];delete g;
	}
}
int main()
{
	N=get(),M=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}
	dfs0(1,0);dfs(1,0);int ans=0;For(i,0,M)ans=(ans+f[1][i])%P;cout<<ans<<'\n';return 0;
}