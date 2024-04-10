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

#define MAX 101010
#define MOD 100000009
#define INF 1000000000000

#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

void solve() {
	ll N;
	cin >> N;
	ll i;
	vector<ll> v, vv, sum;
	v.resize(N + 1);
	vv.resize(N + 1);
	sum.resize(N + 1);
	ll a = 1;
	ll Q;
	cin >> Q;
	string s;
	cin >> s;
	for (i = 1; i <= N; i++) v[i] = s[i - 1] == '+' ? 1 : -1, vv[i] = v[i] * a, a *= -1;
	for (i = 1; i <= N; i++) sum[i] = sum[i - 1] + vv[i];
	map<ll, vector<ll>> plus, minus;
	for (i = 1; i <= N; i++) {
		if (vv[i] == 1) plus[sum[i]].push_back(i);
		else minus[sum[i]].push_back(i);
	}
	for (i = 1; i <= Q; i++) {
		ll l, r;
		cin >> l >> r;
		if (r - l <= 1) {
			if (r == l) cout << 1 << ln << l << ln;
			else {
				if (v[l] == v[r]) cout << 0 << ln;
				else cout << 2 << ln << l << bb << r << ln;
			}
			continue;
		}
		if ((r - l + 1) % 2 == 0) {
			if (sum[r] - sum[l - 1] == 0) {
				cout << 0 << ln;
				continue;
			}
			cout << 2 << ln;
			cout << l << bb;
			l++;
		}
		else cout << 1 << ln;
		ll delta = sum[r] - sum[l - 1];
		ll msum = (delta - 1) / 2 + sum[l - 1];
		ll psum = (delta + 1) / 2 + sum[l - 1];
		if (!minus[msum].empty()) {
			ll ind = lower_bound(minus[msum].begin(), minus[msum].end(), l) - minus[msum].begin();
			if (ind < minus[msum].size() && minus[msum][ind] <= r) {
				cout << minus[msum][ind] << ln;
				continue;
			}
		}
		ll ind = lower_bound(plus[psum].begin(), plus[psum].end(), l) - plus[psum].begin();
		if (ind < plus[psum].size()) cout << plus[psum][ind] << ln;
	}
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