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

ll arr[MAX];

ll gcd(ll a, ll b) {
	while (b) {
		if (!a) return abs(b);
		b %= a ^= b ^= a ^= b;
	}
	return abs(a);
}

void solve() {
	ll N;
	cin >> N;
	ll i;
	for (i = 1; i <= N; i++) cin >> arr[i];
	if (N == 1) {
		cout << 0 << ln;
		return;
	}
	ll j;
	map<pair<pll, pll>, ll> mp;
	for (i = 1; i <= N; i++) {
		for (j = i + 1; j <= N; j++) {
			ll dx = j - i;
			ll dy = arr[j] - arr[i];
			ll g = gcd(dx, dy);
			dx /= g;
			dy /= g;
			ll b = dx * arr[i] - dy * i;
			g = gcd(dx, b);
			mp[{ { dy, dx }, { b / g, dx / g }}]++;
		}
	}
	map<ll, ll> mp1;
	for (i = 1; i <= N; i++) mp1[i * (i - 1) / 2] = i;
	ll mx = 0;
	for (auto it = mp.begin(); it != mp.end(); it++) mx = max(it->second, mx);
	cout << N - mp1[mx] << ln;
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