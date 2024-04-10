

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

using Mint = TypeModular<integral_variable<int>>;

const int N = 505;
const int M = N * N / 2;
Mint with_inv[N][M];
Mint tmp[M];
Mint huemp[M];

Mint C[N][N];

void solve() {
	int nn = nxt(), mod = nxt();
	set_prime(mod);

	with_inv[0][0] = 1;
	for (int n = 1; n < N; ++n) {
		Mint cur = 0;
		for (int i = 0; i <= n * (n - 1) / 2; ++i) {
			cur += with_inv[n - 1][i];
			if (i >= n) {
				cur -= with_inv[n - 1][i - n];
			}
			with_inv[n][i] = cur;
		}
	}
	for (int i = 0; i < N; ++i) {
		C[i][0] = C[i][i] = 1;
		for (int j = 1; j < i; ++j) {
			C[i][j] = C[i - 1][j] + C[i - 1][j - 1];
		}
	}

	Mint ans = 0;
	for (int n = 2; n < nn; ++n) {
		// Mint cur = 0;
		// partial_sum(with_inv[n], with_inv[n] + n * (n - 1) / 2 + 1, tmp);
		// for (int d = 1; d <= n; ++d) {
		// 	for (int i = d + 1; i <= n * (n - 1) / 2; ++i) {
		// 		cur += with_inv[n][i] * tmp[i - d - 1] * (n + 1 - d);
		// 	}
		// }
		partial_sum(with_inv[n], with_inv[n] + n * (n - 1) / 2 + 1, tmp);
		partial_sum(tmp, tmp + n * (n - 1) / 2 + 1, tmp);
		partial_sum(tmp, tmp + n * (n - 1) / 2 + 1, huemp);
		Mint cur = 0;
		for (int i = 0; i <= n * (n - 1) / 2 - 2; ++i) {
			if (i < n + 1) {
				cur += with_inv[n][i + 2] * (tmp[i] * (n + 1) - huemp[i]);
			} else {
				cur += with_inv[n][i + 2] * (tmp[i] * (n + 1) - (huemp[i] - huemp[i - n - 1]));
			}
		}
		for (int i = nn; i > n + 1; --i) {
			cur *= i;
		}
		ans += cur; // * C[nn][n + 1];
	}
	cout << ans << "\n";
}

void stupid(int n) {
	auto calc_inv = [&](const vector<int>& p) {
		int ans = 0;
		for (int x : p) {
			for (int y : p) {
				if (x == y) {
					break;
				}
				if (y > x) {
					++ans;
				}
			}
		}
		return ans;
	};
	vector<vector<int>> ps;
	vector<int> p(n);
	iota(all(p), 0);
	int ans = 0;
	do {
		for (auto q : ps) {
			if (calc_inv(q) > calc_inv(p)) {
				++ans;
			}
		}
		ps.push_back(p);
	} while (next_permutation(all(p)));
	cout << ans << "\n";
}

int main() {
	// stupid(6);
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}