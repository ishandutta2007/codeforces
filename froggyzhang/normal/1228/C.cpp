#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
const ll mod=1e9+7;
const double eps=1e-2;
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
ll x,n,ans;
ll qpow(ll a,ll b){
	ll ans=1;
	while(b){
		if(b&1)ans=ans*a%mod;
		a=a*a%mod;
		b>>=1;
	}
	return ans;
}
ll F(ll p){
	ll r=p,tmp=1;
	while(r<=n){
		tmp=tmp*qpow(p,n/r)%mod;
		if(1.0L*r*p>1.0L*n+eps)break;
		r*=p;
	}
	return tmp;
}
int main(){
	x=read(),n=read();
	ans=1;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			ans=ans*F(i)%mod;;
			while(x%i==0)x/=i;
		}
	}
	if(x>1){
		ans=ans*F(x)%mod;
	}
	cout<<ans<<endl;
	return 0;
}