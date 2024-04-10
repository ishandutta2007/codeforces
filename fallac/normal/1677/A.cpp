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

int arr[MAX];
ll cnt[MAX];

void solve() {
	int N;
	cin >> N;
	int i;
	for (i = 1; i <= N; i++) cin >> arr[i];
	for (i = 0; i <= N + 1; i++) cnt[i] = 0;
	int l, r;
	ll ans = 0;
	for (r = N; r >= 1; r--) {
		ll sum = 0;
		for (l = r - 2; l >= 1; l--) {
			sum += (ll)cnt[arr[l + 1]];
			if (arr[l] < arr[r]) ans += sum;
		}
		for (i = arr[r]; i <= N; i++) cnt[i]++;
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