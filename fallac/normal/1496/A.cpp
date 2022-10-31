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


void solve() {
	ll N, K;
	cin >> N >> K;
	string s;
	cin >> s;
	ll i, c=1;
	for (i = 0; i < K; i++) {
		if (s[i] != s[N - i - 1]) c = 0;
	}
	if (2 * K < N && c) cout << yes << ln;
	else cout << no << ln;
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