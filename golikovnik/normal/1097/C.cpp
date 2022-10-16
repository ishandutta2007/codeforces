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
	map<int, int> ends, starts;
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		int bal = 0;
		int min_bal = INF;
		for (char ch : s) {
			if (ch == '(') {
				bal++;
			} else {
				bal--;
			}
			min_bal = min(min_bal, bal);
		}
		if (min_bal < 0) {
			if (min_bal == bal) {
				ends[bal]++;
			}
		} else {
			starts[bal]++;
		}
	}
	int ans = 0;
	for (auto[k, v] : starts) {
		if (k) {
			ans += min(v, ends[-k]);
		} else {
			ans += min(v, ends[0]);
			v -= min(v, ends[0]);
			ans += v / 2;
		}
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