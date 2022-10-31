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

void solve() {
	ll N;
	cin >> N;
	ll i;
	vector<pll> arr(N + 1, pll(N + 1, 0));
	ll x;
	for (i = 1; i <= N; i++) {
		cin >> x;
		arr[x].first = min(arr[x].first, i);
		arr[x].second = i;
	}
	for (i = 0; i <= N; i++) if (arr[i].first + 2 > arr[i].second) arr[i].first = INF;
	sort(arr.begin(), arr.end());
	while (arr.size() && arr.back().first == INF) arr.pop_back();
	if (arr.empty()) {
		cout << 0 << ln;
		return;
	}
	ll mx = 0;
	for (i = 0; i < arr.size(); i++) {
		if (mx < arr[i].second) mx = arr[i].second;
		else arr[i].first = INF;
	}
	sort(arr.begin(), arr.end());
	while (arr.size() && arr.back().first == INF) arr.pop_back();
	if (arr.empty()) {
		cout << 0 << ln;
		return;
	}
	N = arr.size();
	ll ep = -1;
	ll ans = 0;
	for (i = 0; i < N; i++) {
		if (i != N - 1 && arr[i + 1].first <= ep && ep <= arr[i + 1].second) continue;
		if (arr[i].first <= ep && ep <= arr[i].second) {
			ans += arr[i].second - ep - 1;
			ep = arr[i].second;
		}
		else {
			ans += arr[i].second - arr[i].first - 1;
			ep = arr[i].second;
		}
	}
	cout << ans << ln;
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