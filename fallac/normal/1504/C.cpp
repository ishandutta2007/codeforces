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
	string a;
	cin >> a;
	if (a[0] == '0' || a[N - 1] == '0') {
		cout << no << ln;
		return;
	}
	ll i;
	vector<ll> v;
	for (i = 0; i < N; i++) if (a[i] == '1') v.push_back(i);
	ll cnt = 0;
	for (i = 1; i < v.size(); i++) if ((v[i] - v[i - 1] + 1) % 2) cnt++;
	if (cnt % 2) {
		cout << no << ln;
		return;
	}
	if (v.size() % 2) {
		cout << no << ln;
		return;
	}
	vector<ll> r1, r2;
	r1.resize(N);
	r2.resize(N);
	ll cnt1, cnt2;
	cnt1 = cnt2 = 0;
	for (i = 1; i < v.size(); i++) {
		ll k;
		if ((v[i] - v[i - 1] + 1) % 2) {
			for (k = v[i - 1] + 1; k <= v[i] - 2; k++) {
				r1[k] = -1;
				r2[k] = 1;
				r1[k + 1] = 1;
				r2[k + 1] = -1;
				k++;
			}
			if (cnt1 > cnt2) r1[v[i] - 1] = -1, r2[v[i] - 1] = 1, cnt1--, cnt2++;
			else r1[v[i] - 1] = 1, r2[v[i] - 1] = -1, cnt1++, cnt2--;
		}
		else {
			for (k = v[i - 1] + 1; k <= v[i] - 1; k++) {
				r1[k] = -1;
				r2[k] = 1;
				r1[k + 1] = 1;
				r2[k + 1] = -1;
				k++;
			}
		}
	}
	for (i = 0; i < v.size() / 2; i++) r1[v[i]] = r2[v[i]] = 1;
	for (; i < v.size(); i++) r1[v[i]] = r2[v[i]] = -1;
	cout << yes << ln;
	for (i = 0; i < N; i++) {
		if (r1[i] == 1) cout << '(';
		else cout << ')';
	}
	cout << ln;
	for (i = 0; i < N; i++) {
		if (r2[i] == 1) cout << '(';
		else cout << ')';
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