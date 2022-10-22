#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define MAXN 501
int N,P,fc[MAXN],inv[MAXN],pw[MAXN],f[MAXN][MAXN],ans;
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}int C(int a,int b){return 1ll*fc[a]*inv[b]%P*inv[a-b]%P;}
int main()
{
	cin>>N>>P;fc[0]=pw[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P,pw[i]=pw[i-1]*2%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	f[0][0]=1;For(i,0,N)For(j,0,i)For(k,1,N-i)f[i+k+1][j+k]=(f[i+k+1][j+k]+1ll*f[i][j]*C(j+k,k)%P*pw[k-1])%P;For(i,1,N)ans=(ans+f[N+1][i])%P;cout<<ans<<endl;return 0;
}