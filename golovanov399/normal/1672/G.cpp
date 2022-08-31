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

constexpr int mod = 998'244'353;
using Mint = Montgomery<mod>;

struct Dsu {
	int n;
	vector<int> p, rk;

	Dsu(int _n): n(_n), p(_n), rk(_n) {
		std::iota(p.begin(), p.end(), 0);
	}

	int get(int v) {
		return v == p[v] ? v : p[v] = get(p[v]);
	}

	bool merge(int u, int v) {
		u = get(u);
		v = get(v);
		if (u == v) {
			return false;
		}
		if (rk[u] < rk[v]) {
			swap(u, v);
		}
		p[v] = u;
		if (rk[u] == rk[v]) {
			++rk[u];
		}
		return true;
	}
};

void solve() {
	int n = nxt(), m = nxt();
	vector<string> a(n);
	for (int i = 0; i < n; ++i) {
		cin >> a[i];
	}

	if (n % 2 == 0 && m % 2 == 0) {
		int cnt = 0;
		for (auto s : a) {
			cnt += count(all(s), '?');
		}
		cout << Mint(2).pow(cnt) << "\n";
		return;
	}

	if (n % 2 == 0 && m % 2 == 1) {
		vector<string> b(m, string(n, ')'));
		for (int i = 0; i < n; ++i) {
			for (int j = 0; j < m; ++j) {
				b[j][i] = a[i][j];
			}
		}
		a.swap(b);
		swap(n, m);
	}

	if (n % 2 == 1 && m % 2 == 0) {
		Mint ans = 0;
		for (int p : {0, 1}) {
			Mint tmp = 1;
			for (int j = 0; j < m; ++j) {
				int cur = 0;
				int cn = 0;
				for (int i = 0; i < n; ++i) {
					if (a[i][j] == '?') {
						++cn;
					} else if (a[i][j] == '1') {
						cur ^= 1;
					}
				}
				if (cur != p && cn == 0) {
					tmp = 0;
				}
				if (cn) {
					tmp *= Mint(2).pow(cn - 1);
				}
			}
			ans += tmp;
		}
		cout << ans << "\n";
		return;
	}

	assert(n % 2 == 1 && m % 2 == 1);
	Mint ans = 0;
	for (int p : {0, 1}) {
		Mint tmp = 1;
		Dsu dsu(n);
		vector<int> row(n);
		for (int j = 0; j < m; ++j) {
			int cur = 0;
			vector<int> qm;
			for (int i = 0; i < n; ++i) {
				if (a[i][j] == '?') {
					qm.push_back(i);
				} else if (a[i][j] == '1') {
					cur ^= 1;
					row[i] ^= 1;
				}
			}
			if (cur != p) {
				if (qm.empty()) {
					tmp = 0;
				} else {
					row[qm[0]] ^= 1;
				}
			}
			if (!qm.empty()) {
				// tmp *= Mint(2).pow((int)qm.size() - 1);
				for (int k = 1; k < (int)qm.size(); ++k) {
					if (!dsu.merge(qm[0], qm[k])) {
						tmp *= 2;
					}
				}
			}
		}
		vector<int> penalty(n);
		vector<int> cnt(n);
		for (int i = 0; i < n; ++i) {
			int v = dsu.get(i);
			cnt[v] += 1;
			penalty[v] += (row[i] != p);
		}
		for (int i = 0; i < n; ++i) {
			if (cnt[i]) {
				if (penalty[i] % 2) {
					tmp = 0;
				} else {
					// tmp *= Mint(2).pow(cnt[i] - 1);
				}
			}
		}
		ans += tmp;
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