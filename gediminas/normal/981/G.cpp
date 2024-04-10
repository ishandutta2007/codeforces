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

int VERY_RANDOM_NUMBER = (uint64_t)(std::make_unique<char>().get()) ^
						 (uint64_t)(std::chrono::high_resolution_clock::now().time_since_epoch().count());

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

struct UnionFind {
	vector<int> par;
	vector<int> siz;
	vector<int> val;
	UnionFind() { }
	UnionFind(int N) {
		par.resize(N);
		siz.resize(N);
		val.resize(N);

		for (int i = 0; i < N; i++) {
			par[i] = i;
			siz[i] = 1;

			val[i] = i;
		}
	}
	int operator[](const int &x) {
		return val[getParent(x)];
	}
	int getParent(int x) {
		int t = x;

		while (par[x] != x)
			x = par[x];

		par[t] = x;
		return x;
	}
	int getSize(const int &x) {
		return siz[getParent(x)];
	}
	bool merge(int x, int y) {
		x = getParent(x);
		y = getParent(y);

		if (x == y)
			return false;

		if (siz[x] > siz[y])
			swap(x, y); // siz[x] is smaller

		par[x] = y;
		siz[y] += siz[x];
		val[y] = max(val[x], val[y]);
		return true;

	}
	bool connected(const int &x, const int &y) {
		return getParent(x) == getParent(y);
	}
};

/*inputa
4 4
1 1 2 1
1 1 2 2
1 1 4 1
2 1 4
*/
/*output
10
*/
/*inputa
3 7
1 1 1 3
1 1 1 3
1 1 1 2
1 1 1 1
2 1 1
1 1 1 2
2 1 1
*/
/*output
4
8
*/
/*input
10 20
*/
struct ASD {
	UnionFind seg;
	set<int> tasks;
	vector<int> task;
	void prep(int n) {
		tasks.insert(n);

		for (auto && i : tasks) {
			task.push_back(i);
		}

		tasks.clear();
		seg = UnionFind(task.size());
	}
};

const ll mod = 998244353;

struct Node {
	Node *left = NULL, *right = NULL;
	int from, to;
	long long sum = 0;
	long long lazyadd = 0, lazymul = 1;
	Node(int from, int to): from(from), to(to) {
		if (from == to)
			return;

		left = new Node(from, (from + to) / 2);
		right = new Node((from + to) / 2 + 1, to);
	}
	void fix() {
		sum *= lazymul;
		sum %= mod;
		sum += (to - from + 1) * lazyadd;
		sum %= mod;

		if (from != to) {
			left->lazymul *= lazymul;
			left->lazymul %= mod;
			left->lazyadd *= lazymul;
			left->lazyadd %= mod;
			left->lazyadd += lazyadd;
			left->lazyadd %= mod;

			right->lazymul *= lazymul;
			right->lazymul %= mod;
			right->lazyadd *= lazymul;
			right->lazyadd %= mod;
			right->lazyadd += lazyadd;
			right->lazyadd %= mod;
		}

		lazymul = 1;
		lazyadd = 0;
	}
	long long get(int fr, int t) {
		fix();

		if (fr <= from and to <= t)
			return sum;

		if (t < from or to < fr)
			return 0;

		return (left->get(fr, t) + right->get(fr, t)) % mod;
	}
	void update(int fr, int t, long long add = 1, long long mul = 2) {
		if (fr > t)
			return;

		fix();

		if (t < from or to < fr)
			return;

		if (fr <= from and to <= t) {
			lazyadd = add;
			lazymul = mul;
			fix();
		}
		else {
			left->update(fr, t, add, mul);
			right->update(fr, t, add, mul);
			sum = (left->sum + right->sum) % mod;
		}
	}
	~Node() {
		if (left) {
			delete left;
			delete right;
		}
	}
};

// #define test
// #define gener

#ifdef gener
#define test
#endif
int main () {
	srand(32);
	int n, m;
	cin >> n >> m;
	map<int, ASD> x;
	vector<pair<int, pair<int, int>>> q(m);

	for (int i = 0; i < m; i++) {
		int t;
#ifdef gener
		t = i % 2 + 1;
		q[i].y = makep(rand() % n, rand() % n);

		if (q[i].y.x > q[i].y.y)
			swap(q[i].y.x, q[i].y.y);

#else
		cin >> t >> q[i].y;
		q[i].y -= makep(1, 1);
#endif

		if (t == 1) {
#ifdef gener
			q[i].x = rand() % 3;
#else
			cin >> q[i].x;
#endif
			x[q[i].x].tasks.insert(q[i].y.x);
			x[q[i].x].tasks.insert(q[i].y.y + 1);
		}
		else {
			q[i].x = -1;
		}
	}

	for (auto && i : x) {
		i.second.prep(n);
	}

#ifdef test
	multiset<int> slow[n] = {};
#endif

	Node medis(0, n - 1);

	for (int i = 0; i < m; i++) {
		debug(q[i].y, q[i].x);
#ifdef test
		{
			vi t(n);
			vi y(n);

			for (int i = 0; i < n; i++) {
				t[i] = slow[i].size();
				y[i] = medis.get(i, i);
			}

			debug(t, y, t == y);
		}
#endif


		if (q[i].x == -1) {
			int ret = medis.get(q[i].y.x, q[i].y.y);
#ifdef test
			int ats = 0;

			for (int j = q[i].y.x; j <= q[i].y.y; j++) {
				ats += slow[j].size();
			}

			debug(ats, ret);
			debug(ats == ret);
			assert(ats == ret);
#endif

			cout << ret << "\n";
		}
		else {
#ifdef test
			vi y(n);

			for (int j = 0; j < n; j++) {
				y[j] = slow[j].count(q[i].x);
			}

			debug(y);

			for (int j = q[i].y.x; j <= q[i].y.y; j++) {
				if (slow[j].count(q[i].x)) {
					vi a(slow[j].begin(), slow[j].end());
					slow[j].insert(a.begin(), a.end());
				}
				else
					slow[j].insert(q[i].x);
			}

#endif

			ASD &d = x[q[i].x];
			int it = lower_bound(d.task.begin(), d.task.end(), q[i].y.x) - d.task.begin();
			int it2 = lower_bound(d.task.begin(), d.task.end(), q[i].y.y + 1) - d.task.begin();

			debug(d.task);
			debug(d.seg.par);
			debug(d.seg.val);

			while (it < it2) {
				debug(d.task[it], d.task[d.seg[it]] - 1, 0, 2);
				medis.update(d.task[it], min(q[i].y.y, d.task[d.seg[it]] - 1), 0, 2);

				if (q[i].y.y <= d.task[d.seg[it]] - 1) {
					break;
				}

				int iki = min(q[i].y.y, d.task[d.seg[it] + 1] - 1);
				debug(d.task[d.seg[it]], iki, 1, 1);
				medis.update(d.task[d.seg[it]], iki, 1, 1);
				int t = d.seg[it] + 1;
				debug(it, it + 1);
				d.seg.merge(it, d.seg[it]+1);
				it = t;
			}

			d.seg.merge(it2 - 1, it2);
		}

		debug(medis.get(0, n - 1));
	}
}