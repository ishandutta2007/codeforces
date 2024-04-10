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

ll gcd(ll a, ll b) {
	while (b) b %= a ^= b ^= a ^= b;
	return a;
}

void solve() {
	ll N;
	cin >> N;
	ll i;
	vector<ll> o, e;
	for (i = 1; i <= N; i++) {
		ll a;
		cin >> a;
		if (a % 2) o.push_back(a);
		else e.push_back(a);
	}
	ll j;
	ll cnt = 0;
	for (i = 0; i < e.size(); i++) {
		for (j = i + 1; j < e.size(); j++) {
			cnt++;
		}
	}
	for (i = 0; i < e.size(); i++) {
		for (j = 0; j < o.size(); j++) {
			cnt++;
		}
	}
	for (i = 0; i < o.size(); i++) {
		for (j = i + 1; j < o.size(); j++) {
			if (gcd(o[i], 2 * o[j]) > 1) cnt++;
		}
	}
	cout << cnt << ln;
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