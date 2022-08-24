#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

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

constexpr int mod = 998'244'353;
using Mint = Montgomery<mod>;

void solve() {
	int n = nxt();
	const int sz = (n + 1) / 2;
	InvfactStuff<mod> stuff(3 * n);

	vector<Mint> p(n);
	p[0] = 1;
	for (int i = 1; i < n; ++i) {
		int cnt = n - 1 - i;
		// for (int b = sz; b <= n - i; ++b) {
		// 	p[i] += stuff.factorial(n - 1 - b) * stuff.inverse_factorial(n - i - b);
		// }
		p[i] = stuff.C(n - sz, i) / stuff.C(i + cnt, i);
	}

	Mint cur = 0;
	for (int i = n - 1; i >= 0; --i) {
		Mint tmp = 0;
		if (i) {
			tmp = p[i] * stuff.inverse(i);
		}
		p[i] -= cur;
		cur += tmp;
	}

	for (auto x : p) {
		cout << x * stuff.factorial(n - 1) << " ";
	}
	cout << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}