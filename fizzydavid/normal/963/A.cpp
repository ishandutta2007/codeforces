//by yjz
#include<bits/stdc++.h>
using namespace std;
#define FF first
#define SS second
#define PB push_back
#define MP make_pair
#define bged(v) (v).begin(),(v).end()
#define foreach(it,s) for(__typeof((s).begin()) it=(s).begin();it!=(s).end();it++)
typedef long long ll;
const int Imx=2147483647;
const ll Lbig=2e18;
const int mod=1e9+9;
ll qpow(ll x,ll k){return k==0?1:1ll*qpow(1ll*x*x%mod,k>>1)*(k&1?x:1)%mod;}
int n,a,b,m;
char s[100111];
int main()
{
	scanf("%d%d%d%d",&n,&b,&a,&m);
	scanf("%s",s);
	ll k=qpow(a,m)*qpow(b,mod-1-m)%mod;
	ll ans=0;
	for(int i=0;i<m&&i<=n;i++)
	{
		int l=(n-i)/m+1;
		ll f=qpow(a,i)*qpow(b,n-i)%mod;
		if(s[i]=='-')f=mod-f;
		if(k==1)ans+=l*f%mod;
		else ans+=qpow(1-k,mod-2)*f%mod*(1-qpow(k,l))%mod;
	}
	ans=(ans%mod+mod)%mod;
	cout<<ans<<endl;
	return 0;
}