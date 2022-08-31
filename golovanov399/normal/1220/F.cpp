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
	int to_push;
	int mx;
};

struct SegTree {
	int n;
	vector<Node> a;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.assign(n + n, {0, 0});
	}

	void push(int v) {
		if (a[v].to_push != 0) {
			a[v + v].to_push += a[v].to_push;
			a[v + v].mx += a[v].to_push;
			a[v + v + 1].to_push += a[v].to_push;
			a[v + v + 1].mx += a[v].to_push;
			a[v].to_push = 0;
		}
	}

	void add(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].to_push += x;
			a[v].mx += x;
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);
		a[v].mx = max(a[v + v].mx, a[v + v + 1].mx);
	}

	void add(int l, int r, int x) {
		add(1, 0, n, l, r, x);
	}

	int get(int v, int l1, int r1, int l, int r) const {
		if (l >= r1 || l1 >= r) {
			return 0;
		}
		if (l <= l1 && r >= r1) {
			return a[v].mx;
		}
		// push(v);
		int m = (l1 + r1) / 2;
		return a[v].to_push + max(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	int get(int l, int r) const {
		return get(1, 0, n, l, r);
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	vector<int> b(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt() - 1;
		b[a[i]] = i;
	}

	set<int> S = {-1, n};
	SegTree tree(2 * n);
	for (int i = 0; i < n; ++i) {
		int pos = b[i];
		auto it = S.lower_bound(pos);
		int l = *prev(it) + 1;
		int r = *it;
		tree.add(l, r, 1);
		S.insert(pos);
	}

	vector<pair<int, int>> segs(n);
	{
		set<int> S = {b[0]};
		for (int i = 1; i < n; ++i) {
			auto it = S.lower_bound(b[i]);
			int r = it == S.end() ? *S.begin() : *it;
			int l = it == S.begin() ? *S.rbegin() : *prev(it);
			segs[i] = {l, r};
			S.insert(b[i]);
		}
	}

	pair<int, int> ans = {tree.get(0, n), 0};
	// for (int j = 0; j < n; ++j) {
	// 	cerr << tree.get(j, j + 1) << " ";
	// }
	// cerr << "\n";
	for (int i = 0; i < n; ++i) {
		int x = a[i];
		if (x == 0) {
			// int depth = tree.get(i, i + n);
			tree.add(i + n, i + n + 1, 1);
			// for (int j = 0; j < n; ++j) {
			// 	cerr << tree.get(i + 1 + j, i + 1 + j + 1) << " ";
			// }
			// cerr << "\n";
			continue;
		}
		int r = segs[x].second - i;
		if (r < 0) {
			r += n;
		}
		tree.add(i, i + r, -1);
		int l = i - segs[x].first;
		if (l < 0) {
			l += n;
		}
		int hmm = tree.get(i + n - l, i + n - l + 1);
		tree.add(i + n - l + 1, i + n, 1);
		tree.add(i + n, i + n + 1, hmm + 1);
		ans = min(ans, {tree.get(i + 1, i + n + 1), i + 1});

		// for (int j = 0; j < n; ++j) {
		// 	cerr << tree.get(i + 1 + j, i + 1 + j + 1) << " ";
		// }
		// cerr << "\n";
	}

	cout << ans.first << " " << ans.second << "\n";

	return 0;
}