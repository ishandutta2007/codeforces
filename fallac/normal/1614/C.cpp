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

ll pow2[MAX];
pair<pll, ll> qv[MAX];

void solve() {
	ll N, M;
	cin >> N >> M;
	ll i;
	for (i = 1; i <= M; i++) cin >> qv[i].first.first >> qv[i].first.second >> qv[i].second;
	ll k;
	ll ans = 0;
	for (k = 0; k < 31; k++) {
		vector<ll> sumv(N + 10);
		ll x = 1LL << k;
		for (i = 1; i <= M; i++) {
			if (qv[i].second & x) continue;
			sumv[qv[i].first.first]++;
			sumv[qv[i].first.second + 1]--;
		}
		ll s = 0;
		ll num = N;
		for (i = 1; i <= N; i++) {
			s += sumv[i];
			if (s) num--;
		}
		if (num) ans += ((((1LL << k) * pow2[max(0LL, num - 1)]) % MOD) * pow2[N - num]);
		ans %= MOD;
	}
	cout << ans << ln;
}

void init() {
	ll i;
	pow2[0] = 1;
	for (i = 1; i < MAX; i++) {
		pow2[i] = (pow2[i - 1] * 2) % MOD;
	}
}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	tmode;
	init();
	while (T--) {
		solve();
	}
}