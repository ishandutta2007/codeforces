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

const string FAIL = ":(";

void run() {
	int n;
	cin >> n;
	string s;
	cin >> s;
	int total_bal = 0, total_know = 0;
	for (char c : s) {
		if (c != '?') {
			total_know++;
			if (c == '(') {
				total_bal++;
			} else {
				total_bal--;
			}
		}
	}
	int dunno = n - total_know;
	if (dunno - total_bal < 0 || (dunno - total_bal) % 2 != 0) {
		cout << FAIL << "\n";
		return;
	}
	int open = (dunno - total_bal) / 2;
	int bal = 0;
	for (int i = 0; i < n; i++) {
		char& c = s[i];
		if (c == '?') {
			if (open > 0) {
				c = '(';
				open--;
			} else {
				c = ')';
			}
		}
		if (c == '(') {
			bal++;
		} else {
			bal--;
		}
		if (i + 1 != n) {
			if (bal <= 0) {
				cout << FAIL << "\n";
				return;
			}
		}
	}
	if (bal != 0) {
		cout << FAIL << "\n";
		return;
	}
	cout << s << "\n";
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