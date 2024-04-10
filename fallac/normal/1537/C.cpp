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
#define INF 1000000000000

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
	for (i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	if (N == 2) {
		cout << v[0] << ln;
		cout << v[1] << ln;
		return;
	}
	ll mn = INF;
	ll asdf = -1;
	for (i = 1; i < N; i++) {
		if (mn > v[i] - v[i - 1]) {
			mn = v[i] - v[i - 1];
			asdf = i;
		}
	}
	for (i = asdf; i < N; i++) cout << v[i] << ln;
	for (i = 0; i < asdf; i++) cout << v[i] << ln;
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