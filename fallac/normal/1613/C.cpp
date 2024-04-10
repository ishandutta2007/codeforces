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
	ll N, H;
	cin >> N >> H;
	ll i;
	vector<ll> v;
	for (i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
	}
	ll l, r;
	l = 0, r = H;
	while (r - l > 1) {
		ll mid = (l + r + 1) / 2;
		ll mx = 0;
		ll d = 0;
		for (i = 0; i < N; i++) {
			if (v[i] > mx) {
				mx = v[i] + mid - 1;
				d += mid;
			}
			else {
				d += mid - (mx - v[i] + 1);
				mx = v[i] + mid - 1;
			}
		}
		if (d >= H) r = mid;
		else l = mid;
	}
	cout << r << ln;
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