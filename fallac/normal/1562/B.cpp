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

#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

bool chk(ll n) {
	ll i;
	if (n == 1) return false;
	for (i = 2; i * i <= n; i++) {
		if (n % i) continue;
		return false;
	}
	return true;
}

void solve() {
	ll t;
	cin >> t;
	string s;
	cin >> s;
	vector<ll> v;
	ll i;
	for (i = 0; i < s.size() / 2; i++) swap(s[i], s[s.size() - i - 1]);
	for (i = 0; i < t; i++) v.push_back(s[i] - '0');
	ll j, k;
	i = j = k = -1;
	for (i = 0; i < t; i++) {
		if (!chk(v[i])) {
			cout << 1 << ln;
			goto out;
		}
	}
	for (i = 0; i < t; i++) {
		for (j = i + 1; j < t; j++) {
			if (!chk(10 * v[j] + v[i])) {
				cout << 2 << ln;
				goto out;
			}
		}
	}
	for (i = 0; i < t; i++) {
		for (j = i + 1; j < t; j++) {
			for (k = j + 1; k < t; k++) {
				if (!chk(100 * v[k] + 10 * v[j] + v[i])) {
					cout << 3 << ln;
					goto out;
				}
			}
		}
	}
out:
	ll l;
	for (l = t - 1; l >= 0; l--) {
		if (l == i || l == j || l == k) cout << v[l];
	}
	cout << ln;
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