#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

template<typename T>
struct seti : public tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update> {
	seti() {}
	explicit seti(initializer_list<T> o) {
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
void __debuggg(Arg1 &&arg1) {
	cout << " : " << arg1;
}

void __debuggg([[gnu::unused]] const char *arg1) { }

template <typename Arg1>
void __debugg(const char *name, Arg1 &&arg1) {
	cout << name;
	__debuggg(arg1);
	cout << std::endl;
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

	cout.write(names, comma - names);
	__debuggg(arg1);
	cout << " | ";

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

using namespace std;
struct UnionFind {
	vector<int> par;
	vector<int> siz;
	UnionFind(int N) {
		par.resize(N);
		siz.resize(N);

		for (int i = 0; i < N; i++) {
			par[i] = i;
			siz[i] = 1;
		}
	}
	int operator[](const int &x) {
		return getParent(x);
	}
	int getParent(int x) {
		if (par[x] == x)
			return x;

		return par[x] = getParent(par[x]);
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
		return true;

	}
	bool connected(const int &x, const int &y) {
		return getParent(x) == getParent(y);
	}
};

/*link https://codeforces.com/group/nIDHK2OChY/contest/252957/problem/M */
/*input
5 2
..XXX
XX.XX
X.XXX
X...X
XXXX.
*/
/*output
10
*/
/*input
5 3
.....
.XXX.
.XXX.
.XXX.
.....
*/
/*output
25
*/

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, k;
	cin >> n >> k;
	UnionFind un(n * n);
	vector<vector<char>>a(n, vector<char>(n));
	cin >> a;

	auto ind = [&](int i, int j) -> int  {
		return i * n + j;
	};

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (j + 1 < n and a[i][j] == '.' and a[i][j + 1] == '.') {
				un.merge(ind(i, j), ind(i, j + 1));
			}

			if (i + 1 < n and a[i][j] == '.' and a[i + 1][j] == '.') {
				un.merge(ind(i, j), ind(i + 1, j));
			}
		}
	}

	map<int, int> konv;

	for (int i = 0; i < n * n; i++) {
		if (un[i] == i) {
			int t = konv.size();
			konv[i] = t;
		}
	}

	vector<vi> dyd(n, vi(n));
	vector<vi> num(n, vi(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			num[i][j] = konv[un[ind(i, j)]];
			dyd[i][j] = un.getSize(ind(i, j));
		}
	}

	int ats = 0;

	for (int i = 0; i + k <= n; i++) {
		vector<int> kiek(konv.size(), 0);
		int uzd = 0;
		auto add = [&](int i, int j, int del, bool ar = true) -> void {
			if (i < 0 or j < 0 or i >= n or j >= n)
				return;

			if (a[i][j] == 'X') {
				if (ar)
					uzd += del;
			}
			else{
				if (del == 1) {
					if (kiek[num[i][j]] == 0)
						uzd += dyd[i][j];
				}
				else{
					if (kiek[num[i][j]] == 1)
						uzd -= dyd[i][j];
				}
				kiek[num[i][j]] += del;
			}
		};

		for (int j = 0; j < n; j++) {
			for (int t = 0; t < k; t++) {
				add(i + t, j, 1);
			}

			add(i - 1, j, 1, false);
			add(i + k, j, 1, false);

			for (int t = 0; t < k; t++) {
				add(i + t, j + 1, 1, false);
				add(i + t, j - k, 1, false);
			}

			maxi(ats, uzd);

			for (int t = 0; t < k; t++) {
				add(i + t, j + 1, -1, false);
				add(i + t, j - k, -1, false);
			}

			add(i - 1, j - k + 1, -1, false);
			add(i + k, j - k + 1, -1, false);

			for (int t = 0; t < k; t++) {
				add(i + t, j - k + 1, -1);
			}
		}
	}

	cout << ats;
}