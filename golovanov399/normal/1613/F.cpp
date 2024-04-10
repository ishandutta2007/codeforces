

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define imie(x) #x << ": " << x

using namespace std;

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




template <typename outer_type, typename inner_type, int N>
class IFFT {
public:
	using Poly = vector<outer_type>;

	IFFT(): initialized_(false) {}

	~IFFT() {}

	virtual Poly multiply(Poly a, Poly b) {
		if ((int)a.size() > N / 2 || (int)b.size() > N / 2) {
			Poly result(a.size() + b.size() - 1);
			const int low_len = (max(a.size(), b.size()) + 1) / 2;
			Poly a_low(a.begin(), min(a.begin() + low_len, a.end()));
			Poly a_high(min(a.begin() + low_len, a.end()), a.end());
			Poly b_low(b.begin(), min(b.begin() + low_len, b.end()));
			Poly b_high(min(b.begin() + low_len, b.end()), b.end());

			auto tmp = multiply(a_low, b_low);
			for (int i = 0; i < (int)tmp.size(); ++i) {
				result[i] += tmp[i];
				if (low_len + i < (int)result.size()) {
					result[low_len + i] -= tmp[i];
				}
			}
			tmp = multiply(a_high, b_high);
			for (int i = 0; i < (int)tmp.size(); ++i) {
				result[2 * low_len + i] += tmp[i];
				if (low_len + i < (int)result.size()) {
					result[low_len + i] -= tmp[i];
				}
			}
			for (int i = 0; i < (int)a_high.size(); ++i) {
				a_low[i] += a_high[i];
			}
			for (int i = 0; i < (int)b_high.size(); ++i) {
				b_low[i] += b_high[i];
			}
			tmp = multiply(a_low, b_low);
			for (int i = 0; i < (int)tmp.size(); ++i) {
				result[low_len + i] += tmp[i];
			}
			return result;
		}
		int n = 1;
		while (n < (int)a.size() || n < (int)b.size()) {
			n *= 2;
		}
		vector<inner_type> ar(n + n), br(n + n);
		if constexpr (is_convertible_v<outer_type, inner_type>) {
			copy(all(a), ar.begin());
			copy(all(b), br.begin());
		} else {
			throw runtime_error("please, implement your own child multiply function");
		}
		fft(ar);
		fft(br);
		for (int i = 0; i < (int)ar.size(); ++i) {
			ar[i] *= br[i];
		}
		ifft(ar);
		Poly res((int)a.size() + (int)b.size() - 1);
		assert(res.size() <= ar.size());
		if constexpr (is_convertible_v<inner_type, outer_type>) {
			copy_n(ar.begin(), res.size(), res.begin());
		} else {
			throw runtime_error("please, implement your own child multiply function");
		}
		return res;
	}

	virtual Poly square(const Poly& a) {
		int n = 1;
		while (n < (int)a.size()) {
			n *= 2;
		}
		vector<inner_type> ar(n + n);
		if constexpr (is_convertible_v<outer_type, inner_type>) {
			copy(all(a), ar.begin());
		} else {
			throw runtime_error("please, implement your own child square function");
		}
		fft(ar);
		for (int i = 0; i < (int)ar.size(); ++i) {
			ar[i] *= ar[i];
		}
		ifft(ar);
		Poly res((int)a.size() + (int)a.size() - 1);
		assert(res.size() <= ar.size());
		if constexpr (is_convertible_v<inner_type, outer_type>) {
			copy_n(ar.begin(), res.size(), res.begin());
		} else {
			throw runtime_error("please, implement your own child square function");
		}
		return res;
	}

	Poly inverse(const Poly& a, int prec) {
		assert(!a.empty());
		assert(a[0] != 0);
		Poly b = {1 / a[0]};
		for (int len = 1; len < prec; len *= 2) {
			auto tmp = multiply(b, b);
			if ((int)tmp.size() > prec) {
				tmp.resize(prec);
			}
			tmp = multiply(tmp, Poly{a.begin(), a.begin() + min(2 * len, (int)a.size())});
			tmp.resize(2 * len);
			for (int i = 0; i < len; ++i) {
				tmp[i] = b[i] + b[i] - tmp[i];
				tmp[len + i] = -tmp[len + i];
			}
			b.swap(tmp);
		}
		b.resize(prec);
		return b;
	}

