#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

#ifdef ONLINE_JUDGE
	inline int pidorand() {
		return ((rand() & 32767) << 15) | (rand() & 32767);
	}
	#define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

ostream& operator <<(ostream& ostr, const vector<auto>& v) {
	ostr << "{";
	for (int i = 0; i < (int)v.size(); ++i) {
		if (i) {
			ostr << ", ";
		}
		ostr << v[i];
	}
	ostr << "}";
	return ostr;
}

const int blen = 4;
const int Base = 10000;

const int L = 22;
const int N = 1 << L;
bool fft_initialized = false;

using ld = double;
using base = complex<ld>;
using Poly = vector<long long>;

const ld pi = acosl(-1);
base angles[N + 1];
int bitrev[N];

// don't know why such eps, may be changed
const ld eps = 1e-7;

inline bool eq(ld x, ld y) {
	return abs(x - y) < eps;
}

void fft_init() {
	for (int i = 0; i <= N; ++i) {
		angles[i] = {cos(2 * pi * i / N), sin(2 * pi * i / N)};
	}

	for (int i = 0; i < N; ++i) {
		int x = i;
		for (int j = 0; j < L; ++j) {
			bitrev[i] = (bitrev[i] << 1) | (x & 1);
			x >>= 1;
		}
	}

	fft_initialized = true;
}

inline int revBit(int x, int len) {
	return bitrev[x] >> (L - len);
}

void fft(vector<base>& a, bool inverse = false) {
	assert(fft_initialized && "you fucking cunt just write fft_init()");
	int n = a.size();
	assert(!(n & (n - 1)));	// work only with powers of two
	int l = __builtin_ctz(n);

	for (int i = 0; i < n; ++i) {
		int j = revBit(i, l);
		if (i < j) {
			swap(a[i], a[j]);
		}
	}

	for (int len = 1; len < n; len *= 2) {
		for (int start = 0; start < n; start += 2 * len) {
			for (int i = 0; i < len; ++i) {
				base x = a[start + i], y = a[start + len + i];
				int idx = N / 2 / len * i;
				base w = y * angles[inverse ? N - idx : idx];
				a[start + i] = x + w;
				a[start + len + i] = x - w;
			}
		}
	}

	if (inverse) {
		for (auto& x : a) {
			x /= n;
		}
	}
}

Poly multiply(Poly a, Poly b) {
	int n = 1;
	while (n < (int)a.size() || n < (int)b.size()) {
		n *= 2;
	}
	vector<base> ar(n + n), br(n + n);
	for (int i = 0; i < (int)a.size(); ++i) {
		ar[i] = a[i];
	}
	for (int i = 0; i < (int)b.size(); ++i) {
		br[i] = b[i];
	}
	fft(ar);
	fft(br);
	for (int i = 0; i < n + n; ++i) {
		ar[i] = ar[i] * br[i];
	}
	fft(ar, true);
	while (!ar.empty() && eq(norm(ar.back()), 0)) {
		ar.pop_back();
	}
	a.resize(ar.size());
	for (int i = 0; i < (int)a.size(); ++i) {
		a[i] = roundl(real(ar[i]));
	}
	return a;
}

void normalize(vector<long long>& a) {
	while (!a.empty() && a.back() == 0) {
		a.pop_back();
	}
}

struct Num {
	vector<long long> digits;

	Num() {}
	Num(const vector<long long>& _digits): digits(_digits) {};
	Num(const string& s) {
		int cur = 1;
		for (int i = 0; i < (int)s.length(); ++i) {
			if (i % blen == 0) {
				digits.push_back(0);
				cur = 1;
			}
			digits.back() = digits.back() + (int)(s[(int)s.length() - 1 - i] - '0') * cur;
			cur *= 10;
		}
	}

