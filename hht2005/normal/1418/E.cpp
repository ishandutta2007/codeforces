#include<bits/stdc++.h>
using namespace std;
const int maxn=2e5+10,mod=998244353;
int d[maxn],sum[maxn];
int inv(int a) {
	int b=mod-2,ans=1;
	while(b) {//safdgfg
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int main() {
	int n,m,a,b;
	scanf("%d%d",&n,&m);
	for(int i=1;i<=n;i++)scanf("%d",d+i);
	sort(d+1,d+n+1);
	for(int i=n;i>=1;i--)sum[i]=(sum[i+1]+d[i])%mod;
	for(int i=1;i<=m;i++) {
		scanf("%d%d",&a,&b);
		int big=lower_bound(d+1,d+n+1,b)-d;
		if(n-big+1<a)puts("0");
		else printf("%lld\n",(sum[big]*(1-1ll*a*inv(n-big+1)%mod+mod)+(sum[1]-sum[big]+mod)*(1-1ll*a*inv(n-big+2)%mod+mod))%mod);
	}
	return 0;
}