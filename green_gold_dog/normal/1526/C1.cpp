#include <bits/stdc++.h>

using namespace std;

typedef long long ll;
typedef double db;
typedef long double ldb;
typedef complex<double> cd;

const ll INF = 9'000'000'000'000'000'000;
const db PI = acos(-1);

mt19937 rnd32(time(0));
mt19937_64 rnd64(time(0));

template<typename T>
bool assign_max(T& a, T b) {
	if (b > a) {
		a = b;
		return true;
	}
	return false;
}

template<typename T>
bool assign_min(T& a, T b) {
	if (b < a) {
		a = b;
		return true;
	}
	return false;
}

struct segment_tree {
	vector<ll> tree, m;
	ll size;
	segment_tree(vector<ll> arr = vector<ll>(0, 0)) {
		size = 1;
		while (size < arr.size()) {
			size *= 2;
		}
		arr.resize(size, 0);
		m.resize(size * 2, 0);
		tree.resize(size * 2, 0);
		build(1, 0, size, arr);
	}
	void build(ll v, ll l, ll r, vector<ll>& arr) {
		if (r - l == 1) {
			tree[v] = arr[l];
			return;
		}
		ll mid = (l + r) / 2;
		build(v * 2, l, mid, arr);
		build(v * 2 + 1, mid, r, arr);
		tree[v] = min(tree[v * 2],  tree[v * 2 + 1]);
	}
	void push(ll v, ll l, ll r) {
		ll mid = (l + r) / 2;
		tree[v * 2] += m[v];
		tree[v * 2 + 1] += m[v];
		m[v * 2] += m[v];
		m[v * 2 + 1] += m[v];
		m[v] = 0;
	}
	ll get(ll l, ll r) {
		return get(1, 0, size, l, r);
	}
	ll get(ll v, ll l, ll r, ll ql, ll qr) {
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		if (qr <= l || r <= ql) {
			return INF;
		}
		push(v, l, r);
		ll mid = (l + r) / 2;
		return min(get(v * 2, l, mid, ql, qr), get(v * 2 + 1, mid, r, ql, qr));
	}
	void change(ll l, ll r, ll x) {
		change(1, 0, size, l, r, x);
	}
	void change(ll v, ll l, ll r, ll ql, ll qr, ll x) {
		if (ql <= l && r <= qr) {
			tree[v] += x;
			m[v] += x;
			return;
		}
		if (qr <= l || r <= ql) {
			return;
		}
		push(v, l, r);
		ll mid = (l + r) / 2;
		change(v * 2, l, mid, ql, qr, x);
		change(v * 2 + 1, mid, r, ql, qr, x);
		tree[v] = min(tree[v * 2], tree[v * 2 + 1]);
	}
};

void solve() {
	ll n;
	cin >> n;
	vector<ll> arr(n, 0);
	for (ll i = 0; i < n; i++) {
		cin >> arr[i];
	}
	vector<ll> sum(n, 0);
	ll ans = 0;
	vector<pair<ll, ll>> all;
	for (ll i = 0; i < n; i++) {
		if (i > 0) {
			sum[i] += sum[i - 1];
		}
		if (arr[i] > 0) {
			ans++;
			sum[i] += arr[i];
		} else {
			all.push_back(make_pair(arr[i], -i));
		}
	}
	sort(all.begin(), all.end());
	segment_tree st(sum);
	while (!all.empty()) {
		auto[a, b] = all.back();
		b = -b;
		if (st.get(b, n) + a >= 0) {
			st.change(b, n, a);
			ans++;
		}
		all.pop_back();
	}
	cout << ans << '\n';
}

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll t = 1;
	//cin >> t;
	for (ll i = 0; i < t; i++) {
		solve();
	}
}