#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 1000000007
#define MAXN 1000001
int T,N,M,K,fc[MAXN],inv[MAXN],i2[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int C(int a,int b){return 1ll*fc[a]*inv[b]%P*inv[a-b]%P;}
int main()
{
	T=get();
	while(T--)
	{
		N=get(),M=get(),K=get();if(M==N){cout<<1ll*N*K%P<<'\n';continue;}
		fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
		i2[0]=1;For(i,1,N)i2[i]=1ll*i2[i-1]*inv[2]%P;
		int ans=0;For(i,0,M)ans=(ans+1ll*i*K%P*C(N-1-i,M-i)%P*i2[N-i])%P;cout<<ans<<'\n';
	}
	return 0;
}