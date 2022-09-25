#include<bits/stdc++.h>
using namespace std;
#define N 1000100
const int mod=998244353;
typedef long long ll;
int n,ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
const int inv3=qpow(3,mod-2);
int fac[N],ifac[N];
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
inline int C(int n,int m){
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	ios::sync_with_stdio(false);
	cin.tie(0);
	cin>>n;
	init(n);
	for(int i=1;i<=n;++i){
		ans=(ans+1LL*(i&1?C(n,i):mod-C(n,i))*qpow(3,(1LL*n*n-1LL*n*i+i)%(mod-1)))%mod;
	}
	(ans<<=1)%=mod;
	for(int i=1;i<=n;++i){
		ans=(ans+1LL*qpow(3,(1LL*n*(n-i)+1)%(mod-1))*(i&1?C(n,i):mod-C(n,i))%mod*((qpow((mod+1-qpow(inv3,n-i))%mod,n)-1+mod)%mod))%mod;
	}
	cout<<ans<<'\n';
	return 0;
}