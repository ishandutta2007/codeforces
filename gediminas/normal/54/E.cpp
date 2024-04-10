#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
struct seti : public tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {
	seti(): tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>() {}
	explicit seti(initializer_list<T> o): tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>() {
		for (const T &x : o)
			this->insert(x);
	}
	inline T operator[](int i) {
		return *this->find_by_order(i);
	}
};

template<typename T>
struct vectori : public vector<T> {
	explicit vectori(size_t n, T e = T()): vector<T>(n, e) {}
	template< class InputIt >
	vectori( InputIt first, InputIt last): vector<T>(first, last) {}
	explicit vectori(initializer_list<T> o): vector<T>(o) {}
	inline void operator+=(T o) {
		this->push_back(o);
	}
	inline void operator+=(initializer_list<T> o) {
		this->insert(this->end(), o.begin(), o.end());
	}
	inline void operator+=(vectori<T> o) {
		this->insert(this->end(), o.begin(), o.end());
	}
};

#ifdef LOCAL
template<typename T>
ostream &operator<<(ostream &out, const vector<T> &arr) {
	out << "[";
	bool buv = false;

	for (auto && x : arr) {
		if (buv)
			out << ", ";

		out << x;
		buv = true;
	}

	out << "]";
	return out;
}
template<typename T>
ostream &operator<<(ostream &out, const vectori<T> &arr) {
	out << "[";
	bool buv = false;

	for (auto && x : arr) {
		if (buv)
			out << ", ";

		out << x;
		buv = true;
	}

	out << "]";
	return out;
}

template<typename T, typename P>
ostream &operator<<(ostream &out, const map<T, P> &arr) {
	out << "{";
	bool buv = false;

	for (auto && x : arr) {
		if (buv)
			out << ", ";

		out << x.first << " => " << x.second;
		buv = true;
	}

	out << "}";
	return out;
}

template<typename T, typename P>
ostream &operator<<(ostream &out, const set<T, P> &arr) {
	out << "{";
	bool buv = false;

	for (auto && x : arr) {
		if (buv)
			out << ", ";

		out << x;
		buv = true;
	}

	out << "}";
	return out;
}

template<typename T>
ostream &operator<<(ostream &out, const seti<T> &arr) {
	out << "{";
	bool buv = false;

	for (auto && x : arr) {
		if (buv)
			out << ", ";

		out << x;
		buv = true;
	}

	out << "}";
	return out;
}

#define debug(...) __debugg(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __debugg(const char *name, Arg1 &&arg1) {
	cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __debugg(const char *names, Arg1 &&arg1, Args &&... args) {
	const char *comma = strchr(names + 1, ',');
	cout.write(names, comma - names) << " : " << arg1 << " | ";

	if (*(comma + 1) == ' ')
		comma++;

	__debugg(comma + 1, args...);
}
#else
#define debug(...)
#endif

template<typename X, typename Y>
struct Pair {
	X x;
	Y y;
	template<typename X1, typename Y1>
	Pair(const X1 &x, const Y1 &y): x(x), y(y) {}
	Pair() {}
	template<typename X1>
	explicit Pair(const X1 &x): x(x), y(Y()) {}
	template<typename X1, typename Y1>
	Pair<X, Y> operator+(const Pair<X1, Y1> &o)const {
		return Pair<X1, Y1>(x + o.x, y + o.y);
	}
	template<typename X1, typename Y1>
	Pair<X, Y> operator-(const Pair<X1, Y1> &o)const {
		return Pair<X1, Y1>(x - o.x, y - o.y);
	}
	template<typename X1, typename Y1>
	Pair<X, Y> operator*(const Pair<X1, Y1> &o)const {
		return Pair<X1, Y1>(x * o.x, y * o.y);
	}
	template<typename X1, typename Y1>
	Pair<X, Y> operator/(const Pair<X1, Y1> &o)const {
		return Pair<X1, Y1>(x / o.x, y / o.y);
	}
	template<typename X1, typename Y1>
	void operator+=(const Pair<X1, Y1> &o) {
		x += o.x;
		y += o.y;
	}
	template<typename X1, typename Y1>
	void operator-=(const Pair<X1, Y1> &o) {
		x -= o.x;
		y -= o.y;
	}
	template<typename X1, typename Y1>
	void operator*=(const Pair<X1, Y1> &o) {
		x *= o.x;
		y *= o.y;
	}
	template<typename X1, typename Y1>
	void operator/=(const Pair<X1, Y1> &o) {
		x /= o.x;
		y /= o.y;
	}
	template<typename X1, typename Y1>
	bool operator<(const Pair<X1, Y1> &o)const {
		if (x == o.x)
			return y < o.y;

		return x < o.x;
	}
	template<typename X1, typename Y1>
	bool operator<=(const Pair<X1, Y1> &o)const {
		if (x == o.x)
			return y <= o.y;

		return x <= o.x;
	}
	template<typename X1, typename Y1>
	bool operator>(const Pair<X1, Y1> &o)const {
		if (x == o.x)
			return y > o.y;

		return x > o.x;
	}
	template<typename X1, typename Y1>
	bool operator>=(const Pair<X1, Y1> &o)const {
		if (x == o.x)
			return y >= o.y;

		return x >= o.x;
	}
	template<typename X1, typename Y1>
	bool operator==(const Pair<X1, Y1> &o)const {
		return x == o.x and y == o.y;
	}
	template<typename X1, typename Y1>
	bool operator!=(const Pair<X1, Y1> &o)const {
		return x != o.x or y != o.y;
	}
	template<typename X1, typename Y1>
	void swap(Pair<X1, Y1> &o) {
		swap(x, o.x);
		swap(y, o.y);
	}
};

