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
typedef pair<int, int> pi;

#define omode T=1
#define tmode cin>>T
#define cmode(c) T=c
#define bb ' '
#define ln '\n'
#define Ln '\n'

#define MAX 101010
//#define MOD 100000007
//#define MOD 100000009
#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

void solve() {
	int l, r;
	cin >> l >> r;
	int N;
	N = r - l + 1;
	int i;
	vector<int> arr;
	int x;
	for (i = 1; i <= N; i++) cin >> x, arr.push_back(x);
	int ans = 0;
	for (i = 18; i >= 0; i--) {
		x = 1 << i;
		int j;
		int cnt1 = 0, cnt2 = 0;
		for (j = l; j <= r; j++) if (j & x) cnt1++;
		for (auto v : arr) if (v & x) cnt2++;
		if (cnt1 != cnt2) ans |= x;
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