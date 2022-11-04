#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

struct segment_tree {
	vector<ll> tree;
	ll size;
	segment_tree(vector<ll> now = vector<ll>(0, 0)) {
		ll step = 1;
		while (step < now.size()) {
			step *= 2;
		}
		now.resize(step, 0);
		size = now.size();
		tree.resize(size*2, 0);
		build(now, 0, size, 1);
	}
	void build(vector<ll>& now, ll l, ll r, ll v) {
		if (l == r-1) {
			tree[v] = now[l];
			return;
		}
		ll mid = (l+r)/2;
		build(now, l, mid, v*2);
		build(now, mid, r, v*2+1);
		tree[v] = tree[v*2] + tree[v*2+1];
	}
	ll sum(ll l, ll r) {
		return sum(l, r, 1, 0, size);
	}
	ll sum(ll ql, ll qr, ll v, ll l, ll r) {
		if (ql <= l && qr >= r) {
			return tree[v];
		}
		if (r <= ql || l >= qr) {
			return 0;
		}
		ll mid = (l+r)/2;
		return sum(ql, qr, v*2, l, mid) + sum(ql, qr, v*2+1, mid, r);
	}
	void change(ll n) {
		ll now = size+n;
		tree[now] += 1;
		while (now > 1) {
			now /= 2;
			tree[now] = tree[now*2]+tree[now*2+1];
		}
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	ll n;
	cin >> n;
	vector<tuple<ll, ll, ll>> arr(n);
	vector<ll> all;
	for (ll i = 0; i < n; i++) {
		ll x, y;
		cin >> x >> y;
		arr[i] = make_tuple(-x, y, i);
		all.push_back(x);
		all.push_back(y);
	}
	sort(all.begin(), all.end());
	sort(arr.begin(), arr.end());
	map<ll, ll> zip;
	ll last = 0;
	all.resize(unique(all.begin(), all.end())-all.begin());
	for (ll i = 0; i < all.size(); i++) {
		zip[all[i]] = last;
		last++;
	}
	vector<ll> ans(n, 0);
	segment_tree seg(vector<ll>(1111111, 0));
	for (ll i = 0; i < n; i++) {
		auto[_, y, j] = arr[i];
		ans[j] = seg.sum(0, zip[y]);
		seg.change(zip[y]);
	}
	for (auto i : ans) {
		cout << i << '\n';
	}
}