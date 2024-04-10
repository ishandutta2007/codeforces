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

int add(int x, int y, int mod = MOD998) {
	assert(0 <= x && x < mod && 0 <= y && y < mod);
	return x + y >= mod ? x + y - mod : x + y;
}

int sub(int x, int y, int mod = MOD998) {
	assert(0 <= x && x < mod && 0 <= y && y < mod);
	return x - y < 0 ? x - y + mod : x - y;
}

int mul(int x, int y, int mod = MOD998) {
	assert(0 <= x && x < mod && 0 <= y && y < mod);
	return (int) ((1LL * x * y) % mod);
}

int pw(int a, int n, int mod = MOD998) {
	assert(0 <= a && a < mod);
	int res = 1 % mod;
	while (n) {
		if (n & 1) {
			res = mul(res, a, mod);
		}
		a = mul(a, a, mod);
		n >>= 1;
	}
	return res;
}

int inv(int x, int mod = MOD998) {
	return pw(x, mod - 2, mod);
}

vector<int> get_invs(int upto, int mod = MOD998) {
	vector<int> res(upto + 1);
	res[1] = 1;
	for (int i = 2; i <= upto; i++) {
		res[i] = mod - mul(mod / i, res[mod % i], mod);
	}
	return res;
}

void run() {
	int n;
	cin >> n;
	vector<int> a(n);
	map<int, int> mn, mx;
	for (int i = 0; i < n; i++) {
		cin >> a[i];
		if (mn.find(a[i]) == mn.end()) {
			mn[a[i]] = i;
		}
		mx[a[i]] = i;
	}
	vector<pair<int, int>> segs;
	for (auto[k, v] : mn) {
		segs.emplace_back(v, 1);
		segs.emplace_back(mx[k] + 1, 0);
	}
	sort(all(segs));
	int cnt = 0;
	int res = 0;
	for (auto[_, c] : segs) {
		if (c) {
			cnt++;
		} else {
			cnt--;
		}
		if (!cnt) {
			res++;
		}
	}
	int ans = 1;
	for (int it = 0; it < res - 1; it++) {
		ans = mul(ans, 2);
	}
	cout << ans << "\n";
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