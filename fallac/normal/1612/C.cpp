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

//var

//

void solve() {
	ll a, b;
	cin >> a >> b;
	if (a * a <= b) {
		cout << 2 * a - 1 << Ln;
		return;
	}
	if (a * (a + 1) / 2 > b) {
		ll l, r;
		l = -1;
		r = a + 1;
		while (r - l > 1) {
			ll mid = (l + r + 1) / 2;
			if (mid * (mid - 1) / 2 >= b) r = mid;
			else l = mid;
		}
		cout << l << ln;
		return;
	}
	ll l, r;
	l = -1;
	r = a + 1;
	while (r - l > 1) {	
		ll mid = (l + r + 1) / 2;
		if (a * a - (a - mid) * (a - mid + 1) / 2 >= b) r = mid;
		else l = mid;
	}
	cout << l + a << ln;
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