#include <iostream>
#include <vector>
#include <algorithm>
#include <functional>
#include <climits>
#include <tuple>
#include <map>

using namespace std;

struct BinLift {
	vector< vector<int> > lift;
	int d;
	
	inline int rise(int v, int l) {
		for (int i = 0; i < d; i++) {
			if ((l >> i) & 1) {
				v = lift[i][v];
			}
		}
		return v;
	}
	
	BinLift(vector<int> up, int d)
		: lift(d, vector<int>(up.size())), d(d) {
		lift[0] = up;
		for (int i = 1; i < d; i++) {
			for (int j = 0; j < (int)up.size(); j++) {
				lift[i][j] = lift[i-1][lift[i-1][j]];
			}
		}
	}
};

class SegTree {
private:
	int n;
	vector<int> tree;
	void *ptr;
	
	inline int min(int a, int b) {
		return cmp(a, b, ptr) ? a : b;
	}
	
	inline void modify(int x, int tl, int tr, int v, int value) {
		if (tl == tr) {
			tree[x] = value;
			return;
		}
		int tm = (tl + tr) / 2;
		if (v <= tm) {
			modify(x*2, tl, tm, v, value);
		} else {
			modify(x*2+1, tm+1, tr, v, value);
		}
		tree[x] = min(tree[x*2], tree[x*2+1]);
	}
	
	inline int query(int x, int tl, int tr, int l, int r) {
		if (l == tl && tr == r) {
			return tree[x];
		}
		int tm = (tl + tr) / 2;
		if (r <= tm) {
			return query(x*2, tl, tm, l, r);
		} else if (l > tm) {
			return query(x*2+1, tm+1, tr, l, r);
		} else {
			return min(
				query(x*2, tl, tm, l, tm),
				query(x*2+1, tm+1, tr, tm+1, r)
			);
		}
	}
public:
	const function<bool(int, int, void *)> &cmp;
	
	inline void modify(int v, int value) {
		modify(1, 0, n-1, v, value);
	}
	
	inline int query(int l, int r) {
		return query(1, 0, n-1, l, r);
	}
	
	SegTree(int n, const function<bool(int, int, void *)> &cmp, int fill = 0, void *ptr = nullptr)
		: n(n), tree(4*n, fill), ptr(ptr), cmp(cmp) {
	}
};

const int TYPE_BUS = 1;
const int TYPE_QUERY = 0;

struct Fork {
	int type;
	int l, u, v;
	int idx;
};

struct Event {
	int x, y, type, tag1, tag2;
};

inline bool operator<(const Event &a, const Event &b) {
	return make_tuple(a.x, a.type, a.y) < make_tuple(b.x, b.type, b.y);
}

class Fenwick {
private:
	int n;
	vector<int> a;
public:
	inline void modify(int v, int delta) {
		for (; v < n; v |= v+1) {
			a[v] += delta;
		}
	}
	
	inline int sum(int v) {
		int ans = 0;
		for (; v >= 0; v &= v+1, v--) {
			ans += a[v];
		}
		return ans;
	}
	
	Fenwick(int n)
		: n(n), a(n) {
	}
};

