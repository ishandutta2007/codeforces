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
	ll i;
	vector<ll> K(N + 1), H(N + 1);
	for (i = 1; i <= N; i++) cin >> K[i];
	for (i = 1; i <= N; i++) cin >> H[i];
	ll ans = 0;
	ll pv = 0;
	ll mn = INT_FAST64_MAX;
	for (i = N; i >= 1; i--) {
		if (mn > K[i] - H[i]) mn = K[i] - H[i];
		else K[i] = H[i] = -1;
	}
	ll pvi = 0;
	for (i = 1; i <= N; i++) {
		if (K[i] == -1) continue;
		ll dt = K[i] - K[pvi];
		if (dt >= H[i]) {
			ans += H[i] * (H[i] + 1) / 2;
			pv = H[i];
		}
		else {
			ans += dt * pv + dt * (dt + 1) / 2;
			pv += dt;
		}
		pvi = i;
	}
	cout << ans << ln;
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