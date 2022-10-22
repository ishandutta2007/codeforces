#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 2001
int N,M,K,f[MAXN][MAXN];
int main()
{
	cin>>N>>M>>K;if(N<M)swap(N,M);For(i,1,N)f[1][i]=1;
	For(i,2,K+1)For(j,i*2-1,N)For(k,i*2-3,j-2)f[i][j]=(f[i][j]+1ll*(j-k-1)*f[i-1][k])%P;
	cout<<1ll*f[K+1][N]*f[K+1][M]%P<<'\n';return 0;
}