int main() {
	ios_base::sync_with_stdio(false);
	
	int n; cin >> n;
	vector<int> p(n, 0);
	vector< vector<int> > g(n);
	for (int i = 1; i < n; i++) {
		cin >> p[i]; p[i]--;
		g[p[i]].push_back(i);
	}
	
	int timer = 0;
	vector<int> tin(n), tout(n), d(n);
	
	BinLift lift(p, 20);
	
	function<void(int)> dfs1 = [&](int v) {
		tin[v] = timer++;
		d[v] = v ? d[p[v]] + 1 : 0;
		for (int to: g[v]) {
			dfs1(to);
		}
		tout[v] = timer++;
	};
	dfs1(0);
	
	auto upper = [&](int a, int b) {
		return tin[a] <= tin[b] && tout[b] <= tout[a];
	};
	
	auto lca = [&](int a, int b) {
		if (upper(a, b)) {
			return a;
		}
		if (upper(b, a)) {
			return b;
		}
		for (int i = lift.d-1; i >= 0; i--) {
			int c = lift.lift[i][a];
			if (!upper(c, b)) {
				a = c;
			}
		}
		return lift.lift[0][a];
	};
	
	map< pair<int, int>, vector<Fork> > forks;
	
	auto appendFork = [&](int u, int l, int v, int type, int idx) {
		int pu = lift.rise(u, d[u] - d[l] - 1);
		int pv = lift.rise(v, d[v] - d[l] - 1);
		if (pu > pv) {
			swap(u, v);
			swap(pu, pv);
		}
		forks[{pu, pv}].push_back({type, l, u, v, idx});
	};
	
	int m; cin >> m;
	vector< pair<int, int> > bus(m);
	vector< vector<int> > routeBeg(n);
	
	for (int i = 0; i < m; i++) {
		int u, v; cin >> u >> v; u--; v--;
		int l = lca(u, v);
		routeBeg[l].push_back(u);
		routeBeg[l].push_back(v);
		appendFork(u, l, v, TYPE_BUS, i);
		bus[i] = {u, v};
	}
	
	vector<int> sup(n);
	SegTree sst(timer, [](int a, int b, void *ptr) {
		auto d = (vector<int> *)ptr;
		int da = (a < 0) ? INT_MAX : (*d)[a];
		int db = (b < 0) ? INT_MAX : (*d)[b];
		return da < db;
	}, -1, &d);
	vector<int> vals(timer, -1);
	
	function<void(int)> dfs2 = [&](int v) {
		int supv = sst.query(tin[v], tout[v]);
		sup[v] = (supv < 0) ? v : supv;
		vector< pair<int, int> > rollback;
		for (int i: routeBeg[v]) {
			int old = vals[tin[i]];
			if (sst.cmp(v, old, &d)) {
				rollback.emplace_back(tin[i], old);
				sst.modify(tin[i], v);
				vals[tin[i]] = v;
			}
		}
		for (int to: g[v]) {
			dfs2(to);
		}
		reverse(rollback.begin(), rollback.end());
		for (auto it: rollback) {
			sst.modify(it.first, it.second);
			vals[it.first] = it.second;
		}
	};
	dfs2(0);
	
	BinLift slift(sup, 20);
	
	auto wayUp = [&](int a, int b) {
		if (d[slift.lift[slift.d-1][a]] > d[b]) {
			return -1;
		}
		if (a == b) {
			return 0;
		}
		int ans = 0;
		for (int i = slift.d-1; i >= 0; i--) {
			int c = slift.lift[i][a];
			if (d[c] > d[b]) {
				ans += 1 << i;
				a = c;
			}
		}
		return ans+1;
	};
	
	int q; cin >> q;
	vector< pair<int, int> > query(q);
	vector<int> ans(q);
	vector<int> dek(q);
	for (int i = 0; i < q; i++) {
		int u, v; cin >> u >> v; u--; v--;
		int l = lca(u, v);
		int wu = wayUp(u, l), wv = wayUp(v, l);
		ans[i] = (wu < 0 || wv < 0) ? -1 : wu+wv;
		if (u != l && v != l && ans[i] >= 0) {
			int nu = slift.rise(u, wu-1), nv = slift.rise(v, wv-1);
			appendFork(nu, l, nv, TYPE_QUERY, i);
		}
		query[i] = {u, v};
	}
	
	Fenwick fen(timer);
	for (auto it: forks) {
		vector<Event> events;
		for (Fork f: it.second) {
			if (f.type == TYPE_BUS) {
				events.push_back({tin[f.u], tin[f.v], 0, 0, 0});
			} else {
				int xl = tin[f.u]-1, xr = tout[f.u];
				int yl = tin[f.v]-1, yr = tout[f.v];
				events.push_back({xl, yl, 1, f.idx, +1});
				events.push_back({xl, yr, 1, f.idx, -1});
				events.push_back({xr, yl, 1, f.idx, -1});
				events.push_back({xr, yr, 1, f.idx, +1});
			}
		}
		sort(events.begin(), events.end());
		for (Event evt: events) {
			if (evt.type == 0) {
				fen.modify(evt.y, +1);
			} else {
				dek[evt.tag1] += evt.tag2 * fen.sum(evt.y);
			}
		}
		for (Event evt: events) {
			if (evt.type == 0) {
				fen.modify(evt.y, +1);
			}
		}
	}
	
	for (int i = 0; i < q; i++) {
		ans[i] -= !!dek[i];
		cout << ans[i] << "\n";
	}
	return 0;
}