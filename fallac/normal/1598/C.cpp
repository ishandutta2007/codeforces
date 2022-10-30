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
	ll N;
	cin >> N;
	vector<ll> v(N);
	ll i;
	ll sum = 0;
	map<ll, ll> mp;
	for (i = 0; i < N; i++) cin >> v[i], sum += v[i], mp[v[i]]++;
	sum *= 2;
	if (sum % N) {
		cout << 0 << ln;
		return;
	}
	sum /= N;
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	ll ans = 0;
	for (i = 0; i < v.size(); i++) {
		ll k = sum - v[i];
		if (k < v[i]) break;
		if (k == v[i]) ans += mp[v[i]] * (mp[v[i]] - 1) / 2;
		else if (mp[k]) ans += mp[v[i]] * mp[k];
	}
	cout << ans << ln;
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