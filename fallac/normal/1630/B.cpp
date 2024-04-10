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

ll arr[MAX];
vector<pll> ans;

void calc(ll l, ll r, ll x, ll y, ll K) {
	if (K == 1) {
		ans.emplace_back(l, r);
		return;
	}
	ll left = K / 2;
	ll i;
	ll cnt = 0;
	for (i = l; i <= r; i++) {
		if (x <= arr[i] && arr[i] <= y) cnt++;
		else cnt--;
		if (cnt == left) break;
	}
	calc(l, i, x, y, left);
	calc(i + 1, r, x, y, K - left);
}

void solve() {
	ans.clear();
	ll N, K;
	cin >> N >> K;
	vector<ll> v(N + 1);
	ll i, a;
	for (i = 1; i <= N; i++) cin >> arr[i], v[arr[i]]++;
	ll lim = (N + K + 1) / 2;
	ll x, y;
	ll sum = 0;
	y = 1;
	ll mx, my;
	mx = my = 0;
	ll mn = N + 10;
	for (x = 1; x <= N; x++) {
		while (y <= N && sum < lim) {
			sum += v[y];
			y++;
		}
		if (sum >= lim && mn > y - 1 - x) {
			mn = y - 1 - x;
			mx = x;
			my = y - 1;
		}
		sum -= v[x];
	}
	calc(1, N, mx, my, K);
	cout << mx << bb << my << ln;
	sort(ans.begin(), ans.end());
	for (i = 0; i < K; i++) cout << ans[i].first << bb << ans[i].second << Ln;
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