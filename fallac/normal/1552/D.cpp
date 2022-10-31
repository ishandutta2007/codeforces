/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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
#define MOD 100000009
#define INF 1000000000000

//#define vv vector
#define pq priority_queue
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

void solve() {
	ll N;
	cin >> N;
	vector<ll> v;
	vector<ll> dp;
	ll i;
	v.resize(N + 1);
	for (i = 1; i <= N; i++) {
		cin >> v[i];
		v[i] = abs(v[i]);
	}
	if (N == 1) {
		if (v[1] == 0) cout << yes << ln;
		else cout << no << ln;
		return;
	}
	ll K = 1 << N;
	dp.resize(K + 1);
	ll j;
	for (i = 0; i < K; i++) {
		for (j = 0; j < N; j++) {
			if ((i >> j) & 1) dp[i] += v[j + 1];
		}
	}
	for (i = 1; i < K; i++) {
		if (dp[i] == 0) {
			cout << yes << ln;
			return;
		}
		for (j = i + 1; j < K; j++) {
			if (dp[i] == dp[j]) {
				cout << yes << ln;
				return;
			}
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