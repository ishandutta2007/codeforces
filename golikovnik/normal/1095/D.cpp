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

void run() {
	int n;
	cin >> n;
	vector<pair<int, int>> p(n);
	for (auto &x : p) {
		cin >> x.first >> x.second;
		x.first--, x.second--;
	}
	function<bool(int, int)> in = [&](int x, int who) {
		return p[x].first == who || p[x].second == who;
	};
	vector<int> ans;
	ans.reserve(n);
	ans.push_back(0);
	if (in(p[0].first, p[0].second)) {
		ans.push_back(p[0].first);
	} else {
		ans.push_back(p[0].second);
	}
	while (szof(ans) < n) {
		ans.push_back(p[ans[szof(ans) - 2]].first + p[ans[szof(ans) - 2]].second - ans.back());
	}
	for (int x : ans) {
		cout << x + 1 << " ";
	}
	cout << "\n";
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