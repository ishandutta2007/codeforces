#include<bits/stdc++.h>
using namespace std;
const int N=2e5+10,mod=1e9+7,M=2e5;
int fac[N],inv[N];
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int C(int n,int m) {
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main() {
	int T,n,k;
	fac[0]=1;
	for(int i=1;i<=M;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[M]=qpow(fac[M],mod-2);
	for(int i=M;i>=1;i--)inv[i-1]=1ll*inv[i]*i%mod;
	scanf("%d",&T);
	while(T--) {
		scanf("%d%d",&n,&k);
		if(k==0) {
			puts("1");
			continue;
		}
		int sum=0,ans=0,P=1;
		for(int i=0;i<n;i+=2)
			sum=(sum+C(n,i))%mod;
		if(n&1)printf("%d\n",qpow(sum+1,k));
		else {
			for(int i=k;i>=1;i--) {
				ans=(ans+1ll*P*qpow(2,1ll*(i-1)*n%(mod-1)))%mod;
				P=1ll*P*sum%mod;
			}
			printf("%d\n",(ans+P)%mod);
		}
	}
}