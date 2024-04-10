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
	vector<pair<pll, ll>> arr(N);
	vector<ll> ans(N);
	ll i;
	for (i = 0; i < N; i++) cin >> arr[i].first.first;
	for (i = 0; i < N; i++) cin >> arr[i].first.second;
	for (i = 0; i < N; i++) arr[i].second = i;
	sort(arr.begin(), arr.end());
	ans[arr[N - 1].second] = 1;
	ll b = arr[N - 1].first.second;
	vector<ll> mb(N);
	mb[0] = arr[0].first.second;
	for (i = 1; i < N; i++) mb[i] = max(mb[i - 1], arr[i].first.second);
	for (i = N - 2; i >= 0; i--) {
		if (mb[i] > b) {
			ans[arr[i].second] = 1;
			b = min(arr[i].first.second, b);
		}
	}
	for (i = 0; i < N; i++) cout << ans[i];
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