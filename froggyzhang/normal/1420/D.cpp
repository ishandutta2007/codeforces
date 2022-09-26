#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
#define N 600030
const int mod=998244353;
typedef long long ll;
inline ll read(){
	ll x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9'){
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9'){
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int l[N],r[N],n,m,a[N],len,fac[N],ifac[N],cntl[N],cntr[N],ans;
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=1LL*fac[i-1]*i%mod;
	}
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	}
}
inline int C(int n,int m){
	if(n<0||m<0||n-m<0)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	n=read(),m=read();
	init(n);
	for(int i=1;i<=n;++i){
		l[i]=read(),r[i]=read();
		a[++len]=l[i],a[++len]=r[i];
	}
	sort(a+1,a+len+1);
	len=unique(a+1,a+len+1)-a-1;
	for(int i=1;i<=n;++i){
		l[i]=lower_bound(a+1,a+len+1,l[i])-a;
		r[i]=lower_bound(a+1,a+len+1,r[i])-a;
		++cntl[l[i]],++cntr[r[i]];
	}
	for(int i=1,now=0;i<=len;++i){
		ans=(ans-C(now,m)+mod)%mod;
		now+=cntl[i];
		ans=(ans+C(now,m))%mod;
		now-=cntr[i];
	}
	printf("%d\n",ans);
	return 0;
}