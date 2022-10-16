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

/*input
3
1 0 0
0 1 0
0 0 1
*/
/*input
7
0 8 9
5 9 -2
6 -8 -7
9 4 5
-4 -9 9
-4 5 2
-6 8 -7
*/
/*input
2
1 0 0
1 1 0
*/
/*input
24
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
10000000 10000000 10000000
*/
int n;

struct skai {
	ll a = 0, b = 0, c = 0;
	bool operator<(const skai &o)const {
		if (o.a == a)
			return b < o.b;

		return a < o.a;
	}
};

vector<skai> r;
map<pll, pll> y;

skai temp1;
ll tem = 0;
int dal;

void generate1(int d) {
	if (d > dal) {
		if (y.count(makep(temp1.a, temp1.b)))
			maxi(y[makep(temp1.a, temp1.b)], makep(temp1.c, tem));
		else
			y[makep(temp1.a, temp1.b)] = makep(temp1.c, tem);
	}
	else {
		tem *= 4;
		// -1
		temp1.b += r[d].b;
		temp1.c += r[d].c;
		temp1.a -= r[d].c;
		temp1.b -= r[d].c;
		tem++;
		generate1(d + 1);
		temp1.b -= r[d].b;
		temp1.c -= r[d].c;
		temp1.a += r[d].c;
		temp1.b += r[d].c;
		// -2
		temp1.a += r[d].a;
		temp1.c += r[d].c;
		temp1.a -= r[d].c;
		temp1.b -= r[d].c;
		tem++;
		generate1(d + 1);
		temp1.a -= r[d].a;
		temp1.c -= r[d].c;
		temp1.a += r[d].c;
		temp1.b += r[d].c;
		// -3
		temp1.a += r[d].a;
		temp1.b += r[d].b;
		tem++;
		generate1(d + 1);
		temp1.a -= r[d].a;
		temp1.b -= r[d].b;
		tem /= 4;
	}
}

skai temp2;
ll tem2 = 0;
ll ats = -200000000000ll;
ll hhh = 0;

void generate2(int d) {
	if (d >= n) {
		if (y.count(makep(temp2.c - temp2.a, temp2.c - temp2.b))) {
			pll yy = y[makep(temp2.c - temp2.a, temp2.c - temp2.b)];

			if (temp2.c + yy.x > ats) {
				ats = temp2.c + yy.x;
				hhh = tem2 + ((yy.y) << (2 * n - dal * 2 - 2));
			}
		}
	}
	else {
		tem2 *= 4;
		// -1
		temp2.b += r[d].b;
		temp2.c += r[d].c;
		tem2++;
		generate2(d + 1);
		temp2.b -= r[d].b;
		temp2.c -= r[d].c;
		// -2
		temp2.a += r[d].a;
		temp2.c += r[d].c;
		tem2++;
		generate2(d + 1);
		temp2.a -= r[d].a;
		temp2.c -= r[d].c;
		// -3
		temp2.a += r[d].a;
		temp2.b += r[d].b;
		tem2++;
		generate2(d + 1);
		temp2.a -= r[d].a;
		temp2.b -= r[d].b;
		tem2 /= 4;
	}
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	r.resize(n);

	for (auto && i : r) {
		cin >> i.a >> i.b >> i.c;
	}

	dal = n / 2;

	generate1(0);

	generate2(dal + 1);

	if ( ats > -200000000000ll) {
		vi atss(n, 0);
		int p = n - 1;
		debug(bitset<50>(hhh));

		while (hhh > 0) {
			atss[p] = hhh % 4;
			hhh /= 4;
			p--;
		}

		debug(ats, atss);

		for (auto && x : atss) {
			if (x == 1)
				cout << "MW\n";
			else if (x == 2)
				cout << "LW\n";
			else if (x == 3)
				cout << "LM\n";

			assert(x > 0);
		}
	}
	else {
		cout << "Impossible\n";
	}
}