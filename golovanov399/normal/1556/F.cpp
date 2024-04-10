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

template <typename T>
struct TypeModular {
	using Type = typename decay<decltype(T::value)>::type;
	Type val;

	static constexpr Type mod() {
		return T::value;
	}

	TypeModular(long long _val = 0) {
		if (_val < 0 || (_val > 0 && _val >= mod())) {
			val = _val % mod();
			if (val < 0) {
				val += mod();
			}
		} else {
			val = _val;
		}
	}

	friend TypeModular operator -(const TypeModular& a) {
		return {-a.val};
	}

	friend TypeModular operator +(const TypeModular& a, const TypeModular& b) {
		Type res = a.val + b.val;
		if (res >= mod()) {
			res -= mod();
		}
		return {res};
	}

	friend TypeModular operator -(const TypeModular& a, const TypeModular& b) {
		Type res = a.val - b.val;
		if (res < 0) {
			res += mod();
		}
		return {res};
	}

	friend TypeModular operator *(const TypeModular& a, const TypeModular& b) {
		return {1ll * a.val * b.val};
	}

	friend TypeModular operator /(const TypeModular& a, const TypeModular& b) {
		return a * b.inv();
	}

	TypeModular& operator +=(const TypeModular& b) {
		val += b.val;
		if (val >= mod()) {
			val -= mod();
		}
		return *this;
	}

	TypeModular& operator -=(const TypeModular& b) {
		val -= b.val;
		if (val < 0) {
			val += mod();
		}
		return *this;
	}

	TypeModular& operator *=(const TypeModular& b) {
		val = 1ll * val * b.val % mod();
		return *this;
	}

	TypeModular& operator /=(const TypeModular& b) {
		*this *= b.inv();
		return *this;
	}

	TypeModular& operator ++() {
		val += 1;
		if (val == mod()) {
			val = 0;
		}
		return *this;
	}

	TypeModular operator ++(int) {
		TypeModular tmp(*this);
		operator ++();
		return tmp;
	}

	friend bool operator ==(const TypeModular& a, const TypeModular& b) {
		return a.val == b.val;
	}

	friend bool operator !=(const TypeModular& a, const TypeModular& b) {
		return a.val != b.val;
	}

	TypeModular pow(long long b) const {
		TypeModular res{1}, a{*this};
		while (b) {
			if (b & 1ll) {
				res *= a;
			}
			b >>= 1;
			a *= a;
		}
		return res;
	}

	TypeModular inv() const {
		assert(val);
		return _inv(val, mod());
	}

	int _inv(int a, int b) const {
		return a == 1 ? a : b - 1ll * _inv(b % a, a) * b / a % b;
	}

	explicit operator Type() const {
		return val;
	}

	explicit operator bool() const {
		return val;
	}
};

template <typename T = int>
struct integral_variable {
	static T value;
};

template <typename T> T integral_variable<T>::value;

void set_prime(int p) {
	integral_variable<int>::value = p;
}

template <typename T>
ostream& operator <<(ostream& ostr, const TypeModular<T>& x) {
	return ostr << x.val;
}

template <int mod>
using Modular = TypeModular<integral_constant<int, mod>>;

template <int mod>
struct InvfactStuff {
	using Mint = Modular<mod>;

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


constexpr int mod = 1'000'000'007;
using Mint = Modular<mod>;

const int N = 15;
const int NN = 1 << N;
const int M = 5e6;
pair<int, int> mask_pair[M];

Mint prob_win[N][NN];
int beg[NN];

Mint prob_mass_win[M];
Mint prob_draws[NN];

int encode(int x, int y) {
	int res = beg[y];
	int cur = 1;
	for (int i = 0; i < N; ++i) {
		if (y & (1 << i)) {
			continue;
		} else {
			if (x & (1 << i)) {
				res += cur;
			}
			cur *= 2;
		}
	}
	return res;
}

void solve() {
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}
	InvfactStuff<mod> stuff(*max_element(all(a)) * 2);

	const int nn = 1 << n;
	int cur = 0;
	for (int m1 = 0; m1 < nn; ++m1) {
		int mask = (nn - 1) ^ m1;
		beg[m1] = cur;
		for (int m2 = mask;; m2 = (m2 - 1) & mask) {
			mask_pair[cur++] = {m2, m1};
			if (m2 == 0) {
				break;
			}
		}
		reverse(mask_pair + beg[m1], mask_pair + cur);
	}
	for (int i = 0; i < cur; ++i) {
		assert(encode(mask_pair[i].first, mask_pair[i].second) == i);
	}

	for (int mask = 0; mask < nn; ++mask) {
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				continue;
			}
			if (mask == 0) {
				prob_win[i][mask] = 1;
				continue;
			}
			int j = __builtin_ctz(mask);
			prob_win[i][mask] = prob_win[i][mask ^ (1 << j)] * a[i] * stuff.inverse(a[i] + a[j]);
		}
	}

	for (int i = 0; i < cur; ++i) {
		const auto& [x, y] = mask_pair[i];
		if (x == 0) {
			prob_mass_win[i] = 1;
		} else {
			int j = __builtin_ctz(x);
			prob_mass_win[i] = prob_win[j][y] * prob_mass_win[encode(x ^ (1 << j), y)];
		}
	}
	for (int mask = 0; mask < nn; ++mask) {
		prob_draws[mask] = 1;
		for (int sm = mask; sm; sm = (sm - 1) & mask) {
			if (sm == mask) {
				continue;
			}
			prob_draws[mask] -= prob_draws[sm] * prob_mass_win[encode(sm, mask ^ sm)];
		}
	}

	Mint ans = 0;
	for (int mask = 0; mask < nn; ++mask) {
		ans += prob_draws[mask] * prob_mass_win[encode(mask, (nn - 1) ^ mask)] * __builtin_popcount(mask);
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}