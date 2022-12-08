#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7,N=3e6+10,inv3=333333336;
inline int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int f[N][2],inv[N],fac[N];
int C(int n,int m) {
	if(m>n||m<0)return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main() {
	int n,q,w;
	scanf("%d%d",&n,&q);
	fac[0]=1;
	for(int i=1;i<=3*n+3;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[3*n+3]=qpow(fac[3*n+3],mod-2);
	for(int i=3*n+3;i>=1;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=0;i<=3*n;i++) {
		f[i][0]=((C(3*n+3,i+1)-2ll*f[i-1][0]-f[i-1][1])*inv3%mod+mod)%mod;
		f[i][1]=(f[i][0]+f[i-1][0])%mod;
	}
	while(q--) {
		scanf("%d",&w);
		printf("%d\n",f[w][0]);
	}
	return 0;
}