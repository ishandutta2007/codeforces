#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define N 200020
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
int n,m;
ll fac[N],inv[N],ans;
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
	fac[0]=1;
	for(int i=1;i<=n;i++){
		fac[i]=fac[i-1]*i%mod;
	}
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;i--){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
ll C(int n,int m){
	return fac[n]*inv[m]%mod*inv[n-m]%mod;
}
int main(){
	init(200000);
	n=read(),m=read();
	for(int i=2;i<n;i++){
		ans=(ans+C(m,n-1)*(n-2)%mod*C(n-3,i-2)%mod)%mod;
	}
	cout<<ans<<endl;
	return 0;
}