#include <algorithm>
#include <bitset>
#include <cassert>
#include <chrono>
#include <climits>
#include <cstdint>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <deque>
#include <fstream>
#include <functional>
#include <iostream>
#include <iomanip>
#include <map>
#include <numeric>
#include <queue>
#include <random>
#include <set>
#include <stack>
#include <sstream>
#include <tuple>
#include <vector>

using namespace std;
using namespace chrono;

#ifdef DEBUG
	#define LOCAL_INPUT_FILE
#else
	//#define USE_FILE_IO
#endif

#ifdef USE_FILE_IO
	#define INPUT_FILE "input.txt"
	#define OUTPUT_FILE "output.txt"
	#define cin ____cin
	#define cout ____cout
	ifstream cin(INPUT_FILE);
	ofstream cout(OUTPUT_FILE);
#else
	#ifdef LOCAL_INPUT_FILE
		#define cin ____cin
		ifstream cin("input.txt");
	#endif
#endif

const int infinity = (int)1e9 + 42;
const int64_t llInfinity = (int64_t)1e18 + 256;
const int module = (int)1e9 + 7; 
const long double eps = 1e-8;

mt19937_64 randGen(system_clock().now().time_since_epoch().count());

inline void raiseError(string errorCode) {
	cerr << "Error : " << errorCode << endl;
	exit(42);
}

template<class Int>
class Fraction {
private:
	Int n;
	Int d;
	
	inline static Int gcd(const Int &a, const Int &b) {
		return (b == Int(0)) ? a : gcd(b, a % b);
	}
	
	inline void truncate() {
		Int g = gcd(abs(n), abs(d));
		n /= g;
		d /= g;
		if (d < Int(0)) {
			n *= -1;
			d *= -1;
		}
	}
public:
	Fraction()
		: n(0), d(1) {
	}
	
	explicit Fraction(int64_t v)
		: n(v), d(1) {
	}
	
	explicit Fraction(const Int &v)
		: n(v), d(1) {
	}
	
	explicit Fraction(string s) {
		size_t p = s.find('/');
		if (p == string::npos) {
			istringstream nIs(s); nIs >> n;
			d = Int(1);
		} else {
			istringstream nIs(s.substr(0, p)); nIs >> n;
			istringstream dIs(s.substr(p+1));  dIs >> d;
		}
		truncate();
	}
	
	Fraction(const Int &n, const Int &d)
		: n(n), d(d) {
		truncate();
	}
	
	inline string toString() const {
		ostringstream os; os << *this;
		return os.str();
	}
	
	inline Int numerator() const {
		return n;
	}
	
	inline Int denominator() const {
		return d;
	}
	
	inline friend istream &operator>>(istream &is, Fraction &a) {
		string s; is >> s;
		a = Fraction(s);
		return is;
	}
	
	inline friend ostream &operator<<(ostream &os, const Fraction &a) {
		if (a.d == Int(1)) {
			return os << a.n;
		} else {
			return os << a.n << "/" << a.d;
		}
	}
	
	inline Fraction &operator=(const string &s) {
		return *this = Fraction(s);
	}
	
	inline Fraction &operator=(const Int &v) {
		return *this = Fraction(v);
	}
	
	inline friend bool operator<(const Fraction &a, const Fraction &b) {
		return a.n * b.d < b.n * a.d;
	}
	
	inline friend bool operator<=(const Fraction &a, const Fraction &b) {
		return a.n * b.d <= b.n * a.d;
	}
	
	inline friend bool operator>(const Fraction &a, const Fraction &b) {
		return a.n * b.d > b.n * a.d;
	}
	
	inline friend bool operator>=(const Fraction &a, const Fraction &b) {
		return a.n * b.d >= b.n * a.d;
	}
	
	inline friend bool operator==(const Fraction &a, const Fraction &b) {
		return a.n * b.d == b.n * a.d;
	}
	
	inline friend bool operator!=(const Fraction &a, const Fraction &b) {
		return a.n * b.d != b.n * a.d;
	}
	
	inline friend Fraction operator+(const Fraction &a) {
		return a;
	}
	
	inline friend Fraction operator-(const Fraction &a) {
		return Fraction(-a.n, a.d);
	}
	
