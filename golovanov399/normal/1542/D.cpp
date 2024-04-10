

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
#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

constexpr int mod = 998'244'353;
using Mint = Modular<mod>;

struct Op {
	char c;
	int x;
};

void solve() {
	int n = nxt();
	vector<Op> ops(n);
	for (int i = 0; i < n; ++i) {
		cin >> ops[i].c;
		if (ops[i].c == '+') {
			ops[i].x = nxt();
		} else {
			ops[i].x = 0;
		}
	}

	auto calc = [&](const vector<int>& a) {
		vector<Mint> dp(n);
		bool has_one = false;
		vector<Mint> tmp(n);
		dp[0] = 1;
		for (int x : a) {
			if (x == -1) {
				for (int i = 0; i < n - 1; ++i) {
					tmp[i] = dp[i + 1];
				}
				tmp[n - 1] = 0;
				if (!has_one) {
					tmp[0] += dp[0];
				}
				for (int i = 0; i < n; ++i) {
					dp[i] += tmp[i];
				}
			} else if (x == 0) {
				for (int i = 0; i < n - 1; ++i) {
					tmp[i + 1] = dp[i];
				}
				tmp[0] = 0;
				for (int i = 0; i < n; ++i) {
					dp[i] += tmp[i];
				}
			} else if (x == 1) {
				has_one = true;
			} else if (x == 2) {
				for (int i = 0; i < n; ++i) {
					dp[i] *= 2;
				}
			} else {
				assert(false);
			}
		}
		return accumulate(all(dp), Mint(0));
	};

	Mint ans = 0;
	for (int i = 0; i < n; ++i) {
		if (ops[i].c == '-') {
			continue;
		}
		vector<int> val(n, -1);
		for (int j = 0; j < n; ++j) {
			if (ops[j].c == '-') {
				continue;
			}
			if (j == i) {
				val[j] = 1;
			} else if (make_pair(ops[j].x, j) < make_pair(ops[i].x, i)) {
				val[j] = 0;
			} else {
				val[j] = 2;
			}
		}
		ans += ops[i].x * calc(val);
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