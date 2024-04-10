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
	int n, k;
	cin >> n >> k;
	if (k > n) {
		cout << "NO\n";
		return;
	}
	vector<int> a(n);
	map<int, vector<int>> mp;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		mp[x].push_back(i);
		if (szof(mp[x]) > k) {
			cout << "NO\n";
			return;
		}
	}
	cout << "YES\n";
	int c = 0;
	vector<int> ans(n);
	for (auto &[_, v] : mp) {
		for (int x : v) {
			ans[x] = c++;
			c %= k;
		}
	}
	for (int i = 0; i < n; i++) {
		cout << ans[i] + 1 << " ";
	}
	cout << "\n";
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