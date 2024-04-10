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
	string s;
	cin >> s;
	ll i;
	bool c = true;
	ll sz = s.size();
	for (i = 0; s[i]; i++) if (s[sz - i - 1] != 'a') break;
	if (i == sz) {
		cout << no << ln;
		return;
	}
	else {
		cout << yes << ln;
		ll x = i;
		for (i = 0; i < x; i++) cout << s[i];
		cout << 'a';
		for (i = x; i < sz; i++) cout << s[i];
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