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

struct Node {
	Node *left = NULL, *right = NULL;
	int from, to;
	long long sum = 0, lazy = 0;
	Node(int from, int to): from(from), to(to) {
		if (from == to)
			return;

		left = new Node(from, (from + to) / 2);
		right = new Node((from + to) / 2 + 1, to);
	}
	void fix() {
		sum += (to - from + 1) * lazy;

		if (from != to) {
			left->lazy += lazy;
			right->lazy += lazy;
		}

		lazy = 0;
	}
	long long get(int fr, int t) {
		if (fr > t)
			return 0;

		fix();

		if (fr <= from and to <= t)
			return sum;

		if (t < from or to < fr)
			return 0;

		return left->get(fr, t) + right->get(fr, t);
	}
	void update(int fr, int t, long long delta) {
		if (fr > t)
			return;

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
			sum = left->sum + right->sum;
		}
	}
	~Node() {
		if (left) {
			delete left;
			delete right;
		}
	}
};

/*input
3 6
1 2
1 3
0 3 1 2
0 2 3 1
0 1 5 2
1 1
1 2
1 3
*/
/*input
6 11
1 2
2 5
5 4
1 6
1 3
0 3 1 3
0 3 4 5
0 2 1 4
0 1 5 5
0 4 6 2
1 1
1 2
1 3
1 4
1 5
1 6
*/
/*input
3 4
1 2
1 3
0 2 5 0
1 1
1 2
1 3
*/
/*input
10 11
1 2
2 3
3 4
4 5
5 6
6 7
7 8
8 9
9 10
0 5 1 1
1 1
1 2
1 3
1 4
1 5
1 6
1 7
1 8
1 9
1 10
*/
int kuris[100100] = {};
vector<int> gra[100100];
int counter = 0;
int kiekyra = 0;
int gyl[100100] = {};
void dfs(int d, int p) {
	kuris[d] = counter;
	kiekyra++;

	for (auto && i : gra[d]) {
		if (i == p)
			continue;

		gyl[i] = gyl[d] + 1;
		dfs(i, d);
	}
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, q;
	cin >> n >> q;

	for (int i = 1; i < n; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gra[a].push_back(b);
		gra[b].push_back(a);
	}

	Node bendras(0, n + 1);
	int laips = gra[0].size();
	Node *kiekv[laips];

	int viso = 1;

	for (int i = 0; i < laips; i++) {
		counter = i;
		kiekyra = 0;
		gyl[gra[0][i]] = 1;
		dfs(gra[0][i], 0);
		viso += kiekyra;
		kiekv[counter] = new Node(0, kiekyra + 1);
	}

	assert(viso == n);

	for (int i = 0; i < q; i++) {
		ll t, v;
		cin >> t >> v;
		v--;

		if (t == 0) {
			ll x, d;
			cin >> x >> d;

			if (v == 0) {
				bendras.update(0, d, x);
			}
			else {
				bendras.update(0, d - gyl[v], x);
				kiekv[kuris[v]]->update(max(d - gyl[v] + 1, gyl[v] - d), d + gyl[v], x);
			}
		}
		else {
			if (v == 0) {
				cout << bendras.get(0, 0) << "\n";
			}
			else {
				cout << bendras.get(gyl[v], gyl[v]) + kiekv[kuris[v]]->get(gyl[v], gyl[v]) << "\n";
			}
		}
	}
}