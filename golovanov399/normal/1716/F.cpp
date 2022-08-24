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


#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

constexpr int mod = 998'244'353;
using Mint = Montgomery<mod>;

const int N = 2022;
Mint st[N][N];

void solve() {
	int n = nxt(), m = nxt(), k = nxt();
	if (m == 1) {
		cout << Mint(n).pow(k) << "\n";
		return;
	}
	Mint ans = 0;
	Mint a = (m + 1) / 2, b = m / 2;
	a /= b;
	Mint ff = 1;
	Mint apow = 1;
	Mint x = Mint(a) / (a + 1);
	for (int i = 1; i <= k && i <= n; ++i) {
		ff *= n + 1 - i;
		apow *= x;
		ans += apow * ff * st[k][i];
	}
	cout << ans * b.pow(n) * (a + 1).pow(n) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	st[0][0] = 1;
	for (int i = 1; i < N; ++i) {
		for (int j = 1; j <= i; ++j) {
			st[i][j] = st[i - 1][j] * j + st[i - 1][j - 1];
		}
	}

	int t = nxt();
	for (int i = 1; i <= t; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}