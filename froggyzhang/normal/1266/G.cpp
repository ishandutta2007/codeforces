#include<bits/stdc++.h>
using namespace std;
#define N 1000010
const int mod=998244353;
typedef long long ll;
int n,ifac[N],fac[N],c[N<<1],ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	init(n);
	c[0]=n;
	for(int i=1;i<n;++i){
		c[i]=1LL*fac[n]*ifac[n-i+1]%mod*(1LL*(n-i)*(n-i)%mod+1)%mod;
	}
	for(int i=n;i<(n<<1);++i){
		c[i]=(fac[n]-c[i-n]+mod)%mod;
	}
	int x=1LL*n*fac[n]%mod;
	ans=1LL*x*(x+1)/2%mod;
	for(int i=1;i<(n<<1);++i){
		ans=(ans+1LL*(mod-c[i])*i)%mod;
	}
	cout<<ans<<'\n';
	return 0;
}