// #include <bits/stdc++.h>


#include <bits/stdc++.h>


#include <memory>	// to define make_unique

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define imie(x) #x << ": " << x

using namespace std;

#include <iostream>
#include <vector>
#include <utility>

using std::istream;

template <typename T>
istream& operator >>(istream& istr, std::vector<T>& vec) {
	for (auto& x : vec) {
		istr >> x;
	}
	return istr;
}

template <typename T, typename U>
istream& operator >>(istream& istr, std::pair<T, U>& pr) {
	return istr >> pr.first >> pr.second;
}

template <typename T = int>
T nxt(istream& istr = std::cin) {
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

	int operator ()() const {
		return val;
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

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

using Mint = TypeModular<integral_variable<int>>;

void solve() {
	int n = nxt(), q = nxt();
	int mod = nxt();
	set_prime(mod);
	vector<Mint> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] += nxt();
	}
	for (int i = 0; i < n; ++i) {
		a[i] -= nxt();
	}

	vector<Mint> fib(n + 10);
	fib[0] = 0;
	fib[1] = 1;
	for (int i = 2; i < (int)fib.size(); ++i) {
		fib[i] = fib[i - 2] + fib[i - 1];
	}

	int zcnt = 0;
	a.insert(a.begin(), 0);
	a.insert(a.begin(), 0);
	a.push_back(0);
	a.push_back(0);
	for (int i = (int)a.size() - 1; i >= 2; --i) {
		a[i] -= a[i - 1] + a[i - 2];
	}
	for (auto x : a) {
		zcnt += x == 0;
	}
	auto inc = [&](int i, const Mint& x) {
		zcnt -= a[i] == 0;
		a[i] += x;
		zcnt += a[i] == 0;
	};
	auto add = [&](int l, int r, const Mint& x) {
		inc(l, x);
		inc(r, -x * fib[r - l + 1]);
		inc(r + 1, -x * fib[r - l]);
	};

	while (q--) {
		char c;
		cin >> c;
		int l = nxt() - 1, r = nxt();
		int sign = c == 'A' ? 1 : -1;
		add(l + 2, r + 2, sign);
		cout << (zcnt == (int)a.size() ? "YES" : "NO") << "\n";
	}
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