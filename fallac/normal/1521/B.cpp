/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

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
	vector<ll> v;
	v.resize(N + 1);
	ll i;
	for (i = 1; i <= N; i++) cin >> v[i];
	ll mn, x;
	mn = INT64_MAX;
	for (i = 1; i <= N; i++) if (mn > v[i]) mn = v[i], x = i;
	cout << N - 1 << ln;
	for (i = x + 1; i <= N; i++) cout << x << bb << i << bb << mn << bb << mn + i - x << ln;
	for (i = x - 1; i >= 1; i--) cout << x << bb << i << bb << mn << bb << mn + x - i << ln;
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