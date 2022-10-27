#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;

inline ll func(ll a, ll b){
	if(a&1)return (a%mod)*((b>>1)%mod)%mod;
	return ((a>>1)%mod)*(b%mod)%mod;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll n, m;
	cin>>n>>m;
	ll ans = (n%mod)*(m%mod)%mod;
	for(ll r, l = 1; l <= m && l <= n; l = r + 1){
		r = n/(n/l);
		if(r > m)r = m;
		ans -= ((n/l)%mod)*func(r+l, r-l+1)%mod;
		if(ans < 0)ans += mod;
	}
	cout<<ans<<endl;

	return 0;
}