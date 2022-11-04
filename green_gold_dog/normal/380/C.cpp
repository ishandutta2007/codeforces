#include <bits/stdc++.h>
typedef long long ll;

using namespace std;

ll pass() {
	return 0;
}

struct node {
	ll ans = 0, pref = 0, suff = 0, n = 1;
	node(char c = '.') {
		(c != '.' ? (c == '(' ? suff = 1 : pref = 1) : pass());
	}
	node(node a, node b) {
		n = a.n+b.n;
		ans = a.ans + b.ans + min(a.suff, b.pref);
		pref = a.pref+b.pref-min(a.suff, b.pref);
		suff = b.suff+a.suff-min(a.suff, b.pref);
	}
};

struct segment_tree {
	vector<node> tree;
	ll size;
	segment_tree(string s) {
		ll step = 1;
		while (step < s.size()) {
			step *= 2;
		}
		s.resize(step, '.');
		size = step;
		tree.resize(size*2, node());
		build(1, 0, size, s);
	}
	void build(ll v, ll l, ll r, string& s) {
		if (r - l == 1) {
			tree[v] = node(s[l]);
			return;
		}
		ll mid = (l+r)/2;
		build(v*2, l, mid, s);
		build(v*2+1, mid, r, s);
		tree[v] = node(tree[v*2], tree[v*2+1]);
	}
	node sum(ll l, ll r) {
		return sum(l, r, 1, 0, size);
	}
	node sum(ll ql, ll qr, ll v, ll l, ll r) {
		if (qr <= l || r <= ql) {
			return node();
		}
		if (ql <= l && r <= qr) {
			return tree[v];
		}
		ll mid = (l+r)/2;
		return node(sum(ql, qr, v*2, l, mid), sum(ql, qr, v*2+1, mid, r));
	}
};

int main() {
    	ios_base::sync_with_stdio(false);
    	cin.tie(0);
    	cout.tie(0);
	string s;
	cin >> s;
	segment_tree seg(s);
	ll n;
	cin >> n;
	for (ll i = 0; i < n; i++) {
		ll l, r;
		cin >> l >> r;
		cout << seg.sum(l-1, r).ans*2 << '\n';
	}
}