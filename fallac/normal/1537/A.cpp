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
	v.resize(N + 1);
	ll sum = 0;
	for (i = 1; i <= N; i++) {
		cin >> v[i];
		sum += v[i];
	}
	if (sum == N) {
		cout << 0 << ln;
		return;
	}
	if (sum < N) {
		cout << 1 << ln;
		return;
	}
	cout << sum - N << ln;
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