	bool operator <(const Num& ot) const {
		if (digits.size() != ot.digits.size()) {
			return digits.size() < ot.digits.size();
		}
		for (int i = (int)digits.size() - 1; i >= 0; --i) {
			if (digits[i] != ot.digits[i]) {
				return digits[i] < ot.digits[i];
			}
		}
		return false;
	}

	void mul(int k) {
		for (auto& x : digits) {
			x *= k;
		}
		long long carry = 0;
		for (int i = 0; carry || i < (int)digits.size(); ++i) {
			while (i >= (int)digits.size()) {
				digits.push_back(0);
			}
			carry += digits[i];
			digits[i] = carry % Base;
			carry /= Base;
		}
	}

	Num operator *(const Num& ot) const {
		auto res = multiply(digits, ot.digits);
		normalize(res);
		// cerr << digits << " " << ot.digits << " -> " << res << " ";
		long long carry = 0;
		for (int i = 0; carry || i < (int)res.size(); ++i) {
			while (i >= (int)res.size()) {
				res.push_back(0);
			}
			carry += res[i];
			res[i] = carry % Base;
			carry /= Base;
		}
		// cerr << res << "\n";
		return {res};
	}

	void add1() {
		digits[0] += 1;
		int i = 0;
		while (digits[i] >= Base) {
			digits[i] = 0;
			++i;
			if (i >= (int)digits.size()) {
				digits.push_back(0);
			}
			++digits[i];
		}
	}

	void div2() {
		if (digits[0] % 2) {
			add1();
		}
		long long carry = 0;
		for (int i = (int)digits.size() - 1; i >= 0; --i) {
			digits[i] += carry;
			carry = digits[i] % 2 * Base;
			digits[i] /= 2;
		}
		normalize(digits);
	}
};

Num pw(int _a, int b) {
	Num res("1"), a(to_string(_a));
	while (b) {
		if (b & 1) {
			res = res * a;
		}
		b >>= 1;
		a = a * a;
	}
	return res;
}

int main() {
	fft_init();
	ios_base::sync_with_stdio(0);
	// string s(1500000, 0);
	// for (int i = 0; i < (int)s.length(); ++i) {
	// 	s[i] = '0' + rand() % 10;
	// }
	string s;
	cin >> s;

	if ((int)s.length() == 1) {
		int n = s[0] - '0';
		cout << vector<int>{0, 1, 2, 3, 4, 5, 5, 6, 6, 6}[n] << "\n";
		return 0;
	}

	int initial = (int)s.size() - 1;
	initial = initial * log(10) / log(3) - log(4) / log(3);
	initial = max(initial, 0);
	Num n = pw(3, initial);
	Num n0(s);
	Num n1 = n0;
	n1.div2();
	Num n2 = n1;
	n2.div2();
	int ans = 1e9;
	int deg = initial;
	while (n < n2) {
		n.mul(3);
		++deg;
	}
	ans = min(ans, deg * 3 + 4);
	while (n < n1) {
		n.mul(3);
		++deg;
	}
	ans = min(ans, deg * 3 + 2);
	while (n < n0) {
		n.mul(3);
		++deg;
	}
	ans = min(ans, deg * 3);
	printf("%d\n", ans);

	/*
	Num n(s);
	vector<int> deg = {1};
	vector<Num> num = {{"3"}};
	while (num.back() < s) {
		auto tmp = num.back();
		num.push_back(tmp * tmp);
		int d = deg.back();
		deg.push_back(d * 2);
	}

	auto getLog3 = [&]() {
		int res = 0;
		Num cur("1");
		for (int i = (int)deg.size() - 1; i >= 0; --i) {
			auto tmp = cur * num[i];
			if (tmp < n) {
				cur.digits.swap(tmp.digits);
				res += deg[i];
			}
		}
		return res + 1;
	};

	int ans = 3 * getLog3();
	n.div2();
	ans = min(ans, 3 * getLog3() + 2);
	n.div2();
	ans = min(ans, 3 * getLog3() + 4);

	printf("%d\n", ans);
	*/

	return 0;
}