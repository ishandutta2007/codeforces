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

struct SegTree {
	int n;
	vector<long long> a;
	vector<long long> ad;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
		ad.resize(n + n);
	}

	void push(int v) {
		if (ad[v]) {
			ad[v + v] += ad[v];
			a[v + v] += ad[v];
			ad[v + v + 1] += ad[v];
			a[v + v + 1] += ad[v];
			ad[v] = 0;
		}
	}

	void add(int v, int l1, int r1, int l, int r, long long x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			ad[v] += x;
			a[v] += x;
			return;
		}
		int m = (l1 + r1) / 2;
		push(v);
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);
		a[v] = max(a[v + v], a[v + v + 1]);
	}

	void add(int l, int r, long long x) {
		add(1, 0, n, l, r, x);
	}

	long long get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return -1e18;
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		int m = (l1 + r1) / 2;
		push(v);
		return max(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	long long get(int l, int r) {
		return get(1, 0, n, l, r);
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt(), m = nxt(), p = nxt();
	vector<pair<int, int>> a(n);
	for (int i = 0; i < n; ++i) {
		a[i].first = nxt();
		a[i].second = nxt();
	}
	sort(all(a));
	map<int, int> B;
	for (int i = 0; i < m; ++i) {
		int x = nxt(), y = nxt();
		if (!B.count(x)) {
			B[x] = y;
		} else {
			B[x] = min(B[x], y);
		}
	}
	vector<int> all_guys;
	vector<int> costs;
	for (auto [x, y] : B) {
		all_guys.push_back(x);
		costs.push_back(y);
	}

	int sz = all_guys.size();

	vector<array<int, 3>> events;
	for (int i = 0; i < n; ++i) {
		events.push_back({a[i].first, -1, a[i].second});
	}
	for (int i = 0; i < p; ++i) {
		int x = nxt(), y = nxt(), z = nxt();
		events.push_back({x, y, z});
	}
	sort(all(events));
	SegTree tree(sz);
	for (int i = 0; i < sz; ++i) {
		tree.add(i, i + 1, -costs[i]);
	}
	long long ans = -1e18;
	for (const auto& ev : events) {
		int y = ev[1], cost = ev[2];
		if (y == -1) {
			ans = max(ans, -cost + tree.get(0, sz));
		} else {
			tree.add(upper_bound(all(all_guys), y) - all_guys.begin(), sz, cost);
		}
	}

	cout << ans << "\n";

	return 0;
}