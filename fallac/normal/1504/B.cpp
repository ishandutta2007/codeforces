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
	cin >> N;
	string a, b;
	cin >> a >> b;
	ll i;
	ll s0, s1;
	s0 = s1 = 0;
	vector<ll> num0, num1;
	num0.resize(N + 1);
	num1.resize(N + 1);
	if (a[0] == '0') num0[0] = 1;
	else num1[0] = 1;
	for (i = 1; i < N; i++) {
		num0[i] = num0[i - 1];
		num1[i] = num1[i - 1];
		if (a[i] == '0') num0[i]++;
		else num1[i]++;
	}
	vector<ll> v;
	v.push_back(-1);
	for (i = 0; i < N; i++) if (num0[i] == num1[i]) v.push_back(i);
	if (v.size() == 1) {
		if (a == b) cout << yes << ln;
		else cout << no << ln;
		return;
	}
	for (i = 1; i < v.size(); i++) {
		ll c = 0;
		bool check = true;
		if (a[v[i]] == b[v[i]]) c = 1;
		for (ll k = v[i - 1] + 1; k <= v[i]; k++) {
			if (c) {
				if (a[k] != b[k]) {
					check = false;
					break;
				}
			}
			else {
				if (a[k] == b[k]) {
					check = false;
					break;
				}
			}
		}
		if (!check) {
			cout << no << ln;
			return;
		}
	}
	for (i = v[v.size() - 1] + 1; i < N; i++) {
		if (a[i] != b[i]) {
			cout << no << ln;
			return;
		}	
	}
	cout << yes << ln;
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