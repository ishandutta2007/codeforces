#include <bits/stdc++.h>
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

struct Node {
	ll l_val, r_val, incr_left, incr_right, arrays;
	bool all_incr;

	Node() {
	}

	Node(ll val) {
		l_val = val;
		r_val = val;
		incr_left = 0;
		incr_right = 0;
		arrays = 1;
		all_incr = true;
	}
};

Node merge_nodes(const Node& a, const Node& b) {
	Node c;
	c.l_val = a.l_val;
	c.r_val = b.r_val;
	c.incr_left = a.incr_left;
	if (a.all_incr && a.r_val <= b.l_val) {
		c.incr_left += 1 + b.incr_left;
	}
	c.incr_right = b.incr_right;
	if (b.all_incr && a.r_val <= b.l_val) {
		c.incr_right += 1 + a.incr_right;
	}
	c.arrays = a.arrays + b.arrays;
	if (a.r_val <= b.l_val) {
		c.arrays += (a.incr_right+1)*(b.incr_left+1);
	}
	c.all_incr = (a.all_incr && b.all_incr && a.r_val <= b.l_val);
	return c;
}

struct Tree {
	typedef Node T;
	T f(T a, T b) { return merge_nodes(a, b); } // (any associative fn)
	vector<T> s; int n;
	Tree(int n = 0, T def = Node(0)) : s(2*n, def), n(n) {}
	void update(int pos, T val) {
		for (s[pos += n] = val; pos /= 2;)
			s[pos] = f(s[pos * 2], s[pos * 2 + 1]);
	}
	T query(int b, int e) { // query [b, e)
		T ra = Node(INT_MAX), rb = Node(INT_MIN);
		for (b += n, e += n; b < e; b /= 2, e /= 2) {
			if (b % 2) ra = f(ra, s[b++]);
			if (e % 2) rb = f(s[--e], rb);
		}
		return f(ra, rb);
	}
};

void solve() {
	ll n, q;
	cin >> n >> q;
	vector<ll> a(n);
	int two = 1;
	while (two < n)
		two *= 2;
	Tree tree(two);
	rep(i,0,n) {
		cin >> a[i];
		tree.update(i, Node(a[i]));
	}
	rep(i,0,q) {
		int type;
		cin >> type;
		if (type == 1) {
			int x, y;
			cin >> x >> y;
			--x;
			tree.update(x, Node(y));
		} else {
			ll l, r;
			cin >> l >> r;
			--l;
			Node res = tree.query(l, r);
			cout << res.arrays-2 << endl;
		}
	}
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
		solve();
}