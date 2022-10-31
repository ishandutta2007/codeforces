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
#define bbb ' '
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
	string s;
	cin >> s;
	vector<ll> v, a;
	v.resize(11);
	a.resize(11);
	ll i;
	for (i = 0; i < 10; i++) v[i + 1] = (s[i] == '1' ? 1 : (s[i] == '0' ? 0 : -1));
	a = v;
	//A
	ll ans = 10;
	for (i = 1; i <= 10; i++) {
		if (i % 2) {
			if (v[i] == -1) v[i] = 1;
		}
		else {
			if (v[i] == -1) v[i] = 0;
		}
		ll j;
		ll a, b, aa, bb;
		a = b = aa = bb = 0;
		for (j = 1; j <= i; j++) {
			if (j % 2) {
				if (v[j]) a++;
			}
			else {
				if (v[j]) b++;
			}
		}
		for (j = i + 1; j <= 10; j++) {
			if (j % 2) aa++;
			else bb++;
		}
		if ((b + bb) < a) {
			ans = min(ans, i);
			break;
		}
	}
	v = a;
	for (i = 1; i <= 10; i++) {
		if (i % 2) {
			if (v[i] == -1) v[i] = 0;
		}
		else {
			if (v[i] == -1) v[i] = 1;
		}
		ll j;
		ll a, b, aa, bb;
		a = b = aa = bb = 0;
		for (j = 1; j <= i; j++) {
			if (j % 2) {
				if (v[j]) a++;
			}
			else {
				if (v[j]) b++;
			}
		}
		for (j = i + 1; j <= 10; j++) {
			if (j % 2) aa++;
			else bb++;
		}
		if ((a + aa) < b) {
			ans = min(ans, i);
			break;
		}
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