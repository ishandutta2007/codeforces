#include <algorithm>
#include <functional>
#include <iostream>
#include <vector>

using namespace std;

const int INF = 1e9;

using Info = pair<pair<int, int>, pair<int, int>>;

struct SegmentTree {
	int size;
	vector<int> max, max2, min, min2;

	explicit SegmentTree(const vector<int>& tin) {
		size = static_cast<int>(tin.size());
		max.resize(size << 2, -INF);
		max2.resize(size << 2, -INF);
		min.resize(size << 2, INF);
		min2.resize(size << 2, INF);
		Build(tin);
	}

	static Info Merge(const Info& l, const Info& r) {
		vector<int> mx = {l.first.first, l.first.second, r.first.first, r.first.second};
		vector<int> mi = {l.second.first, l.second.second, r.second.first, r.second.second};
		sort(mx.rbegin(), mx.rend());
		sort(mi.begin(), mi.end());
		return {{mx[0], mx[1]}, {mi[0], mi[1]}};
	}


	void Upd(int v) {
		int l = v * 2;
		int r = v * 2 + 1;
		Info res = Merge({{max[l], max2[l]}, {min[l], min2[l]}}, {{max[r], max2[r]}, {min[r], min2[r]}});
		max[v] = res.first.first;
		max2[v] = res.first.second;
		min[v] = res.second.first;
		min2[v] = res.second.second;
	}

	void Build(int v, int tl, int tr, const vector<int>& tin) {
		if (tl == tr) {
			max[v] = min[v] = tin[tl];
		} else {
			int tm = (tl + tr) / 2;
			Build(v * 2, tl, tm, tin);
			Build(v * 2 + 1, tm + 1, tr, tin);
			Upd(v);
		}
	}

	Info Get(int v, int tl, int tr, int l, int r) {
		if (l > r) {
			return {{-INF, -INF}, {INF, INF}};
		} else if (l == tl && r == tr) {
			return {{max[v], max2[v]}, {min[v], min2[v]}};
		} else {
			int tm = (tl + tr) / 2;
			Info x = Get(v * 2, tl, tm, l, std::min(r, tm));
			Info y = Get(v * 2 + 1, tm + 1, tr, std::max(l, tm + 1), r);
			return Merge(x, y);
		}
	}

	void Build(const vector<int>& tin) {
		Build(1, 0, size - 1, tin);
	}

	Info Get(int l, int r) {
		Info res = Get(1, 0, size - 1, l, r);
		if (res.first.second == -INF) {
			res.first.second = res.first.first;
		}
		if (res.second.second == INF) {
			res.second.second = res.second.first;
		}
		return res;
	}
};

int main() {
	ios::sync_with_stdio(false);
	cin.tie(nullptr);
	int n, q;
	cin >> n >> q;
	vector<int> p(n);
	vector<vector<int>> g(n);
	for (int i = 1; i < n; ++i) {
		cin >> p[i];
		--p[i];
		g[p[i]].push_back(i);
	}
	vector<int> lg(n + 1);
	for (int i = 2; i <= n; ++i) {
		lg[i] = lg[i / 2] + 1;
	}
	vector<vector<int>> up(lg[n] + 1, vector<int>(n));
	for (int v = 0; v < n; ++v) {
		up[0][v] = p[v];
	}
	for (int pow = 1; pow <= lg[n]; ++pow) {
		for (int v = 0; v < n; ++v) {
			up[pow][v] = up[pow - 1][up[pow - 1][v]];
		}
	}
	vector<int> tin(n), inv_tin(n), lv(n);
	int timer = 0;
	function<void(int)> DFS = [&](int v) {
		tin[v] = timer++;
		inv_tin[tin[v]] = v;
		for (int u : g[v]) {
			lv[u] = lv[v] + 1;
			DFS(u);
		}
	};
	DFS(0);
	function<int(int, int)> LCA = [&](int u, int v) {
		if (lv[u] < lv[v]) {
			swap(u, v);
		}
		for (int pow = lg[n]; pow >= 0; --pow) {
			if ((lv[u] - lv[v]) & (1 << pow)) {
				u = up[pow][u];
			}
		}
		if (u == v) {
			return u;
		}
		for (int pow = lg[n]; pow >= 0; --pow) {
			if (up[pow][u] != up[pow][v]) {
				u = up[pow][u];
				v = up[pow][v];
			}
		}
		return p[u];
	};
	SegmentTree segment_tree(tin);
	while (q--) {
		int l, r;
		cin >> l >> r;
		--l, --r;
		Info info = segment_tree.Get(l, r);
		if (r - l == 1) {
			if (lv[l] >= lv[r]) {
				cout << r + 1 << ' ' << lv[l] << '\n';
			} else {
				cout << l + 1 << ' ' << lv[r] << '\n';
			}
		} else {
			int u1 = inv_tin[info.first.second], v1 = inv_tin[info.second.first];
			int u2 = inv_tin[info.first.first], v2 = inv_tin[info.second.second];
			int w1 = LCA(u1, v1);
			int w2 = LCA(u2, v2);
			// cout << w1 + 1 << ' ' << w2 + 1 << '\n';
			if (lv[w1] >= lv[w2]) {
				cout << inv_tin[info.first.first] + 1 << ' ' << lv[w1] << '\n';
			} else {
				cout << inv_tin[info.second.first] + 1 << ' ' << lv[w2] << '\n';
			}
		}
	}
	return 0;
}