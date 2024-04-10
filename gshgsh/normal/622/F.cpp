#include<iostream>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 1000001
int N,K,y[MAXN],pre[MAXN],suf[MAXN],fc[MAXN],inv[MAXN],ans;
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int main()
{
	cin>>N>>K;fc[0]=1;For(i,1,K+2)fc[i]=1ll*fc[i-1]*i%P;inv[K+2]=pow(fc[K+2],P-2);FOR(i,K+1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	pre[0]=1;For(i,1,K+2)pre[i]=1ll*pre[i-1]*(N-i+P)%P;suf[K+3]=1;FOR(i,K+2,1)suf[i]=1ll*suf[i+1]*(N-i+P)%P;For(i,1,K+2)y[i]=(y[i-1]+pow(i,K))%P;
	For(i,1,K+2)ans=(ans+1ll*y[i]*pre[i-1]%P*suf[i+1]%P*pow(P-1,K+2-i)%P*inv[i-1]%P*inv[K+2-i])%P;cout<<ans<<endl;return 0;
}