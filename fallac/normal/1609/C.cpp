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

void solve() {
	ll N;
	cin >> N;
	ll i;
	vector<ll> arr;
	ll e;
	cin >> e;
	ll a;
	ll cnt = 0;
	for (i = 1; i <= N; i++) {
		cin >> a;
		ll j;
		ll c = 1;
		ll aa = a;
		for (j = 2; j * j <= a; j++) {
			if (a % j == 0 && j != a) {
				c = 0;
				break;
			}
		}
		if (c == 0) c = 2;
		if (aa == 1) c = 0;
		arr.push_back(c);
		if (c == 1) cnt--;
	}
	arr.push_back(1);
	vector<vector<ll>> v(e);
	for (i = 0; i < N; i++) v[i % e].push_back(arr[i]);
	for (i = 0; i < e; i++) {
		vector<ll> sv;
		ll j;
		ll pv = 0;
		map<ll, ll> mp;
		mp[0]++;
		for (j = 0; j < v[i].size(); j++) sv.push_back(pv + v[i][j]), mp[sv[j]]++, pv = sv[j];
		for (j = 0; j < sv[v[i].size() - 1]; j++) cnt += mp[j] * mp[j + 1];
	}
	cout << cnt << ln;
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