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

#define MAX 301010
#define MOD 100000009
#define INF 1000000000000000

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define yes "YES"
#define no "NO"

ll arr[MAX];
ll chk[MAX];

void solve() {
	ll N;
	cin >> N;
	ll i;
	for (i = 0; i <= 20010; i++) chk[i] = 0;
	for (i = 1; i <= N; i++) cin >> arr[i];
	if (N % 2 == 0) {
		for (i = 1; i <= N / 2; i++) {
			ll a, b;
			a = 2 * i - 1;
			b = i * 2;
			cout << -arr[b] << bb << arr[a] << bb;
		}
		cout << Ln;
		return;
	}
	ll p, q;
	p = q = -1;
	for (i = 1; i <= N; i++) {
		if (chk[arr[i] + 10000]) {
			p = chk[arr[i] + 10000];
			q = i;
			break;
		}
		chk[arr[i] + 10000] = i;
	}
	vector<ll> B(N + 1);
	vector<pair<ll, ll>> vp;
	for (i = 1; i <= N; i++) vp.emplace_back(arr[i], i);
	sort(vp.begin(), vp.end());
	if (p == -1 || N <= 60000) {
		for (i = 1; i + 2 < N; i += 2) {
			B[i] = -arr[i + 1];
			B[i + 1] = arr[i];
		}
		ll a, b, c;
		a = N - 2;
		b = N - 1;
		c = N;
		B[a] = arr[b] * arr[c];
		B[b] = -2 * arr[a] * arr[c];
		B[c] = arr[a] * arr[b];
		for (i = 1; i <= N; i++) cout << B[i] << bb;
		cout << ln;
		return;
	}
	if (q < p) swap(p, q);
	ll asdf = 1;
	for (i = 0; i < N; i += 2) {
		if (vp[i].first == vp[i + 1].first) {
			if (asdf) {
				B[vp[i].second] = -2 * vp[i + 2].first;
				B[vp[i + 1].second] = vp[i + 2].first;
				B[vp[i + 2].second] = vp[i + 1].first;
				i++;
				asdf = 0;
			}
			else {
				B[vp[i].second] = -1;
				B[vp[i + 1].second] = 1;
			}
		}
		else {
			B[vp[i].second] = vp[i + 1].first;
			B[vp[i + 1].second] = -vp[i].first;
		}
	}
	for (i = 1; i <= N; i++) cout << B[i] << bb;
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