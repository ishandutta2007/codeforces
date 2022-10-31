/*

*/

#include <bits/stdc++.h>
#include <cassert>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx,avx2,fma")

using namespace std;
typedef long long ll;
typedef pair<ll, ll> pll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 401010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll arr[MAX];
ll rev[MAX];

vector<pll> qv;

void f(ll i, ll j) {
	qv.emplace_back(i, j);
	ll x, y;
	x = arr[i];
	y = arr[j];
	swap(arr[i], arr[j]);
	swap(rev[x], rev[y]);
}

void solve() {
	ll N;
	cin >> N;
	ll i;
	for (i = 1; i <= N; i++) cin >> arr[i], rev[arr[i]] = i;
	if (rev[1] != 1) {
		ll loc = rev[1];
		if (loc <= N / 2) {
			f(loc, N);
			f(1, N);
		}
		else f(1, loc);
	}
	for (i = 2; i <= N / 2; i++) {
		ll loc = rev[i];
		if (loc <= N / 2) {
			if (loc == i) continue;
			f(loc, N);
			f(N, i);
		}
		else {
			f(loc, 1);
			f(i, N);
			f(1, N);
			f(i, N);
			f(1, loc);
		}
	}
	for (i = N / 2 + 1; i <= N; i++) {
		ll loc = rev[i];
		if (loc == i) continue;
		f(loc, 1);
		f(1, i);
		f(1, loc);
	}
	cout << qv.size() << ln;
	for (auto q : qv) cout << q.first << bb << q.second << ln;
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