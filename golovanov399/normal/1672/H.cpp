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
	int c0;
	array<int, 2> c1;

	Node(): c0(0), c1({0, 0}) {}
	Node(int _c0, int _c10, int _c11): c0(_c0), c1({_c10, _c11}) {}
};

Node merge(const Node& a, const Node& b) {
	return {a.c0 + b.c0, a.c1[0] + b.c1[a.c0 % 2], a.c1[1] + b.c1[(a.c0 + 1) % 2]};
};

Node from_len(int len) {
	return {(len + 1) % 2, len % 2, 0};
}

struct Segtree {
	int n;
	vector<Node> a;

	Segtree(const vector<int>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = Node(!ar[i], ar[i], 0);
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = merge(a[i + i], a[i + i + 1]);
		}
	}

	Node get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return Node();
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		int m = (l1 + r1) / 2;
		return merge(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	Node get(int l, int r) {
		return get(1, 0, n, l, r);
	}
};

void solve() {
	int n = nxt(), q = nxt();
	string s;
	cin >> s;
	assert('0' % 2 == 0);
	for (int i = 1; i < n; i += 2) {
		s[i] ^= 1;
	}

	vector<int> start;
	int last = -1;
	vector<int> ids(n);
	for (int i = 0; i < n; ++i) {
		if (last != s[i] - '0') {
			last = s[i] - '0';
			start.push_back(i);
		}
		ids[i] = (int)start.size() - 1;
	}
	start.push_back(n);
	const int sz = (int)start.size() - 1;
	vector<int> blocks;
	for (int i = 0; i < sz; ++i) {
		blocks.push_back((start[i + 1] - start[i]) % 2);
	}
	Segtree tree(blocks);

	while (q--) {
		int l = nxt() - 1, r = nxt() - 1;
		int li = ids[l], ri = ids[r];
		if (li == ri) {
			cout << "1\n";
			continue;
		}
		Node nd = tree.get(li + 1, ri);
		nd = merge(from_len(start[li + 1] - l), nd);
		nd = merge(nd, from_len(r + 1 - start[ri]));
		if (nd.c0) {
			cout << max(nd.c1[0], nd.c1[1]) + (nd.c0 + 1) / 2 + (nd.c0 % 2 == 0 && nd.c1[0] <= nd.c1[1]) << "\n";
		} else {
			cout << nd.c1[0] + nd.c1[1] << "\n";
		}
		// cout << min(nd.c1[0], nd.c1[1]) << "\n";
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