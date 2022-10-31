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
	vector<ll> v(N + 1);
	for (i = 1; i <= N; i++) cin >> v[i];
	ll ans = 0;
	ll cnt = 0;
	ll c = 0;
	ll ccnt = 0;
	for (i = 2; i < N; i++) {
		if (v[i] >= 2) c = 1;
		ccnt += v[i];
	}
	if (ccnt % 2 && N == 3) {
		cout << -1 << ln;
		return;
	}
	for (i = 2; i < N; i++) {
		if (v[i] % 2) ans += v[i] / 2, v[i] = 1;
		else ans += v[i] / 2 - 1, v[i] = 2;		
	}
	if (!c) {
		cout << -1 << ln;
		return;
	}
	cout << ans + N - 2 << ln;
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