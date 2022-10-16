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

string ask(const string &s) {
	cout << "? " << s << endl;
	string res;
	cin >> res;
	return res;
}

void run() {
	string t;
	cin >> t;
	int n = szof(t);
	vector<int> primes = {19, 23, 25};
	vector<vector<int>> rem(3, vector<int>(n));
	for (int p = 0; p < 3; p++) {
		int pr = primes[p];
		string s = t;
		for (int i = 0; i < n; i++) {
			s[i] = 'a' + i % pr;
		}
		string res = ask(s);
		for (int i = 0; i < n; i++) {
			rem[p][i] = res[i] - 'a';
		}
	}
	map<tuple<int, int, int>, int> by_rem;
	for (int i = 0; i < n; i++) {
		by_rem[make_tuple(rem[0][i], rem[1][i], rem[2][i])] = i;
	}
	vector<int> p(n);
	for (int i = 0; i < n; i++) {
		p[i] = by_rem[make_tuple(i % primes[0], i % primes[1], i % primes[2])];
	}
	string ans = t;
	for (int i = 0; i < n; i++) {
		ans[i] = t[p[i]];
	}
	cout << "! " << ans << endl;
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