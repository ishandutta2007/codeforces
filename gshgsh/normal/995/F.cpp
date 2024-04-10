#include<algorithm>
#include<iostream>
#include<random>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 5001
int N,M,f[MAXN][MAXN];vector<int>E[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
void dfs(int u){For(i,1,N+5)f[u][i]=1;for(auto v:E[u]){dfs(v);For(j,1,N+5)f[u][j]=1ll*f[u][j]*f[v][j]%P;}For(i,2,N+5)f[u][i]=(f[u][i]+f[u][i-1])%P;}
int solve(int x){int ans=0;For(i,1,N+5){int mul=f[1][i],Div=1;For(j,1,N+5)if(i!=j)mul=1ll*mul*(x-j+P)%P,Div=1ll*Div*(i-j+P)%P;ans=(ans+1ll*mul*pow(Div,P-2))%P;}return ans;}
int main(){N=get(),M=get();For(i,2,N)E[get()].push_back(i);dfs(1);cout<<solve(M)<<'\n';}