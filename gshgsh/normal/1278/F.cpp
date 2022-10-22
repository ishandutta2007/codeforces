#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 5001
int N,M,K,f[MAXN][MAXN],ans;
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int calc(int N,int M){int ans=1;For(i,N-M+1,N)ans=1ll*ans*i%P;return ans;}
int main()
{
	cin>>N>>M>>K;f[0][0]=1;For(i,1,K)For(j,1,i)f[i][j]=(f[i-1][j-1]+1ll*j*f[i-1][j])%P;
	For(i,0,min(N,K))ans=(ans+1ll*f[K][i]*calc(N,i)%P*pow(M,N-i))%P;cout<<1ll*ans*pow(pow(M,N),P-2)%P<<'\n';return 0;
}