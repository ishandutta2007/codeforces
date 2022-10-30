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
	vector<pll> v;
	ll i;
	ll a;
	for (i = 1; i <= N; i++) {
		cin >> a;
		v.push_back({ -a, i });
	}
	sort(v.begin(), v.end());
	vector<ll> ans(N + 1);
	ll cnt = 2;
	ans[0] = 0;
	ll m = 1;
	ll s = 0;
	for (i = 0; i < N; i++) {
		ans[v[i].second] = cnt / 2;
		ans[v[i].second] *= m;
		m *= -1;
		cnt++;
		s += abs(ans[v[i].second] * v[i].first) * 2;
	}
	cout << s << ln;
	for (i = 0; i <= N; i++) cout << ans[i] << bb;
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