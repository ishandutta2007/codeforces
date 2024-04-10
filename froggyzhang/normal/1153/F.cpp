#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 8050 
typedef long long ll;
const ll mod=998244353;
inline int read(){
    int x=0,f=1;
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
int n,k,L;
ll fac[N],inv[N],ans,pw2[N];
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
void init(int n){
	fac[0]=pw2[0]=1;
	for(int i=1;i<=n;++i){
		fac[i]=fac[i-1]*i%mod;
		pw2[i]=(pw2[i-1]<<1)%mod;
	}
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
ll C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	n=read(),k=read(),L=read();
	init(n<<2);
	for(int i=k;i<=n;++i){
		for(int j=0;j<=n-i;++j){
			ans=(ans+((j&1)?-1:1)*pw2[i+j]*C(n,i)%mod*C(n-i,j)%mod*fac[i+j]%mod*fac[i+j]%mod*inv[2*i+2*j+1]%mod+mod)%mod;
		}
	}
	printf("%lld\n",ans*L%mod);
	return 0;
}