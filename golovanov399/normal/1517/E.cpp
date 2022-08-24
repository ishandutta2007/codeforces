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
		if (_val < 0 || _val >= mod()) {
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

constexpr int mod = 998'244'353;
using Mint = Modular<mod>;

Mint f(const vector<int>& a, long long thres, bool can_finish_with_skip = true) {
	if (thres < 0) {
		return 0;
	}

	const int n = a.size();
	vector<long long> p(n + 1);
	for (int i = 0; i < n; ++i) {
		p[i + 1] = a[i];
		if (i > 0) {
			p[i + 1] += p[i - 1];
		}
	}

	auto get_max_nomore = [&](int from, long long mx) {
		int l = 0, r = (n - from + 1) / 2;
		while (r > l + 1) {
			int m = (l + r) / 2;
			if (p[from + 2 * m + 1] - p[from + 1] <= mx) {
				l = m;
			} else {
				r = m;
			}
		}
		return l;
	};

	Mint ans = 1;
	long long cur = 0;
	for (int i = 0; i < n; ++i) {
		cur += a[i];
		if (cur > thres) {
			break;
		}
		int m = get_max_nomore(i, thres - cur);
		ans += m + 1;
		if (i + 2 * m == n - 1 && m > 0 && !can_finish_with_skip) {
			ans -= 1;
		}
	}
	return ans;
}

Mint solve(vector<int> a) {
	const int n = a.size();
	if (n == 1) {
		return 1;
	}
	long long s = accumulate(all(a), 0ll);
	s = (s - 1) / 2;

	vector<int> b(a.begin() + 1, a.end() - 1);
	Mint ans = f(b, s) + f(b, s - a[0]) + f(b, s - a[n - 1], false) + f(b, s - a[0] - a[n - 1], false);
	// cerr << f(b, s) << " " << f(b, s - a[0]) << " " << f(b, s - a[n - 1], false) << " " << f(b, s - a[0] - a[n - 1], false) << "\n";
	long long cur = 0;
	for (int i = n - 1; i > 1; --i) {
		cur += a[i];
		if (i < n - 1) {
			ans += cur <= s;
		}
	}
	cur = a[0];
	for (int i = 2; i < n; i += 2) {
		cur += a[i];
		ans += cur <= s;
		if (i + 2 < n - 1) {
			ans += cur + a.back() <= s;
		}
	}
	return ans;
}

Mint stupid(vector<int> a) {
	const int n = a.size();
	int ans = 0;
	for (int mask = 0; mask < (1 << n); ++mask) {
		vector<int> p, c;
		for (int i = 0; i < n; ++i) {
			if (mask & (1 << i)) {
				c.push_back(i);
			} else {
				p.push_back(i);
			}
		}
		int sump = 0, sumc = 0;
		bool ok = true;
		for (int i : c) {
			sumc += a[i];
		}
		for (int i : p) {
			sump += a[i];
		}
		for (int i = 1, last = 0; i < (int)c.size(); ++i) {
			if (c[i] - c[i - 1] < last) {
				ok = false;
			}
			last = c[i] - c[i - 1];
		}
		for (int i = 1, last = n; i < (int)p.size(); ++i) {
			if (p[i] - p[i - 1] > last) {
				ok = false;
			}
			last = p[i] - p[i - 1];
		}
		if (ok && sumc < sump) {
			// for (int x : p) {
			// 	cerr << x << " ";
			// }
			// cerr << "\n";
			// cerr << bitset<6>(mask) << "\n";
			++ans;
		}
	}
	return ans;
}

int main() {
#if 1
	int t = nxt();
	while (t--) {
		int n = nxt();
		vector<int> a(n);
		generate(all(a), nxt);
		cout << (n <= 3 ? stupid(a) : solve(a)) << "\n";
	}
#else
	while (true) {
		int n = 4;
		vector<int> a(n);
		for (int i = 0; i < n; ++i) {
			a[i] = rand() % 100 + 1;
		}
		auto our = solve(a);
		auto actual = stupid(a);
		if (our != actual) {
			cout << n << "\n";
			for (int x : a) {
				cout << x << " ";
			}
			cout << "\n";
			cout << "   our: " << our << "\n";
			cout << "actual: " << actual << "\n";
			return 0;
		} else {
			cerr << "ok ";
		}
	}
#endif

	return 0;
}