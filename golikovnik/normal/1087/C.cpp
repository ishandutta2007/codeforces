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

typedef pair<int, int> pt;

void run() {
	vector<pt> a(3);
	for (auto &p : a) {
		cin >> p.first >> p.second;
	}
	pair<int, set<pt>> ans = {INF, {}};
	do {
		set<pt> path;
		int x = a[0].first, y = a[0].second;
		while (x != a[1].first) {
			path.emplace(x, y);
			x = x < a[1].first ? x + 1 : x - 1;
		}
		while (y != a[1].second) {
			path.emplace(x, y);
			y = y < a[1].second ? y + 1 : y - 1;
		}
		while (x != a[2].first || y != a[2].second) {
			path.emplace(x, y);
			int nx = x < a[2].first ? x + 1 : x - 1;
			int ny = y < a[2].second ? y + 1 : y - 1;
			if (path.count({x, ny}) && y != a[2].second) {
				y = ny;
			} else {
				if (x != a[2].first) {
					x = nx;
				} else {
					y = ny;
				}
			}
		}
		path.emplace(x, y);
		ans = min(ans, {szof(path), path});
	} while (next_permutation(all(a)));
	cout << ans.first << "\n";
	for (auto &p : ans.second) {
		cout << p.first << " " << p.second << "\n";
	}
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