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

#define int ll

int ask(int x, int y, int z) {
	cout << "? " << x << " " << y << " " << z << endl;
	int res;
	cin >> res;
	return res;
}

vector<int> get_five(int start) {
	vector<int> sums;
	for (int x = start; x < start + 5; x++) {
		for (int y = x + 1; y < start + 5; y++) {
			for (int z = y + 1; z < start + 5; z++) {
				sums.push_back(ask(x, y, z));
			}
		}
	}
	set<int> vals(all(sums));
	if (szof(vals) == 1) {
		int x = *vals.begin() / 2;
		return {x, x, x, x, x};
	}
	int ac = *vals.begin();
	int ce = *vals.rbegin();
	for (int ad : {ac, *(++vals.begin())}) {
		for (int be : {ce, *(++vals.rbegin())}) {
			for (int bd : vals) {
				int dd = ad + bd + ce - be - ac;
				if (dd & 1) {
					continue;
				}
				int d = dd / 2;
				int e = be + d - bd;
				int b = be - e;
				int c = ce - e;
				int a = ac - c;
				vector<int> v = {a, b, c, d, e};
				do {
					vector<int> tmp;
					for (int i = 0; i < 5; i++) {
						for (int j = i + 1; j < 5; j++) {
							for (int k = j + 1; k < 5; k++) {
								tmp.push_back(min({v[i], v[j], v[k]}) + max({v[i], v[j], v[k]}));
							}
						}
					}
					if (tmp == sums) {
						return v;
					}
				} while (next_permutation(all(v)));
			}
		}
	}
	throw;
}

void run() {
	int n;
	cin >> n;
	vector<int> ans;
	for (int i = 0; i + 4 < n; i += 5) {
		for (int x : get_five(i + 1)) {
			ans.push_back(x);
		}
	}
	if (n % 5 != 0) {
		vector<int> lol = get_five(n - 4);
		for (int i = 5 - n % 5; i < 5; i++) {
			ans.push_back(lol[i]);
		}
	}
	cout << "! ";
	for (int x : ans) {
		cout << x << " ";
	}
	cout << endl;
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