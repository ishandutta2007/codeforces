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

struct Dsu {
	int n;
	vector<int> p, rk;

	Dsu(int _n): n(_n), p(_n), rk(_n) {
		iota(all(p), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	bool merge(int u, int v) {
		u = get(u);
		v = get(v);
		if (u == v) {
			return false;
		}
		if (rk[u] < rk[v]) {
			swap(u, v);
		}
		p[v] = u;
		if (rk[u] == rk[v]) {
			++rk[u];
		}
		return true;
	}
};

struct Edge {
	int to;
	long long cost;
};

const int N = 222222;
vector<Edge> g[N];

void add_edge(int u, int v, long long cost) {
	cost = -cost;
	g[u].push_back({v, cost});
	g[v].push_back({u, cost});
}

char used[N];
void handle(int v, set<pair<long long, int>>& S) {
	used[v] = true;
	for (const auto& e : g[v]) {
		if (used[e.to]) {
			continue;
		}
		S.insert({e.cost, e.to});
	}
}

void solve() {
	int m = nxt(), n = nxt();
	vector<long long> a(m), b(n);
	generate(all(a), nxt);
	generate(all(b), nxt);
	long long ans = 0;
	for (int i = 0; i < m; ++i) {
		int k = nxt();
		while (k --> 0) {
			int x = nxt() - 1;
			add_edge(i, m + x, a[i] + b[x]);
			ans += a[i] + b[x];
		}
	}

	set<pair<long long, int>> S;
	for (int i = 0; i < n + m; ++i) {
		if (used[i]) {
			continue;
		}

		handle(i, S);
		while (!S.empty()) {
			auto [c, v] = *S.begin();
			S.erase(S.begin());
			if (used[v]) {
				continue;
			}
			ans += c;
			handle(v, S);
		}
	}

	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}