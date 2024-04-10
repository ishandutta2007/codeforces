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

int query(int x) {
	cout << "? " << x << endl;
	int v;
	cin >> v;
	return v;
}

void solve() {
	int N;
	cin >> N;
	int i;
	int l, r;
	l = 0, r = 1000000000;
	while (r - l > 1) {
		int mid = (l + r + 1) / 2;
		if (query(mid) == 1) r = mid;
		else l = mid;
	}
	int L = r - N + 1;
	int ans = r;
	for (int h = 2; h <= N; h++) {
		int l, r;
		l = L + N;
		if (l % h) l /= h;
		else l /= h, l--;
		r = L + N - 1;
		if (r % h) r /= h;
		else r /= h, r--;
		for (i = l; i <= r; i++) {
			int x = query(i);
			if (x) ans = min(ans, x * i);
		}
	}
	cout << "! " << ans << endl;
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