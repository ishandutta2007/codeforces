#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
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

constexpr int mod = 1'000'000'007;
using Mint = Montgomery<mod>;

const int N = 2022;	// happy new year!
Mint pref[N][2 * N];
Mint suf[N][2 * N];

inline bool can_be(char c, int x) {
	return c == '?' || c == (char)('0' + x);
}

void solve() {
	int n = nxt();
	string s, t;
	cin >> s >> t;

	fill(pref[0], pref[0] + 2 * N, 0);
	pref[0][N] = 1;
	for (int i = 0; i < n; ++i) {
		fill(pref[i + 1], pref[i + 1] + 2 * N, 0);
		for (int x : {0, 1}) {
			for (int y : {0, 1}) {
				if (!can_be(s[i], x) || !can_be(t[i], y)) {
					continue;
				}
				int to_add = 0;
				if (x != y) {
					to_add += (x == i % 2 ? 1 : -1);
				}
				for (int j = N - i; j <= N + i; ++j) {
					pref[i + 1][j + to_add] += pref[i][j];
				}
			}
		}
	}

	fill(suf[0], suf[0] + 2 * N, 0);
	suf[0][N] = 1;
	for (int i = 0; i < n; ++i) {
		fill(suf[i + 1], suf[i + 1] + 2 * N, 0);
		for (int x : {0, 1}) {
			for (int y : {0, 1}) {
				if (!can_be(s[n - 1 - i], x) || !can_be(t[n - 1 - i], y)) {
					continue;
				}
				int to_add = 0;
				if (x != y) {
					to_add += (x == (n - 1 - i) % 2 ? 1 : -1);
				}
				for (int j = N - i; j <= N + i; ++j) {
					suf[i + 1][j + to_add] += suf[i][j];
				}
			}
		}
	}

	Mint ans = 0;
	for (int i = 1; i < n; ++i) {
		for (int d = 1; d <= n; d += 2) {
			ans += pref[i][N + d] * suf[n - i][N - d] * d;
			ans += pref[i][N - d] * suf[n - i][N + d] * d;
		}
		for (int d = 2; d <= n; d += 2) {
			ans += pref[i][N + d] * suf[n - i][N - d] * d;
			ans += pref[i][N - d] * suf[n - i][N + d] * d;
		}
	}
	cout << ans << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}