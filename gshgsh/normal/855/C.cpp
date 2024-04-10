#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 100001
int N,M,k,x,f[MAXN][11][3];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
void dfs(int u,int p)
{
	int g[11][3];f[u][0][0]=k-1,f[u][1][1]=1,f[u][0][2]=M-k;
	for(auto v:E[u])if(v!=p)
	{
		dfs(v,u);For(i,0,x)For(j,0,2)g[i][j]=f[u][i][j],f[u][i][j]=0;
		For(i,0,x)For(j,0,i)
		{
			f[u][i][0]=(f[u][i][0]+1ll*f[v][j][0]*g[i-j][0]+1ll*f[v][j][1]*g[i-j][0]+1ll*f[v][j][2]*g[i-j][0])%P;
			f[u][i][1]=(f[u][i][1]+1ll*f[v][j][0]*g[i-j][1])%P;
			f[u][i][2]=(f[u][i][2]+1ll*f[v][j][0]*g[i-j][2]+1ll*f[v][j][2]*g[i-j][2])%P;
		}
	}
}
int main()
{
	N=get(),M=get();For(i,1,N-1){int u=get(),v=get();E[u].push_back(v),E[v].push_back(u);}k=get(),x=get();
	dfs(1,0);int ans=0;For(i,0,x)For(j,0,2)ans=(ans+f[1][i][j])%P;cout<<ans<<'\n';return 0;
}