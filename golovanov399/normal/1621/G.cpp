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

void solve() {
	int n = nxt();
	vector<int> a(n);
	generate(all(a), nxt);

	auto values = a;
	make_unique(values);
	for (auto& x : a) {
		x = lower_bound(all(values), x) - values.begin();
	}
	const int m = values.size();

	vector<Mint> pref(n);
	vector<Mint> suf(n);
	{
		Fenwick<Mint> f(m);
		for (int i = 0; i < n; ++i) {
			pref[i] = f.get(a[i] - 1) + 1;
			f.add(a[i], pref[i]);
		}
	}
	{
		Fenwick<Mint> f(m);
		for (int i = n - 1; i >= 0; --i) {
			suf[i] = f.get(m - 1) - f.get(a[i]) + 1;
			f.add(a[i], suf[i]);
		}
	}
	vector<pair<int, int>> ar(n);
	for (int i = 0; i < n; ++i) {
		ar[i] = {a[i], -i};
	}
	sort(all(ar));
	reverse(all(ar));
	vector<vector<int>> by_right(n);
	int mx = -1;
	for (auto p : ar) {
		if (mx > -p.second) {
			by_right[mx].push_back(-p.second);
		} else {
			suf[-p.second] = 0;
		}
		mx = max(mx, -p.second);
	}
	for (int r = 0; r < n; ++r) {
		auto v = by_right[r];
		if (v.empty()) {
			continue;
		}
		sort(all(v));
		vector<int> vals = {a[r]};
		for (int x : v) {
			vals.push_back(a[x]);
		}
		make_unique(vals);
		Fenwick<Mint> f(vals.size());
		f.add(lower_bound(all(vals), a[r]) - vals.begin(), 1);
		reverse(all(v));
		for (int x : v) {
			int idx = lower_bound(all(vals), a[x]) - vals.begin();
			auto cur = f.get((int)vals.size() - 1) - f.get(idx);
			suf[x] -= cur;
			f.add(idx, cur);
		}
	}
	Mint ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += pref[i] * suf[i];
	}
	cout << ans << "\n";
}

int main() {
	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}