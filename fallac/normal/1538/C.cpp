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

#define MAX 101010
#define MOD 100000009

#define vv vector
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
	vector<ll> v;
	ll l, r;
	cin >> l >> r;
	ll a;
	for (i = 1; i <= N; i++) cin >> a, v.push_back(a);
	sort(v.begin(), v.end());
	ll sum = 0;
	for (i = 0; i < N; i++) {
		ll ind1 = lower_bound(v.begin(), v.end(), l - v[i]) - v.begin();
		ll ind2 = upper_bound(v.begin(), v.end(), r - v[i]) - v.begin();
		sum += max(0LL, ind2 - ind1);
		ll p = 2 * v[i];
		if (l <= p && p <= r) sum--;
	}
	cout << sum / 2 << ln;
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