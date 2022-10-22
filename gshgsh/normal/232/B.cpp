#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define ll long long
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 101
#define MAXM 10001
int N,K,f[MAXN][MAXM],C[MAXN][MAXN],pw[MAXN][MAXN];ll M,cnt[MAXN];
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	cin>>N>>M>>K;For(i,1,M%N)cnt[i]=M/N+1;For(i,M%N+1,N)cnt[i]=M/N;For(i,0,N){C[i][0]=1;For(j,1,i)C[i][j]=(C[i-1][j-1]+C[i-1][j])%P;}For(i,0,N)For(j,1,N)pw[i][j]=pow(C[N][i],cnt[j]%(P-1));
	f[0][0]=1;For(i,1,N)For(j,max(K-(N-i)*N,0),min(K,N*i))For(k,0,min(N,j))f[i][j]=(f[i][j]+1ll*f[i-1][j-k]*pw[k][i])%P;cout<<f[N][K]<<'\n';return 0;
}