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


/*link https://codeforces.com/group/nIDHK2OChY/contest/252493/problem/G */
/*input
2 2 3
>>
^^
A 2 1
C 1 2 <
A 2 1
*/
/*output
1 3
-1 -1
*/
/*input
4 5 7
><<^<
^<^^>
>>>^>
>^>>^
A 3 1
A 2 2
C 1 4 <
A 3 1
C 1 2 ^
A 3 1
A 2 2
*/
/*output
0 4
-1 -1
-1 -1
0 2
0 2
*/
const char UP = '^';
const char LEFT = '<';
const char RIGHT = '>';
pii kur[100000][10];
bool beg[100000][10];
char kryp[100000][10];
bool sutaisyta[10];
int pr, pab;
int n, m, q;
void taisyk(int i, int j) {
	if (sutaisyta[j])
		return;

	if (kryp[i][j] == UP) {
		if (i - 1 >= pr) {
			kur[i][j] = kur[i - 1][j];
			beg[i][j] = beg[i - 1][j];
		}
		else {
			kur[i][j] = {i - 1, j};
			beg[i][j] = false;
		}
	}
	else if (kryp[i][j] == LEFT) {
		if (j - 1 >= 0) {
			taisyk(i, j - 1);
			kur[i][j] = kur[i][j - 1];
			beg[i][j] = beg[i][j - 1];
		}
		else {
			kur[i][j] = {i, j - 1};
			beg[i][j] = false;
		}
	}
	else if (kryp[i][j] == RIGHT) {
		if (j + 1 < m) {
			taisyk(i, j + 1);
			kur[i][j] = kur[i][j + 1];
			beg[i][j] = beg[i][j + 1];
		}
		else {
			kur[i][j] = {i, j + 1};
			beg[i][j] = false;
		}
	}

	sutaisyta[j] = true;
}

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n >> m >> q;
	const int sqrtn = 340;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> kryp[i][j];
		}
	}

	auto fix = [&](int i) -> void {
		pr = i * sqrtn;
		pab = min((i + 1) * sqrtn - 1, n - 1);

		for (int i = pr; i <= pab; i++) {
			for (int j = 0; j < m; j++) {
				beg[i][j] = false;
				sutaisyta[j] = false;

				if (j + 1 < m) {
					if (kryp[i][j] == RIGHT and kryp[i][j + 1] == LEFT) {
						beg[i][j] = beg[i][j + 1] = true;
						sutaisyta[j] = sutaisyta[j + 1] = true;
					}
				}
			}

			for (int j = 0; j < m; j++) {
				taisyk(i, j);
			}
		}
	};

	for (int i = 0; i <= (n - 1) / sqrtn; i++) {
		fix(i);
	}

	for (int ttt = 0; ttt < q; ttt++) {
		char t;
		pii d;
		cin >> t >> d.x >> d.y;
		d.y--, d.x--;

		if (t == 'A') {
			debug(d, beg[d.x][d.y]);

			while (d.x >= 0 and d.y >= 0 and d.y < m and beg[d.x][d.y] != true) {
				d = kur[d.x][d.y];
			}

			while (d.x >= 0 and d.y >= 0 and d.y < m and beg[d.x][d.y] != true) {
				if (kryp[d.x][d.y] == UP) {
					d.x--;
				}
				else if (kryp[d.x][d.y] == LEFT) {
					d.y--;
				}
				else if (kryp[d.x][d.y] == RIGHT) {
					d.y++;
				}
			}

			if (d.x >= 0 and d.y >= 0 and d.y < m and beg[d.x][d.y]) {
				cout << -1 << " " << -1;
			}
			else {
				cout << d.x + 1 << " " << d.y + 1;
			}

			cout << "\n";
		}
		else {
			cin >> kryp[d.x][d.y];
			fix(d.x / sqrtn);
		}
	}
}