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

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

vector<ll> va[MAX];

void solve() {
	ll N;
	cin >> N;
	ll i;
	ll a;
	for (i = 0; i <= N; i++) va[i].clear();
	for (i = 1; i <= N; i++) cin >> a, va[a].push_back(i);
	vector<ll> ans;
	ll ptr = 1;
	ll k = 0;
	ll st = 1;
	while (ptr <= N) {
		ll ind = lower_bound(va[k].begin(), va[k].end(), st) - va[k].begin();
		if (ind == va[k].size()) {
			ptr++;
			st = ptr;
			ans.push_back(k);
			k = 0;
		}
		else ptr = max(ptr, va[k][ind]), k++;
	}
	cout << ans.size() << ln;
	for (auto v : ans) cout << v << bb;
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