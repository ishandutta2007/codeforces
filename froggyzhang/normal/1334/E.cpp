#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
using namespace std;
#define N 2333333
typedef long long ll;
const ll mod=998244353;
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
ll D,fac[N],inv[N];
vector<ll> vec;
int Q;
ll _gcd(ll a,ll b){
	if(b==0)return a;
	return _gcd(b,a%b);
}
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
	for(int i=1;i<=n;++i){
		fac[i]=fac[i-1]*i%mod;
	}
	inv[n]=qpow(fac[n],mod-2);
	for(int i=n-1;i>=0;--i){
		inv[i]=inv[i+1]*(i+1)%mod;
	}
}
ll calc(ll x,ll y){
	if(x==y)return 1;
	ll tmp=x/y;
	ll ans=1;
	int tot=0;
	for(int j=0;j<vec.size()&&vec[j]*vec[j]<=tmp;++j){
		ll i=vec[j];
		if(tmp%i==0){
			int cnt=0;
			while(tmp%i==0){
				++cnt;
				tmp/=i;
			}
			tot+=cnt;
			ans=ans*inv[cnt]%mod;
		}
	} 
	if(tmp>1){
		++tot;
	}
	return ans*fac[tot]%mod;
}
int main(){
	D=read(),Q=read();
	init(2000000);
	for(ll i=2;i*i<=D;++i){
		if(D%i==0){
			vec.push_back(i);
			while(D%i==0)D/=i; 
		}
	}
	if(D>1)vec.push_back(D);
	while(Q--){
		ll u=read(),v=read();
		ll g=_gcd(u,v);
		printf("%I64d\n",calc(u,g)*calc(v,g)%mod);
	}
//	getchar(); 
	return 0;
}