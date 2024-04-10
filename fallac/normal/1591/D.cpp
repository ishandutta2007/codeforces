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

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 100000000000000

#define yes "YES"
#define no "NO"

//var

//

void solve() {
	ll N;
	cin >> N;
	ll i;
	vector<ll> v(N + 1);
	vector<pll> pv;
	for (i = 1; i <= N; i++) cin >> v[i], pv.emplace_back(v[i], i);
	sort(pv.begin(), pv.end());
	for (i = 0; i < N - 1; i++) {
		if (pv[i].first == pv[i + 1].first) {
			cout << yes << ln;
			return;
		}
	}
	vector<ll> ne(N + 1), vis(N + 1);
	for (i = 0; i < N; i++) ne[i + 1] = pv[i].second;
	ll chk = 1;
	for (i = 1; i <= N; i++) {
		if (vis[i] == 0) {
			ll v = i;
			ll cnt = 0;
			while (!vis[v]) {
				cnt++;
				vis[v] = 1;
				v = ne[v];
			}
			if (cnt % 2 == 0) chk = !chk;
		}
	}
	if (chk) cout << yes << ln;
	else cout << no << Ln;
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