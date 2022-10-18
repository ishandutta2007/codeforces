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
typedef vector<pii> vpii;

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

/*link https://codeforces.com/contest/990/problem/G */
/*input
3
1 2 3
1 2
2 3
*/
/*output
1 4
2 1
3 1
*/
/*input
6
1 2 4 8 16 32
1 6
6 3
3 4
4 2
6 5
*/
/*output
1 6
2 5
4 6
8 1
16 2
32 1
*/
/*input
4
9 16 144 6
1 3
2 3
4 3
*/
/*output
1 1
2 1
3 1
6 2
9 2
16 2
144 1
*/

ll gcd(ll a, ll b) {
	if (a > b)
		swap(a, b);

	if (a == 0)
		return b;

	return gcd(b % a, a);
}

vector<bool> apl;
vector<bool> apl2;
vector<int> gra[200000];
int n;
ll m;
vll ats;
vi dyd;
vi gyl;
vi a;
set<int> pask;
vi idom;
vi kiek;
const int lima = 200001;
int raskdyd(int d, int p) {
	apl2[d] = true;
	dyd[d] = 1;

	for (auto && i : gra[d]) {
		if (i == p or apl[i])
			continue;

		dyd[d] += raskdyd(i, d);
	}

	return dyd[d];
}
void raskgyl(int d, int p, ll dal = 0) {
	dal = gcd(a[d], dal);
	pask.insert(dal);
	kiek[dal]++;

	for (auto && i : gra[d]) {
		if (i == p or apl[i])
			continue;

		raskgyl(i, d, dal);
	}
}
int ieskok(int d, int p, int didz) {
	for (auto && i : gra[d]) {
		if (i == p or apl[i])
			continue;

		if (dyd[i] > didz)
			return ieskok(i, d, didz);
	}

	return d;
}
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	cin >> n;
	a.resize(n);
	cin >> a;
	apl = vector<bool>(n, false);
	dyd = vi(n, 0);
	gyl = vi(n, 0);
	ats = vll(lima, 0);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		a--, b--;
		gra[a].push_back(b);
		gra[b].push_back(a);
	}


	while (true) {
		bool rad = false;
		apl2 = vector<bool>(n, false);
		vi kiek2 = vi(200000, 0);
		kiek = vi(200000, 0);

		for (int i = 0; i < n; i++) {
			if (!apl[i] and !apl2[i]) {
				int dydis = raskdyd(i, -1);
				int cent = ieskok(i, -1, dydis / 2);

				ats[a[cent]]++;
				kiek2[a[cent]]++;
				set<int> idom;
				idom.insert(a[cent]);

				for (auto && j : gra[cent]) {
					if (apl[j])
						continue;

					pask.clear();
					raskgyl(j, cent, a[cent]);

					debug(pask, idom);

					for (auto && i : pask) {
						for (auto && j : idom) {
							ats[gcd(i, j)] += kiek2[j] * 1ll * kiek[i];
						}
					}

					for (auto && i : pask) {
						idom.insert(i);
						kiek2[i] += kiek[i];
						kiek[i] = 0;
					}
				}

				for (auto && i : idom) {
					kiek2[i] = 0;
				}

				rad = true;
				apl[cent] = true;
			}
		}

		if (!rad)
			break;
	}

	for (int i = 1; i < lima; i++) {
		if (ats[i])
			cout << i << " " << ats[i] << "\n";
	}

}