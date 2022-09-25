#include<bits/stdc++.h>
using namespace std;
#define N 1000100
typedef long long ll;
const int mod=1e9+7;
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
int n,m,fac[N],ifac[N],ans;
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
	if(n<m)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	n=read(),m=read();read(),read();
	init(max(n,m));
	ans=1LL*fac[n-2]*C(m-1,n-2)%mod;
	for(int i=1;i<n-1;++i){
		ans=(ans+1LL*C(m-1,i-1)*qpow(m,n-i-1)%mod*C(n-2,i-1)%mod*fac[i-1]%mod*(i+1)%mod*qpow(n,n-i-2))%mod;
	}
	printf("%d\n",ans);
	return 0;
}