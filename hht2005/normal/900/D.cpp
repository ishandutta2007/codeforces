#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int mu(int x) {
	int f=1;
	for(int i=2;i<=x/i;i++) {
		int cnt=0;
		while(x%i==0)x/=i,cnt++;
		if(cnt>1)return 0;
		if(cnt)f*=-1;
	}
	if(x!=1)f*=-1;
	return (mod+f)%mod;
}
signed main() {
	int x,y,ans=0;
	cin>>x>>y;
	if(y%x)return puts("0"),0;
	int n=y/x;
	for(int i=1;i<=n/i;i++) {
		if(n%i)continue;
		ans=(ans+1ll*mu(i)*qpow(2,n/i-1))%mod;
		if(i*i!=n)ans=(ans+1ll*mu(n/i)*qpow(2,i-1))%mod;
	}
	printf("%d\n",ans);
	return 0;
}