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
		V res = V{};
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

struct Node {
	int val;
	int add;
};

struct Segtree {
	int n;
	vector<Node> a;

	Segtree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n, {(int)1e9, 0});
	}

	void push(int v) {
		for (int i : {0, 1}) {
			a[v + v + i].val += a[v].add;
			a[v + v + i].add += a[v].add;
		}
		a[v].add = 0;
	}

	void add(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].val += x;
			a[v].add += x;
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		add(v + v, l1, m, l, r, x);
		add(v + v + 1, m, r1, l, r, x);
		a[v].val = min(a[v + v].val, a[v + v + 1].val);
	}

	void add(int l, int r, int x) {
		add(1, 0, n, l, r, x);
	}

	void set(int pos, int val) {
		int l = 0, r = n;
		int v = 1;
		while (r > l + 1) {
			int m = (l + r) / 2;
			push(v);
			if (pos >= m) {
				l = m;
				v = v * 2 + 1;
			} else {
				r = m;
				v *= 2;
			}
		}
		a[v].val = val;
		while (v > 1) {
			v /= 2;
			a[v].val = min(a[v + v].val, a[v + v + 1].val);
		}
	}

	void rem(int pos) {
		set(pos, 1e9);
	}

	pair<int, int> get_rightmost_min() {
		int mn = a[1].val;
		int l = 0, r = n;
		int v = 1;
		while (r > l + 1) {
			int m = (l + r) / 2;
			push(v);
			if (a[v + v + 1].val == mn) {
				l = m;
				v = v + v + 1;
			} else {
				r = m;
				v = v + v;
			}
		}
		return {mn, l};
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

void solve() {
	int n = nxt();
	vector<int> a(n), b(n);
	generate(all(a), nxt);
	generate(all(b), nxt);

	if (all_of(all(a), [&](int x) { return x == a[0]; })) {
		Mint ans = 1;
		for (int i = 1; i <= n; ++i) {
			ans *= i;
		}
		cout << ans << "\n";
		return;
	}

	int mn = *min_element(all(a));
	int cnt = 0;
	for (int i = 0; i < n; ++i) {
		if (a[i] == mn) {
			++cnt;
			if (b[i] == 0) {
				cout << "0\n";
				return;
			}
		}
	}

	if (cnt > 1) {
		cout << "0\n";
		return;
	}

	int t = mn + (n - 1);
	if (any_of(all(a), [&](int x) { return x > t; })) {
		cout << "0\n";
		return;
	}

	int cnt_equal_positive = 0, cnt_equal_negative = 0;
	vector<int> pos, neg;
	for (int i = 0; i < n; ++i) {
		if (a[i] == t) {
			(b[i] ? cnt_equal_positive : cnt_equal_negative) += 1;
		} else {
			(b[i] ? pos : neg).push_back(a[i]);
		}
	}

	sort(all(pos));
	for (int i = 0; i < (int)pos.size() - 1; ++i) {
		if (pos[i] == pos[i + 1]) {
			cout << "0\n";
			return;
		}
	}
	Segtree tree(t + 1);
	for (int x : pos) {
		tree.set(x, t - x);
	}
	for (int x : a) {
		tree.add(0, x, -1);
	}
	
	vector<int> cnt_neg(t + 1);
	for (int x : neg) {
		cnt_neg[x] += 1;
	}
	Fenwick<int> f(t + 1);
	for (int x : a) {
		f.add(x, 1);
	}

	auto get_fenv = [&]() {
		int res = 0;
		int s = 0;
		for (int i = 1 << (31 - __builtin_clz(f.n)); i; i >>= 1) {
			if (res + i > f.n) {
				continue;
			}
			if (s + f.a[res + i - 1] + (res + i) <= t) {
				res += i;
				s += f.a[res - 1];
			}
		}
		return res;
	};

	Mint ans = 1;
	for (int it = 0; it < n - cnt_equal_positive - cnt_equal_negative; ++it) {
		auto [mn, i] = tree.get_rightmost_min();
		if (mn < 0) {
			cout << "0\n";
			return;
		}

		// take one of the only valid group of negative guys
		int l = get_fenv();
		if (f.get(l - 1) + l != t || cnt_neg[l] <= 0) {
			l = -1;
		}

		// cerr << i << " " << l << "\n";
		if (mn == 0) {
			if (l > i) {
				i = l;
				ans *= cnt_neg[i]--;
			} else {
				tree.rem(i);
			}
			// if there is someone negative > him, we must pick him now
			// if there is someone negative <= him, we ignore
			f.add(i, -1);
			tree.add(i, t, -1);
		} else if (l > i) {
			ans *= cnt_neg[l]--;
			f.add(l, -1);
			tree.add(l, t, -1);
		} else {
			ans = 0;
		}
	}
	InvfactStuff<mod> stuff(t);
	ans *= stuff.C(n, cnt_equal_positive);
	ans *= stuff.factorial(cnt_equal_negative);
	ans *= stuff.factorial(cnt_equal_positive);
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}