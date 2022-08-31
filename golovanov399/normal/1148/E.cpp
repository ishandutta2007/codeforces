#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#define random_shuffle(...) shuffle(__VA_ARGS__, rng)
#define rand() rng()

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct SegTree {
	int n;
	vector<pair<long long, int>> a;
	vector<long long> to_add;

	SegTree(const vector<long long>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = {ar[i], i};
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = min(a[i + i], a[i + i + 1]);
		}
		to_add.assign(n + n, 0);
	}

	void push(int v) {
		for (int x : {v + v, v + v + 1}) {
			to_add[x] += to_add[v];
			a[x].first += to_add[v];
		}
		to_add[v] = 0;
	}

	pair<long long, int> get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return {LLONG_MAX, 0};
		} else if (l <= l1 && r >= r1) {
			return a[v];
		}
		push(v);
		int m = (l1 + r1) / 2;
		return min(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	pair<long long, int> get(int l, int r) {
		return get(1, 0, n, l, r);
	}

	void add(int v, int l1, int r1, int l, int r, long long x) {
		if (l >= r1 || l1 >= r) {
			return;
		} else if (l <= l1 && r >= r1) {
			a[v].first += x;
			to_add[v] += x;
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);
		a[v] = min(a[v + v], a[v + v + 1]);
	}

	void add(int l, int r, long long x) {
		add(1, 0, n, l, r, x);
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<pair<int, int>> a(n), b(n);
	for (int i = 0; i < n; ++i) {
		a[i] = {nxt(), i};
	}
	for (int i = 0; i < n; ++i) {
		b[i] = {nxt(), i};
	}
	sort(all(a));
	sort(all(b));
	long long s = 0, t = 0;
	vector<long long> diff;
	for (int i = 0; i < n; ++i) {
		s += a[i].first;
		t += b[i].first;
		if (s > t) {
			cout << "NO\n";
			return 0;
		}
		diff.push_back(t - s);
	}
	if (s != t) {
		cout << "NO\n";
		return 0;
	}
	printf("YES\n");

	vector<tuple<int, int, long long>> ans;
	SegTree tree(diff);
	vector<pair<int, int>> st = {{0, n}};
	while (!st.empty()) {
		auto [l, r] = st.back();
		st.pop_back();
		if (r <= l) {
			continue;
		}
		auto p = tree.get(l, r);
		// cerr << "[" << l << ", " << r << "): " << p.second << " (" << p.first << ")\n";
		if (p.first > 0) {
			ans.push_back({a[l].second, a[r].second, p.first});
			tree.add(l, r, -p.first);
		}
		st.push_back({l, p.second});
		st.push_back({p.second + 1, r});
	}

	printf("%d\n", (int)ans.size());
	for (const auto& [i, j, x] : ans) {
		printf("%d %d %lld\n", i + 1, j + 1, x);
	}

	return 0;
}