	Poly derivative(Poly a) {
		if (a.empty()) {
			return a;
		}
		a.erase(a.begin());
		for (int i = 0; i < (int)a.size(); ++i) {
			a[i] *= i + 1;
		}
		return a;
	}

	Poly primitive(Poly a) {
		a.insert(a.begin(), 0);
		for (int i = 1; i < (int)a.size(); ++i) {
			a[i] /= i;
		}
		return a;
	}

	Poly log(const Poly& a, int prec) {
		assert(!a.empty());
		assert(a[0] == 1);
		auto res = primitive(multiply(derivative(a), inverse(a, prec)));
		res.resize(prec);
		return res;
	}

	Poly exp(const Poly& a, int prec) {
		assert(!a.empty());
		assert(a[0] == 0);
		Poly b = {1};
		for (int len = 1; len < prec; len *= 2) {
			auto tmp = Poly{a.begin(), a.begin() + min(2 * len, (int)a.size())};
			tmp.resize(2 * len);
			tmp[0] += 1;
			auto l = log(b, 2 * len);
			for (int i = 0; i < 2 * len; ++i) {
				tmp[i] -= l[i];
			}
			b = multiply(tmp, b);
			b.resize(2 * len);
		}
		b.resize(prec);
		return b;
	}

	pair<Poly, Poly> divmod(Poly a, Poly b) {
		assert(!b.empty());
		assert(b.back() != 0);
		if (a.size() < b.size()) {
			return {{0}, a};
		}
		reverse(all(a));
		reverse(all(b));
		auto q = inverse(b, a.size() - b.size() + 1);
		q = multiply(a, q);
		q.resize(a.size() - b.size() + 1);
		reverse(all(q));
		reverse(all(a));
		reverse(all(b));
		Poly r(b.size() - 1);
		auto bq = multiply(b, q);
		for (int i = 0; i < (int)r.size(); ++i) {
			r[i] = a[i] - bq[i];
		}
		return {q, r};
	}

	struct ProductTree {
		int n;
		vector<Poly> a;
		vector<outer_type> x;
		IFFT* owner;

		ProductTree(const vector<outer_type>& _x, IFFT* that): x(_x), owner(that) {
			n = 1;
			while (n < (int)x.size()) {
				n *= 2;
			}
			a.resize(n + n);
			outer_type one{1};
			for (int i = 0; i < (int)x.size(); ++i) {
				a[n + i] = {-x[i], one};
			}
			for (int i = n - 1; i > 0; --i) {
				if (a[2 * i].empty()) {
					continue;
				} else if (a[2 * i + 1].empty()) {
					a[i] = a[2 * i];
				} else {
					a[i] = owner->multiply(a[2 * i], a[2 * i + 1]);
				}
			}
		}

		const Poly& top() {
			return a[1];
		}

		void rec_multipoint(int v, int l, int r, Poly p, vector<outer_type>& ans) {
			if (l >= (int)x.size()) {
				return;
			}
			p = owner->divmod(p, a[v]).second;
			if (r <= l + 64) {
				for (int i = l; i < r && i < (int)x.size(); ++i) {
					outer_type& res = ans[i] = 0;
					for (int j = (int)p.size() - 1; j >= 0; --j) {
						res = res * x[i] + p[j];
					}
				}
				return;
			}
			int m = (l + r) / 2;
			rec_multipoint(v + v, l, m, p, ans);
			rec_multipoint(v + v + 1, m, r, p, ans);
		}

		vector<outer_type> multipoint(const Poly& p) {
			vector<outer_type> ans(x.size());
			rec_multipoint(1, 0, n, p, ans);
			return ans;
		}
	};

	Poly multipoint(Poly p, const vector<outer_type>& x) {
		ProductTree tree(x, this);
		return multipoint(tree, p);
	}

	Poly interpolate(const vector<outer_type>& x, const vector<outer_type>& y) {
		ProductTree tree(x, this);
		auto denom = tree.multipoint(derivative(tree.top()));
		auto inter = [&](const auto& self, int v, int l, int r) -> Poly {
			if (l >= (int)x.size()) {
				return {};
			}
			if (l + 1 == r) {
				return {y[l] / denom[l]};
			}
			int m = (l + r) / 2;
			auto left = self(self, v + v, l, m);
			auto right = self(self, v + v + 1, m, r);
			if (right.empty()) {
				return left;
			}
			left = multiply(left, tree.a[v + v + 1]);
			right = multiply(right, tree.a[v + v]);
			if (left.size() < right.size()) {
				left.resize(right.size());
			}
			for (int i = 0; i < (int)right.size(); ++i) {
				left[i] += right[i];
			}
			return left;
		};
		return inter(inter, 1, 0, tree.n);
	}

protected:
	static constexpr int L = 31 - __builtin_clz(N);
	static_assert(!(N & (N - 1)));
	vector<inner_type> angles;
	vector<int> bitrev;
	bool initialized_;

