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
	string s;
	cin >> s;
	ll N = s.size();
	vector<ll> v;
	ll i;
	v.resize(N + 1);
	for (i = 0; s[i]; i++) {
		if (s[i] == '1') v[i + 1] = 1;
		else if (s[i] == '0') v[i + 1] = 0;
		else v[i + 1] = -1;
	}
	ll j = 1;
	ll ans = 0;
	ll num = 0;
	ll curr = -1;
	if (v[1] != -1) num = 1, curr = v[1];
	for (i = 1; i <= N; i++) {
		if (i > j) {
			curr = v[i];
			j = i;
			if (v[i] != -1) num = 1;
		}
		for (j; j <= N - 1; j++) {
			ll n = j + 1;
			if (curr == -1) curr = v[n];
			else {
				if (curr != v[n]) curr = 1 - curr;
				else break;
			}
			if (v[n] != -1) num++;
		}
		ans += j - i + 1;
		if (v[i] != -1) num--;
		if (!num) curr = -1;
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