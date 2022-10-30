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

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 301010
//#define MOD 100000007
#define MOD 1000000007
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll arr[MAX];

ll mpow(ll x, ll y) {
	if (y < 0) return 0LL;
	if (!y) return 1;
	ll res = mpow(x, y / 2);
	res *= res;
	res %= MOD;
	if (y & 1) res *= x;
	return res % MOD;
}

void solve() {
	ll N;
	cin >> N;
	ll i;
	ll a;
	ll ans = 0;
	vector<ll> o, e;
	for (i = 1; i <= N; i++) {
		cin >> a;
		(a % 2 ? o : e).push_back(a);
	}
	ans += (mpow(2, e.size()) - 1) * (mpow(2, o.size()) - 1);
	ans %= MOD;
	ans += mpow(2, o.size()) - 1;
	ans %= MOD;
	for (i = 1; i <= 30; i++) {
		vector<ll> a;
		ll j;
		for (j = 0; j < e.size(); j++) {
			if (e[j] % (1LL << i) == 0) a.push_back(e[j] >> i);
		}
		vector<ll> oo, ee;
		for (j = 0; j < a.size(); j++) {
			(a[j] % 2 ? oo : ee).push_back(a[j]);
		}
		ll ooo = max((mpow(2, (ll)oo.size() - 1) - 1), 0LL);
		ans += ooo * mpow(2, ee.size());
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