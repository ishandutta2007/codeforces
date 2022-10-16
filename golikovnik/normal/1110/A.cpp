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
	int b, k;
	cin >> b >> k;
	vector<int> bpw(k);
	bpw[0] = 1;
	for (int i = 1; i < k; i++) {
		bpw[i] = bpw[i - 1] * b % 2;
	}
	int ans = 0;
	for (int i = 0; i < k; i++) {
		int x;
		cin >> x;
		ans += (x * bpw[k - i - 1]) % 2;
		ans %= 2;
	}
	cout << (ans ? "odd" : "even") << "\n";
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