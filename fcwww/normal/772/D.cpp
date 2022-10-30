#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
using namespace std;
#define mod 1000000007
typedef long long ll;
#define N 1000050
ll mi[N];
void fwt(ll *a,int len,int flg) {
	int i,k,j,t;
	for(k=10;k<=len;k*=10) {
		t=k/10;
		for(i=0;i<len;i+=k) {
			if(flg==1) {
				for(j=i+k-1;j>=i+t;j--) {
					a[j-t]=(a[j-t]+a[j])%mod;
				}
			}else {
				for(j=i+t;j<i+k;j++) {
					a[j-t]=(a[j-t]-a[j])%mod;
				}
			}
		}
	}
}
ll a[N],b[N],c[N];
int main() {
	int len=1000000,i,n,x;
	scanf("%d",&n);
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		a[x]++; b[x]=(b[x]+x)%mod; c[x]=(c[x]+ll(x)*x)%mod;
	}
	for(mi[0]=i=1;i<len;i++) mi[i]=(mi[i-1]<<1)%mod;
	fwt(a,len,1),fwt(b,len,1),fwt(c,len,1);
	for(i=0;i<len;i++) {
		if(a[i]) {
			if(a[i]==1) a[i]=c[i];
			else a[i]=mi[a[i]-2]*(b[i]*b[i]%mod+c[i])%mod;
		}
	}
	fwt(a,len,-1);
	ll ans=0;
	for(i=1;i<len;i++) a[i]=(a[i]+mod)%mod,ans^=i*a[i];
	printf("%lld\n",ans);
}