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
	set<int> st;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		st.insert(x);
	}
	auto fail = []() {
		cout << "-1\n";
		exit(0);
	};
	if (st.size() > 3) {
		fail();
	}
	if (st.size() == 1) {
		cout << "0\n";
		return;
	}
	vector<int> vals(all(st));
	if (vals.size() == 2) {
		if (vals[0] % 2 == vals[1] % 2) {
			cout << (vals[0] + vals[1]) / 2 - vals[0] << "\n";
			return;
		}
		cout << vals[1] - vals[0] << "\n";
		return;
	}
	if (vals[1] - vals[0] == vals[2] - vals[1]) {
		cout << vals[1] - vals[0] << "\n";
		return;
	}
	fail();
}

int32_t main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout.precision(10); cout << fixed;
	int tests = 1;
	// cin >> tests;
	while (tests--) {
		run();
	}
	cerr << "Time elapsed: " << static_cast<double>(clock()) / CLOCKS_PER_SEC << "s.\n";
	return 0;
}