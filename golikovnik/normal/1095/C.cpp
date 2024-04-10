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
	int n, k;
	cin >> n >> k;
	multiset<int> repr;
	for (int b = 0; b < 32; b++) {
		if (n & (1 << b)) {
			repr.insert(1 << b);
		}
	}
	if (k < szof(repr)) {
		cout << "NO\n";
		return;
	}
	while (k > szof(repr) && *repr.rbegin() > 1) {
		int x = *repr.rbegin();
		repr.erase(repr.find(*repr.rbegin()));
		repr.insert(x >> 1);
		repr.insert(x >> 1);
	}
	if (szof(repr) != k) {
		cout << "NO\n";
		return;
	}
	cout << "YES\n";
	for (int x : repr) {
		cout << x << " ";
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