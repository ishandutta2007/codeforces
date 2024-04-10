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
	vector<ll> v(N + 1), pr(N + 2), su(N + 2);
	for (i = 1; i <= N; i++) cin >> v[i];
	for (i = 1; i <= N; i++) pr[i] = max(pr[i - 1], v[i]);
	su[N + 1] = 1000000001;
	for (i = N; i >= 1; i--) su[i] = min(su[i + 1], v[i]);
	for (i = 1; i < N; i++) {
		if (pr[i] > su[i + 1]) {
			cout << "YES" << ln;
			return;
		}
	}
	cout << "NO" << ln;
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