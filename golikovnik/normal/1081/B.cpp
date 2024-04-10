// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str to_string

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
	vector<int> a(n);
	map<int, int> cnt;
	for (int &x : a) {
		cin >> x;
		x = n - x;
		cnt[x]++;
	}
	for (auto[k, v] : cnt) {
		if (v % k != 0) {
			cout << "Impossible\n";
			return;
		}
	}
	cout << "Possible\n";
	int cur = 0;
	map<int, int> clr;
	for (int i = 0; i < n; i++) {
		if (cnt[a[i]] % a[i] == 0) {
			clr[a[i]] = ++cur;
		}
		cout << clr[a[i]] << " ";
		cnt[a[i]]--;
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