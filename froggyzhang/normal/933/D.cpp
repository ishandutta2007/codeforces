#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
inline ll read(){
    ll x=0,f=1;
    char c=getchar();
    while(c<'0'||c>'9'){
        if(c=='-')f=-1;
        c=getchar();
    }
    while(c>='0'&&c<='9'){
        x=(x<<3)+(x<<1)+c-'0';
        c=getchar();
    }
    return x*f;
}
ll n,m,ans,tot,inv2,inv6,fac[100],inv[100],f[10],pre[10],suf[10],myh[10];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
inline ll S3(ll x){
	x%=mod;
	return x*(x+1)%mod*(2*x+1)%mod*inv6%mod;
}
inline ll S2(ll x){
	x%=mod;
	return x*(x+1)%mod*inv2%mod;
}
void init(int n){
	fac[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=fac[i-1]*i%mod;
	}
	inv[n]=qpow(fac[n],mod-2)%mod;
	for(int i=n-1;i>=0;--i){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
	for(int i=1;i<=8;++i){
		myh[i]=qpow(fac[i-1]*fac[8-i]%mod,mod-2);
	}
	inv2=qpow(2,mod-2);
	inv6=qpow(6,mod-2);
}
ll Lagrange(ll n){
	n%=mod;
	if(n<=8)return f[n];
	pre[0]=suf[9]=1;
	for(int i=1;i<=8;++i){
		pre[i]=pre[i-1]*(n-i)%mod;
	}
	for(int i=8;i>=0;--i){
		suf[i]=suf[i+1]*(n-i)%mod;
	}
	ll ans=0;
	for(int i=1;i<=8;++i){
		ans=(ans+f[i]*pre[i-1]%mod*suf[i+1]%mod*myh[i]%mod*((8-i)&1?-1:1))%mod;
	}
	return ans;
}
int main(){
//	freopen("count.in","r",stdin);
//	freopen("count.out","w",stdout);
	n=read();
	init(10);
	m=sqrt(n)+1;
	tot=(S3(n)+S2(n))%mod*inv2%mod;
	for(register ll X=0;X*X<=n;++X){
		ll Y=sqrt(n-X*X);
		ans=(ans+tot*Y%mod)%mod;
		for(int i=1;i<=8;++i){
			ll p=X*X+i*i-1;
			f[i]=(f[i-1]+S3(p)-S2(p)*((n+1)%mod)%mod)%mod;
		}
		ans=(ans+Lagrange(Y));
	}
	cout<<((ans%mod+mod)%mod*4+tot)%mod<<endl;
	return 0;
}