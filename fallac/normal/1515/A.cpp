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

void NO() {
	cout << no << ln;
	exit(0);
}

void solve() {
	ll N, X;
	cin >> N >> X;
	ll i;
	vector<ll> v;
	v.resize(N);
	ll sum = 0;
	for (i = 0; i < N; i++) cin >> v[i], sum += v[i];
	if (sum == X) cout << no << ln;
	else {
		cout << yes << ln;
		sort(v.begin(), v.end());
		sum = 0;
		for (i = 0; i < N; i++) {
			sum += v[i];
			if (sum == X) swap(v[i], v[i + 1]);
		}
		for (i = 0; i < N; i++) cout << v[i] << bb;
		cout << ln;
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