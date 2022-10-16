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
5
5 5 5 5 5
3
1 3 2
2 2 1
4 4 1
*/
const ll inf = 1000000000000000000ll;
struct Node {
	Node *left = NULL, *right = NULL;
	int from, to;
	ll xL = 0, xR = 0;
	int zemL = 1, zemR = 1;
	int aukL = 1, aukR = 1;
	int hillL = 1, hillR = 1;
	int hill = 1;
	ll lazy = 0;
	int sz = 0;
	Node(int from, int to): from(from), to(to) {
		sz = to - from + 1;

		if (from == to) {
			return;
		}

		left = new Node(from, (from + to) / 2);
		right = new Node((from + to) / 2 + 1, to);
	}
	void fix() {
		xL += lazy;
		xR += lazy;

		if (from != to) {
			left->lazy += lazy;
			right->lazy += lazy;
		}

		lazy = 0;
	}
	void update(int fr, int t, long long delta) {
		fix();

		if (t < from or to < fr)
			return;

		if (fr <= from and to <= t) {
			lazy += delta;
			fix();
		}
		else {
			left->update(fr, t, delta);
			right->update(fr, t, delta);
			xL = left->xL;
			xR = right->xR;
			hill = max(left->hill, right->hill);
			zemL = left->zemL;
			zemR = right->zemR;
			aukL = left->aukL;
			aukR = right->aukR;
			hillL = left->hillL;
			hillR = right->hillR;

			if (left->xR < right->xL) {
				maxi(hill, left->zemR + right->hillL);

				if (left->sz == left->aukL)
					aukL = left->aukL + right->aukL;

				if (right->sz == right->zemR)
					zemR = left->zemR + right->zemR;

				if (right->sz == right->hillR)
					hillR = left->zemR + right->hillR;

				if (left->sz == left->aukL)
					hillL = left->aukL + right->hillL;
			}
			/*
			ll xL = 0, xR = 0;
			int zemL = 1, zemR = 1;
			int aukL = 1, aukR = 1;
			int hillL = 1, hillR = 1;
			int hill = 1;
			*/
			else if (left->xR > right->xL) {
				maxi(hill, left->hillR + right->zemL);

				if (left->sz == left->zemL)
					zemL = left->zemL + right->zemL;

				if (right->sz == right->aukR)
					aukR = left->aukR + right->aukR;

				if (right->sz == right->zemL)
					hillR = left->hillR + right->zemL;

				if (left->sz == left->hillR)
					hillL = left->hillR + right->zemL;
			}

			maxi(hillL, zemL);
			maxi(hillL, aukL);
			maxi(hillR, zemR);
			maxi(hillR, aukR);
			maxi(hill, hillL);
			maxi(hill, hillR);
		}
	}
	void print() {
		debug(from, to, hill, hillL, zemR, hillR, zemL);

		if (left) {
			left->print();
			right->print();
		}
	}
	~Node() {
		if (left) {
			delete left;
			delete right;
		}
	}
};

// #define test_gener
// #define checkink
#ifdef test_gener
#define checkink
#endif
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
#ifdef test_gener

	while (true) {
#endif
		int n;
#ifndef test_gener
		cin >> n;
#else
		n = 20;
		cout << n << endl;
#endif
		Node medis(0, n - 1);
		ll a[n] = {};

		for (int i = 0; i < n; i++) {
#ifndef test_gener
			cin >> a[i];
#else
			cout << a[i] << endl;
#endif
			medis.update(i, i, a[i]);
		}

		int m;
#ifndef test_gener
		cin >> m;
#else
		m = 5;
		cout << m << endl;
#endif

		for (int i = 0; i < m; i++) {
			ll l, r, d;
#ifndef test_gener
			cin >> l >> r >> d;
			l--, r--;
#else
			l = random() % n;
			r = random() % n;
			d = 1;
#endif

			if (l > r)
				swap(l, r);

#ifdef test_gener
			cout << l << " " << r << " " << d << endl;
#endif

			medis.update(l, r, d);
#ifdef checkink
			cout << "ATS1:";
#endif
			cout << medis.hill << "\n";

#ifdef checkink

			for (int j = l; j <= r; j++) {
				a[j] += d;
			}

			int ma = 1;

			for (int j = 0; j < n; j++) {
				bool maz = false;
				bool ger = true;

				for (int l = j + 1; l < n; l++) {
					if (a[l] == a[l - 1]) {
						ger = false;
						break;
					}
					else {
						maxi(ma, 2);
					}

					if (!maz) {
						if (a[l - 1] < a[l]) {

						}
						else {
							maz = true;
						}
					}
					else {
						if (a[l - 1] < a[l]) {
							ger = false;
							break;
						}
						else {

						}
					}

					if (ger)
						ma = max(ma, l - j + 1);
				}
			}

			cout << "REAL: " << ma << endl;

			if (ma != medis.hill) {
				medis.print();

				for (int i = 0; i < n; i++) {
					cout << a[i] << endl;
				}

				exit(1);
			}

#endif
		}

#ifdef test_gener
		cout << endl;
	}

#endif

}