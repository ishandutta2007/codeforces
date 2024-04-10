// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const ll MOD = 1e9 + 7;
const ll MOD998 = 998244353;
const int INF = 1e9;
const ll LLINF = 1e18;

mt19937_64 rng((uint) chrono::steady_clock::now().time_since_epoch().count());

template <class T>
T rnd(T l, T r) {
	return uniform_int_distribution<T>(l, r)(rng);
}

struct DSU {
	int n;
	vector<int> p;
	vector<ll> cost;

	explicit DSU(int n) : n(n), p(n), cost(n) {
		iota(all(p), 0);
	}

	int get(int v) {
		return p[v] == v ? v : p[v] = get(p[v]);
	}

	ll get_cost(int v) {
		return cost[get(v)];
	}

	bool same_set(int u, int v) {
		return get(u) == get(v);
	}

	int unite(int u, int v) {
		u = get(u), v = get(v);
		if (u == v) {
			throw;
		}
		p[u] = v;
		cost[v] = min(cost[v], cost[u]);
		return v;
	}
};

void run() {
	int n, m;
	cin >> n >> m;
	vector<ll> a(n);
	for (ll &x : a) {
		cin >> x;
	}
	vector<tuple<int, int, ll>> edges(m);
	for (auto &x : edges) {
		int u, v;
		ll w;
		cin >> u >> v >> w;
		u--, v--;
		x = make_tuple(u, v, w);
	}
	sort(all(edges), [](auto &x, auto &y) {
		return get<2>(x) < get<2>(y);
	});
	ll ans = 0;
	DSU dsu(n);
	for (int i = 0; i < n; i++) {
		dsu.cost[i] = a[i];
	}
	set<pair<ll, int>> cc;
	for (int i = 0; i < n; i++) {
		cc.emplace(a[i], i);
	}
	int i = 0;
	for (int it = 0; it < n - 1; it++) {
		ll cost = cc.begin()->first + (++cc.begin())->first;
		while (i < m && dsu.same_set(get<0>(edges[i]), get<1>(edges[i]))) {
			i++;
		}
		if (i == m || cost < get<2>(edges[i])) {
			ans += cost;
			ll res = min(cc.begin()->first, (++cc.begin())->first);
			int a = cc.begin()->second, b = (++cc.begin())->second;
			cc.erase(cc.begin());
			cc.erase(cc.begin());
			cc.emplace(res, dsu.unite(a, b));
		} else {
			ll fi = dsu.get_cost(get<0>(edges[i])), se = dsu.get_cost(get<1>(edges[i]));
			cc.erase({fi, dsu.get(get<0>(edges[i]))});
			cc.erase({se, dsu.get(get<1>(edges[i]))});
			ans += get<2>(edges[i]);
			cc.emplace(min(fi, se), dsu.unite(get<0>(edges[i]), get<1>(edges[i])));
		}
	}
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests;
	tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}