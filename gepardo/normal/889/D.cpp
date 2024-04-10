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

namespace Fractions {
template<class Int>
class Fraction {
private:
	Int n;
	Int d;
	
	inline static Int gcd(const Int& a, const Int& b) {
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
	
	Fraction(const Int& v)
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
	
	Fraction(const Int& n, const Int& d)
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
	
	inline friend istream& operator>>(istream& is, Fraction& a) {
		string s; is >> s;
		a = Fraction(s);
		return is;
	}
	
	inline friend ostream& operator<<(ostream& os, const Fraction& a) {
		if (a.d == Int(1)) {
			return os << a.n;
		} else {
			return os << a.n << "/" << a.d;
		}
	}
	
	inline Fraction& operator=(const string& s) {
		return *this = Fraction(s);
	}
	
	inline Fraction& operator=(const Int& v) {
		return *this = Fraction(v);
	}
	
	inline friend bool operator<(const Fraction& a, const Fraction& b) {
		return a.n * b.d < b.n * a.d;
	}
	
	inline friend bool operator<=(const Fraction& a, const Fraction& b) {
		return a.n * b.d <= b.n * a.d;
	}
	
	inline friend bool operator>(const Fraction& a, const Fraction& b) {
		return a.n * b.d > b.n * a.d;
	}
	
	inline friend bool operator>=(const Fraction& a, const Fraction& b) {
		return a.n * b.d >= b.n * a.d;
	}
	
	inline friend bool operator==(const Fraction& a, const Fraction& b) {
		return a.n * b.d == b.n * a.d;
	}
	
	inline friend bool operator!=(const Fraction& a, const Fraction& b) {
		return a.n * b.d != b.n * a.d;
	}
	
	inline friend Fraction operator+(const Fraction& a) {
		return a;
	}
	
	inline friend Fraction operator-(const Fraction& a) {
		return Fraction(-a.n, a.d);
	}
	
	inline Fraction& operator++() {
		n += d;
		truncate();
		return *this;
	}
	
	inline Fraction operator++(int) {
		Fraction ret = *this;
		++(*this);
		return ret;
	}
	
	inline Fraction& operator--() {
		n -= d;
		truncate();
		return *this;
	}
	
	inline Fraction operator--(int) {
		Fraction ret = *this;
		--(*this);
		return ret;
	}
	
	inline friend Fraction operator+(const Fraction& a, const Fraction& b) {
		return Fraction(a.n * b.d + a.d * b.n, a.d * b.d);
	}
	
	inline friend Fraction operator-(const Fraction& a, const Fraction& b) {
		return Fraction(a.n * b.d - a.d * b.n, a.d * b.d);
	}
	
	inline friend Fraction operator*(const Fraction& a, const Fraction& b) {
		return Fraction(a.n * b.n, a.d * b.d);
	}
	
	inline friend Fraction operator/(const Fraction& a, const Fraction& b) {
		return Fraction(a.n * b.d, a.d * b.n);
	}
	
	inline Fraction& operator+=(const Fraction& delta) {
		return *this = *this + delta;
	}
	
	inline Fraction& operator-=(const Fraction& delta) {
		return *this = *this - delta;
	}
	
	inline Fraction& operator*=(const Fraction& delta) {
		return *this = *this * delta;
	}
	
	inline Fraction& operator/=(const Fraction& delta) {
		return *this = *this / delta;
	}
	
	inline long double toDouble() {
		return (long double)n / d;
	}
	
	inline friend Fraction abs(Fraction a) {
		a.n = abs(a.n);
		a.d = abs(a.d);
		return a;
	}
};
}

using Fraction = Fractions::Fraction<int64_t>;

struct Point {
	int64_t x, y;
	
	auto toPair() {
		return make_pair(x, y);
	}
	
	inline friend ostream & operator <<(ostream &os, const Point &p) {
		return os << "{" << p.x << ", " << p.y << "}";
	}
};

signed main() {
	#ifndef USE_FILE_IO
		ios_base::sync_with_stdio(false);
	#endif
	int n; cin >> n;
	vector<Point> v(n);
	int64_t sumX = 0, sumY = 0;
	for (int i = 0; i < n; i++) {
		cin >> v[i].x >> v[i].y;
		sumX += v[i].x;
		sumY += v[i].y;
	}
	Fraction pX {sumX, n}, pY {sumY, n};
	vector<char> active(n, true);
	for (int i = 0; i < n; i++) {
		if (v[i].x == pX && v[i].y == pY) {
			active[i] = false;
		}
		if (!active[i]) {
			continue;
		}
		for (int j = 0; j < i; j++) {
			if (!active[j]) {
				continue;
			}
			if (v[i].x + v[j].x == 2 * pX && v[i].y + v[j].y == 2 * pY) {
				active[i] = active[j] = false;
				break;
			}
		}
	}
	vector<Point> q;
	for (int i = 0; i < n; i++) {
		if (active[i]) {
			q.push_back(v[i]);
		}
	}
	if (q.empty()) {
		cout << -1 << endl;
		return 0;
	}
	
	set<Fraction> anses;
	int qs = q.size();
	
	auto check = [&](const Fraction &x, const Fraction &y) {
		if (2*pX == q[0].x + x) {
			return;
		}
		
		Fraction fK = -(2*pY - q[0].y - y) / (2*pX - q[0].x - x);
		long double k = fK.toDouble();
		long double pivot = pX.toDouble() * k + pY.toDouble();
		
		vector<long double> p(qs);
		for (int j = 0; j < qs; j++) {
			p[j] = q[j].x * k + q[j].y;
		}
		sort(p.begin(), p.end());
		bool ok = true;
		for (int j = 0; j < qs; j++) {
			if (abs(2 * pivot - p[j] - p[qs - j - 1]) > (long double)1e-9) {
				ok = false;
				break;
			}
		}
		if (ok) {
			anses.insert(fK);
		}
	};
	
	for (int i = 1; i < qs; i++) {
		check(q[i].x, q[i].y);
	}
	check(pX, pY);
	
	int ans = anses.size();
	auto v2 = v;
	set<int64_t> uniqueX;
	sort(v2.begin(), v2.end(), [&](Point a, Point b) -> bool {
		return a.x < b.x;
	});
	for (int i = 0; i < n; i++) {
		uniqueX.insert(v2[i].x + v2[n-i-1].x);
	}
	ans += uniqueX.size() == 1;
	
	cout << ans << endl;
	return 0;
}