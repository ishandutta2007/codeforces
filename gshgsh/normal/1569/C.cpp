#include<algorithm>
#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
#define For(i,l,r) for(int i=l;i<=r;i++)
#define FOR(i,l,r) for(int i=l;i>=r;i--)
#define P 998244353
#define MAXN 200001
int T,N,a[MAXN],fc[MAXN],inv[MAXN];
int get(){int x=0,f=1;char c=getchar();while(c<'0'||c>'9')c=='-'&&(f=-1),c=getchar();while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();return x*f;}
int pow(int a,int b){int ans=1;while(b)(b&1)&&(ans=1ll*ans*a%P),a=1ll*a*a%P,b>>=1;return ans;}
int C(int a,int b){return 1ll*fc[a]*inv[b]%P*inv[a-b]%P;}
int main()
{
	T=get();N=MAXN-1;fc[0]=1;For(i,1,N)fc[i]=1ll*fc[i-1]*i%P;inv[N]=pow(fc[N],P-2);FOR(i,N-1,0)inv[i]=1ll*inv[i+1]*(i+1)%P;
	while(T--)
	{
		N=get();For(i,1,N)a[i]=get();sort(a+1,a+N+1,greater<int>());
		if(a[1]==a[2]){cout<<fc[N]<<'\n';continue;}if(a[1]>a[2]+1){cout<<"0\n";continue;}
		int x=2;while(x<N&&a[x]==a[x+1])x++;x--;int ans=fc[N];For(i,0,N-x-1)ans=(ans-1ll*fc[i]*fc[N-i-1]%P*C(N-x-1,i)%P+P)%P;cout<<ans<<'\n';
	}
	return 0;
}