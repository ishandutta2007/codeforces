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

int add(int x, int y) {
	return x + y >= MOD998 ? x + y - MOD998 : x + y;
}

int mul(int x, int y) {
	return 1LL * x * y % MOD998;
}

int sub(int x, int y) {
	return x - y < 0 ? x - y + MOD998 : x - y;
}

int pw(int a, int n) {
	int res = 1;
	while (n) {
		if (n & 1) {
			res = mul(res, a);
		}
		a = mul(a, a);
		n >>= 1;
	}
	return res;
}

int inv(int x) {
	return pw(x, MOD998 - 2);
}

void run() {
	int p, s, r;
	cin >> p >> s >> r;
	vector<vector<int>> choose(p + s + 1, vector<int>(p + s + 1));
	for (int i = 0; i <= p + s; i++) {
		choose[i][0] = choose[i][i] = 1;
		for (int j = 1; j < i; j++) {
			choose[i][j] = add(choose[i - 1][j - 1], choose[i - 1][j]);
		}
	}
	auto binom = [&](int n, int k) {
		if (k < 0 || n < 0) {
			return 1;
		}
		return choose[n][k];
	};
	auto binom_repl = [&](int n, int k) {
		return binom(n + k - 1, k);
	};
	int good = 0, total = 0;
	for (int score = r; score <= s; score++) {
		total = add(total, binom_repl(p - 1, s - score));
		for (int same = 0; score * (same + 1) <= s && same < p; same++) {
			int left_people = p - same - 1, left_sum = s - score * (same + 1);
			int res = 0;
			for (int k = 0; k <= left_people && k * score <= left_sum; k++) {
				int ways = mul(binom(left_people, k), binom_repl(left_people, left_sum - k * score));
				res = (k & 1 ? sub(res, ways) : add(res, ways));
			}
			good = add(good, mul(binom(p - 1, same), mul(res, inv(same + 1))));
		}
	}
	cout << mul(good, inv(total)) << "\n";
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
	return 0;
}