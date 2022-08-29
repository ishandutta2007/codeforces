#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define ll int
const int D=1000002;
ll f[D],g[D],p1[D],p2[D],b[D];
#define rep(i,a,n) for (int i=a;i<n;i++)
#define per(i,a,n) for (int i=n-1;i>=a;i--)
ll ksm(ll a,ll b) {
	ll ans=1;
	while(b) {
		if(b&1) ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}

ll calcn(int d,ll *a,ll n) {
	if (n<=d) return a[n];
	p1[0]=p2[0]=1;
	rep(i,0,d+1) {
		ll t=(n-i+mod)%mod;
		p1[i+1]=1ll*p1[i]*t%mod;
	}
	rep(i,0,d+1) {
		ll t=(n-d+i+mod)%mod;
		p2[i+1]=1ll*p2[i]*t%mod;
	}
	ll ans=0;
	rep(i,0,d+1) {
		ll t=1ll*g[i]*g[d-i]%mod*p1[i]%mod*p2[d-i]%mod*a[i]%mod;
		if ((d-i)&1) ans=(ans-t+mod)%mod;
		else ans=(ans+t)%mod;
	}
	return ans;
}
void init(int M) {
	f[0]=f[1]=g[0]=g[1]=1;
	rep(i,2,M+5) f[i]=1ll*f[i-1]*i%mod;
	g[M+4]=ksm(f[M+4],mod-2);
	per(i,1,M+4) g[i]=1ll*g[i+1]*(i+1)%mod;
}
ll polysum(ll m,ll *a,ll n) {
	for(int i=0; i<=m; i++) b[i]=a[i];
	b[m+1]=calcn(m,b,m+1);
	rep(i,1,m+2) b[i]=(b[i-1]+b[i])%mod;
	return calcn(m+1,b,n-1);
}

ll n,k;ll a[1000005],tot=0;ll pri[700002];
bool v[1000003];
int main() {
	
	init(1000005);
	cin>>n>>k;
	if(k==0) {
		cout<<n<<endl;
		return 0;
	}
	a[0]=0;
	a[1]=1;
	for(int i=2; i<=k+2; i++)	{
		if(!v[i]) {
			a[i]=ksm(i,k);
			pri[++tot]=i;
		}
		for(int j=1; j<=tot; j++)		{
			int x=pri[j];
			if(i*x>k+2)break;
			v[i*x]=1;a[i*x]=1ll*a[i]*a[x]%mod;
			if(!i%x) {

				break;
			}			
			 
		}
	}	
	ll ans=polysum(k+2,a,n+1);
	cout<<ans<<endl;
return 0;
}