	void initialize() {
		fill_angles();
		fill_bitrev();
		initialized_ = true;
	}

	virtual void fill_angles() = 0;

	void fill_bitrev() {
		bitrev.assign(N, 0);
		for (int i = 0; i < N; ++i) {
			for (int j = 0; j < L; ++j) {
				bitrev[i] = (bitrev[i] << 1) | !!(i & (1 << j));
			}
		}
	}

	void butterfly(vector<inner_type>& a) {
		if (!initialized_) {
			initialize();
		}
		const int n = a.size();
		assert(!(n & (n - 1)));
		const int l = __builtin_ctz(n);

		for (int i = 0; i < n; ++i) {
			int j = revbit(i, l);
			if (j > i) {
				swap(a[i], a[j]);
			}
		}
	}

	int revbit(int num, int len) const {
		return bitrev[num] >> (L - len);
	}

	virtual void fft(vector<inner_type>& a) {
		if (!initialized_) {
			initialize();
		}

		const int n = a.size();
		assert(!(n & (n - 1)));
		butterfly(a);

		for (int len = 1; len < n; len *= 2) {
			for (int start = 0; start < n; start += 2 * len) {
				for (int i = 0; i < len; ++i) {
					const auto w = angles[N / 2 / len * i];
					const auto x = a[start + i], y = a[start + len + i] * w;
					a[start + i] = x + y;
					a[start + len + i] = x - y;
				}
			}
		}
	}

	void ifft(vector<inner_type>& a) {
		fft(a);
		outer_type to_div = outer_type(1) / a.size();
		for (auto& x : a) {
			x *= to_div;
		}
		reverse(1 + all(a));
	}
};
// #include "modular.h"

template <int mod, int N = (1 << __builtin_ctz(mod - 1))>
class NTT : public IFFT<Montgomery<mod>, Montgomery<mod>, N> {
	using Mint = Montgomery<mod>;
protected:
	void fill_angles() {
		vector<int> primes;
		for (int x = mod - 1, p = 2; x > 1; ++p) {
			if (p * p > x) {
				primes.push_back(x);
				break;
			}
			if (x % p == 0) {
				primes.push_back(p);
				while (x % p == 0) {
					x /= p;
				}
			}
		}
		auto isPrimitiveRoot = [&](Mint g) {
			for (int p : primes) {
				if (g.pow(mod / p) == 1) {
					return false;
				}
			}
			return true;
		};
		int g = 2;
		while (!isPrimitiveRoot(g)) {
			++g;
		}
		g = Mint(g).pow(mod / N).get();

		this->angles.assign(N, 1);
		for (int i = 1; i < N; ++i) {
			this->angles[i] = this->angles[i - 1] * g;
		}
		assert(this->angles.back() * g == 1);
	}

	void ntt(vector<Mint>& a) {
		fft(a);
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

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

constexpr int mod = 998'244'353;
using Mint = Montgomery<mod>;

NTT<mod, (1 << 20)> ntt;

const int N = 255'555;
vector<int> a[N];
int deg[N];

void dfs(int v, int p) {
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		deg[v] += 1;
		dfs(x, v);
	}
}

using Poly = vector<Mint>;

Poly calc(const vector<Poly>& ps, int l, int r) {
	if (r == l + 1) {
		return ps[l];
	} else {
		const int m = (l + r) / 2;
		return ntt.multiply(calc(ps, l, m), calc(ps, m, r));
	}
}

void solve() {
	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0, 0);
	vector<Poly> ps;
	for (int i = 0; i < n; ++i) {
		ps.push_back({1, -deg[i]});
	}
	Poly p = calc(ps, 0, n);
	InvfactStuff<mod> stuff(n);
	Mint ans = 0;
	for (int i = 0; i < n; ++i) {
		ans += p[i] * stuff.factorial(n - i);
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