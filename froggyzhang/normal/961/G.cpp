#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
typedef long long ll;
#define N 200020
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
int qpow(int a,int b){
	int ans=1;
	while(b){
		if(b&1)ans=1LL*ans*a%mod;
		a=1LL*a*a%mod;
		b>>=1;
	}
	return ans;
}
int n,k,ans,sum,fac[N],ifac[N];
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
int main(){
	n=read(),k=read();
	init(n);
	for(int i=1;i<=n;++i){
		sum=(sum+read())%mod;
	}
	for(int j=0;j<k;++j){
		ans=(ans+1LL*((k-1-j)&1?mod-C(k-1,j):C(k-1,j))*((qpow(j+1,n-1)+(n==1?0:1LL*(n-1)*qpow(j+1,n-2)))%mod))%mod;
	}
	ans=1LL*ans*sum%mod*ifac[k-1]%mod;
	printf("%d\n",ans);
	return 0;
}