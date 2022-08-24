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

struct Query {
	int id;
	int k, pos;

	bool operator <(const Query& ot) const {
		return k < ot.k;
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

	int getmin(int need) {
		int pos = 0;
		for (int i = (1 << (32 - __builtin_clz(n))); i > 0; i /= 2) {
			if (pos + i <= n && a[pos + i - 1] < need) {
				pos += i;
				need -= a[pos - 1];
			}
		}
		return pos;
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	int m = nxt();
	vector<int> ans(m);
	vector<Query> q(m);
	for (int i = 0; i < m; ++i) {
		q[i].id = i;
		q[i].k = nxt();
		q[i].pos = nxt();
	}
	sort(all(q));

	vector<pair<int, int>> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = {-a[i], i};
	}
	sort(all(ar));
	int idx = 0;
	Fenwick f(n);
	for (int i = 0; i < n; ++i) {
		f.add(ar[i].second, 1);
		while (idx < m && q[idx].k == i + 1) {
			ans[q[idx].id] = a[f.getmin(q[idx].pos)];
			++idx;
		}
	}

	for (int x : ans) {
		printf("%d\n", x);
	}

	return 0;
}