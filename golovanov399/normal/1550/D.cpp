

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define imie(x) #x << ": " << x

using namespace std;


template <typename T>
istream& operator >>(istream& istr, vector<T>& vec) {
	for (auto& x : vec) {
		istr >> x;
	}
	return istr;
}

template <typename T, typename U>
istream& operator >>(istream& istr, pair<T, U>& pr) {
	return istr >> pr.first >> pr.second;
}

template <typename T = int>
T nxt(istream& istr = cin) {
	T x;
	istr >> x;
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

template <typename T>
istream& operator >>(istream& istr, TypeModular<T>& x) {
	x = nxt(istr);
	return istr;
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

constexpr int mod = 1'000'000'007;
using Mint = Modular<mod>;

void solve() {
	int n = nxt(), l = nxt(), r = nxt();
	InvfactStuff<mod> stuff(n);
	const int off = min(r - n, 1 - l);
	Mint ans = off * stuff.C(n, n / 2);
	if (n % 2) {
		ans *= 2;
	}
	for (int i = 1;; ++i) {
		int can_one = n + 1 - max(1, l + off + i);
		int can_two = min(n, r - off - i);
		int can_both = can_one + can_two - n;
		if (can_one < n / 2 || can_two < n / 2 || can_both < 0) {
			break;
		}
		ans += stuff.C(can_both, n / 2 - (can_one - can_both));
		if (n % 2) {
			ans += stuff.C(can_both, n / 2 + 1 - (can_one - can_both));
		}
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