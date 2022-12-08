#include<bits/stdc++.h>
using namespace std;
const int maxn=3e5+10,mod=998244353;
int c[maxn],sum[maxn];
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
	int n;
	scanf("%d",&n);
	for(int i=1;i<=n;i++)scanf("%d",c+i);
	sort(c+1,c+n+1,greater<int>());
	for(int i=1;i<=n;i++)sum[i]=(sum[i-1]+c[i])%mod;
	for(int i=1;i<=n;i++) {
		int T=i,ans=0,cnt=0;
		while(T+i<n)ans=(ans+1ll*(++cnt)*(sum[T+i]-sum[T]))%mod,T+=i;
		ans=(ans+1ll*(sum[n]-sum[T])*(++cnt))%mod;
		printf("%lld ",1ll*(ans+mod)*qpow(n,mod-2)%mod);
	}
	puts("");
	return 0;
}