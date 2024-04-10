#include <bits/stdc++.h>

using namespace std;

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
	Pair(const X1 &x): x(x) {}
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
void printi(const T &arr, string skyr) {
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
void printp(const Pair<X, Y> &p, string skyr) {
	cout << p.x << skyr << p.y;
}

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

/*input
5 5
1 2
2 3
3 1
4 1
5 2
*/
/*input
4 3
1 2
4 3
3 2
*/
/*input
4 4
1 2
2 3
3 4
4 1
*/
/*input
6 7
1 2
2 3
3 1
3 4
4 5
5 6
6 4
*/
/*input
6 5
1 2
2 3
2 4
3 5
4 6
*/
const int maxn = 300010;
UnionFind<maxn> par;
vector<pair<int, int> > gra[maxn];
bool tarjan[maxn];
set<int> gra2[maxn];
int nmin[maxn];
int num[maxn];
int timer = 1;
int n, m;

void dfs(int d, int p = -1) {
	nmin[d] = num[d] = timer++;

	for (auto && xx : gra[d]) {
		int x = xx.x;

		if (x == p)
			continue;

		if (num[x] != 0)
			nmin[d] = min(nmin[d], num[x]);
		else {
			dfs(x, d);
			nmin[d] = min(nmin[d], nmin[x]);

			if (nmin[x] > num[d]) {
				tarjan[xx.y] = true;
			}
		}
	}
}

bool apl[maxn];
int fr;
void dfs2(int d) {
	apl[d] = true;
	par.merge(fr, d);

	for (auto && xx : gra[d]) {
		if (apl[xx.x] or tarjan[xx.y])
			continue;

		dfs2(xx.x);
	}
}

pair<int, int> diam(int d, int p) {
	int ma1 = 0, ma2 = 0;
	int dia = 0;

	for (auto && x : gra2[d]) {
		if (x == p)
			continue;

		pii t = diam(x, d);
		dia = max(dia, t.x);
		t.y++;

		if (t.y >= ma1) {
			ma2 = ma1;
			ma1 = t.y;
		}
		else if (t.y >= ma2) {
			ma2 = t.y;
		}
	}

	return makep(max(dia, ma1 + ma2), ma1);
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gra[a].push_back(make_pair(b, i));
		gra[b].push_back(make_pair(a, i));
	}

	for (int i = 0; i < n; i++) {
		if (num[i] == 0)
			dfs(i);
	}

	for (int i = 0; i < n; i++) {
		if (!apl[i]) {
			fr = i;
			dfs2(i);
		}
	}

	for (int i = 0; i < n; i++) {
		for (auto && x : gra[i]) {
			if (tarjan[x.y])
				gra2[par[i]].insert(par[x.x]);
		}
	}

	cout << diam(par[0], -1).x << endl;

	return 0;
}