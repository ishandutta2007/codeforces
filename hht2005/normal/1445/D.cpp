#include<bits/stdc++.h>
using namespace std;
const int maxn=4e5+10,mod=998244353;
int a[maxn];
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main() {
	int n,ans=0,ans1=1;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		scanf("%d",a+i);
	sort(a+1,a+2*n+1);
	for(int i=1;i<=n;i++)ans=(ans-a[i]+mod)%mod;
	for(int i=n+1;i<=2*n;i++)ans=(ans+a[i])%mod;
	for(int i=1;i<=n;i++) {
		ans=1ll*ans*(2*n-i+1)%mod;
		ans1=1ll*ans1*i%mod;
	}
	printf("%lld\n",1ll*ans*qpow(ans1,mod-2)%mod);
	return 0;
}