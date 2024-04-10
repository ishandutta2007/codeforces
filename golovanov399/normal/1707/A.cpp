#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

const int inf = 1e9;

struct Node {
	int val;
	int idx;
	int push;

	bool operator <(const Node& ot) const {
		return val < ot.val;
	}
};

Node merge(const Node& a, const Node& b) {
	return {min(a.val, b.val), a.val < b.val ? a.idx : b.idx, 0};
}

struct Segtree {
	int n;
	vector<Node> a;

	Segtree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n, {inf, -1, 0});
	}

	void push(int v) {
		for (int t : {0, 1}) {
			a[v + v + t].val += a[v].push;
			a[v + v + t].push += a[v].push;
		}
		a[v].push = 0;
	}

	Node get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return {inf, -1, 0};
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

	void add(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].val += x;
			a[v].push += x;
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);
		a[v] = merge(a[v + v], a[v + v + 1]);
	}

	void add(int l, int r, int x) {
		add(1, 0, n, l, r, x);
	}

	void upd(int pos, int val) {
		int v = 1, l = 0, r = n;
		while (r > l + 1) {
			push(v);
			int m = (l + r) / 2;
			if (pos >= m) {
				v = v * 2 + 1;
				l = m;
			} else {
				v = v * 2;
				r = m;
			}
		}
		a[v] = {val, pos, 0};
		while (v > 1) {
			v /= 2;
			a[v] = merge(a[v + v], a[v + v + 1]);
		}
	}
};

void solve() {
	int n = nxt(), q = nxt();
	vector<int> a(n);
	generate(all(a), nxt);
	priority_queue<int> pq;
	int cur = 0;
	Segtree tree(n);
	string s(n, '0');
	for (int i = 0; i < n; ++i) {
		if (q < a[i]) {
			pq.push(i);
		} else {
			tree.upd(i, q - a[i]);
			++cur;
			s[i] = '1';
		}
	}
	pair<int, int> ans = {cur, 0};
	vector<vector<int>> ops;
	int it = 0;
	while (!pq.empty() && q--) {
		++it;
		int i = pq.top();
		pq.pop();
		++cur;
		ops.push_back({i});
		while (true) {
			auto nd = tree.get(i, n);
			if (nd.val > 0) {
				break;
			}
			--cur;
			pq.push(nd.idx);
			tree.upd(nd.idx, inf);
			ops.back().push_back(nd.idx);
		}
		tree.add(i, n, -1);
		ans = max(ans, {cur, it});
	}
	for (int i = 0; i < ans.second; ++i) {
		for (int j : ops[i]) {
			s[j] ^= 1;
		}
	}
	cout << s << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}