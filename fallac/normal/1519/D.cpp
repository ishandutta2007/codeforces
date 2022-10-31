/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")
#pragma GCC target("avx2")

using namespace std;
typedef long long ll;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'

#define MAX 5010
#define MOD 100000009

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var
ll A[MAX], B[MAX];
ll rev[MAX];
ll arr[MAX][MAX]; //i times rotating
ll mul[MAX], nsum[MAX];
//
void solve() {
	ll N;
	cin >> N;
	ll i, j;
	for (i = 1; i <= N; i++) cin >> A[i];
	for (i = 1; i <= N; i++) cin >> B[i];
	for (i = 1; i <= N; i++) rev[i] = B[N - i + 1];
	for (i = 0; i < N; i++) {
		for (j = 1; j <= N; j++) arr[i][j] = A[j] * rev[((i + j - 1) % N) + 1];
		for (j = 1; j <= N; j++) arr[i][j] += arr[i][j - 1];
	}
	for (i = 1; i <= N; i++) mul[i] = A[i] * B[i];
	for (i = 1; i <= N; i++) nsum[i] = nsum[i - 1] + mul[i];
	ll ans = 0;
	for (i = 1; i <= N; i++) {
		for (j = i; j <= N; j++) {
			ll l, r;
			l = i, r = j;
			ll x = min(l - 1, N - j);
			l -= x, r += x;
			ll p;
			if (l == 1) p = N - r;
			else p = r - l + 1;
			l = i, r = j;
			ans = max(ans, nsum[l - 1] + nsum[N] - nsum[r] + arr[p][r] - arr[p][l - 1]);
		}
	}
	cout << ans << ln;
}

void init() {

}

signed main() {
	ios::sync_with_stdio(false), cin.tie(0);
	ll T;
	omode;
	while (T--) {
		init();
		solve();
	}
}