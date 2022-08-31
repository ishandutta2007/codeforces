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
	int bal;
	int minbal;
};

Node merge(const Node& left, const Node& right) {
	return {left.bal + right.bal, min(left.minbal, left.bal + right.minbal)};
}

Node unitnode = {0, (int)1e9};

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
		// for (int i = 1; i < n + n; ++i) {
		// 	a[i].max_minbal = -1e9;
		// }
	}

	Node get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return unitnode;
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

	void add(int pos, int x) {
		pos += n;
		a[pos] = {x, min(0, x)};
		while (pos > 1) {
			pos /= 2;
			a[pos] = merge(a[pos * 2], a[pos * 2 + 1]);
		}
	}

	void inc(int pos) {
		// cerr << "inc " << pos << "\n";
		add(pos, 1);
	}

	void dec(int pos) {
		// cerr << "dec " << pos << "\n";
		add(pos, -1);
	}

	bool isOk(int m) {
		auto node = get(0, m);
		// cerr << node.bal << " " << node.minbal << "\n";
		return node.bal > node.minbal;
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> p(n), q(n);
	for (int i = 0; i < n; ++i) {
		p[nxt() - 1] = i;
	}
	for (int i = 0; i < n; ++i) {
		q[i] = nxt() - 1;
	}

	SegTree tree(2 * n);
	int cur = n - 1;
	for (int i = 0; i < n; ++i) {
		while (!tree.isOk(2 * n)) {
			tree.inc(2 * p[cur--]);
		}
		printf("%d ", cur + 2);
		tree.dec(2 * q[i] + 1);
	}
	printf("\n");

	return 0;
}