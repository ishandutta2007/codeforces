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

#define MAX 1010100
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll arr[MAX];

bool cmp(pll p1, pll p2) {
	if (p1.first != p2.first) return p1.first < p2.first;
	else return p1.second > p2.second;
}

void solve() {
	ll N;
	cin >> N;
	ll i;
	vector<vector<ll>> v(8192);
	vector<ll> chk(8192, INF);
	vector<ll> ans(8192);
	for (i = 1; i <= N; i++) cin >> arr[i], v[arr[i]].push_back(i);
	chk[0] = 0;
	v[0].push_back(0);
	for (i = 0; i <= 5000; i++) {
		ll j;
		if (v[i].empty()) continue;
		vector<ll> nw(8192, INF);
		nw[0] = 0;
		for (j = 0; j < 8192; j++) {
			ll x = i ^ j;
			ll ind = upper_bound(v[i].begin(), v[i].end(), chk[x]) - v[i].begin();
			if (ind == v[i].size()) continue;
			ans[j] = 1;
			nw[j] = min(nw[j], v[i][ind]);
		}
		for (j = 0; j < 8192; j++) chk[j] = min(chk[j], nw[j]);
	}
	ll cnt = 0;
	ans[0] = 1;
	for (i = 0; i < 8192; i++) cnt += ans[i];
	cout << cnt << ln;
	for (i = 0; i < 8192; i++) if (ans[i]) cout << i << bb;
	cout << ln;
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