#include<bits/stdc++.h>
using namespace std;
const int maxn=10010,mod=998244353;
int inv[maxn],fac[maxn],g[maxn];
int C(int n,int m) {
	if(m>n)return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int f(int s,int n,int m) {
	if(s<0)return 0;
	if(n==0&&s==0)return 1;
	for(int i=0;i<=n;i++)g[n-i]=C(s-i*(m+1)+n-1,n-1);
	int ans=0;
	for(int i=0;i<=n;i++) {
		if((n-i)&1)ans=(ans-1ll*C(n,i)*g[i]%mod+mod)%mod;
		else ans=(ans+1ll*C(n,i)*g[i]%mod+mod)%mod;
	}
	return ans;
}
int main() {
	fac[0]=1;
	for(int i=1;i<=10000;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[10000]=qpow(fac[10000],mod-2);
	for(int i=9999;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	int p,s,r,ans=0;
	scanf("%d%d%d",&p,&s,&r);
	for(int x=r;x<=s;x++)
		for(int y=1;y<=p;y++)
			ans=(ans+1ll*C(p-1,y-1)*f(s-x*y,p-y,x-1)%mod*qpow(y,mod-2)%mod)%mod;
	printf("%lld\n",1ll*ans*qpow(C(s-r+p-1,p-1),mod-2)%mod);
	return 0;
}