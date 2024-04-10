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
	ll N, M;
	cin >> N >> M;
	ll i;
	vector<ll> a, b;
	vector<ll> aaa;
	aaa.resize(10000);
	a.resize(N);
	b.resize(M);
	set<ll> s;
	for (i = 0; i < N; i++) cin >> a[i], aaa[a[i]] = 1;
	for (i = 0; i < M; i++) cin >> b[i];
	for (i = 0; i < M; i++) {
		if (aaa[b[i]] == 1) {
			cout << yes << ln;
			cout << 1 << bb << b[i] << ln;
			return;
		}
	}
	cout << no << ln;
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