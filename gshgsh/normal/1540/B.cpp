#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define pb push_back
#define P 1000000007
#define I2 500000004
#define MAXN 201
int N,f[MAXN][MAXN],dep[MAXN],fa[MAXN][10],ans;vector<int>E[MAXN];
int get(){int x=0;char c=getchar();while(c<'0'||c>'9')c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
void dfs(int u,int f){dep[u]=dep[f]+1;fa[u][0]=f;For(i,1,9)fa[u][i]=fa[fa[u][i-1]][i-1];for(auto v:E[u])if(v!=f)dfs(v,u);}
int lca(int x,int y){if(dep[x]<dep[y])swap(x,y);FOR(i,9,0)if(dep[fa[x][i]]>=dep[y])x=fa[x][i];if(x==y)return x;FOR(i,9,0)if(fa[x][i]!=fa[y][i])x=fa[x][i],y=fa[y][i];return fa[x][0];}
int main()
{
	N=get();For(i,1,N-1){int u=get(),v=get();E[u].pb(v),E[v].pb(u);}
	For(i,1,N)f[i][0]=1;For(i,1,N)For(j,1,N)f[i][j]=1ll*(f[i-1][j]+f[i][j-1])*I2%P;
	For(i,1,N){dfs(i,0);For(j,1,N-1)For(k,j+1,N){int l=lca(j,k);ans=(ans+f[dep[j]-dep[l]][dep[k]-dep[l]])%P;}}
	cout<<1ll*ans*pow(N,P-2)%P<<endl;return 0;
}