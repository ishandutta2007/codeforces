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
	vector<long long> to_add;

	SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
		to_add.resize(n + n);
	}

	void relax(int v) {
		a[v + v] += to_add[v];
		to_add[v + v] += to_add[v];
		a[v + v + 1] += to_add[v];
		to_add[v + v + 1] += to_add[v];
		to_add[v] = 0;
	}

	void add(int v, int l1, int r1, int l, int r, long long x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v] += x;
			to_add[v] += x;
			return;
		}
		relax(v);
		int m = (l1 + r1) / 2;
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);
		a[v] = min(a[v + v], a[v + v + 1]);
	}

	void add(int l, int r, long long x) {
		add(1, 0, n, l, r, x);
	}

	long long get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return LLONG_MAX;
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		relax(v);
		int m = (l1 + r1) / 2;
		return min(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	long long get(int l, int r) {
		return get(1, 0, n, l, r);
	}
};

const int N = 555555;
vector<int> a[N];
int tin[N];
int tout[N];
int sz[N];
int timer;

void dfs(int v, int p = -1) {
	int pid = -1;
	for (int i = 0; i < (int)a[v].size(); ++i) {
		if (a[v][i] == p) {
			pid = i;
			continue;
		}
		dfs(a[v][i], v);
		sz[v] += sz[a[v][i]];
	}
	sz[v] += 1;
	if (pid > -1) {
		a[v].erase(a[v].begin() + pid);
	}
	sort(all(a[v]), [&](int x, int y) {
		return sz[x] < sz[y];
	});
}

void dfstm(int v) {
	tin[v] = timer++;
	for (int x : a[v]) {
		dfstm(x);
	}
	tout[v] = timer;
}

struct ChShit {
	vector<long long> xs, ys;

	void clear() {
		xs.clear();
		ys.clear();
	}

	void add(long long x, long long y) {
		if (!xs.empty() && xs.back() == x && ys.back() <= y) {
			return;
		}
		while (!xs.empty() && xs.back() == x) {
			xs.pop_back();
			ys.pop_back();
		}
		while ((int)xs.size() >= 2) {
			int s = xs.size();
			if ((xs[s - 1] - xs[s - 2]) * (y - ys[s - 1]) - (ys[s - 1] - ys[s - 2]) * (x - xs[s - 1]) <= 0) {
				xs.pop_back();
				ys.pop_back();
			} else {
				break;
			}
		}

		xs.push_back(x);
		ys.push_back(y);
	}

	long long get(long long a, long long b) {
		// find min(ax + by)
		while ((int)xs.size() >= 2) {
			int s = xs.size();
			if (a * xs[s - 1] + b * ys[s - 1] >= a * xs[s - 2] + b * ys[s - 2]) {
				xs.pop_back();
				ys.pop_back();
			} else {
				break;
			}
		}
		return a * xs.back() + b * ys.back();
	}
};

ChShit shit;

int n;
long long answer = LLONG_MAX;
void getAnswer(int v, SegTree& tree) {
	for (int x : a[v]) {
		getAnswer(x, tree);
	}
	// cerr << v << ": ";
	// for (int i = 0; i < n; ++i) {
	// 	cerr << tree.get(tin[i], tin[i] + 1) << " ";
	// }
	// cerr << "\n";
	for (int x : a[v]) {
		if (!shit.xs.empty()) {
			// cerr << v << " " << x << " " << tin[x] << " " << tout[x] << " " << tree.get(tin[x], tout[x]) << " " << tree.get(tin[x], tout[x]) + 1ll * sz[x] * (sz[x] + 1) / 2 - 1ll * n * sz[x] + shit.get(sz[x], 1) + 1ll * n * (n - 1) / 2 << "\n";
			answer = min(answer, tree.get(tin[x], tout[x]) + 1ll * sz[x] * (sz[x] + 1) / 2 - 1ll * n * sz[x] + shit.get(sz[x], 1));
		}
		shit.add(sz[x], tree.get(tin[x], tout[x]) + 1ll * sz[x] * (sz[x] + 1) / 2 - 1ll * n * sz[x]);
	}
	for (int x : a[v]) {
		answer = min(answer, tree.get(tin[x], tout[x]) + 1ll * (n - sz[x]) * (n - sz[x] - 1) / 2 - 1ll * n * (n - 1) / 2);
		// cerr << v << " " << x << " " << tree.get(tin[x], tout[x]) + 1ll * (n - sz[x]) * (n - sz[x] - 1) / 2 << "\n";
		tree.add(tin[x], tout[x], 1ll * (sz[v] - sz[x]) * (sz[v] - sz[x] - 1) / 2);
		// cerr << "add " << 1ll * (sz[v] - sz[x]) * (sz[v] - sz[x] - 1) / 2 << " to " << x << "\n";
	}
	shit.clear();
	tree.add(tin[v], tin[v] + 1, 1ll * sz[v] * (sz[v] - 1) / 2);
	// cerr << v << " " << tin[v] << " " << 1ll * sz[v] * (sz[v] - 1) / 2 << "\n";
}

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

	n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	dfs(0);
	dfstm(0);

	SegTree tree(n);
	getAnswer(0, tree);
	cout << -answer + 1ll * n * (n - 1) / 2 << "\n";

	return 0;
}