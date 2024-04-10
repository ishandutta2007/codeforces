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
#define MOD 1000000007
//#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll cnt[6000000];
ll dp[6000000];

void solve() {
	ll N;
	cin >> N;
	ll i;
	ll a;
	for (i = 1; i <= N; i++) {
		cin >> a;
		vector<ll> pv;
		ll j;
		ll x = a;
		for (j = 2; j * j <= x; j++) {
			while (x % j == 0) x /= j, pv.push_back(j);
		}
		if (x != 1) pv.push_back(x);
		vector<ll> plist;
		plist.push_back(1);
		for (auto p : pv) {
			ll s = plist.size();
			for (j = 0; j < s; j++) plist.push_back(plist[j]);
			for (j = 0; j < s; j++) plist[j] *= p;
			sort(plist.begin(), plist.end());
			plist.erase(unique(plist.begin(), plist.end()), plist.end());
		}
		for (auto p : plist) cnt[p]++;
	}
	dp[1] = N;
	ll ans = N, j;
	for (i = 2; i <= 5000000; i++) {
		if (cnt[i] == 0) {
			dp[i] = N;
			continue;
		}
		ll j;
		ll x = i;
		vector<ll> pv;
		for (j = 2; j * j <= x; j++) {
			while (x % j == 0) x /= j, pv.push_back(j);
		}
		if (x != 1) pv.push_back(x);
		vector<ll> plist;
		plist.push_back(1);
		for (auto p : pv) {
			ll s = plist.size();
			for (j = 0; j < s; j++) plist.push_back(plist[j]);
			for (j = 0; j < s; j++) plist[j] *= p;
			sort(plist.begin(), plist.end());
			plist.erase(unique(plist.begin(), plist.end()), plist.end());
		}
		ll a;
		for (auto ss : plist) {
			if (ss == i) continue;
			a = dp[ss] + (i - ss) * cnt[i];
			dp[i] = max(dp[i], a);
		}
		ans = max(ans, dp[i]);
	}
	cout << ans << Ln;
}

void init() {
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	init();
	while (T--) {
		solve();
	}
}