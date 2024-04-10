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
	vector<ll> a;
	ll N;
	cin >> N;
	ll m = 0;
	ll i;
	a.resize(N + 1);
	for (i = 1; i <= N; i++) {
		cin >> a[i];
		m = max(m, a[i]);
	}
	if (N == 1) {
		cout << 0 << ln;
		return;
	}
	set<ll> s;
	for (i = 2; i <= N; i++) {
		s.insert(a[i] - a[i - 1]);
	}
	if (s.size() >= 3) {
		cout << -1 << ln;
		return;
	}
	if (s.size() == 1) {
		if (s.find(0) != s.end()) {
			cout << 0 << ln;
			return;
		}
		else {
			cout << 0 << ln;
			return;
		}
	}
	else {
		if (s.find(0) != s.end()) {
			cout << -1 << ln;
			return;
		}
		else {
			ll p, q;
			set<ll>::iterator it;
			it = s.begin();
			p = *it;
			it++;
			q = *it;
			ll mm = abs(p - q);
			if (mm <= m) {
				cout << -1 << ln;
				return;
			}
			cout << abs(p - q) << ln;
			if (p > 0) cout << abs(p) << ln;
			else cout << abs(q) << ln;
			return;
		}
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