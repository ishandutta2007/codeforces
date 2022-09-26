#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
typedef long long ll;
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
int T;
ll a,m; 
ll _gcd(ll a,ll b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
ll PHI(ll x){
	ll ans=x;
	for(ll i=2;i*i<=x;i++){
		if(x%i==0){
			ans=ans/i*(i-1);
			while(x%i==0)x/=i;
		}
	}
	if(x>1)ans=ans/x*(x-1);
	return ans;
}
int main(){
	T=read();
	while(T--){
		a=read(),m=read();
		ll tmp=m/_gcd(a,m);
		printf("%lld\n",PHI(tmp));
	}
	return 0;
}