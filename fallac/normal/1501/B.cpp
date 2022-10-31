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

//var

//

void solve() {
	ll N;
	cin >> N;
	vector<pair<ll, ll>> a;
	vector<ll> cc;
	cc.resize(N + 1);
	ll i, p;
	for (i = 1; i <= N; i++) {
		cin >> p;
		if (!p) continue;
		else a.push_back({ i - p + 1, i });
	}
	sort(a.begin(), a.end());
	pair<ll, ll> r;
	ll ptr = 0;
	for (i = 0; i < a.size(); i++) {
		for (ll j = max(ptr + 1, a[i].first); j <= a[i].second; j++) {
			cc[j] = 1;
		}
		ptr = max(ptr, a[i].second);
	}
	for (i = 1; i <= N; i++) cout << cc[i] << ln;
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