#include<bits/stdc++.h>
using namespace std;
const int N=1<<22;
using ll=long long;
ll e[N],a[N],mod;
int b[N];
void FWT(ll *x,int n,int f) {
	for(int i=2;i<=n;i<<=1) {
		int m=i/2;
		for(int j=0;j<n;j+=i)
			for(int k=0;k<m;k++) {
				ll a=x[j+k];
				x[j+k]=(a+x[j+k+m])%mod;
				x[j+k+m]=(a-x[j+k+m]+mod)%mod;
			}
	}
	if(f==1)return;
	for(int i=0;i<n;i++)
		x[i]/=n;
}
void mul(ll *a,ll *b,int n) {
	for(int i=0;i<n;i++)
		a[i]=(__int128)a[i]*b[i]%mod;
}
int main() {
	int m,p;
	ll t;
	scanf("%d%lld%d",&m,&t,&p);
	int n=1<<m;
	mod=1ll*n*p;
	for(int i=0;i<n;i++)
		scanf("%lld",e+i);
	for(int i=0;i<=m;i++)
		scanf("%d",b+i);
	for(int i=0;i<n;i++) {
		int c=0;
		for(int j=0;j<m;j++)
			c+=i>>j&1;
		a[i]=b[c];
	}
	FWT(e,n,1);
	FWT(a,n,1);
	while(t) {
		if(t&1)mul(e,a,n);
		mul(a,a,n);
		t>>=1;
	}
	FWT(e,n,-1);
	for(int i=0;i<n;i++)
		printf("%lld\n",e[i]);
	return 0;
}