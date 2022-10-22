#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define P 998244353
#define MAXN 2001
int N,K,l,f[MAXN*2][MAXN][2];int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	cin>>N>>K>>l;f[0][0][0]=1;For(i,1,N*2+1)For(j,0,min(i,N))For(k,0,1){if(j)f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k])%P;if(j+1<=min(i-1,N))f[i][j][k]=(f[i][j][k]+1ll*(j+1)*f[i-1][j+1][k])%P;if(k&&j>=K)f[i][j][k]=(f[i][j][k]+f[i-1][j][0])%P;}
	int ans=1ll*l*f[N*2+1][0][1]%P*pow(2,N)%P;For(i,N+1,N*2+1)ans=1ll*ans*pow(i,P-2)%P;cout<<ans<<endl;return 0;
}