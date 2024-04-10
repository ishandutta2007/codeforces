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

//var

//
int arr[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 0; i < N; i++) cin >> arr[i];
	if (N == 1) {
		cout << 0 << ln;
		return;
	}
	int ans = arr[N - 1] - arr[0];
	for (i = 0; i < N; i++) ans = max(ans, arr[(i + N - 1) % N] - arr[i]);
	for (i = 1; i < N; i++) ans = max(ans, arr[i] - arr[0]);
	for (i = 0; i < N - 1; i++) ans = max(ans, arr[N - 1] - arr[i]);
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