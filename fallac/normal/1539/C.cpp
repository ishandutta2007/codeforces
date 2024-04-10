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
	ll K, X;
	cin >> N >> K >> X;
	ll i;
	vector<ll> v;
	for (i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		v.push_back(a);
	}
	sort(v.begin(), v.end());
	ll cnt = 1;
	vector<ll> sub;
	for (i = 1; i < N; i++) {
		if (v[i] - v[i - 1] > X) cnt++, sub.push_back(((v[i] - v[i - 1] - 1) / X));
	}
	sort(sub.begin(), sub.end());
	for (auto asdf : sub) {
		if (asdf <= K) K -= asdf, cnt--;
		else break;
	}
	cout << cnt << ln;
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