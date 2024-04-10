#include<bits/stdc++.h>
using namespace std;
#define N 4000040
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
int fac[N],ifac[N],inv[N],n,m,ans;
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
	for(int i=1;i<=n;++i)fac[i]=1LL*fac[i-1]*i%mod;
	ifac[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i)ifac[i]=1LL*ifac[i+1]*(i+1)%mod;
	inv[1]=1;
	for(int i=2;i<=n;++i)inv[i]=1LL*inv[mod%i]*(mod-mod/i)%mod;
}
inline int C(int n,int m){
	if(n<m||n<0||m<0)return 0;
	return 1LL*fac[n]*ifac[n-m]%mod*ifac[m]%mod;
}
int main(){
	n=read(),m=read();
	init(n+m);
	for(int i=1;i<=n;++i){
		ans=(ans+1LL*(i&1?C(n,i):mod-C(n,i))*(m+i)%mod*inv[i])%mod;	
	}
	int g0=0;
	for(int i=0;i<=n;++i){
		g0=(g0+1LL*C(n,i)*fac[i]%mod*fac[n+m-i-1]%mod*m%mod*ifac[n+m]%mod*(i+1))%mod;
	}
	ans=1LL*ans*g0%mod;
	printf("%d\n",ans);
	return 0;
}