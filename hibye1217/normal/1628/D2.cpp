#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
using ll = long long;
using ld = long double;
using ull = unsigned long long;
#define fr first
#define sc second
using pi2 = pair<int, int>;
using pl2 = pair<ll, ll>;
using pd2 = pair<ld, ld>;
#define all(v) v.begin(), v.end()
#define unq(v) sort( all(v) ); v.erase( unique( all(v) ), v.end() );

const ll mod = 1e9 + 7;
const int N = 2000000;

ll fpow(ll a, ll b){
	ll res = 1, mul = a, bit = b;
	while (bit){
		if (bit & 1){ res = res*mul % mod; }
		mul = mul*mul % mod; bit >>= 1;
	}
	return res;
}
inline ll finv(ll a){ return fpow(a, mod-2); }

ll fac[2000020], inv[2000020];
ll two[2000020], val[2000020];

inline ll ncr(int n, int r){
	if (r < 0 || n < r){ return 0; }
	return fac[n] * inv[r] % mod * inv[n-r] % mod;
}

void Main(){
	fac[0] = 1;
	for (int i = 1; i <= N; i++){ fac[i] = fac[i-1]*i % mod; }
	inv[N] = finv(fac[N]);
	for (int i = N-1; i >= 0; i--){ inv[i] = inv[i+1]*(i+1) % mod; }
	for (int i = 0; i <= N; i++){
		if (i == 0){ two[i] = 1; }
		else{ two[i] = two[i-1] * 2 % mod; }
		if (i != 0){ val[i] = two[i-1]*i % mod; }
		else{ val[i] = 0; }
	}
	int t; cin >> t;
	while (t--){
		int n, m; ll k; cin >> n >> m >> k;
		if (n == m){
			cout << (k*n) % mod << endl;
			continue;
		}
		ll ans = 0;
		int d = 0;
		for (int i = m; i >= 0; i--){
			ll res = val[i] * ncr(n-m-1+d, d) % mod;
			//cout << res << endl;
			d += 1;
			ans += res; ans %= mod;
		}
		ans *= finv(two[n-1]); ans %= mod;
		ans *= k; ans %= mod;
		cout << ans << endl;
	}
}

//#define DEBUG
int main(){
#ifndef DEBUG
	ios_base::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
#endif
	cout.setf(ios::fixed);
	cout.precision(0);
	Main();
}