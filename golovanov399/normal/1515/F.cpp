#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Edge {
	int to;
	int id;
};

const int N = 333333;
vector<Edge> a[N];
char used[N];

struct Dsu {
	int n;
	vector<int> p, rk;
	vector<long long> sum;

	Dsu(int _n): n(_n), p(_n), rk(_n), sum(_n) {
		iota(all(p), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	long long getsum(int v) {
		return sum[get(v)];
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
		sum[u] += sum[v];
		if (rk[u] == rk[v]) {
			rk[u] += 1;
		}
		return true;
	}
};

vector<int> ans;
int ptr[N];

void dfs(int v, Dsu& dsu) {
	while (ptr[v] < (int)a[v].size()) {
		if (dsu.getsum(v) <= 0) {
			return;
		}
		++ptr[v];
		if (dsu.merge(v, a[v][ptr[v] - 1].to)) {
			ans.push_back(a[v][ptr[v] - 1].id);
			dfs(a[v][ptr[v] - 1].to, dsu);
		}
	}
}

void solve() {
	int n = nxt(), m = nxt(), x = nxt();
	vector<int> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = nxt() - x;
	}
	long long s = accumulate(all(ar), 0ll);
	if (s < -x) {
		cout << "NO\n";
		return;
	}
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back({v, i});
		a[v].push_back({u, i});
	}

	Dsu dsu(n);
	for (int i = 0; i < n; ++i) {
		dsu.sum[i] = ar[i];
	}
	for (int i = 0; i < n; ++i) {
		if (dsu.getsum(i) > 0) {
			dfs(i, dsu);
		}
	}
	for (int i = 0; i < n; ++i) {
		for (const auto& e : a[i]) {
			if (dsu.merge(i, e.to)) {
				ans.push_back(e.id);
			}
		}
	}
	cout << "YES\n";
	for (int x : ans) {
		cout << x + 1 << "\n";
	}
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}