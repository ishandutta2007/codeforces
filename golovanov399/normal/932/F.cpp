#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Linear {
	long long a, b;

	long long get(long long t) const {
		return a * t + b;
	}
};

struct PwLinear {
	vector<long double> ts;
	vector<Linear> fs;

	PwLinear() {}

	PwLinear(const Linear& f) {
		ts = {};
		fs = {f};
	}

	long long get(long long x) {
		int idx = lower_bound(all(ts), x) - ts.begin();
		return fs[idx].get(x);
	}
};

#define merge lisfdgh

PwLinear merge(const PwLinear& a, const PwLinear& b) {
	if (b.fs.empty()) {
		return a;
	}

	PwLinear res;
	int l = 0, r = 0;
	bool first_less = a.fs[l].a > b.fs[l].a;
	if (a.fs[0].a == b.fs[0].a) {
		first_less = a.fs[l].b < b.fs[l].b;
	}
	res.fs = {first_less ? a.fs[l] : b.fs[l]};
	auto ff = a.fs[0], sf = b.fs[0];
	while (l < (int)a.ts.size() && r < (int)b.ts.size()) {
		long double t;
		int changed_idx = 0;
		if (a.ts[l] < b.ts[r]) {
			t = a.ts[l];
			++l;
		} else {
			t = b.ts[r];
			++r;

			changed_idx = 1;
		}

		bool new_first_less = (ff.a * t + ff.b < sf.a * t + sf.b);
		if (new_first_less != first_less) {
			long double mid_t = (long double)(ff.b - sf.b) / (sf.a - ff.a);
			res.ts.push_back(mid_t);
			res.fs.push_back(first_less ? sf : ff);
			first_less = new_first_less;
		}

		bool leader_changed = (changed_idx != first_less);
		if (leader_changed) {
			res.ts.push_back(t);
			res.fs.push_back(changed_idx ? b.fs[r] : a.fs[l]);
		}

		ff = a.fs[l];
		sf = b.fs[r];
	}

	while (l < (int)a.ts.size()) {
		long double t = a.ts[l];
		int changed_idx = 0;
		++l;

		bool new_first_less = (ff.a * t + ff.b < sf.a * t + sf.b);
		if (new_first_less != first_less) {
			long double mid_t = (long double)(ff.b - sf.b) / (sf.a - ff.a);
			res.ts.push_back(mid_t);
			res.fs.push_back(first_less ? sf : ff);
			first_less = new_first_less;
		}

		bool leader_changed = (changed_idx != first_less);
		if (leader_changed) {
			res.ts.push_back(t);
			res.fs.push_back(changed_idx ? b.fs[r] : a.fs[l]);
		}

		ff = a.fs[l];
	}
	while (r < (int)b.ts.size()) {
		long double t = b.ts[r];
		int changed_idx = 1;
		++r;

		bool new_first_less = (ff.a * t + ff.b < sf.a * t + sf.b);
		if (new_first_less != first_less) {
			long double mid_t = (long double)(ff.b - sf.b) / (sf.a - ff.a);
			res.ts.push_back(mid_t);
			res.fs.push_back(first_less ? sf : ff);
			first_less = new_first_less;
		}

		bool leader_changed = (changed_idx != first_less);
		if (leader_changed) {
			res.ts.push_back(t);
			res.fs.push_back(changed_idx ? b.fs[r] : a.fs[l]);
		}

		sf = b.fs[r];
	}

	bool new_first_less = (ff.a < sf.a);
	if (ff.a == sf.a) {
		new_first_less = ff.b < sf.b;
	}
	if (new_first_less != first_less) {
		long double mid_t = (long double)(ff.b - sf.b) / (sf.a - ff.a);
		res.ts.push_back(mid_t);
		res.fs.push_back(first_less ? sf : ff);
		first_less = new_first_less;
	}

	return res;
}

struct SegTree {
	int n;
	vector<PwLinear> a;
	vector<int> cap;
	vector<int> good;

	SegTree() {}

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
		cap.resize(n + n);
		good.resize(n + n);

		for (int i = 1; i < n * 2; ++i) {
			cap[i] = n >> (31 - __builtin_clz(i));
		}
	}

	long long getMin(int v, int l1, int r1, int l, int r, long long x) {
		if (l >= r1 || l1 >= r) {
			return LLONG_MAX;
		}
		if (l <= l1 && r >= r1) {
			return a[v].get(x);
		}
		int mid = (l1 + r1) / 2;
		return min(getMin(v + v, l1, mid, l, r, x),
				   getMin(v + v + 1, mid, r1, l, r, x));
	}

	long long getMin(int l, int r, int x) {
		return getMin(1, 0, n, l, r, x);
	}

	void mark(int v, const Linear& f) {
		// cerr << "mark " << v << "\n";
		v += n;
		a[v] = f;
		good[v] += 1;
		while (v > 1) {
			v /= 2;
			good[v] += 1;
			if (good[v] == cap[v]) {
				// cerr << v << " is full now\n";
				a[v] = merge(a[v * 2], a[v * 2 + 1]);
			}
		}
	}
};

const int N = 111111;
vector<int> a[N];
int ar[N], br[N];
int timer = 0;
SegTree tree;
long long ans[N];

void dfs(int v, int p = -1) {
	int tin = ++timer;
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
	}
	int tout = timer;
	// cerr << v << ": [" << tin << ", " << tout << ")\n";
	if (tin == tout) {
		ans[v] = 0;
	} else {
		ans[v] = tree.getMin(tin, tout, ar[v]);
	}
	tree.mark(tin - 1, {br[v], ans[v]});
	// cerr << v << " is dfsed\n";
}

int main() {
	int n = nxt();
	for (int i = 0; i < n; ++i) {
		ar[i] = nxt();
	}
	for (int i = 0; i < n; ++i) {
		br[i] = nxt();
	}
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	tree = SegTree(n);
	dfs(0);

	for (int i = 0; i < n; ++i) {
		printf("%lld ", ans[i]);
	}
	printf("\n");

	return 0;
}