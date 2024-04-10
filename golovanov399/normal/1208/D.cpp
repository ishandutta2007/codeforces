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
	pair<long long, int> val;
	long long add;
};

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(const vector<long long>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n * 2);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = {{ar[i], -i}, 0ll};
		}
		for (int i = (int)ar.size(); i < n; ++i) {
			a[n + i] = {{LLONG_MAX / 10, -i}, 0ll};
		}
		for (int i = n - 1; i > 0; --i) {
			a[i].val = min(a[i + i].val, a[i + i + 1].val);
		}
	}

	void relax(int v) {
		if (a[v].add) {
			for (int i = 0; i < 2; ++i) {
				a[v + v + i].add += a[v].add;
				a[v + v + i].val.first += a[v].add;
			}
		}
		a[v].add = 0;
	}

	pair<long long, int> get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return {LLONG_MAX / 10, 0};
		}
		if (l <= l1 && r >= r1) {
			return a[v].val;
		}
		relax(v);
		int m = (l1 + r1) / 2;
		return min(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	pair<long long, int> get(int l, int r) {
		return get(1, 0, n, l, r);
	}

	void add(int v, int l1, int r1, int l, int r, long long x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].val.first += x;
			a[v].add += x;
			return;
		}
		relax(v);
		int m = (l1 + r1) / 2;
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);
		a[v].val = min(a[v + v].val, a[v + v + 1].val);
	}

	void add(int l, int r, long long x) {
		add(1, 0, n, l, r, x);
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<long long> a(n);
	for (int i = 0; i < n; ++i) {
		scanf("%lld", &a[i]);
	}

	SegTree tree(a);
	vector<int> ans(n);
	for (int i = 1; i <= n; ++i) {
		auto [val, pos] = tree.get(0, n);
		pos = -pos;
		// cerr << pos << " " << val << "\n";
		ans[pos] = i;
		tree.add(pos + 1, n, -i);
		tree.add(pos, pos + 1, LLONG_MAX / 10);
	}

	for (int x : ans) {
		printf("%d ", x);
	}
	printf("\n");

	return 0;
}