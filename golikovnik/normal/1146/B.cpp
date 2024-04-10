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
	string s;
	cin >> s;
	int a_by_far = 0;	
	int n = szof(s);
	string test;
	for (int i = 0; i < n; i++) {
		if (s[i] == 'a') {
			a_by_far++;
		}
		if (n == i + 1 + i + 1 - a_by_far) {
			test = s.substr(0, i + 1);
			break;
		}
	}
	if (test.empty()) {
		cout << ":(\n";
		return;
	}
	string res = test;
	for (char c : test) {
		if (c != 'a') {
			res += c;
		}
	}
	if (res == s) {
		cout << test << "\n";
	} else {
		cout << ":(\n";
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
	cerr << "Time elapsed: " << static_cast<double>(clock()) / CLOCKS_PER_SEC << "s.\n";
	return 0;
}