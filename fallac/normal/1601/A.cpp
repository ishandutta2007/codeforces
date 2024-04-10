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

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll gcd(ll a, ll b) {
	while (b) {
		if (a == 0) return b;
		a ^= b ^= a ^= b %= a;
	}
	return a;
}

void solve() {
	ll N;
	cin >> N;
	vector<ll> v(N);
	ll i;
	for (i = 0; i < N; i++) cin >> v[i];
	ll ans = 0;
	for (i = 0; i < 32; i++) {
		ll cnt = 0;
		ll j;
		for (j = 0; j < N; j++) if ((1 << i) & v[j]) cnt++;
		ans = gcd(ans, cnt);
	}
	vector<ll> asdf;
	for (i = 1; i <= N; i++) if (ans % i == 0) asdf.push_back(i);
	for (auto x : asdf) cout << x << bb;
	cout << ln;
}

void init() {

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