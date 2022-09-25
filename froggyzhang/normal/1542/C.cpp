#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
const ll lim=1e16;
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
int T;
ll n;
vector<ll> vec;
void Solve(){
	n=read();
	int ans=n%mod;
	for(auto x:vec)ans=(ans+n/x)%mod;
	printf("%d\n",ans);
}
int main(){
	T=read();
	vec.push_back(1LL);
	for(ll i=2;;++i){
		ll x=i/__gcd(vec.back(),i)*vec.back();
		if(x>lim)break;
		vec.push_back(x);
	}
	while(T--){
		Solve();
	}
	return 0;
}