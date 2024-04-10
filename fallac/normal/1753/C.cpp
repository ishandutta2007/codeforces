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
typedef pair<int, int> pii;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 201010
//#define MOD 100000007
//#define MOD 100000009
#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll mpow(ll x, ll y) {
	if (!y) return 1;
	ll res = mpow(x, y >> 1);
	res *= res;
	res %= MOD;
	if (y & 1) res *= x, res %= MOD;
	return res;
}

ll inv(ll x) {
	return mpow(x, MOD - 2);
}

int arr[MAX];

void solve() {
	ll N;
	cin >> N;
	int i;
	int z = N, sum = 0;
	for (i = 1; i <= N; i++) cin >> arr[i], z -= arr[i];
	for (i = 1; i <= z; i++) sum += arr[i];
	ll dp = 0;
	ll M = N * (N - 1);
	M >>= 1;
	M %= MOD;
	for (i = 1; i <= sum; i++) {
		dp += M * inv((1ll * i * i) % MOD);
		dp %= MOD;
	}
	cout << dp << Ln;
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