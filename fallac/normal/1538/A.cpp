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
	v.resize(N + 1);
	ll mn = 1000000000, mx = 0;
	ll ind1, ind2;
	for (i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
		if (mn > a) mn = a, ind2 = i;
		if (mx < a) mx = a, ind1 = i;
	}
	ll p, q, r;
	p = max(ind1, ind2);
	q = N - min(ind1, ind2) + 1;
	r = N - (abs(ind1 - ind2)) + 1;
	cout << min(min(p, q), r) << ln;
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