	inline Fraction &operator++() {
		n += d;
		truncate();
		return *this;
	}
	
	inline Fraction operator++(int) {
		Fraction ret = *this;
		++(*this);
		return ret;
	}
	
	inline Fraction &operator--() {
		n -= d;
		truncate();
		return *this;
	}
	
	inline Fraction operator--(int) {
		Fraction ret = *this;
		--(*this);
		return ret;
	}
	
	inline friend Fraction operator+(const Fraction &a, const Fraction &b) {
		return Fraction(a.n * b.d + a.d * b.n, a.d * b.d);
	}
	
	inline friend Fraction operator-(const Fraction &a, const Fraction &b) {
		return Fraction(a.n * b.d - a.d * b.n, a.d * b.d);
	}
	
	inline friend Fraction operator*(const Fraction &a, const Fraction &b) {
		return Fraction(a.n * b.n, a.d * b.d);
	}
	
	inline friend Fraction operator/(const Fraction &a, const Fraction &b) {
		return Fraction(a.n * b.d, a.d * b.n);
	}
	
	inline Fraction &operator+=(const Fraction &delta) {
		return *this = *this + delta;
	}
	
	inline Fraction &operator-=(const Fraction &delta) {
		return *this = *this - delta;
	}
	
	inline Fraction &operator*=(const Fraction &delta) {
		return *this = *this * delta;
	}
	
	inline Fraction &operator/=(const Fraction &delta) {
		return *this = *this / delta;
	}
	
	inline friend Fraction abs(Fraction a) {
		a.n = abs(a.n);
		a.d = abs(a.d);
		return a;
	}
};

typedef Fraction<int64_t> IntFraction;

class FenwickTree {
private:
	int n;
	vector<int64_t> a;
public:
	inline void add(int v, int64_t delta) {
		for (; v < n; v |= v+1) {
			a[v] += delta;
		}
	}
	
	inline int64_t sum(int v) {
		int64_t res = 0;
		for (; v >= 0; v &= v+1, v--) {
			res += a[v];
		}
		return res;
	}
	
	inline int64_t sum(int l, int r) {
		return sum(r) - sum(l-1);
	}
	
	FenwickTree(int n)
		: n(n), a(n, 0) {
	}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n, w; cin >> n >> w;
	vector< pair<int, int> > a(n);
	for (int i = 0; i < n; i++) {
		cin >> a[i].first >> a[i].second;
	}
	sort(a.begin(), a.end());
	vector<IntFraction> factor1(n);
	vector<IntFraction> factor2(n);
	map<IntFraction, int> kompr1;
	map<IntFraction, int> kompr2;
	for (int i = 0; i < n; i++) {
		int64_t x = a[i].first, v = a[i].second;
		factor1[i] = IntFraction(x, v + w);
		factor2[i] = IntFraction(x, v - w);
		kompr1[factor1[i]] = 42;
		kompr2[factor2[i]] = 42;
	}
	int ktr1 = 0, ktr2 = 0;
	for (auto &it: kompr1) {
		it.second = ktr1++;
	}
	for (auto &it: kompr2) {
		it.second = ktr2++;
	}
	FenwickTree f1m(ktr1), f1p(ktr1);
	FenwickTree f2m(ktr2), f2p(ktr2);
	int64_t ans = (int64_t)n * (n-1) / 2;
	for (int i = 0; i < n; i++) {
		int val1 = ktr1 - kompr1[factor1[i]] - 1;
		int val2 = kompr2[factor2[i]];
		if (a[i].first < 0) {
			ans -= f1m.sum(val1 - 1);
			ans -= f2m.sum(val2 - 1);
			ans -= f1p.sum(val1 + 1, ktr1 - 1);
			ans -= f2p.sum(val2 + 1, ktr2 - 1);
			f1m.add(val1, +1);
			f2m.add(val2, +1);
		} else {
			ans -= f1p.sum(val1 - 1);
			ans -= f2p.sum(val2 - 1);
			ans -= f1m.sum(val1 + 1, ktr1 - 1);
			ans -= f2m.sum(val2 + 1, ktr2 - 1);
			f1p.add(val1, +1);
			f2p.add(val2, +1);
		}
	}
	cout << ans << endl;
	return 0;
}