#include <bits/stdc++.h>

#include <cstdint>
#include <istream>
#include <ostream>

using std::istream, std::ostream;

template <uint32_t base>
struct Montgomery {
	using i32 = int32_t;
	using u32 = uint32_t;
	using u64 = uint64_t;

	static constexpr u32 mod() {
		return base;
	}

	static constexpr u32 np = []() {
		u32 x = base;
		for (int i = 0; i < 4; ++i) {
			x *= 2u - base * x;
		}
		return -x;
	}();
	static constexpr u32 r2 = -(u64)(base) % base;

	static_assert(base < (1u << 30));
	static_assert(base * np + 1 == 0);

	static u32 reduce(u64 x) {
		return (x + (u64)((u32)x * np) * base) >> 32;
	}

	u32 x;
	Montgomery(): x(0) {}
	constexpr Montgomery(long long y): x(y ? reduce((u64)(y % base + base) * r2) : 0) {}

	Montgomery& operator +=(const Montgomery& ot) {
		if ((i32)(x += ot.x - 2 * base) < 0) {
			x += 2 * base;
		}
		return *this;
	}

	Montgomery& operator -=(const Montgomery& ot) {
		if ((i32)(x -= ot.x) < 0) {
			x += 2 * base;
		}
		return *this;
	}

	Montgomery& operator *=(const Montgomery& ot) {
		x = reduce((u64)x * ot.x);
		return *this;
	}

	Montgomery& operator /=(const Montgomery& ot) {
		return *this *= ot.inverse();
	}

	friend Montgomery operator +(Montgomery a, const Montgomery& b) {
		a += b;
		return a;
	}

	friend Montgomery operator -(Montgomery a, const Montgomery& b) {
		a -= b;
		return a;
	}

	friend Montgomery operator *(Montgomery a, const Montgomery& b) {
		a *= b;
		return a;
	}

	friend Montgomery operator /(Montgomery a, const Montgomery& b) {
		a /= b;
		return a;
	}

	Montgomery operator -() const {
		return Montgomery() - *this;
	}

	u32 get() const {
		u32 res = reduce(x);
		return res < base ? res : res - base;
	}

	u32 operator ()() const {
		return get();
	}

	Montgomery inverse() const {
		return pow(base - 2);
	}

	Montgomery inv() const {
		return inverse();
	}

	Montgomery pow(int64_t p) const {
		if (p < 0) {
			return pow(-p).inverse();
		}
		Montgomery res = 1;
		Montgomery a = *this;
		while (p) {
			if (p & 1) {
				res *= a;
			}
			p >>= 1;
			a *= a;
		}
		return res;
	}

	friend istream& operator >>(istream& istr, Montgomery& m) {
		long long x;
		istr >> x;
		m = Montgomery(x);
		return istr;
	}

	friend ostream& operator <<(ostream& ostr, const Montgomery& m) {
		return ostr << m.get();
	}

	bool operator ==(const Montgomery& ot) const {
		return (x >= base ? x - base : x) == (ot.x >= base ? ot.x - base : ot.x);
	}

	bool operator !=(const Montgomery& ot) const {
		return (x >= base ? x - base : x) != (ot.x >= base ? ot.x - base : ot.x);
	}

	explicit operator int64_t() const {
		return x;
	}

	explicit operator bool() const {
		return x;
	}
};


#include <vector>


using std::vector;

template <int mod>
struct InvfactStuff {
	using Mint = Montgomery<mod>;

	int n;
	vector<Mint> inv, fact, invfact;

	explicit InvfactStuff(int _n): n(_n + 1), inv(_n + 1, 1), fact(_n + 1, 1), invfact(_n + 1, 1) {
		for (int i = 2; i < n; ++i) {
			inv[i] = -inv[mod % i] * (mod / i);
			fact[i] = fact[i - 1] * i;
			invfact[i] = invfact[i - 1] * inv[i];
		}
	}

	Mint C(int n, int k) const {
		if (k < 0 || k > n) {
			return 0;
		}
		assert(n < this->n);
		return fact[n] * invfact[k] * invfact[n - k];
	}

	Mint binom(int n, int k) const {
		return C(n, k);
	}

	Mint factorial(int n) const {
		assert(n < this->n);
		return fact[n];
	}

	Mint inverse_factorial(int n) const {
		assert(n < this->n);
		return invfact[n];
	}

	Mint inverse(int n) const {
		assert(n < this->n);
		return inv[n];
	}

	Mint falling(int n, int k) const {
		if (k > n) {
			return 0;
		}
		assert(n < this->n);
		return fact[n] * invfact[n - k];
	}
};

template <typename Func>
void rec_pythagorean(long long x, long long y, long long z, long long n, const Func& f) {
	if (z > n) {
		return;
	}
	f(x, y, z);
	rec_pythagorean(
		1 * x - 2 * y + 2 * z,
		2 * x - 1 * y + 2 * z,
		2 * x - 2 * y + 3 * z,
		n, f);
	rec_pythagorean(
		1 * x + 2 * y + 2 * z,
		2 * x + 1 * y + 2 * z,
		2 * x + 2 * y + 3 * z,
		n, f);
	rec_pythagorean(
		-1 * x + 2 * y + 2 * z,
		-2 * x + 1 * y + 2 * z,
		-2 * x + 2 * y + 3 * z,
		n, f);
}

template <typename Func>
void for_all_pythagorean_triples(long long n, const Func& f) {
	rec_pythagorean(3, 4, 5, n, f);
}


using std::vector;

template <typename V = int>
struct Fenwick {
	int n;
	vector<V> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, const V& x) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	V get(int pos) const {
		V res = 0;
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	V get(int l, int r) const {
		return get(r - 1) - get(l - 1);
	}

	int get_min_atleast(V x) const {
		int res = 0;
		for (int i = 1 << (31 - __builtin_clz(n)); i; i >>= 1) {
			if (res + i > n) {
				continue;
			}
			if (a[res + i - 1] < x) {
				res += i;
				x -= a[res - 1];
			}
		}
		return res;
	}

	int get_max_atmost(V x) const {
		int res = 0;
		for (int i = 1 << (31 - __builtin_clz(n)); i; i >>= 1) {
			if (res + i > n) {
				continue;
			}
			if (a[res + i - 1] <= x) {
				res += i;
				x -= a[res - 1];
			}
		}
		return res - 1;
	}
};

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

constexpr int mod = 998'244'353;
using Mint = Montgomery<mod>;
const int N = 222'222;

void solve() {
	int n = nxt(), m = nxt();
	map<int, int> scnt;
	for (int i = 0; i < n; ++i) {
		scnt[nxt()] += 1;
	}
	vector<int> ts(m);
	generate(all(ts), nxt);

	InvfactStuff<mod> stuff(n);
	Fenwick<Mint> f(N);
	Mint prod_if = 1;
	for (auto [k, v] : scnt) {
		prod_if *= stuff.inverse_factorial(v);
		f.add(k, v);
	}

	Mint ans = 0;
	for (int i = 0; i <= n && i < m; ++i) {
		if (i == n) {
			ans += 1;
			break;
		}
		ans += stuff.factorial(n - 1 - i) * prod_if * f.get(ts[i] - 1);
		if (scnt[ts[i]] == 0) {
			break;
		}
		prod_if *= scnt[ts[i]]--;
		f.add(ts[i], -1);
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}