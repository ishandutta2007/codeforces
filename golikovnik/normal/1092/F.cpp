// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str to_string

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

const int N = 2e5 + 20;

int a[N];
vector<int> graph[N];
ll s[N];
ll ans;
ll total;

void dfs(int u, int p = -1, int d = 0) {
	s[u] = a[u];
	for (int v : graph[u]) if (v != p) {
		ans += 1LL * a[v] * (d + 1);
		dfs(v, u, d + 1);
		s[u] += s[v];
	}
}

void dfs2(int u, ll cur, int p) {
	cur -= s[u];
	cur += total - s[u];
	ans = max(ans, cur);
	for (int v : graph[u]) if (v != p) {
		dfs2(v, cur, u);
	}
}

void run() {
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		total += a[i];
	}
	for (int i = 1; i < n; i++) {
		int u, v;
		cin >> u >> v;
		--u, --v;
		graph[u].push_back(v);
		graph[v].push_back(u);
	}
	dfs(0);
	ll root = ans;
	for (int u : graph[0]) {
		dfs2(u, root, 0);
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