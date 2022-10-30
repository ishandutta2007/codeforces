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
	ll N, x;
	cin >> N >> x;
	ll i;
	vector<ll> v, s;
	ll a;
	for (i = 0; i < N; i++) {
		cin >> a;
		v.push_back(a);
	}
	s = v;
	sort(s.begin(), s.end());
	for (i = 0; i < N; i++) {
		if (i < x && (N - 1 - i) < x) {
			if (s[i] != v[i]) {
				cout << no << ln;
				return;
			}
		}
	}
	cout << yes << Ln;
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