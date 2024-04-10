#ifdef DEBUG
	#define _GLIBCXX_DEBUG
#endif
#include <iostream>
#include <vector>
#include <algorithm>
#include <cassert>

using namespace std;

template<int Modulo>
class Modular {
private:
	int value;
public:
	inline friend Modular binPow(Modular a, int pow) {
		Modular res = 1;
		while (pow) {
			if (pow & 1) {
				res *= a;
			}
			a *= a;
			pow >>= 1;
		}
		return res;
	}
	
	inline friend Modular rev(const Modular &a) {
		return binPow(a, Modulo - 2);
	}
	
	Modular()
		: value(0) {
	}
	
	Modular(int64_t v)
		: value(v % Modulo)  {
		if (value < 0) {
			value += Modulo;
		}
	}
	
	inline friend Modular operator-(const Modular &a) {
		return -a.value;
	}
	
	inline Modular &operator=(int64_t b) {
		value = b % Modulo;
		return *this;
	}
	
	inline Modular &operator+=(const Modular &b) {
		value += b.value;
		value %= Modulo;
		return *this;
	}
	
	inline Modular &operator-=(const Modular &b) {
		value += Modulo;
		value -= b.value;
		value %= Modulo;
		return *this;
	}
	
	inline Modular &operator*=(const Modular &b) {
		value = ((int64_t)value * b.value) % Modulo;
		return *this;
	}
	
	inline Modular &operator/=(const Modular &b) {
		return *this *= rev(b);
	}
	
	inline friend Modular operator+(Modular a, const Modular &b) {
		return a += b;
	}
	
	inline friend Modular operator-(Modular a, const Modular &b) {
		return a -= b;
	}
	
	inline friend Modular operator*(Modular a, const Modular &b) {
		return a *= b;
	}
	
	inline friend Modular operator/(Modular a, const Modular &b) {
		return a /= b;
	}
	
	inline friend bool operator==(const Modular &a, const Modular &b) {
		return a.value == b.value;
	}
	
	inline friend bool operator!=(const Modular &a, const Modular &b) {
		return a.value != b.value;
	}
	
	inline friend ostream &operator<<(ostream &os, const Modular &a) {
		return os << a.value;
	}
	
	inline int val() {
		return value;
	}
};

const int mod = 10007;

typedef Modular<mod> ModInt;

template<typename T>
inline T calcRecurrence(const vector<T> &a, vector<T> &p, int t) {
	int psz = p.size();
	assert(t >= psz);
	T res = 0;
	for (int i = 0; i < psz; i++) {
		res += a[t-i-1] * p[i];
	}
	return res;
}

template<typename T>
inline vector<T> findRecurrence(const vector<T> &a) {
	vector<T> p {};
	int nz = -1;
	vector<T> nzv {};
	T nzd = 1;
	for (int i = 0; i < (int)a.size(); i++) {
		T v = calcRecurrence(a, p, i);
		T delta = a[i] - v;
		if (delta == T(0)) {
			continue;
		}
		T dif = delta / nzd;
		vector<T> x = nzv;
		for (T &j: x) {
			j *= -dif;
		}
		x.insert(x.begin(), i - nz, 0);
		if (nz >= 0) {
			x[i - nz - 1] = dif;
		}
		if (i - nz + (int)nzv.size() >= (int)p.size()) {
			nz = i;
			nzv = p;
			nzd = delta;
		}
		if (p.size() < x.size()) {
			p.resize(x.size(), T(0));
		}
		for (int i = 0; i < (int)x.size(); i++) {
			p[i] += x[i];
		}
	}
	return p;
}

template<typename T>
inline vector<T> polyMul(const vector<T> &a, const vector<T> &b) {
	if (a.empty() || b.empty()) {
		return vector<T>();
	}
	int n = a.size(), m = b.size();
	vector<T> c(n + m - 1);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			c[i+j] += a[i] * b[j];
		}
	}
	return c;
}

template<typename T>
inline vector<T> polyMod(vector<T> a, const vector<T> &b) {
	assert(!b.empty());
	assert(b.back() != T(0));
	int n = a.size(), m = b.size();
	while (n >= m) {
		if (a.back() != T(0)) {
			T c = a.back() / b.back();
			for (int i = 0; i < m; i++) {
				a[n-m+i] -= c * b[i]; 
			}
		}
		a.pop_back();
		n--;
	}
	while (!a.empty() && a.back() == T(0)) {
		a.pop_back();
	}
	return a;
}

template<typename T>
inline vector<T> polyPowMod(vector<T> a, const vector<T> &m, int64_t n) {
	vector<T> res = polyMod({T(1)}, m);
	while (n) {
		if (n & 1) {
			res = polyMod(polyMul(res, a), m);
		}
		a = polyMod(polyMul(a, a), m);
		n >>= 1;
	}
	return res;
}

template<typename T>
inline T seekRecurrence(const vector<T> &a, vector<T> p, int64_t k) {
	assert(a.size() >= p.size());
	if (k < (int)a.size()) {
		return a[k];
	}
	reverse(p.begin(), p.end());
	p.push_back(T(-1));
	auto xk = polyPowMod({T(0), T(1)}, p, k);
	T res = 0;
	for (int i = 0; i < (int)xk.size(); i++) {
		res += a[i] * xk[i];
	}
	return res;
}

inline void add(int &a, int b) {
	a += b;
	if (a >= mod) {
		a -= mod;
	}
}

int main() {
	#ifdef DEBUG
		freopen("input.txt", "r", stdin);
	#endif
	ios_base::sync_with_stdio(false);
	
	string s; cin >> s;
	int n = s.size();
	int64_t k; cin >> k;
	
	const int mx = 1451;
	const int knt = 1400;
	
	static int mul[mod][27];
	for (int i = 0; i < mod; i++) {
		for (int j = 0; j < 27; j++) {
			mul[i][j] = (i * j) % mod;
		}
	}
	
	static int dp[201][201][mx+2] = {};
	static int res[mx+2] = {};
	dp[0][n][0] = 1;
	for (int i = 0; i <= n; i++) {
		for (int j = n; j >= i; j--) {
			for (int k = 0; k < mx; k++) {
				int val = dp[i][j][k];
				if (!val) {
					continue;
				}
				if (i == j) {
					add(dp[i][j][k+2], mul[val][26]);
					add(res[k], val);
					add(res[k+1], mul[val][26]);
					continue;
				}
				if (i+1 == j) {
					add(res[k], val);
					add(dp[i+1][j][k+1], val);
					add(dp[i][j][k+2], mul[val][25]);
					continue;
				}
				if (s[i] == s[j-1]) {
					add(dp[i+1][j-1][k], val);
					add(dp[i][j][k+2], mul[val][25]);
				} else {
					add(dp[i+1][j][k+1], val);
					add(dp[i][j-1][k+1], val);
					add(dp[i][j][k+2], mul[val][24]);
				}
			}
		}
	}
	
	vector<ModInt> a(knt);
	for (int i = 0; i < knt; i++) {
		a[i] = res[i];
	}
	auto p = findRecurrence(a);
	
	for (int i = knt; i < mx; i++) {
		ModInt v = seekRecurrence(a, p, i);
		assert(v == res[i]);
	}
	cout << seekRecurrence(a, p, k) << endl;
	
	return 0;
}