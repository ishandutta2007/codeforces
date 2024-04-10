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

ll arr[MAX];

void solve() {
	ll N, K;
	cin >> N >> K;
	ll i;
	set<ll> s;
	ll m = 0;
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
		m = max(arr[i], m);
		s.insert(arr[i]);
	}
	if (K == 0) {
		cout << N << ln;
		return;
	}
	sort(arr + 1, arr + N + 1);
	ll mex = 0;
	set<ll>::iterator it;
	for (it = s.begin(); it != s.end(); it++) {
		if (*it == mex) mex++;
		else break;
	}
	if (mex > m) {
		cout << m + K + 1 << ln;
		return;
	}
	if (s.find((mex + m + 1) / 2) == s.end()) cout << N + 1 << ln;
	else cout << N << ln;
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