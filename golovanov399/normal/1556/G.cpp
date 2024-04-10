#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

struct Node {
	int left, right;
	long long l, r;
	bool blocked;

	Node() {}
	Node(long long _l, long long _r): left(-1), right(-1), l(_l), r(_r), blocked(false) {}
};

const int N = 50505 * 200;
Node nodes[N];
int sz = 0;

struct Query {
	int type;
	long long l, r;
};

void create_more(int v, long long l, long long r) {
	if (l >= nodes[v].r || nodes[v].l >= r) {
		return;
	}
	if (nodes[v].l >= l && nodes[v].r <= r) {
		nodes[v].blocked = true;
		return;
	}
	if (nodes[v].left == -1) {
		long long len = nodes[v].r - nodes[v].l;
		nodes[v].left = sz;
		nodes[sz++] = Node(nodes[v].l, nodes[v].l + len / 2);
		nodes[v].right = sz;
		nodes[sz++] = Node(nodes[v].l + len / 2, nodes[v].r);
	}
	create_more(nodes[v].left, l, r);
	create_more(nodes[v].right, l, r);
}

int idx[N];
vector<int> g[N];

void add_edge(int u, int v) {
	// cerr << u << " " << v << "\n";
	g[u].push_back(v);
	g[v].push_back(u);
}

void draw_edges(int v, int rem, long long l, long long r, long long bit, int to) {
	// cerr << "draw edges " << to << " -> [" << nodes[v].l << ", " << nodes[v].r << ")\n";
	if (nodes[v].left == -1) {
		if (l + bit > r || to < idx[v]) {
			add_edge(to, idx[v]);
		}
		return;
	}
	if (l + bit == r) {
		// cerr << nodes[v].l << " " << nodes[v].r << " return\n";
		return;
	}
	bit >>= 1;
	draw_edges(l & bit ? nodes[v].right : nodes[v].left, rem, l, r, bit, to);
	if (rem) {
		draw_edges(l & bit ? nodes[v].left : nodes[v].right, rem - 1, l, r, bit, to);
	}
}

struct Dsu {
	int n;
	vector<int> p, rk;

	Dsu(int _n): p(_n), rk(_n) {
		iota(all(p), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	bool merge(int u, int v) {
		u = get(u), v = get(v);
		if (u == v) {
			return false;
		}
		if (rk[u] < rk[v]) {
			swap(u, v);
		}
		p[v] = u;
		if (rk[u] == rk[v]) {
			++rk[u];
		}
		return true;
	}
};

int find_block(long long x) {
	int v = 0;
	while (nodes[v].left > -1) {
		int u = nodes[v].left;
		if (nodes[u].r > x) {
			v = u;
		} else {
			v = nodes[v].right;
		}
	}
	return idx[v];
}

void solve() {
	int n = nxt(), q = nxt();
	nodes[sz++] = Node(0, 1ll << n);
	vector<Query> qrs(q);
	for (int i = 0; i < q; ++i) {
		string s;
		cin >> s;
		long long l, r;
		cin >> l >> r;
		if (s == "block") {
			r += 1;
		}
		qrs[i] = {s == "block" ? 0 : 1, l, r};
		if (s == "block") {
			create_more(0, l, r);
		}
	}

	vector<int> blocks;
	memset(idx, -1, sizeof(idx));
	for (int i = 0; i < sz; ++i) {
		if (nodes[i].left == -1) {
			idx[i] = blocks.size();
			blocks.push_back(i);
		}
	}
	const int cnt = blocks.size();
	for (int i = 0; i < cnt; ++i) {
		int v = blocks[i];
		draw_edges(0, 1, nodes[v].l, nodes[v].r, 1ll << n, i);
	}

	Dsu dsu(cnt);
	auto enable = [&](int v) {
		nodes[blocks[v]].blocked = false;
		for (int u : g[v]) {
			if (!nodes[blocks[u]].blocked) {
				dsu.merge(u, v);
			}
		}
	};
	for (int i = 0; i < cnt; ++i) {
		int v = blocks[i];
		if (!nodes[v].blocked) {
			enable(i);
		}
	}
	vector<int> ans;

	// for (int i : blocks) {
	// 	cerr << "[" << nodes[i].l << ", " << nodes[i].r << ") ";
	// }
	// cerr << "\n";

	function<void(int, long long, long long)> unblock = [&](int v, long long l, long long r) {
		if (l >= nodes[v].r || nodes[v].l >= r) {
			return;
		}
		if (nodes[v].l >= l && nodes[v].r <= r) {
			enable(idx[v]);
			return;
		}
		assert(nodes[v].left > -1);
		unblock(nodes[v].left, l, r);
		unblock(nodes[v].right, l, r);
	};

	for (int i = q - 1; i >= 0; --i) {
		if (qrs[i].type) {
			int x = find_block(qrs[i].l);
			int y = find_block(qrs[i].r);
			ans.push_back(dsu.get(x) == dsu.get(y));
		} else {
			unblock(0, qrs[i].l, qrs[i].r);
		}
	}
	reverse(all(ans));
	for (int x : ans) {
		cout << x << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}