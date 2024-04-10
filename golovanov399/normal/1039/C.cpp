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

const int mod = 1000000007;

struct Dsu {
	int n;
	vector<int> rk, p;

	Dsu(int _n): n(_n), rk(_n), p(_n) {
		iota(all(p), 0);
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
		if (rk[u] == rk[v]) {
			++rk[u];
		}
		return true;
	}
};

int main() {
	mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
	cin.sync_with_stdio(0);

	int n, m, k;
	cin >> n >> m >> k;
	vector<long long> c(n);
	for (int i = 0; i < n; ++i) {
		cin >> c[i];
	}

	vector<array<long long, 3>> ed;
	for (int i = 0; i < m; ++i) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		ed.push_back({c[u] ^ c[v], u, v});
	}

	vector<long long> xs;
	for (auto v : ed) {
		xs.push_back(v[0]);
	}
	make_unique(xs);
	Dsu dsu(2 * m);
	map<pair<int, int>, int> M;
	auto getIdx = [&](int i, int v) {
		auto it = M.find({i, v});
		if (it != M.end()) {
			return it->second;
		} else {
			int sz = M.size();
			return M[{i, v}] = sz;
		}
	};
	for (auto e : ed) {
		int idx = lower_bound(all(xs), e[0]) - xs.begin();
		int u = e[1], v = e[2];

		int du = getIdx(idx, u);
		int dv = getIdx(idx, v);
		dsu.merge(du, dv);
	}

	set<int> used;
	vector<int> num_comps(xs.size(), n);
	for (const auto& [p, v] : M) {
		int par = dsu.get(v);
		if (used.count(par)) {
			--num_comps[p.first];
		} else {
			used.insert(par);
		}
	}

	vector<long long> deg(n + 1);
	deg[0] = 1;
	for (int i = 1; i <= n; ++i) {
		deg[i] = deg[i - 1] * 2 % mod;
	}

	long long ans = 0;
	for (int x : num_comps) {
		ans += deg[x];
	}

	ans += ((1ll << k) - (int)xs.size()) % mod * deg[n] % mod;
	cout << ans % mod << "\n";

	return 0;
}