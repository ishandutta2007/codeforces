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

#define MAX 301010
#define MOD 100000009

#define vv vector
#define pq priority_queue
#define pp pair<ll, ll>
#define ff first
#define ss second
#define yes "YES"
#define no "NO"

struct dat {
	ll lmx;
	ll rmx;
	ll mx;
	ll sz;
	dat() :lmx(0), rmx(0), mx(0), sz(1) {}
	dat(ll l, ll r, ll m, ll s) :lmx(l), rmx(r), mx(m), sz(s) {}
};

dat operator+(dat d1, dat d2) {
	dat d;
	d.lmx = max(d1.lmx, d1.sz + d2.lmx);
	d.rmx = max(d2.rmx, d2.sz + d1.rmx);
	d.sz = d1.sz + d2.sz;
	d.mx = max(max(d1.rmx + d2.lmx, max(d.lmx, d.rmx)), max(d1.mx, d2.mx));
	return d;
}

struct segtree {
	vector<dat> tree;
	vector<ll> l, r;
	ll s;
	void init(ll x = 1) {
		if (x >= s) {
			l[x] = r[x] = x - s + 1;
			return;
		}
		init(x * 2);
		init(x * 2 + 1);
		tree[x] = tree[x * 2] + tree[x * 2 + 1];
		l[x] = l[x * 2];
		r[x] = r[x * 2 + 1];
	}
	void update(ll x, dat d) {
		x += s - 1;
		tree[x] = d;
		x /= 2;
		while (x) {
			tree[x] = tree[x * 2] + tree[x * 2 + 1];
			x /= 2;
		}
	}
	dat query(ll low, ll high, ll loc = 1) {
		if (l[loc] == low && r[loc] == high) return tree[loc];
		if (high <= r[loc * 2]) return query(low, high, loc * 2);
		if (low >= l[loc * 2 + 1]) return query(low, high, loc * 2 + 1);
		return query(low, r[loc * 2], loc * 2) + query(l[loc * 2 + 1], high, loc * 2 + 1);
	}
	segtree(ll N) {
		s = 1LL << (ll)ceil(log2(N));
		tree.resize(2 * s + 1);
		l.resize(2 * s + 1);
		r.resize(2 * s + 1);
	}
};

void solve() {
	
}

vector<ll> num[MAX];

void init() {
	ll N;
	cin >> N;
	ll i;
	vector<ll> arr;
	arr.resize(N + 1);
	vector<ll> v;
	for (i = 1; i <= N; i++) cin >> arr[i], v.push_back(arr[i]);
	sort(v.begin(), v.end());
	v.erase(unique(v.begin(), v.end()), v.end());
	for (i = 1; i <= N; i++) arr[i] = lower_bound(v.begin(), v.end(), arr[i]) - v.begin() + 1;
	ll mx = 0;
	for (i = 1; i <= N; i++) mx = max(mx, arr[i]);
	for (i = 1; i <= N; i++) num[arr[i]].push_back(i);
	segtree seg = segtree(N);
	for (i = 1; i <= N; i++) seg.tree[i + seg.s - 1] = dat(1, 1, 1, 1);
	seg.init();
	vector<ll> ans;
	ans.resize(N + 1);
	for (i = 1; i <= mx; i++) {
		for (auto loc : num[i]) {
			ll calc;
			calc = 0;
			if (loc + 1 <= N) calc += max(seg.query(loc + 1, N).lmx, 0LL);
			if (loc - 1 >= 1) calc += max(seg.query(1, loc - 1).rmx, 0LL);
			ans[loc] = max(ans[loc], (calc + 1) / 2);;
		}
		for (auto loc : num[i]) seg.update(loc, dat(-1, -1, -1, -1));
	}
	for (i = 1; i <= mx; i++) num[i].clear();
	for (i = 1; i <= N; i++) arr[i] = mx + 1 - arr[i];

	for (i = 1; i <= N; i++) num[arr[i]].push_back(i);
	seg = segtree(N);
	for (i = 1; i <= N; i++) seg.tree[i + seg.s - 1] = dat(1, 1, 1, 1);
	seg.init();
	for (i = 1; i <= mx; i++) {
		for (auto loc : num[i]) {
			ll calc;
			calc = 0;
			if (loc + 1 <= N) calc += max(seg.query(loc + 1, N).lmx, 0LL);
			if (loc - 1 >= 1) calc += max(seg.query(1, loc - 1).rmx, 0LL);
			ans[loc] = max(ans[loc], (calc) / 2);
		}
		for (auto loc : num[i]) seg.update(loc, dat(-1, -1, -1, -1));
	}

	for (i = 1; i <= N; i++) cout << ans[i] << ln;
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