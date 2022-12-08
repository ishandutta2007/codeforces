#include<bits/stdc++.h>
using namespace std;
const int maxn=5010,mod=998244353;
int lim[maxn],f[maxn],a[maxn],fac[maxn],inv[maxn];
int qpow(int a,int b) {
	int ans=1;
	while(b) {
		if(b&1)ans=1ll*ans*a%mod;
		a=1ll*a*a%mod;
		b>>=1;
	}
	return ans;
}
int A(int n,int m) {
	if(m<0||m>n)return 0;
	return 1ll*fac[n]*inv[n-m]%mod;
}
int main() {
	int n;
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=n;i++)scanf("%d",a+i);
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--)inv[i]=1ll*inv[i+1]*(i+1)%mod;
	sort(a+1,a+n+1);
	for(int i=1;i<=n;i++)
		for(int j=1;2*a[j]<=a[i];j++)
			lim[i]++;
	for(int i=1;i<=n;i++) {
		f[i]=A(n-1,lim[i]);
		for(int j=1;2*a[j]<=a[i];j++)
			f[i]=(f[i]+1ll*f[j]*A(n-lim[j]-2,lim[i]-lim[j]-1))%mod;
	}
	if(2*a[n-1]>a[n])return puts("0"),0;
	printf("%d\n",f[n]);
	return 0;
}