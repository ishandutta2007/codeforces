#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Node {
	int mn;
	int sub;
	int idx;

	bool operator <(const Node& ot) const {
		return make_pair(mn, -idx) < make_pair(ot.mn, -ot.idx);
	}
};

const int inf = 1e8;

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.assign(n + n, {0, 0, 0});
		for (int i = 0; i < n; ++i) {
			a[n + i].idx = i;
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = min(a[i + i], a[i + i + 1]);
		}
	}

	void relax(int v) {
		a[v] = min(a[v + v], a[v + v + 1]);
		a[v].sub = 0;
	}

	void push(int v) {
		if (a[v].sub) {
			for (int t : {0, 1}) {
				a[v + v + t].mn -= a[v].sub;
				a[v + v + t].sub += a[v].sub;
			}
			a[v].sub = 0;
		}
	}

	Node get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return {inf, 0, -1};
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		push(v);
		int m = (l1 + r1) / 2;
		return min(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	Node get(int l, int r) {
		return get(1, 0, n, l, r);
	}

	void sub(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].mn -= x;
			a[v].sub += x;
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		sub(v + v, l1, m, l, r, x);
		sub(v + v + 1, m, r1, l, r, x);
		relax(v);
	}

	void sub(int l, int r, int x) {
		sub(1, 0, n, l, r, x);
	}

	void chg(int pos, int x) {
		vector<int> path;
		pos += n;
		while (pos) {
			path.push_back(pos);
			pos /= 2;
		}
		reverse(all(path));
		for (int x : path) {
			if (x < n) {
				push(x);
			}
		}
		pos = path.back();
		a[pos] = {x, 0, pos - n};
		pos /= 2;
		while (pos) {
			relax(pos);
			pos /= 2;
		}
	}
};

struct Query {
	int l, r, idx;

	bool operator <(const Query& ot) const {
		return tie(l, r) < tie(ot.l, ot.r);
	}
};

struct Fenwick {
	int n;
	vector<int> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, int x) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	int get(int pos) {
		int res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), q = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = i + 1 - nxt();
		if (a[i] < 0) {
			a[i] = inf;
		}
	}
	vector<Query> qrs(q);
	for (int i = 0; i < q; ++i) {
		qrs[i].l = nxt();
		qrs[i].r = n - nxt();
		qrs[i].idx = i;
	}

	sort(all(qrs));
	vector<int> ans(q);

	Fenwick fenw(n);
	SegTree tree(n);
	for (int i = n - 1; i >= 0; --i) {
		tree.chg(i, a[i]);
		while (true) {
			auto nd = tree.get(i, n);
			if (nd.mn == 0) {
				// cerr << i + 1 << ": " << nd.idx + 1 << "\n";
				fenw.add(nd.idx, 1);
				tree.chg(nd.idx, inf);
				tree.sub(nd.idx, n, 1);
			} else {
				// cerr << i + 1 << " -- {mn: " << nd.mn << ", sub: " << nd.sub << ", idx: " << nd.idx << "}\n";
				break;
			}
		}
		while (!qrs.empty() && qrs.back().l == i) {
			ans[qrs.back().idx] = fenw.get(qrs.back().r - 1);
			qrs.pop_back();
		}
	}

	for (int x : ans) {
		cout << x << "\n";
	}

	return 0;
}