template<typename X, typename Y>
Pair<X, Y> makep(const X &x, const Y &y) {
	return Pair<X, Y>(x, y);
}

template<typename X, typename Y>
ostream &operator<<(ostream &out, const Pair<X, Y> &p) {
	out << "(" << p.x << ", " << p.y << ")";
	return out;
}

template<typename X, typename Y>
istream &operator>>(istream &in, Pair<X, Y> &p) {
	in >> p.x >> p.y;
	return in;
}

#define make_pair(...) makep(__VA_ARGS__)
#define pair Pair

typedef long long ll;
typedef unsigned long long ull;
typedef long double ld;
typedef vector<int> vi;
typedef vector<ll> vll;
typedef Pair<int, int> pii;
typedef Pair<ll, ll> pll;
typedef vector<pll> vpll;

template<typename T>
istream &operator>>(istream &in, vector<T> &arr) {
	for (auto && x : arr) {
		in >> x;
	}

	return in;
}

template<typename T>
void printi(const T &arr, char skyr = '\n') {
	bool buv = false;

	for (auto && x : arr) {
		if (buv)
			cout << skyr;

		cout << x;
		buv = true;
	}
}

template<typename T>
void printi(const T &arr, const string &skyr) {
	bool buv = false;

	for (auto && x : arr) {
		if (buv)
			cout << skyr;

		cout << x;
		buv = true;
	}
}

template<typename X, typename Y>
void printp(const Pair<X, Y> &p, char skyr = ' ') {
	cout << p.x << skyr << p.y;
}


template<typename X, typename Y>
void printp(const Pair<X, Y> &p, const string &skyr) {
	cout << p.x << skyr << p.y;
}

template<typename X, typename Y>
inline X mini(X &a, const Y &b) __attribute__((always_inline));
template<typename X, typename Y>
inline X mini(X &a, const Y &b) {
	if (a > b)
		a = b;

	return a;
}
template<typename X, typename Y>
inline X maxi(X &a, const Y &b) __attribute__((always_inline));
template<typename X, typename Y>
inline X maxi(X &a, const Y &b) {
	if (a < b)
		a = b;

	return a;
}

template<ll X, ll Y>
inline bool between(ll v)__attribute__((always_inline));
template<ll X, ll Y>
inline bool between(ll v) {
	return ull(v - X) <= ull(Y - X);
}

inline bool between(ll X, ll v, ll Y) __attribute__((always_inline));
inline bool between(ll X, ll v, ll Y) {
	return ull(v - X) <= ull(Y - X);
}

template<class Type>
struct Point {
	Type x, y;
	Point(const Type &x, const Type &y): x(x), y(y) {}
	Point(const Type &x): x(x), y(0) {}
	Point(): x(0), y(0) {}
	template<class Type2>
	Point(const Point<Type2> &o): x(o.x), y(o.y) { }
	template<class Type2>
	Point(const Point<Type2> &A, const Point<Type2> &B) {
		*this = B - A;
	}
	Type distanceSq(const Point &p) const {
		return (x - p.x) * (x - p.x) + (y - p.y) * (y - p.y);
	}
	long double distance(const Point &p) const {
		return sqrtl((x - p.x) * (x - p.x) + (y - p.y) * (y - p.y));
	}
	long double abs() const {
		return sqrtl(x * x + y * y);
	}
	Type absSq() const {
		return x * x + y * y;
	}
	Point operator+(const Point &a) const {
		return Point(x + a.x, y + a.y);
	}
	Point &operator+=(const Point &a) {
		x += a.x;
		y += a.y;
		return *this;
	}
	Point operator-(const Point &a) const {
		return Point(x - a.x, y - a.y);
	}
	Point operator-() const {
		return Point(-x, -y);
	}
	Point &operator-=(const Point &a) {
		x -= a.x;
		y -= a.y;
		return *this;
	}
	Point operator*(const Point &a) const {
		return Point(x * a.x - y * a.y, x * a.y + y * a.x);
	}
	Point &operator*=(const Point &a) {
		x = x * a.x - y * a.y;
		y = x * a.y + y * a.x;
		return *this;
	}
	Point operator*(const Type &a) const {
		return Point(x * a, y * a);
	}
	Point operator/(const Type &a) const {
		return Point(x / a, y / a);
	}
	Point operator*=(const Type &a) {
		x = x * a;
		y = y * a;
		return *this;
	}
	bool operator==(const Point &a)const {
		return x == a.x and y == a.y;
	}
	Type dot(const Point &a)const {
		return x * a.x + y * a.y;
	}
	Type cross(const Point &a)const {
		return x * a.y - y * a.x;
	}
	Point rotate(long double ang) {
		return *this * Point(cos(ang), sin(ang));
	}
	bool operator<(const Point &a) const {
		if (x == a.x)
			return y < a.y;

		return x < a.x;
	}
};
template<class Type>
ostream &operator<<(ostream &out, const Point<Type> &p) {
	out << p.x << " " << p.y;
	return out;
}
template<class Type>
istream &operator>>(istream &in, Point<Type> &p) {
	in >> p.x >> p.y;
	return in;
}
typedef Point<long long> point;
typedef Point<long double> pointd;

