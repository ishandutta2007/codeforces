/*

*/

#include <bits/stdc++.h>

#pragma GCC optimize("O3")
#pragma GCC optimize("Ofast")
#pragma GCC optimize("unroll-loops")

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
#define MOD 998244353
#define INF 1000000000000

//#define vv vector
#define pq priority_queue
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

//var

//

struct segtree {
	ll N, s;
	vector<ll> tree, l, r;
	void init(ll x = 1) {
		if (x >= s) {
			l[x] = r[x] = x - s + 1;
			return;
		}
		init(x * 2);
		init(x * 2 + 1);
		l[x] = l[x * 2];
		r[x] = r[x * 2 + 1];
	}
	segtree(ll n) {
		N = n;
		s = 1LL << (ll)ceil(log2(N));
		tree.resize(2 * s + 1);
		l.resize(2 * s + 1);
		r.resize(2 * s + 1);
		init();
	}
	void update(ll x, ll a) {
		x += s - 1;
		tree[x] = a;
		x /= 2;
		while (x) {
			tree[x] = tree[x * 2] + tree[x * 2 + 1];
			tree[x] %= MOD;
			x /= 2;
		}
	}
	ll query(ll low, ll high, ll loc = 1) {
		if (l[loc] == low && r[loc] == high) return tree[loc];
		if (r[loc * 2] >= high) return query(low, high, loc * 2);
		if (l[loc * 2 + 1] <= low) return query(low, high, loc * 2 + 1);
		return (query(low, r[loc * 2], loc * 2) + query(l[loc * 2 + 1], high, loc * 2 + 1)) % MOD;
	}
	segtree() {

	}
};

ll X[MAX], Y[MAX], S[MAX];
ll dp[MAX];

void solve() {
	ll N;
	cin >> N;
	ll i;
	segtree seg;
	seg = segtree(N);
	vector<ll> v;
	for (i = 1; i <= N; i++) {
		cin >> X[i] >> Y[i] >> S[i];
		v.push_back(X[i]);
	}
	sort(v.begin(), v.end());
	dp[1] = X[1] - Y[1];
	seg.update(1, dp[1]);
	for (i = 2; i <= N; i++) {
		ll y = Y[i];
		ll ind = lower_bound(v.begin(), v.end(), y) - v.begin() + 1;
		dp[i] = X[i] - Y[i];
		if (ind <= i) dp[i] += seg.query(ind, i);
		dp[i] %= MOD;
		seg.update(i, dp[i]);
	}
	ll sum = X[N] + 1;
	for (i = 1; i <= N; i++) sum += S[i] * dp[i], sum %= MOD;
	if (sum < 0) sum += MOD;
	cout << sum << ln;
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