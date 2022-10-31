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
	ll Q;
	cin >> N;
	cin >> Q;
	string s;
	cin >> s;
	ll i;
	vector<ll> v;
	vector<ll> sum;
	v.resize(N + 1);
	sum.resize(N + 1);
	for (i = 0; i < N; i++) {
		v[i + 1] = s[i] - 96;
		sum[i + 1] = sum[i] + v[i + 1];
	}
	while (Q--) {
		ll a, b;
		cin >> a >> b;
		cout << sum[b] - sum[a - 1] << ln;
	}
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}