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

struct Edge {
	int u, v;
	int w;

	int id;
};

struct Dsu {
	int n;
	vector<int> p;
	vector<int> rk;

	Dsu(int _n): n(_n) {
		p.resize(n);
		rk.assign(n, 0);
		for (int i = 0; i < n; ++i) {
			p[i] = i;
		}
	}

	int get(int v) {
		return p[v] == v ? v : p[v] = get(p[v]);
	}

	bool merge(int u, int v) {
		u = get(u), v = get(v);
		if (u == v) {
			return false;
		}
		if (rk[u] > rk[v]) {
			swap(u, v);
		}
		p[v] = u;
		if (rk[u] == rk[v]) {
			rk[u] += 1;
		}
		return true;
	}
};

void dfs(const vector<vector<int>>& a, int v, vector<char>& used) {
	used[v] = 1;
	for (int x : a[v]) {
		if (!used[x]) {
			dfs(a, x, used);
		}
	}
}

int main() {
	int n = nxt(), m = nxt();
	vector<Edge> edges(m);
	for (int i = 0; i < m; ++i) {
		int u = nxt() - 1, v = nxt() - 1, w = nxt();
		edges[i] = {u, v, w, i};
	}

	sort(all(edges), [](const Edge& e1, const Edge& e2) {
		return e1.w > e2.w;
	});

	vector<char> cycled(n);
	vector<vector<int>> ed(n);
	Dsu dsu(n);

	long long ans = 0;
	for (auto e : edges) {
		if (cycled[e.u] && cycled[e.v]) {
			continue;
		}
		ans += e.w;
		if (!dsu.merge(e.u, e.v)) {
			dfs(ed, e.u, cycled);
		} else {
			ed[e.u].push_back(e.v);
			ed[e.v].push_back(e.u);
			if (cycled[e.u] || cycled[e.v]) {
				int v = (cycled[e.u] ? e.v : e.u);
				dfs(ed, v, cycled);
			}
		}
	}

	cout << ans << "\n";

	return 0;
}