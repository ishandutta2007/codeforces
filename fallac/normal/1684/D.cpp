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

#define MAX 301010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll arr[MAX];

void solve() {
	ll N, K;
	cin >> N >> K;
	int i;
	ll ans = -K * (K + 1) / 2;
	for (i = 1; i <= N; i++) cin >> arr[i], ans += arr[i];
	reverse(arr + 1, arr + N + 1);
	for (i = 1; i <= N; i++) arr[i] = i - arr[i];
	sort(arr + 1, arr + N + 1);
	for (i = 1; i <= K; i++) ans += arr[i];
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