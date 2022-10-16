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
	string s;
	cin >> s;
	int bal = 0;
	vector<int> min_pref(n + 1), pref(n + 1);
	for (int i = 0; i < n; i++) {
		int new_bal = bal + (s[i] == '(' ? 1 : -1);
		min_pref[i + 1] = min(new_bal, min_pref[i]);
		pref[i + 1] = new_bal;
		bal = new_bal;
	}
	vector<int> min_suff(n + 1);
	for (int i = n - 1; i >= 0; i--) {
		int x = s[i] == '(' ? 1 : -1;
		min_suff[i] = min(x, min_suff[i + 1] + x);
	}
	if (bal != 2 && bal != -2) {
		cout << "0\n";
		return;
	}
	bool need_close = bal < 0;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (need_close) {
			if (s[i] == ')') {
				ans += (min_pref[i] >= 0 && min_suff[i + 1] + pref[i] + 1 >= 0);
			}
		} else if (s[i] == '(') {
			ans += (min_pref[i] >= 0 && pref[i + 1] >= 2 && min_suff[i + 1] + pref[i] - 1 >= 0);
		}
	}
	cout << ans << "\n";
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