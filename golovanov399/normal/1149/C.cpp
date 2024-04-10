#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

struct Node {
	int to_add;
	int max_x, min_x, max_xyx, max_xyy, max_yyx;

	explicit Node(int x = 0) {
		to_add = 0;
		max_x = min_x = x;
		max_xyx = 0;
		max_xyy = max_yyx = -x;
	}

	void add(int x) {
		to_add += x;
		max_x += x;
		min_x += x;
		max_xyy -= x;
		max_yyx -= x;
	}
};

ostream& operator <<(ostream& ostr, const Node& node) {
	ostr << "{" << "to_add: " << node.to_add << ", max_x: " << node.max_x << ", min_x: " << node.min_x << ", max_xyx: " << node.max_xyx << ", max_xyy: " << node.max_xyy << ", max_yyx: " << node.max_yyx << "}";
	return ostr;
}

void merge(const Node& l, const Node& r, Node& res) {
	res.max_x = max(l.max_x, r.max_x);
	res.min_x = min(l.min_x, r.min_x);
	res.max_xyy = max({l.max_xyy, r.max_xyy, l.max_x - 2 * r.min_x});
	res.max_yyx = max({l.max_yyx, r.max_yyx, r.max_x - 2 * l.min_x});
	res.max_xyx = max({l.max_xyx, r.max_xyx, l.max_x + r.max_yyx, l.max_xyy + r.max_x});
}

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(vector<int> ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = Node(ar[i]);
		}
		for (int i = n - 1; i > 0; --i) {
			merge(a[i + i], a[i + i + 1], a[i]);
		}
		// for (int i = 1; i < 2 * n; ++i) {
		// 	cerr << a[i] << "\n";
		// 	if ((i & (i + 1)) == 0) {
		// 		cerr << "\n";
		// 	}
		// }
	}

	void relax(int v) {
		a[v + v].add(a[v].to_add);
		a[v + v + 1].add(a[v].to_add);
		a[v].to_add = 0;
	}

	void add(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].add(x);
			return;
		}
		relax(v);
		int m = (l1 + r1) / 2;
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);
		merge(a[v + v], a[v + v + 1], a[v]);
	}

	void add(int l, int r, int x) {
		add(1, 0, n, l, r, x);
	}

	int getDiam() const {
		return max(a[1].max_x, a[1].max_xyx);
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n = nxt(), q = nxt();
	string s;
	cin >> s;
	vector<int> ar(2 * n - 1);
	for (int i = 0; i < 2 * n - 2; ++i) {
		if (s[i] == '(') {
			ar[i + 1] = ar[i] + 1;
		} else {
			ar[i + 1] = ar[i] - 1;
		}
	}

	SegTree tree(ar);
	cout << tree.getDiam() << "\n";
	while (q--) {
		int l = nxt() - 1, r = nxt() - 1;
		if (l > r) {
			swap(l, r);
		}
		int x = (s[l] == '(') ? -2 : 2;
		swap(s[l], s[r]);
		tree.add(l + 1, r + 1, x);

		cout << tree.getDiam() << "\n";
		// cerr << tree.a[1] << "\n";
	}

	return 0;
}