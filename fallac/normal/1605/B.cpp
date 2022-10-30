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
#define INF 1000000000000

#define yes "YES"
#define no "NO"

//var

//

void solve() {
	ll N;
	cin >> N;
	string s;
	cin >> s;
	vector<ll> v;
	ll i;
	for (i = 0; i < N; i++) v.push_back(s[i] - '0');
	vector<vector<ll>> vv;
	while (1) {
		ll c = 0;
		for (i = 1; i < N; i++) {
			if (v[i - 1] > v[i]) c = 1;
		}
		if (c == 0) break;
		vector<ll> a, b;
		for (i = 0; i < N; i++) if (s[i] == '1') a.push_back(i);
		for (i = N - 1; i >= 0; i--) if (s[i] == '0') b.push_back(i);
		ll k;
		ll aaa = min(a.size(), b.size());
		for (k = 0; k < aaa; k++) {
			if (a[k] >= b[k]) break;
		}
		vector<ll> asdf;
		for (i = 0; i < k; i++) {
			asdf.push_back(a[i]);
			asdf.push_back(b[i]);
		}
		sort(asdf.begin(), asdf.end());
		vv.push_back(asdf);
		for (i = 0; i < k; i++) v[asdf[asdf.size() - 1]] = 1, asdf.pop_back();
		for (i = 0; i < k; i++) v[asdf[asdf.size() - 1]] = 0, asdf.pop_back();
	}
	cout << vv.size() << ln;
	for (i = 0; i < vv.size(); i++) {
		cout << vv[i].size() << bb;
		for (ll j = 0; j < vv[i].size(); j++) cout << vv[i][j] + 1 << bb;
		cout << ln;
	}
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