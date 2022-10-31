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

#define MAX 201010
//#define MOD 100000007
#define MOD 100000009
//#define MOD 998244353
#define INF 1000000000000

#define yes "YES"
#define no "NO"

ll arr[MAX];
ll gcd(ll a, ll b) {
	if (a > b) swap(a, b);
	if (a == 0) return b;
	return gcd(a, b % a);
}

struct fenwick {
	ll N;
	vector<ll> tree;
	fenwick(ll N = 0) :N(N) { tree.resize(N + 1); }
	void update(ll x, ll a) {
		x = N + 1 - x;
		while (x <= N) {
			tree[x] = gcd(tree[x], a);
			x += (x & -x);
		}
	}
	ll query(ll x) {
		x = N + 1 - x;
		ll ans = 0;
		while (x) {
			ans = gcd(ans, tree[x]);
			x -= (x & -x);
		}
		return ans;
	}
};

void solve() {
	ll N;
	cin >> N;
	ll i;
	fenwick bit(N);
	for (i = 1; i <= N; i++) cin >> arr[i];
	ll ans = 0;
	if (arr[1] == 1) cout << 1 << bb, bit.update(1, 1), ans++;
	else cout << 0 << bb, bit.update(1, arr[1]);
	for (i = 2; i <= N; i++) {
		bit.update(i, arr[i]);
		ll l, r;
		l = 0, r = i;
		while (r - l > 1) {
			ll mid = (l + r + 1) / 2;
			if (i - mid + 1 - bit.query(mid) <= 0) r = mid;
			else l = mid;
		}
		if (bit.query(r) == i - r + 1) {
			bit.update(i, 1);
			ans++;
		}
		cout << ans << bb;
	}
	cout << ln;
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