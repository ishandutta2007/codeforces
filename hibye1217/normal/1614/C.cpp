#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

using ll = long long;
using ld = long double;

#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;

#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const ll mod = 1e9 + 7;
ll fpow(ll a, ll b){
	ll res = 1, mul = a, bit = b;
	while (bit){
		if (bit&1){ res = res*mul % mod; }
		mul = mul*mul % mod; bit >>= 1;
	}
	return res;
}

// #define DEBUG

void Main(){
	int t; cin >> t;
	while (t--){
		int n, m; cin >> n >> m;
		ll bit = 0;
		while (m--){
			int l, r; ll x; cin >> l >> r >> x;
			bit |= x;
		}
		bit %= mod;
		ll ans = bit * fpow(2, n-1) % mod;
		cout << ans << endl;
	}
}

int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}