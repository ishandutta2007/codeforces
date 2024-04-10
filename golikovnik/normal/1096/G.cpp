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

int sub(int x, int y) {
	return x - y < 0 ? x - y + MOD998 : x - y;
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

// codeforces.com/profile/tourist
namespace ntt {
	int base = 1;
	vector<int> roots = {0, 1};
	vector<int> rev = {0, 1};
	int max_base = -1;
	int root = -1;

	void init() {
		int tmp = MOD998 - 1;
		max_base = 0;
		while (tmp % 2 == 0) {
			tmp /= 2;
			max_base++;
		}
		root = 2;
		while (true) {
			if (pw(root, 1 << max_base) == 1) {
				if (pw(root, 1 << (max_base - 1)) != 1) {
					break;
				}
			}
			root++;
		}
	}

	void ensure_base(int nbase) {
		if (max_base == -1) {
			init();
		}
		if (nbase <= base) {
			return;
		}
		assert(nbase <= max_base);
		rev.resize(1 << nbase);
		for (int i = 0; i < (1 << nbase); i++) {
			rev[i] = (rev[i >> 1] >> 1) + ((i & 1) << (nbase - 1));
		}
		roots.resize(1 << nbase);
		while (base < nbase) {
			int z = pw(root, 1 << (max_base - 1 - base));
			for (int i = 1 << (base - 1); i < (1 << base); i++) {
				roots[i << 1] = roots[i];
				roots[(i << 1) + 1] = mul(roots[i], z);
			}
			base++;
		}
	}

	void fft(vector<int> &a) {
		int n = szof(a);
		assert((n & (n - 1)) == 0);
		int zeros = __builtin_ctz(n);
		ensure_base(zeros);
		int shift = base - zeros;
		for (int i = 0; i < n; i++) {
			if (i < (rev[i] >> shift)) {
				swap(a[i], a[rev[i] >> shift]);
			}
		}
		for (int k = 1; k < n; k <<= 1) {
			for (int i = 0; i < n; i += 2 * k) {
				for (int j = 0; j < k; j++) {
					int x = a[i + j];
					int y = mul(a[i + j + k], roots[j + k]);
					a[i + j] = add(x, y);
					a[i + j + k] = sub(x, y);
				}
			}
		}
	}

	vector<int> multiply(vector<int> a, vector<int> b, int eq = 0) {
		int need = szof(a) + szof(b) - 1;
		int nbase = 0;
		while ((1 << nbase) < need) {
			nbase++;
		}
		ensure_base(nbase);
		int sz = 1 << nbase;
		a.resize(sz);
		b.resize(sz);
		fft(a);
		if (eq) {
			b = a;
		} else {
			fft(b);
		}
		int inv_sz = inv(sz);
		for (int i = 0; i < sz; i++) {
			a[i] = mul(mul(a[i], b[i]), inv_sz);
		}
		reverse(a.begin() + 1, a.end());
		fft(a);
		a.resize(need);
		return a;
	}

	vector<int> pw(vector<int> a, int n) {
		int need = szof(a) * n - n + 1;
		int nbase = 0;
		while ((1 << nbase) < need) {
			nbase++;
		}
		ensure_base(nbase);
		int sz = 1 << nbase;
		a.resize(sz);
		fft(a);
		int inv_sz = inv(sz);
		for (int i = 0; i < sz; i++) {
			a[i] = mul(::pw(a[i], n), inv_sz);
		}
		reverse(a.begin() + 1, a.end());
		fft(a);
		a.resize(need);
		return a;
	}

	vector<int> square(vector<int> a) {
		return pw(a, 2);
	}
}

void run() {
	int n, k;
	cin >> n >> k;
	vector<int> digits(10);
	for (int i = 0; i < k; i++) {
		int d;
		cin >> d;
		digits[d] = 1;
	}
	auto dp = ntt::pw(digits, n / 2);
	int ans = 0;
	for (int x : dp) {
		ans = add(ans, mul(x, x));
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