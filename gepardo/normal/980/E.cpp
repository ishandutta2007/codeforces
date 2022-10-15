#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <cassert>
#include <climits>

using namespace std;

class SegTree {
private:
	int n;
	vector<int> tree;
	vector<int> lazy;
	
	inline void push(int x, int tl, int tr) {
		if (lazy[x] != INT_MIN) {
			tree[x] = max(tree[x], lazy[x]);
			if (tl != tr) {
				lazy[x*2] = max(lazy[x*2], lazy[x]);
				lazy[x*2+1] = max(lazy[x*2+1], lazy[x]);
			}
			lazy[x] = INT_MIN;
		}
	}
	
	inline void update(int x, int tl, int tr, int l, int r, int value) {
		push(x, tl, tr);
		if (l > r) {
			return;
		}
		if (l == tl && tr == r) {
			lazy[x] = max(lazy[x], value);
			push(x, tl, tr);
			return;
		}
		int tm = (tl + tr) / 2;
		update(x*2, tl, tm, l, min(r, tm), value);
		update(x*2+1, tm+1, tr, max(tm+1, l), r, value);
		tree[x] = max(tree[x*2], tree[x*2+1]);
	}
	
	inline int query(int x, int tl, int tr, int l, int r) {
		push(x, tl, tr);
		if (l > r) {
			return INT_MIN;
		}
		if (l == tl && tr == r) {
			return tree[x];
		}
		int tm = (tl + tr) / 2;
		return max(
			query(x*2, tl, tm, l, min(r, tm)),
			query(x*2+1, tm+1, tr, max(tm+1, l), r)
		);
	}
public:
	inline void update(int l, int r, int value) {
		update(1, 0, n-1, l, r, value);
	}
	
	inline int query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
	
	SegTree(int n)
		: n(n), tree(4*n, INT_MIN), lazy(4*n, INT_MIN) {
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, k; cin >> n >> k;
	vector< vector<int> > g(n);
	for (int i = 1; i < n; i++) {
		int a, b; cin >> a >> b;
		a = n - a; b = n - b;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	
	int ac = n-k;
	vector<char> alive(n, true);
	vector<int> d(n), l(n), r(n), pre(n);
	SegTree near(n);
	int esz = 0;
	
	function<void(int, int)> dfs = [&](int v, int p) {
		pre[v] = p;
		l[v] = r[v] = esz++;
		for (int to: g[v]) {
			if (to == p) {
				continue;
			}
			d[to] = d[v] + 1;
			dfs(to, v);
			r[v] = r[to];
		}
	};
	dfs(0, -1);
	
	ac--;
	alive[0] = false;
	near.update(l[0], r[0], d[0]);
	for (int i = 1; i < n; i++) {
		if (!alive[i]) {
			continue;
		}
		int add = d[i] - near.query(l[i], r[i]);
		if (add > ac) {
			continue;
		}
		int v = i;
		while (alive[v]) {
			alive[v] = false;
			ac--;
			near.update(l[v], r[v], d[v]);
			v = pre[v];
		}
	}
	
	for (int i = 0; i < n; i++) {
		if (alive[n - i - 1]) {
			cout << i+1 << " ";
		}
	}
	cout << endl;
	return 0;
}