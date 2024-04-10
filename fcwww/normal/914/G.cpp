#include <cstdio>
#include <cstring>
#include <algorithm>
#include <cstdlib>
#include <iostream>
using namespace std;
typedef long long ll;
#define mod 1000000007
#define db(x) cerr<<#x<<" = "<<x<<endl
const int inv2=(mod+1)/2;
#define N 150050
ll c[N],f1[N],g[20][N],cnt[N],f[20][N],fib[N],f2[N],f3[N];
void fwt_or(ll *a,int len,int flg) {
	int i,j,k,t;
	for(k=2;k<=len;k<<=1) {
		for(t=k>>1,i=0;i<len;i+=k) for(j=i;j<i+t;j++) {
			if(flg==1) a[j+t]=(a[j+t]+a[j])%mod;
			else a[j+t]=(a[j+t]-a[j])%mod;
		}
	}
}
void fwt_and(ll *a,int len,int flg) {
	int i,j,k,t;
	for(k=2;k<=len;k<<=1) {
		for(t=k>>1,i=0;i<len;i+=k) for(j=i;j<i+t;j++) {
			if(flg==1) a[j]=(a[j]+a[j+t])%mod;
			else a[j]=(a[j]-a[j+t])%mod;
		}
	}
}
void fwt_xor(ll *a,int len,int flg) {
	int i,j,k,t; ll tmp;
	for(k=2;k<=len;k<<=1) {
		for(t=k>>1,i=0;i<len;i+=k) for(j=i;j<i+t;j++) {
			tmp=a[j+t]; a[j+t]=(a[j]-tmp)%mod; a[j]=(a[j]+tmp)%mod;
			if(flg==-1) a[j]=a[j]*inv2%mod,a[j+t]=a[j+t]*inv2%mod;
		}
	}
}
int main() {
	int n;
	scanf("%d",&n);
	int i,x,l=1,mx=0,j,k;
	for(i=1;i<=n;i++) {
		scanf("%d",&x);
		c[x]++;
		mx=max(mx,x);
	}
	while(l<=mx) l<<=1;
	fib[1]=1;
	for(i=2;i<l;i++) fib[i]=(fib[i-1]+fib[i-2])%mod;

	for(i=1;i<l;i++) cnt[i]=cnt[i>>1]+(i&1);
	memcpy(f1,c,sizeof(ll)*l);
	for(i=0;i<l;i++) g[cnt[i]][i]=c[i];
	int lim=cnt[l-1];
	for(i=0;i<=lim;i++) fwt_or(g[i],l,1);
	for(i=0;i<l;i++) for(j=0;j<=lim;j++) if(g[j][i]) for(k=0;j+k<=lim;k++) if(g[k][i]) {
		f[j+k][i]=(f[j+k][i]+g[j][i]*g[k][i])%mod;
	}
	for(i=0;i<=lim;i++) fwt_or(f[i],l,-1);
	for(i=0;i<l;i++) f1[i]=f[cnt[i]][i]*fib[i]%mod;

	for(i=0;i<l;i++) f2[i]=c[i]*fib[i]%mod;

	memcpy(f3,c,sizeof(ll)*l);
	fwt_xor(f3,l,1);
	for(i=0;i<l;i++) f3[i]=f3[i]*f3[i]%mod;
	fwt_xor(f3,l,-1);
	for(i=0;i<l;i++) f3[i]=f3[i]*fib[i]%mod;

	fwt_and(f1,l,1);
	fwt_and(f2,l,1);
	fwt_and(f3,l,1);
	for(i=0;i<l;i++) f1[i]=f1[i]*f2[i]%mod*f3[i]%mod;
	fwt_and(f1,l,-1);
	ll ans=0;
	for(i=0;i<=lim;i++) {
		ans=(ans+f1[1<<i])%mod;
	}
	printf("%lld\n",(ans+mod)%mod);
}