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
ostream &operator<<(ostream &out, const multimap<T, P> &arr) {
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

template<typename T, typename P>
ostream &operator<<(ostream &out, const multiset<T, P> &arr) {
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
	const char *comma = names;
	int gyl = 0;

	while (*comma != ',' or gyl > 0) {
		if (*comma == '(' or * comma == '{' or * comma == '[')
			gyl++;

		if (*comma == ')' or * comma == '}' or * comma == ']')
			gyl--;

		comma++;
	}

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

struct UnionFind {
	vector<int> par;
	vector<int> siz;
	vector<int> val;
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

/*link https://codeforces.com/group/8rU0UX1QW3/contest/248912/problem/D */
/*input
2 2
1 2
3 4
*/
/*output
1 2
2 3
*/
/*input
4 3
20 10 30
50 40 30
50 60 70
90 80 70
*/
/*output
2 1 3
5 4 3
5 6 7
9 8 7
*/
/*input
3 3
1100 1100 1100
1 1100 1
1 1 1
*/

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int a[n][m];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> a[i][j];
		}
	}

	vector<set<int>> gra(n * m);
	vi iki(n * m, 0);

	UnionFind x(n * m);
	auto num = [m](int i, int j) -> ll {
		return i * m + j;
	};

	for (int i = 0; i < n; i++) {
		vpll b;

		for (int j = 0; j < m; j++) {
			b.emplace_back(a[i][j], j);
		}

		sort(b.begin(), b.end());

		for (int j = 1; j < (int)b.size(); j++) {
			if (b[j - 1].x == b[j].x) {
				x.merge(num(i, b[j - 1].y), num(i, b[j].y));
			}
		}
	}

	for (int j = 0; j < m; j++) {
		vpll b;

		for (int i = 0; i < n; i++) {
			b.emplace_back(a[i][j], i);
		}

		sort(b.begin(), b.end());

		for (int i = 1; i < (int)b.size(); i++) {
			if (b[i - 1].x == b[i].x) {
				x.merge(num(b[i - 1].y, j), num(b[i].y, j));
			}
		}
	}

	for (int i = 0; i < n; i++) {
		vpll b;

		for (int j = 0; j < m; j++) {
			b.emplace_back(a[i][j], j);
		}

		sort(b.begin(), b.end());

		for (int j = 1; j < (int)b.size(); j++) {
			if (b[j - 1].x != b[j].x) {
				if (gra[x[num(i, b[j - 1].y)]].insert(x[num(i, b[j].y)]).second)
					iki[x[num(i, b[j].y)]]++;
			}
		}
	}

	for (int j = 0; j < m; j++) {
		vpll b;

		for (int i = 0; i < n; i++) {
			b.emplace_back(a[i][j], i);
		}

		sort(b.begin(), b.end());

		for (int i = 1; i < (int)b.size(); i++) {
			if (b[i - 1].x != b[i].x) {
				if (gra[x[num(b[i - 1].y, j)]].insert(x[num(b[i].y, j)]).second)
					iki[x[num(b[i].y, j)]]++;
			}
		}
	}

	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		cout << x[num(i, j)] << " ";
	// 	}

	// 	cout << endl;
	// }

	debug(gra);
	priority_queue<pii, vector<pii>, greater<pii>> eil;
	int val[n * m];

	for (int i = 0; i < n * m; i++) {
		if (iki[i] == 0 and x[i] == i) {
			eil.emplace(1, i);
			val[i] = 1;
			debug(i);
		}
	}

	debug(iki);

	while (!eil.empty()) {
		int dab = eil.top().y;
		eil.pop();

		debug(dab);

		for (auto && i : gra[dab]) {
			iki[i]--;

			if (iki[i] == 0) {
				val[i] = val[dab] + 1;
				eil.emplace(val[dab] + 1, i);
			}
		}
	}


	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cout << val[x[num(i, j)]] << " ";
		}

		cout << endl;
	}
}