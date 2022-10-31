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

ll f(ll a, ll x) {
	if (!a) return 0LL;
	ll k;
	for (k = 20; k >= x; k--) {
		if ((1LL << k) & a) {
			break;
		}
	}
	if (k < x) return 0;
	else if (k == x) return (a - (1LL << k)) + 1;
	else return f(a - (1LL << k), x) + (1LL << max(0LL, k - 1));
}

void solve() {
	ll a, b;
	cin >> a >> b;
	ll i;
	ll mx = 0;
	for (i = 0; i < 20; i++) {
		mx = max(mx, f(b, i) - f(a - 1, i));
	}
	cout << (b - a + 1) - mx << ln;
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