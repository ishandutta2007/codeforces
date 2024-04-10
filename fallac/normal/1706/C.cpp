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

#define MAX 101010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll H[MAX];
ll pr[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) cin >> H[i];
	if (N <= 4) {
		ll ans = 1e17;
		for (i = 2; i <= N - 1; i++) ans = min(ans, max(0ll, max(H[i + 1], H[i - 1]) - H[i] + 1));
		cout << ans << ln;
	}
	else {
		for (i = 2; i < N; i += 2) pr[i] = pr[i - 2] + max(0ll, max(H[i + 1], H[i - 1]) - H[i] + 1);
		if (N % 2) cout << pr[N - 1] << ln;
		else {
			ll ans = 1e17;
			ll su = 0;
			for (i = N - 1; i >= 3; i -= 2) {
				su += max(0ll, max(H[i + 1], H[i - 1]) - H[i] + 1);
				ans = min(ans, pr[i - 3] + su);
			}
			reverse(H + 1, H + N + 1);
			for (i = 2; i < N; i += 2) pr[i] = pr[i - 2] + max(0ll, max(H[i + 1], H[i - 1]) - H[i] + 1);
			su = 0;
			for (i = N - 1; i >= 3; i -= 2) {
				su += max(0ll, max(H[i + 1], H[i - 1]) - H[i] + 1);
				ans = min(ans, pr[i - 3] + su);
			}
			cout << ans << ln;
		}
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