/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

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
ll N;
//

ll query(ll t, ll i, ll j, ll x) {
	cout << '?' << bb << t << bb << i << bb << j << bb << x << ln;
	cout.flush();
	ll a;
	cin >> a;
	cout.flush();
	return a;
}

pair<ll, ll> guess(ll i, ll j) {
	ll res2 = query(2, i, j, 1);
	if (res2 == 1) return { 1, query(1, i, j, N - 1) };
	if (res2 == 2 && query(1, i, j, 1) == 1) return { query(1, j, i, N - 1), 1 };
	ll p = res2; //min
	ll q = query(1, i, j, N - 1);
	if (q == N) return { p, N };
	else if (q == N - 1 && query(2, i, j, N - 1) == N) return { N, p };
	ll r = query(1, i, j, min(p, q));
	if (r == p + 1) return { p, q };
	else return { q, p };
}

void solve() {
	cin >> N;
	vector<ll> ans;
	ans.resize(N + 1);
	ll i;
	for (i = 1; i <= N - 1; i += 2) {
		pair<ll, ll> p = guess(i, i + 1);
		ans[i] = p.first;
		ans[i + 1] = p.second;
	}
	if (N % 2) {
		pair<ll, ll> p = guess(N - 1, N);
		ans[N - 1] = p.first;
		ans[N] = p.second;
	}
	cout << '!';
	cout.flush();
	for (i = 1; i <= N; i++) cout << bb << ans[i];
	cout.flush();
	cout << ln;
	cout.flush();
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