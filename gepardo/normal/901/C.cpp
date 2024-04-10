#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>
#include <functional>

using namespace std;

struct Edge {
	int src, dst, idx;
};

struct Query {
	int l, r, idx, mul;
};

class SegmentTree {
private:
	int n;
	vector<int64_t> tree;
	vector<int64_t> lazy;
	
	inline void push(int x, int tl, int tr) {
		if (lazy[x]) {
			tree[x] += lazy[x] * (tr - tl + 1);
			if (tl != tr) {
				lazy[x*2] += lazy[x];
				lazy[x*2+1] += lazy[x];
			}
			lazy[x] = 0;
		}
	}
	
	void update(int x, int tl, int tr, int l, int r, int64_t val) {
		if (l > r) {
			push(x, tl, tr);
		} else if (l == tl && r == tr) {
			lazy[x] += val;
			push(x, tl, tr);
		} else {
			push(x, tl, tr);
			int tm = (tl + tr) / 2;
			update(x*2, tl, tm, l, min(r, tm), val);
			update(x*2+1, tm+1, tr, max(l, tm+1), r, val);
			tree[x] = tree[x*2] + tree[x*2+1];
		}
	}
	
	int64_t sum(int x, int tl, int tr, int l, int r) {
		if (l > r) {
			return 0;
		} else if (l == tl && r == tr) {
			push(x, tl, tr);
			return tree[x];
		} else {
			push(x, tl, tr);
			int tm = (tl + tr) / 2;
			return (
				sum(x*2, tl, tm, l, min(r, tm)) +
				sum(x*2+1, tm+1, tr, max(l, tm+1), r)
			);
		}
	}
public:
	inline void update(int l, int r, int64_t val) {
		update(1, 0, n-1, l, r, val);
	}
	
	inline int64_t sum(int l, int r) {
		return sum(1, 0, n-1, l, r);
	}
	
	SegmentTree(int n)
		: n(n), tree(4*n, 0), lazy(4*n) {
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	int n, m; cin >> n >> m;
	vector< vector<int> > g(n);
	for (int i = 0; i < m; i++) {
		int a, b; cin >> a >> b; a--; b--;
		g[a].push_back(b);
		g[b].push_back(a);
	}
	int q; cin >> q;
	vector<int64_t> ans(q);
	vector< vector<Query> > byX(n);
	for (int i = 0; i < q; i++) {
		int l, r; cin >> l >> r; l--; r--;
		if (l != 0) {
			byX[l-1].push_back({l, r, i, -1});
		}
		byX[r].push_back({l, r, i, +1});
	}
	
	vector< vector< pair<int, int> > > loopByL(n);
	int lc = 0;
	
	vector<int> used(n, 0);
	vector<int> stk;
	
	function<void(int, int)> dfs = [&](int v, int p) {
		if (used[v] == 2) {
			return;
		}
		if (used[v] == 1) {
			int l = v, r = v;
			int i = (int)stk.size() - 1;
			do {
				l = min(l, stk[i]);
				r = max(r, stk[i]);
				i--;
			} while (i >= 0 && stk[i] != v);
			loopByL[l].emplace_back(r, lc++);
			return;
		}
		used[v] = 1;
		for (int to: g[v]) {
			if (to == p) {
				continue;
			}
			stk.push_back(to);
			dfs(to, v);
			stk.pop_back();
		}
		used[v] = 2;
	};
	
	for (int i = 0; i < n; i++) {
		if (!used[i]) {
			stk.push_back(i);
			dfs(i, -1);
			stk.pop_back();
		}
	}
	
	priority_queue< pair<int, int>, vector< pair<int, int> >, greater< pair<int, int> > > lq;
	for (int i = 0; i < n; i++) {
		for (auto it: loopByL[i]) {
			lq.push(it);
		}
	}
	lq.emplace(n, lc);
	vector<char> locked(lc+1, true);
	SegmentTree st(n);
	for (int i = 0; i < n; i++) {
		while (!locked[lq.top().second]) {
			lq.pop();
		}
		st.update(i, lq.top().first - 1, 1);
		for (Query q: byX[i]) {
			ans[q.idx] += st.sum(q.l, q.r) * q.mul;
		}
		for (auto it: loopByL[i]) {
			locked[it.second] = false;
		}
	}
	
	for (int i = 0; i < q; i++) {
		cout << ans[i] << "\n";
	}
	return 0;
}