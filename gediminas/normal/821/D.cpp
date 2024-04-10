#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

namespace my {

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

int VERY_RANDOM_NUMBER = (uint64_t)(std::make_unique<char>().get()) ^ (uint64_t)(std::chrono::high_resolution_clock::now().time_since_epoch().count());

struct chash {
	inline int operator()(int x) const {
		return x ^ VERY_RANDOM_NUMBER;
	}
};

template <class A, class B>
using hash_table = gp_hash_table<A, B, chash>;

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
}
using namespace my;

const long long mod = 1000000007;
long long power(long long x, long long l) {
	x = x % mod;

	if (l == 0) return 1;
	else if (l == 1) return x;
	else if (l == 2) return (x * x) % mod;

	long long t = power(x, l >> 1);
	t = (t * t) % mod;

	if (l & 1)
		return (t * x) % mod;

	return t;
}

/*input
4 4 5
1 1
2 1
2 3
3 3
4 3
*/
/*output
2
*/
/*input
5 5 4
1 1
2 1
3 1
3 2
*/
/*output
-1
*/
/*input
2 2 4
1 1
1 2
2 1
2 2
*/
/*output
0
*/
/*input
5 5 4
1 1
2 2
3 3
4 4
*/
/*output
3
*/
struct cell: pll {
	int i;
};

int main () {
	int n, m, k;
	cin >> n >> m >> k;
	bool apl[k + 1] = {}, apl1[k + 1] = {};
	bool apln[n][5] = {}, aplm[m][5] = {};
	vector<int> cn[n], cm[m];
	set<cell> all;
	vector<cell> allv;
	int start;
	{
		for (int i = 0; i < k; i++) {
			cell x;
			cin >> x;
			x.i = i;
			x.x--;
			x.y--;
			allv.push_back(x);

			if (x.x == 0 and x.y == 0)
				start = i;

			all.insert(x);
			cn[x.x].push_back(i);
			cm[x.y].push_back(i);
		}

		cell x;
		x.x = n - 1;
		x.y = m - 1;
		x.i = k;

		if (!all.count(x)) {
			debug("ADD");
			cn[x.x].push_back(k);
			cm[x.y].push_back(k);
			allv.push_back(x);
		}
	}

	int ats = 0;

	deque<int> a;
	deque<int> b;
	b.push_back(start);

	while (!b.empty()) {
		swap(a, b);

		for (auto && i : a) {
			if (!apl[i])
				apl[i] = true;
			else
				i = -1;
		}

		while (!a.empty()) {
			if (a.front() == -1) {
				a.pop_front();
				continue;
			}

			cell d = allv[a.front()];
			a.pop_front();

			if (d.x == n - 1 and d.y == m - 1) {
				debug(ats);
				cout << ats;
				exit(0);
			}

			for (auto && del : {
						makep(-1, 0), makep(0, -1), makep(0, 1), makep(1, 0)
					}) {
				cell i = d;
				i.x += del.x;
				i.y += del.y;
				auto it = all.find(i);

				if (it != all.end()) {
					i = *it;

					if (!apl[i.i]) {
						apl[i.i] = true;
						a.push_back(i.i);
					}
				}
			}

			for (int del = -2; del <= 2; del++) {
				if (d.x + del >= 0 and d.x + del < n) {
					if (!apln[d.x + del][del + 2]) {
						apln[d.x + del][del + 2] = true;

						for (auto && i : cn[d.x + del]) {
							if (!apl[i] and !apl1[i] and (abs(del) < 2 || i != k)) {
								apl1[i] = true;
								b.push_back(i);
								debug(i);
							}
						}
					}
				}
			}

			for (int del = -2; del <= 2; del++) {
				if (d.y + del >= 0 and d.y + del < m) {
					if (!aplm[d.y + del][del + 2]) {
						aplm[d.y + del][del + 2] = true;

						for (auto && i : cm[d.y + del]) {
							if (!apl[i] and !apl1[i] and (abs(del) < 2 || i != k)) {
								apl1[i] = true;
								b.push_back(i);
								debug(i);
							}
						}
					}
				}
			}
		}

		ats++;
	}

	cout << -1;
}