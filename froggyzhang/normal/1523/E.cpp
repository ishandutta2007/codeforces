#include<bits/stdc++.h>
using namespace std;
#define N 1000010
const int mod=1e9+7;
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
int T,n,k,fac[N],ifac[N];
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
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
void Solve(){
	n=read(),k=read();
	int ans=fac[n];
	for(int i=1;i<=n;++i){
		if(1LL*(i-1)*k+1>n)break;
		ans=(ans+1LL*C(n-1-(i-1)*k+i,i)*fac[i]%mod*fac[n-i])%mod;
	}
	ans=1LL*ans*ifac[n]%mod;
	printf("%d\n",ans);	
}
int main(){
	init(1000000);
	T=read();
	while(T--){
		Solve();
	}
	return 0;
}