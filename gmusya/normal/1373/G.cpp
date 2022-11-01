#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <set>

using namespace std;

struct segment_tree {
	struct vertex {
		int val = 0;
		int mod = 0;
	};
	int sz;
	vector <vertex> t;
	segment_tree(int n) {
		int sz = n;
		t.resize(n << 2);
	}
	void build(int v, int tl, int tr) {
		if (tl == tr) {
			t[v].val = tl;
			return;
		}
		int tm = (tl + tr) / 2;
		build(v * 2, tl, tm);
		build(v * 2 + 1, tm + 1, tr);
		t[v].val = max(t[v * 2].val, t[v * 2 + 1].val);
	}
	void update(int v, int tl, int tr, int l, int r, int val) {
		if (l > r) return;
		if (tl == l && tr == r) {
			t[v].mod += val;
			return;
		}
		t[v * 2].mod += t[v].mod;
		t[v * 2 + 1].mod += t[v].mod;
		t[v].mod = 0;
		int tm = (tl + tr) / 2;
		update(v * 2, tl, tm, l, min(tm, r), val);
		update(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r, val);
		t[v].val = max(t[v * 2].val + t[v * 2].mod, t[v * 2 + 1].val + t[v * 2 + 1].mod);
	}
	int query(int v, int tl, int tr, int l, int r) {
		if (l > r) return 0;
		if (tl == l && tr == r) return t[v].val + t[v].mod;
		t[v * 2].mod += t[v].mod;
		t[v * 2 + 1].mod += t[v].mod;
		t[v].mod = 0;
		int tm = (tl + tr) / 2;
		int x = query(v * 2, tl, tm, l, min(tm, r));
		int y = query(v * 2 + 1, tm + 1, tr, max(l, tm + 1), r);
		t[v].val = max(t[v * 2].val + t[v * 2].mod, t[v * 2 + 1].val + t[v * 2 + 1].mod);
		return max(x, y);
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, k, m;
	cin >> n >> k >> m;
	segment_tree t(n + n);
	t.build(1, 0, n + n - 1);
	set <pair <int, int>> pawns;
	multiset <int> maxy;
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		y--;
		int h = abs(k - x) + y;
		if (pawns.find({ x, y }) != pawns.end()) {
			maxy.erase(maxy.find(h));
			t.update(1, 0, n + n - 1, 0, h, -1);
			pawns.erase({ x, y });
		}
		else {
			maxy.insert(h);
			t.update(1, 0, n + n - 1, 0, h, 1);
			pawns.insert({ x, y });
		}
		if (maxy.empty()) cout << 0 << '\n';
		else cout << max(0, t.query(1, 0, n + n - 1, 0, *(--maxy.end())) - n) << '\n';
	}
	return 0;
}