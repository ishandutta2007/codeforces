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
typedef long long ld;
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

using namespace std;
template<int N>
struct UnionFind {
	int par[N];
	int siz[N];
	UnionFind() {
		for (int i = 0; i < N; i++) {
			par[i] = i;
			siz[i] = 1;
		}
	}
	int operator[](const int &x) {
		return getParent(x);
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
		return true;

	}
	bool connected(const int &x, const int &y) {
		return getParent(x) == getParent(y);
	}
};

const int maxN = 200000;
const int logN = 19;
vector<int> gra[maxN];
int par[maxN];
int gyl[maxN];
multiset<pii> pries;
bool apl[maxN];
UnionFind<maxN> name;
set<int> gra2[maxN];

void dfs(int d) {
	apl[d] = true;

	for (auto && x : gra[d]) {
		if (apl[x])
			continue;

		gyl[x] = gyl[d] + 1;
		par[x] = d;
		debug(d, x);
		pries.erase(pries.find(makep(min(d, x), max(d, x))));
		dfs(x);
	}
}

int namea[maxN];

void merge(int a, int b) {
	debug("m", a, b);
	a = name[a], b = name[b];

	while (a != b) {
		if (gyl[b] > gyl[a]) {
			name.merge(b, par[b]);

			if (gyl[par[b]] < gyl[namea[name[b]]])
				namea[name[b]] = par[b];

			b = namea[name[b]];
		}
		else {
			name.merge(a, par[a]);

			if (gyl[par[a]] < gyl[namea[name[a]]])
				namea[name[a]] = par[a];

			a = namea[name[a]];
		}
	}
}

bool apl2[maxN];
int par2[logN][maxN];
int gyl2[maxN];
void dfs2(int d) {
	apl2[d] = true;

	for (auto && x : gra2[d]) {
		if (apl2[x])
			continue;

		gyl2[x] = gyl2[d] + 1;
		par2[0][x] = d;
		dfs2(x);
	}
}

int lca(int a, int b) {
	if (gyl2[a] > gyl2[b])
		swap(a, b);

	//gyl[a] < gyl[b]
	debug("LCA");
	debug(a, b);

	for (int i = logN - 1; i >= 0; i--) {
		if (gyl2[b] - (1 << i) >= gyl2[a])
			b = par2[i][b];
	}

	assert(gyl[a] == gyl[b]);

	if (a == b)
		return a;

	for (int i = logN - 1; i >= 0; i--) {
		if (par2[i][a] != par2[i][b]) {
			b = par2[i][b];
			a = par2[i][a];
		}
	}

	debug(par2[0][a]);
	return par2[0][a];
}

bool blog = false;
UnionFind<maxN> virsun;
UnionFind<maxN> apacion;
int viki[maxN];
int aiki[maxN];
bool virs[maxN];
bool apac[maxN];

void mergeap(int a, int b) {
	if (a == b || blog)
		return;

	a = aiki[apacion[a]];
	b = aiki[apacion[b]];

	while (a != b) {
		debug(a, b);
		int aaa = aiki[apacion[par2[0][a]]];
		apacion.merge(par2[0][a], a);

		if (virs[a]) {
			blog = true;
			return;
		}

		apac[a] = true;
		aiki[apacion[a]] = aaa;
		a = aiki[apacion[a]];
	}
}

void mergevi(int a, int b) {
	if (a == b || blog)
		return;

	a = viki[virsun[a]];
	b = viki[virsun[b]];

	while (a != b) {
		int aaa = viki[virsun[par2[0][a]]];
		virsun.merge(par2[0][a], a);

		if (apac[a]) {
			blog = true;
			return;
		}

		virs[a] = true;
		viki[virsun[a]] = aaa;
		a = viki[virsun[a]];
	}
}

void merge2(int a, int b) {
	int lc = lca(a, b);
	debug(lc);
	mergevi(a, lc);
	mergeap(b, lc);
}

/*inputa
4 4 2
1 2
1 3
2 3
3 4
1 3
4 2
*/
/*inputa
3 2 2
1 2
3 2
1 3
2 1
*/
/*inputa
3 3 2
1 2
1 2
3 2
1 3
2 1
*/
/*inputa
5 4 3
1 2
1 3
3 4
3 5

4 5
2 5
3 1
*/
/*input
2 1 2
1 2

1 2
2 1
*/
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;

	for (int i = 0; i < n; i++) {
		viki[i] = aiki[i] = namea[i] = i;
	}

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gra[a].push_back(b);
		gra[b].push_back(a);
		pries.emplace(min(a, b), max(a, b));
	}

	for (int i = 0; i < n; i++) {
		if (!apl[i]) {
			dfs(i);
			par[i] = i;
		}
	}

	for (auto && x : pries) {
		debug(x);
		merge(x.x, x.y);
	}

	for (int i = 0; i < n; i++) {
		int a = name[i];

		for (auto && x : gra[i]) {
			int b = name[x];

			if (a != b) {
				gra2[a].insert(b);
				gra2[b].insert(a);
			}
		}
	}

	for (int i = 0; i < n; i++) {
		debug(i, name[i], gyl[i]);

		if (!apl2[name[i]]) {
			dfs2(name[i]);
			par2[0][name[i]] = name[i];
		}
	}


	for (int i = 1; i < logN; i++) {
		for (int j = 0; j < n; j++) {
			par2[i][j] = par2[i - 1][par2[i - 1][j]];
		}
	}

	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		debug(name[a], name[b]);

		if (par2[18][name[a]] != par2[18][name[b]])
			blog = true;

		if (!blog)
			merge2(name[a], name[b]);

		if (blog) {
			cout << "No";
			return 0;
		}
	}

	cout << "Yes";
	return 0;
}