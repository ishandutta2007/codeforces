/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;
typedef pair<int, int> pii;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 601010
#define MOD 1000000007
//#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "Yes"
#define no "No"

ll fact[MAX];

ll mpow(ll x, ll y) {
	if (!y) return 1;
	ll res = mpow(x, y >> 1);
	res *= res;
	res %= MOD;
	if (y & 1) res *= x, res %= MOD;
	return res;
}

ll inv(ll x) {
	return mpow(x, MOD - 2);
}

ll C(ll n, ll r) {
	ll res = fact[n];
	res *= inv(fact[r]);
	res %= MOD;
	res *= inv(fact[n - r]);
	res %= MOD;
	return res;
}

void solve() {
	int N;
	cin >> N;
	ll i;
	ll a;
	ll ans = 0;
	fact[0] = 1;
	for (i = 1; i <= 505050; i++) fact[i] = fact[i - 1] * i, fact[i] %= MOD;
	for (i = 0; i <= N; i++) {
		cin >> a;
		if (a == 0) continue;
		a--;
		ans += C(a + i + 1, i + 1);
		ans %= MOD;
	}
	cout << ans << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}