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

#define MAX 601010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000000009

#define yes "YES"
#define no "NO"

ll arr[MAX];

void solve() {
	ll N;
	cin >> N;
	ll i, j;
	for (i = 1; i <= N; i++) cin >> arr[i];
	ll a, b;
	ll ans = -1;
	for (a = 0; a <= 3; a++) {
		for (b = 0; b <= 3; b++) {
			vector<ll> v;
			for (i = 0; i <= a; i++) {
				for (j = 0; j <= b; j++) {
					v.push_back(i + 2 * j);
				}
			}
			sort(v.begin(), v.end());
			v.erase(unique(v.begin(), v.end()), v.end());
			ll M = v.size();
			ll asdf = 0;
			for (i = 1; i <= N; i++) {
				ll mn = 100000000000000000;
				for (j = 0; j < M; j++) {
					if (arr[i] - v[j] >= 0 && (arr[i] - v[j]) % 3 == 0) mn = min(mn, (arr[i] - v[j]) / 3);
				}
				asdf = max(asdf, mn);
			}
			asdf += a + b;
			if (ans == -1) ans = asdf;
			ans = min(ans, asdf);
		}
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