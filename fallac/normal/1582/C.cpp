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

bool chk(vector<ll>& v) {
	ll i;
	for (i = 0; i < v.size(); i++) if (v[i] != v[v.size() - i - 1]) return false;
	return true;
}

void solve() {
	ll N;
	string s;
	cin >> N;
	cin >> s;
	ll c;
	ll mn = INF;
	vector<ll> v(N);
	ll i;
	for (i = 0; i < N; i++) v[i] = s[i] - 'a';
	for (c = 0; c < 26; c++) {
		vector<ll> v1;
		vector<ll> cv(N);
		for (i = 0; i < N; i++) {
			if (v[i] == c) cv[v1.size()]++;
			else v1.push_back(v[i]);
		}
		if (chk(v1)) {
			ll ans = 0;
			if (v1.size() == N) {
				cout << 0 << ln;
				return;
			}
			for (i = 0; i <= v1.size() / 2; i++) ans += (2 * i == v1.size() ? 1 : 2) * min(cv[i], cv[v1.size() - i]);
			mn = min(N - (ans + v1.size()), mn);
		}
	}
	if (mn < INF) cout << mn << ln;
	else cout << -1 << ln;
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