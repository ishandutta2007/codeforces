#include<bits/stdc++.h>
using namespace std;
const int mod=998244353;
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
signed main() {
	int n,ans1=1,ans2=1,ans=0;
	long long k;
	scanf("%d%lld",&n,&k);
	if(k>=n) {
		puts("0");
		return 0;
	}
	for(int i=0;i<=n-k;i++) {
		if(i&1)ans=(ans-1ll*qpow(n-k-i,n)*ans2%mod*qpow(ans1,mod-2)%mod+mod)%mod;
		else ans=(ans+1ll*qpow(n-k-i,n)*ans2%mod*qpow(ans1,mod-2))%mod;
		ans1=1ll*ans1*(i+1)%mod;
		ans2=1ll*ans2*(n-k-i)%mod;
	}
	ans1=ans2=1;
	for(int i=1;i<=k;i++) {
		ans1=1ll*ans1*i%mod;
		ans2=1ll*ans2*(n-i+1)%mod;
	}
	if(k)cout<<2ll*ans*ans2%mod*qpow(ans1,mod-2)%mod<<endl;
	else cout<<1ll*ans*ans2%mod*qpow(ans1,mod-2)%mod<<endl;
	return 0;
}