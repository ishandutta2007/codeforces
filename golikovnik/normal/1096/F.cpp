// #pragma comment(linker, "/stack:200000000")
// #pragma GCC optimize("Ofast")
// #pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>

#define all(x) (x).begin(), (x).end()
#define szof(x) int32_t((x).size())
#define str(x) to_string(x)

using namespace std;
using namespace __gnu_pbds;

typedef tree<
int,
null_type,
less<int>,
rb_tree_tag,
tree_order_statistics_node_update>
ordered_set;

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
	int n;
	cin >> n;
	vector<int> p(n);
	set<int> lol;
	int dunno = 0;
	for (int &x : p) {
		cin >> x;
		if (x > 0) {
			lol.insert(x);
		}
	}
	vector<int> missing;
	for (int i = 1; i <= n; i++) {
		if (lol.find(i) == lol.end()) {
			missing.push_back(i);
		}
	}
	int HALF = inv(2);
	int RATIO = inv(szof(missing));
	ordered_set st;
	int ans = 0;
	int nbigger = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (p[i] < 0) {
			ans = add(ans, mul(nbigger, RATIO));
			dunno++;
		} else {
			ans = add(ans, st.order_of_key(p[i]));
			int nsmaller = (int) (lower_bound(all(missing), p[i]) - missing.begin());
			if (dunno) {
				ans = add(ans, mul(dunno, mul(nsmaller, RATIO)));
			}
			nbigger = add(nbigger, szof(missing) - nsmaller);
			st.insert(p[i]);
		}
	}
	ans = add(ans, mul(dunno, mul(dunno - 1, mul(HALF, HALF))));
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