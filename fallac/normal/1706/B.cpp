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

int pv[2][MAX];
int arr[MAX];
int dp[MAX];
int ans[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 0; i <= N; i++) pv[0][i] = pv[1][i] = dp[i] = ans[i] = 0;
	for (i = 1; i <= N; i++) {
		cin >> arr[i];
		dp[i] = dp[pv[(i + 1) % 2][arr[i]]] + 1;
		ans[arr[i]] = max(ans[arr[i]], dp[i]);
		pv[(i % 2)][arr[i]] = i;
	}
	for (i = 1; i <= N; i++) cout << ans[i] << bb;
	cout << ln;
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