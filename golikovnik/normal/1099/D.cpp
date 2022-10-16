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

void run() {
	int n;
	cin >> n;
	vector<vector<int>> graph(n);
	for (int i = 1; i < n; i++) {
		int p;
		cin >> p;
		graph[p - 1].push_back(i);
	}	
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
	}
	vector<int> vals(n);
	function<void(int, int, int)> dfs = [&](int u, int depth, int byfar){
		if (depth % 2 == 0) {
			int mn = INF;
			for (int v : graph[u]) {
				mn = min(mn, a[v]);
			}
			if (mn < byfar) {
				cout << "-1\n";
				exit(0);
			}
			vals[u] = (mn == INF ? 0 : mn - byfar);
		} else {
			vals[u] = a[u] - byfar;
		}
		for (int v : graph[u]) {
			dfs(v, depth + 1, byfar + vals[u]);
		}
	};
	dfs(0, 1, 0);
	ll ans = 0;
	for (int x : vals) {
		ans += x;
	}
	cout << ans << "\n";
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << 1.0 * clock() / CLOCKS_PER_SEC << "s.\n";
	return 0;
}