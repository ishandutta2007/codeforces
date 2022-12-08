#include<bits/stdc++.h>
using namespace std;
const int N=1e3+10,mod=998244353;
int a[N],f[N],inv[N],fac[N];
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
	if(m>n||m<0)return 0;
	return 1ll*fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main() {//lkjhgvjk
	int n;
	scanf("%d",&n);
	fac[0]=1;
	for(int i=1;i<=n;i++)fac[i]=1ll*fac[i-1]*i%mod;
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n;i>=1;i--)inv[i-1]=1ll*inv[i]*i%mod;
	for(int i=1;i<=n;i++)
		scanf("%d",a+i);
	f[0]=1;
	for(int i=1;i<=n;i++) {
		f[i]=1;
		for(int j=0;j<i;j++)
			if(a[j+1]>0)f[i]=(f[i]+1ll*f[j]*C(i-j-1,a[j+1]))%mod;
	}
	printf("%d\n",f[n]-1);
	return 0;
}