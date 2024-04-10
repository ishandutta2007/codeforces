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

/*input
3 10
4 6 7
*/
/*input
2 12
1 10
*/
/*input
2 7
3 4
*/
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m;
	cin >> n >> m;
	int ats1 = 0;
	vector<int> a(n + 1);
	vector<int> (n + 1);
	a[0] = 0;
	set<int> negal;
	negal.insert(0);
	negal.insert(-1);
	negal.insert(m + 1);

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		negal.insert(a[i]);
	}

	map<int, int> x;

	for (int i = 0; i + 1 <= n; i += 2) {
		x[a[i] - 1] = ats1;
		x[a[i]] = ats1;
		x[a[i] + 1] = ats1 + 1;
		ats1 += a[i + 1] - a[i];
		x[a[i + 1] - 1] = ats1 - 1;
		x[a[i + 1]] = ats1;
		x[a[i + 1] + 1] = ats1;
	}

	debug(x);

	if (n % 2 == 0) {
		x[a[n] - 1] = ats1;
		x[a[n]] = ats1;
		x[a[n] + 1] = ats1 + 1;
		ats1 += m - a[n];
		x[m - 1] = ats1 - 1;
		x[m] = ats1;
		x[m + 1] = ats1;
	}
	else {
		x[m - 1] = ats1;
		x[m] = ats1;
	}

	debug(x);

	map<int, int> y;

	int ats = ats1;

	if (n % 2 == 0) {
		ats1 = 0;
		y[m] = 0;
		y[m - 1] = 0;

		for (int i = n; i - 1 >= 0; i -= 2) {
			y[a[i] + 1] = ats1;
			y[a[i]] = ats1;
			y[a[i] - 1] = ats1 + 1;
			ats1 += a[i] - a[i - 1];
			y[a[i - 1] + 1] = ats1 - 1;
			y[a[i - 1]] = ats1;
			y[a[i - 1] - 1] = ats1;
		}
	}
	else {
		ats1 = 0;
		a.push_back(m);

		for (int i = n + 1; i - 1 >= 0; i -= 2) {
			y[a[i] + 1] = ats1;
			y[a[i]] = ats1;
			y[a[i] - 1] = ats1 + 1;
			ats1 += a[i] - a[i - 1];
			y[a[i - 1] + 1] = ats1 - 1;
			y[a[i - 1]] = ats1;
			y[a[i - 1] - 1] = ats1;
		}
	}

	debug(y);



	for (auto && t : x) {
		if (negal.count(t.first))
			continue;

		ats = max(ats, t.second + y[t.first]);
	}

	cout << ats;
}