#include<bits/stdc++.h>
using namespace std;
#define N 2333
typedef long long ll;
const int mod=998244353;
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
int n,m,ans;
int fac[N<<2],ifac[N<<2];
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
	if(n<0||m<0||n<m)return 0;
	return 1LL*fac[n]*ifac[m]%mod*ifac[n-m]%mod;
}
int main(){
	n=read(),m=read();
	if(n==1||m==1)return !printf("0\n");
	init((n+m)<<1);
	for(int k=1;k<n;++k){
		int sum=0;
		for(int j=2;j<=m;++j){
			int i=j-1;
			sum=(sum+1LL*C(i-1+k,k)*C(m-i+(k-1),k-1))%mod;
			ans=(ans+1LL*sum*C(j-1+(n-k-1),n-k-1)%mod*C(m-j+(n-k),n-k))%mod;
		}
	}
	for(int k=1;k<m;++k){
		int sum=0;
		for(int j=3;j<=n;++j){
			int i=j-2;
			sum=(sum+1LL*C(i-1+k,k)*C(n-i+(k-1),k-1))%mod;
			ans=(ans+1LL*sum*C(j-1+(m-k-1),m-k-1)%mod*C(n-j+(m-k),m-k))%mod;
		}
	}
	printf("%d\n",(ans<<1)%mod);
	return 0;
}