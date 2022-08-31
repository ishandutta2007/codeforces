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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());

const int N = 444444;
vector<int> a[N];
vector<int> qrs_ids[N];
int sz;

struct Dsu {
	int n;
	vector<int> p, rk, node;

	Dsu(int _n): n(_n), p(_n), rk(_n), node(_n) {
		iota(all(p), 0);
		iota(all(node), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	bool merge(int u, int v) {
		u = get(u), v = get(v);
		if (u == v) {
			return false;
		}
		if (rk[u] < rk[v]) {
			swap(u, v);
		}
		p[v] = u;
		a[sz].push_back(node[u]);
		a[sz].push_back(node[v]);
		node[u] = sz;
		++sz;
		if (rk[u] == rk[v]) {
			++rk[u];
		}
		return true;
	}
};

struct SegTree {
	int n;
	vector<pair<int, int>> a;

	SegTree(const vector<int>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = {ar[i], i};
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = max(a[i + i], a[i + i + 1]);
		}
	}

	pair<int, int> getmax(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return {0, 0};
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		int m = (l1 + r1) / 2;
		return max(getmax(v + v, l1, m, l, r), getmax(v + v + 1, m, r1, l, r));
	}

	void clr(int pos) {
		pos += n;
		a[pos] = {0, 0};
		while (pos > 1) {
			pos /= 2;
			a[pos] = max(a[pos + pos], a[pos + pos + 1]);
		}
	}

	int pop(int l, int r) {
		auto v = getmax(1, 0, n, l, r);
		if (!v.first) {
			return 0;
		}
		clr(v.second);
		return v.first;
	}
};

vector<int> order;
int tin[N], tout[N];
int timer = 0;
char used[N];
void dfs(int v) {
	if (used[v]) {
		return;
	}
	used[v] = 1;
	tin[v] = timer++;
	order.push_back(v);
	for (int x : a[v]) {
		dfs(x);
	}
	tout[v] = timer;
}

void solve() {
	int n = nxt(), m = nxt(), q = nxt();
	vector<int> p(n);
	generate(all(p), nxt);
	vector<pair<int, int>> edges(m);
	for (int i = 0; i < m; ++i) {
		edges[i].first = nxt() - 1;
		edges[i].second = nxt() - 1;
	}
	vector<pair<int, int>> qrs(q);
	vector<char> active(m, 1);
	for (int i = 0; i < q; ++i) {
		int t = nxt(), v = nxt() - 1;
		qrs[i] = {t, v};
		if (t == 2) {
			active[v] = 0;
		}
	}

	Dsu dsu(n);
	sz = n;
	for (int i = 0; i < m; ++i) {
		if (active[i]) {
			dsu.merge(edges[i].first, edges[i].second);
		}
	}

	vector<int> ans;
	for (int i = q - 1; i >= 0; --i) {
		if (qrs[i].first == 1) {
			qrs_ids[dsu.node[dsu.get(qrs[i].second)]].push_back(ans.size());
			ans.push_back(0);
		} else {
			dsu.merge(edges[qrs[i].second].first, edges[qrs[i].second].second);
		}
	}

	for (int i = sz - 1; i >= 0; --i) {
		dfs(i);
	}
	for (int& x : order) {
		x = (x < n) ? p[x] : 0;
	}
	
	SegTree tree(order);
	for (int i = sz - 1; i >= 0; --i) {
		reverse(all(qrs_ids[i]));
		for (int qid : qrs_ids[i]) {
			ans[qid] = tree.pop(tin[i], tout[i]);
		}
	}
	reverse(all(ans));
	for (int x : ans) {
		cout << x << "\n";
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}