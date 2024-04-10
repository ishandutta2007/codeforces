/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 301010
#define MOD 1000000007
#define INF 1000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

ll fact[MAX];
ll get(ll x) {
	if (fact[x]) return fact[x];
	else return (fact[x] = (get(x - 1) * x) % MOD);
}

ll mpow(ll x, ll y) {
	if (y == 0) return 1;
	if (y == 1) return x;
	ll res = mpow(x, y / 2);
	res *= res;
	res %= MOD;
	if (y % 2) res *= x;
	res %= MOD;
	return res;
}

ll inv(ll x) {
	return mpow(x, MOD - 2);
}

ll C(ll N, ll R) {
	if (R<0 || R>N) return 0LL;
	ll n, r, nr;
	n = get(N);
	r = get(R);
	nr = get(N - R);
	n *= inv(r);
	n %= MOD;
	n *= inv(nr);
	n %= MOD;
	return n;
}

void solve() {
	ll N, l, r;
	cin >> N >> l >> r;
	ll ans = 0;
	ll a = max(min(r - N, 1 - l) - 1, 0LL);
	if (N % 2) ans += a * C(N, N / 2) * 2;
	else ans += a * C(N, N / 2);
	ans %= MOD;
	ll ptr1, ptr2;
	if (1 - l < r - N) ptr1 = max(1LL, l + 1), ptr2 = min(l + r - 1, r - 1);
	else ptr1 = max(l + r - N, l + 1), ptr2 = min(N, r - 1);
	while (1) {
		ll p1, p2;
		p1 = max(ptr1, 1LL);
		p2 = min(N, ptr2);
		ll asdf = p2 - p1 + 1;
		if (asdf < 0) break;
		ll left, right;
		right = N - p1 + 1 - asdf;
		left = p2 - asdf;
		if (N % 2) {
			ll p = N / 2;
			ll rr = p - left;
			ans += C(asdf, rr);
			rr++;
			ans += C(asdf, rr);
			ans %= MOD;
		}
		else {
			ll rr = N / 2 - left;
			ans += C(asdf, rr);
			ans %= MOD;
		}
		ptr1++;
		ptr2--;
	}
	cout << ans << ln;
}

void init() {
	fact[1] = 1;
	fact[0] = 1;
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	while (T--) {
		init();
		solve();
	}
}