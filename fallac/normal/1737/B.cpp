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

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll get(ll K) {
	ll ans = 0;
	ll l, r;
	l = 0, r = 1e9 + 1;
	while (r - l > 1) {
		ll mid = (l + r + 1) / 2;
		if (mid * mid > K) r = mid;
		else l = mid;
	}
	ans += l;
	l = 0, r = 1e9 + 1;
	while (r - l > 1) {
		ll mid = (l + r + 1) / 2;
		if (mid * (mid + 1) > K) r = mid;
		else l = mid;
	}
	ans += l;
	l = 0, r = 1e9 + 1;
	while (r - l > 1) {
		ll mid = (l + r + 1) / 2;
		if (mid * (mid + 2) > K) r = mid;
		else l = mid;
	}
	ans += l;
	return ans;
}

void solve() {
	ll L, R;
	cin >> L >> R;
	L--;
	ll ans = 0;
	ans += get(R);
	if (L) ans -= get(L);
	cout << ans << ln;
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