using namespace std;
//sum
struct Node {
	Node *left = NULL, *right = NULL;
	int from, to;
	ld sum = 0;
	Node(int from, int to): from(from), to(to) {
		if (from == to)
			return;

		left = new Node(from, (from + to) / 2);
		right = new Node((from + to) / 2 + 1, to);
	}
	ld get(int fr, int t) {
		if (fr <= from and to <= t)
			return sum;

		if (t < from or to < fr)
			return 0;

		return left->get(fr, t) + right->get(fr, t);
	}
	void update(int p, ld delta) {
		sum += delta;

		if (from != to) {
			if (p <= left->to)
				return left->update(p, delta);


			return right->update(p, delta);
		}
	}
	~Node() {
		if (left) {
			delete left;
			delete right;
		}
	}
};

pointd statmenys(pointd la, pointd lb, pointd p) {
	p -= la;
	pointd ch = lb - la;
	pointd jung(ch.x, -ch.y);
	p *= jung;
	p.y = 0;
	return p * ch / ch.absSq() + la;
}

/*input
4
0 0
1 0
1 1
0 1
*/
/*input
8
1 2
2 1
2 -1
1 -2
-1 -2
-2 -1
-2 1
-1 2
*/
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vector<pointd> a(n);
	cin >> a;
	ld ats = 1e200;

	bool nulis = false;

	for (int i = 0; i < n; i++) {
		if ((a[(i) % n] - a[(i + 1) % n]).dot(a[(i + 2) % n] - a[(i + 1) % n]) >= 0) {
			nulis = true;
		}
	}

	if (nulis) {
		cout << 0;
		return 0;
	}

	{
		Node medis(0, 40000);

		auto get = [&](int fr, int to) {
			if (fr <= to) {
				return medis.get(fr, to);
			}
			else {
				return medis.get(fr, 39999) + medis.get(0, to);
			}
		};

		for (int i = 2; i < n; i++) {
			ld t = abs((a[(i) % n] - a[0]).cross(a[i - 1] - a[0])) / 2.0l;
			medis.update(i, t);
			debug(i, t);
		}

		int p = 2;

		for (int i = 0; i < n; i++) {
			pointd dab = a[(i + 1) % n] - a[i];

			while (dab.dot(a[(p + 1) % n] - a[p]) > 0) {
				p = (p + 1) % n;
			}

			debug(i, p);

			pointd sus = statmenys(a[(i + 1) % n], a[i], a[p]);

			debug(a[(i + 1) % n], a[p], sus);

			ld plot = abs((a[(i + 1) % n] - a[0]).cross(sus - a[0])) / 2.0l + abs((sus - a[0]).cross(a[p] - a[0])) / 2.0l;
			debug(plot, (i + 2) % n, p, get((i + 2) % n, p));
			plot -= get((i + 2) % n, p);
			debug(i, p, plot);
			mini(ats, plot);
		}
	}

	reverse(a.begin(), a.end());

	{
		Node medis(0, 40000);

		auto get = [&](int fr, int to) {
			if (fr <= to) {
				return medis.get(fr, to);
			}
			else {
				return medis.get(fr, 39999) + medis.get(0, to);
			}
		};

		for (int i = 2; i < n; i++) {
			ld t = abs((a[(i) % n] - a[0]).cross(a[i - 1] - a[0])) / 2.0l;
			medis.update(i, t);
			debug(i, t);
		}

		int p = 2;

		for (int i = 0; i < n; i++) {
			pointd dab = a[(i + 1) % n] - a[i];

			while (dab.dot(a[(p + 1) % n] - a[p]) > 0) {
				p = (p + 1) % n;
			}

			pointd sus = statmenys(a[(i + 1) % n], a[i], a[p]);

			debug(a[(i + 1) % n], a[p], sus);

			ld plot = abs((a[(i + 1) % n] - a[0]).cross(sus - a[0])) / 2.0l + abs((sus - a[0]).cross(a[p] - a[0])) / 2.0l;
			debug(plot, (i + 2) % n, p, get((i + 2) % n, p));
			plot -= get((i + 2) % n, p);
			debug(i, p, plot);
			mini(ats, plot);
		}
	}

	cout << fixed << setprecision(10) << ats;
}