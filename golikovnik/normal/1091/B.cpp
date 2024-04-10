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
	int n;
	cin >> n;
	vector<pt> a(n), b(n);
	set<pt> pts;
	for (auto &x : a) {
		cin >> x.first >> x.second;
	}
	for (auto &x : b) {
		cin >> x.first >> x.second;
		pts.insert(x);
	}
	for (int i = 0; i < n; i++) {
		int x = a[0].first + b[i].first, y = a[0].second + b[i].second;
		bool ok = 1;
		for (int j = 1; j < n; j++) {
			int need_x = x - a[j].first, need_y = y - a[j].second;
			ok &= ((need_x != b[i].first || need_y != b[i].second) && pts.find({need_x, need_y}) != pts.end());
		}
		if (ok) {
			cout << x << " " << y << "\n";
			return;
		}
	}
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