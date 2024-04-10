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
 
using namespace std;
template<class T>
struct Minimumas {
	vector<T> mas;
	vector<int> laips;
	vector<vector<T>> din;
	Minimumas(vector<T> &d): mas(d) {}
	Minimumas() {}
	T &operator[](int i) {
		return mas[i];
	}
	void push_back(T e) {
		mas.push_back(e);
	}
	void preprocess() {
		laips = vector<int>(mas.size() + 1);
 
		laips[1] = 0;
 
		for (unsigned i = 2; i <= mas.size(); i++)
			laips[i] = 1 + laips[i >> 1];
 
		din = vector<vector<T>>(laips[mas.size()] + 1, vector<T>(mas.size()));
 
		din[0] = mas;
 
		for (int i = 1; i <= laips[mas.size()]; i++) {
			for (int j = 0; j + (1 << i) <= (int)mas.size(); j++)
				din[i][j] = min(din[i - 1][j], din[i - 1][j + (1 << (i - 1))]);
		}
	}
	T get(int fr, int to) {
		if (fr < 0)
			fr = 0;
 
		if (to >= (int)mas.size())
			to = (int)mas.size() - 1;
 
		to++;
		int siz = laips[to - fr];
 
		return min(din[siz][fr] , din[siz][to - (1 << siz)]);
	}
};
struct Maximumas {
	vector<long long> mas;
	vector<long long> laips;
	vector<vector<long long>> din;
	Maximumas(vector<int> d) {
		for (auto && i : d) {
			mas.push_back(i);
		}
	}
	Maximumas() {}
	long long &operator[](int i) {
		return mas[i];
	}
	void push_back(long long e) {
		mas.push_back(e);
	}
	void preprocess() {
		laips = vector<long long>(mas.size() + 1);
 
		laips[1] = 0;
 
		for (unsigned i = 2; i <= mas.size(); i++)
			laips[i] = 1 + laips[i >> 1];
 
		din = vector<vector<long long>>(laips[mas.size()] + 1, vector<long long>(mas.size()));
 
		din[0] = mas;
 
		for (int i = 1; i <= laips[mas.size()]; i++) {
			for (int j = 0; j + (1 << i) <= mas.size(); j++)
				din[i][j] = max(din[i - 1][j], din[i - 1][j + (1 << (i - 1))]);
		}
	}
	long long get(int fr, int to) {
		if (fr < 0)
			fr = 0;
 
		if (to >= (int)mas.size())
			to = (int)mas.size() - 1;
 
		to++;
		int siz = laips[to - fr];
 
		return max(din[siz][fr] , din[siz][to - (1 << siz)]);
	}
};
/*link https://codeforces.com/group/8rU0UX1QW3/contest/248912/problem/A */
/*input
6
1 2 3 2 1 4
6 7 1 2 3 2
*/
/*output
2
*/
/*input
3
3 3 3
1 1 1
*/
/*output
0
*/
/*input
3
1 1 1
1 1 1
*/
/*output
3
*/
 
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	vi a(n);
	vi b(n);
	cin >> a >> b;
	Maximumas aa(a);
	Minimumas<int> bb(b);
	aa.preprocess();
	bb.preprocess();
	vi buv(n), sek(n);
	ll ats = 0;
 
	for (int i = 0; i < n; i++) {
		if (b[i] < a[i]) {
			continue;
		}
 
		int nuo = i - 1;
		int iki = i;
 
		for (int j = 17; j >= 0; j--) {
			int del = (1 << j);
 
			if (aa.get(i, nuo + del) < bb.get(i, nuo + del)) {
				nuo += del;
			}
 
			if (aa.get(i, iki + del) <= bb.get(i, iki + del)) {
				iki += del;
			}
		}
 
		mini(nuo, n - 1);
		mini(iki, n - 1);
 
		debug(nuo, iki);
		ats += iki - nuo;
	}
 
	cout << ats;
}