#include<algorithm>
#include<iostream>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 200001
int N,M,K,a[MAXN],fc[MAXN],inv[MAXN],ans;
int pow(int a,int b){int ans=1;while(b)b&1?ans=1ll*ans*a%P:0,a=1ll*a*a%P,b>>=1;return ans;}
int getans(int N,int M)
{
	fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	int ans=0;For(i,0,N/2)ans=(ans+1ll*fc[N]*inv[N-i*2]%P*inv[i]%P*inv[i]%P*pow(M-2,N-i*2)%P)%P;return 1ll*(pow(M,N)-ans+P)*inv[2]%P;
}
int main(){cin>>N>>K;For(i,1,N)cin>>a[i];M=unique(a+1,a+N+1)-a-1;if(a[M]==a[1])M--;cout<<1ll*pow(K,N-M)*getans(M,K)%P<<endl;return 0;}