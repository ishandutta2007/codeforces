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
	ll K;
	cin >> N >> K;
	vector<ll> a;
	a.push_back(0);
	int i, x;
	for (i = 1; i <= N; i++) cin >> x, a.push_back(x);
	if (K >= N) {
		ll ans = (K * 2 - N - 1) * N / 2;
		for (auto v : a) ans += v;
		cout << ans << ln;
		return;
	}
	else {
		ll ans = K * (K - 1) / 2;
		for (i = 1; i <= N; i++) a[i] += a[i - 1];
		ll mx = 0;
		for (i = K; i <= N; i++) {
			mx = max(mx, a[i] - a[i - K]);
		}
		cout << ans + mx << ln;
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