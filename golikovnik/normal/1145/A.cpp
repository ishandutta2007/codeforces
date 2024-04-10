#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;

typedef long long ll;
typedef long double ld;
typedef unsigned int uint;
typedef unsigned long long ull;

const int MOD = 1e9 + 7;
const int MOD998 = 998244353;
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
	vector<int> a(n);
	for (int &x : a) {
		cin >> x;
	}
	vector<vector<bool>> sorted(n, vector<bool>(n));
	for (int i = 0; i < n; i++) {
		for (int j = i; j < n; j++) {
			sorted[i][j] = is_sorted(a.begin() + i, a.begin() + j + 1);
		}
	}
	function<int(int, int)> solve = [&](int l, int r) {
		if (sorted[l][r]) {
			return r - l + 1;
		}
		int m = (l + r) / 2;
		return max(solve(l, m), solve(m + 1, r));
	};
	cout << solve(0, n - 1) << "\n";
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