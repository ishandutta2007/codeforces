#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 61
int N,f[MAXN][6];
int main()
{
	cin>>N;For(i,0,5)f[1][i]=1;
	For(i,2,N)For(j,0,5)For(k,0,5)if(j!=k&&((j^k)!=1))For(l,0,5)if(j!=l&&((j^l)!=1))f[i][j]=(f[i][j]+1ll*f[i-1][k]*f[i-1][l])%P;
	int ans=0;For(i,0,5)ans=(ans+f[N][i])%P;cout<<ans<<'\n';return 0;
}