#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>
#include <climits>

using namespace std;

const int64_t infinity = (int64_t)1e18 + 42;

class SegmentTree {
private:
	int n;
	vector<int64_t> tree;
	vector<int64_t> lazy;
	
	inline void push(int x, int tl, int tr) {
		if (lazy[x] == infinity) {
			return;
		}
		tree[x] = min(tree[x], lazy[x] - tr);
		if (tl != tr) {
			lazy[x*2] = min(lazy[x*2], lazy[x]);
			lazy[x*2+1] = min(lazy[x*2+1], lazy[x]);
		}
		lazy[x] = infinity;
	}
	
	inline void modify(int x, int tl, int tr, int l, int r, int64_t val) {
		push(x, tl, tr);
		if (l > r) {
			return;
		}
		if (l == tl && tr == r) {
			lazy[x] = min(lazy[x], val);
			push(x, tl, tr);
			return;
		}
		int tm = (tl + tr) / 2;
		modify(x*2, tl, tm, l, min(r, tm), val);
		modify(x*2+1, tm+1, tr, max(tm+1, l), r, val);
		tree[x] = min(tree[x*2], tree[x*2+1]);
	}
	
	inline int64_t query(int x, int tl, int tr, int l, int r) {
		push(x, tl, tr);
		if (l > r) {
			return infinity;
		}
		if (l == tl && tr == r) {
			return tree[x];
		}
		int tm = (tl + tr) / 2;
		return min(
			query(x*2, tl, tm, l, min(r, tm)),
			query(x*2+1, tm+1, tr, max(tm+1, l), r)
		);
	}
public:
	inline void modify(int l, int r, int64_t val) {
		modify(1, 0, n-1, l, r, val);
	}
	
	inline int64_t query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
	
	SegmentTree(int n)
		: n(n), tree(4*n, infinity), lazy(4*n, infinity) {
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, a, b; cin >> n >> a >> b; a--; b--;
	vector<int> g(n-1), k(n);
	for (int i = 0; i < n-1; i++) {
		cin >> g[i];
	}
	for (int i = 0; i < n; i++) {
		cin >> k[i];
	}
	
	if (a > b) {
		a = n - a - 1;
		b = n - b - 1;
		reverse(g.begin(), g.end());
		reverse(k.begin(), k.end());
	}
	
	vector<int> e(n), f(n);
	
	int l = a, r = a;
	vector<char> hasKey(102002, false);
	hasKey[k[a]] = true;
	e[a] = a;
	while (r != b) {
		while (!hasKey[g[r]]) {
			if (l == 0 || !hasKey[g[l-1]]) {
				cout << -1 << endl;
				return 0;
			}
			l--;
			hasKey[k[l]] = true;
		}
		r++;
		hasKey[k[r]] = true;
		e[r] = l;
	}
	
	int lB = l;
	l = a; r = a;
	hasKey.assign(102002, false);
	hasKey[k[a]] = true;
	while (r != b) {
		while (l != lB && hasKey[g[l-1]]) {
			l--;
			hasKey[k[l]] = true;
		}
		f[r] = l;
		assert(hasKey[g[r]]);
		r++;
		hasKey[k[r]] = true;
	}
	assert(l == lB);
	f[b] = l;
	
	SegmentTree st(n);
	st.modify(a, a, a);
	for (int i = a; i <= b; i++) {
		int64_t qur = st.query(lB, e[i]) + i;
		st.modify(f[i], a, qur);
	}
	
	cout << 2*st.query(lB, lB) + b - a << endl;
	return 0;
}