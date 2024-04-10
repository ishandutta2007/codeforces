#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned long long ull;

const ll mod = 1000000007;

ll ap(ll a, ll n){
	n %= mod;
	a %= mod;
	return (n + a - 1)*n%mod;
}

ll compute(ll r){
	ll a[2] = {1, 2};
	int flg = 0;
	ll len = 1;
	ll ret = 0;
	while(r){
		(ret += ap(a[flg], min(r, len))) %= mod;
		r -= min(r, len);
		len <<= 1;
		a[flg] += len;
		flg ^= 1;
	}
	return ret;
}

int main(){
	ios::sync_with_stdio(false);
	cin.tie(NULL);
	cout.tie(NULL);
	cout<<setprecision(32);

	ll l, r;
	cin>>l>>r;
	ll ans = compute(r) - compute(l - 1) + mod;
	if(ans >= mod)ans -= mod;
	cout<<ans<<endl;

	return 0;
}