#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp>

using namespace __gnu_pbds;
using namespace std;

struct trys {
	long long s, p, r;
	int kada;
	bool operator<(const trys &o)const {
		if (kada != o.kada)
			return kada < o.kada;
		else if (s != o.s)
			return s < o.s;
		else if (p != o.p)
			return p < o.p;
		else
			return r < o.r;
	}
};

#ifdef LOCAL
ostream &operator<<(ostream &out, const trys &t) {
	out << "(" << t.s << " " << t.p << " " << t.r << " " << t.kada << ")";
	return out;
}
#endif

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
	void swap() {
		std::swap(x, y);
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

/*link https://codeforces.com/group/8rU0UX1QW3/contest/248912/problem/F */
/*input
8 4 1 1
2 4
0
*/
/*output
0 4
*/
/*input
9 3 2 3
2 3
1 6
-1 0 1
*/
/*output
-1 -1
3 3
3 2
*/
/*input
20 9 2 4
1 5
2 10
-1 0 1 2
*/
/*output
-1 -1
-1 -1
-1 -1
-1 -1
*/

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int e, s, n, m;
	cin >> e >> s >> n >> m;
	vector<pair<pii, int>> degal;

	for (int i = 0; i < n; i++) {
		pii x;
		cin >> x;
		x.swap();

		if (x.x < e)
			degal.emplace_back(x, -1);
	}

	vpll ats(m, pll(-1, -1));

	for (int i = 0; i < m; i++) {
		int x;
		cin >> x;
		degal.emplace_back(pii(x, 3), i);
	}

	sort(degal.begin(), degal.end());

	vll viso(2);
	vll laik(2);
	ll last = e;

	debug(degal);

	for (int i = (int)degal.size() - 1; i >= 0; i--) {
		auto& [x, y] = degal[i].x;
		ll dist = last - x;

		if (dist > s) {
			break;
		}

		if (degal[i].y == -1) {
			if (y == 3) {
				ll viet = s - dist;
				{
					int reg = min(laik[0], viet);
					viso[0] += laik[0] - reg;
					laik[0] = 0;
					viet -= reg;
				}
				{
					int reg = min(laik[1], viet);
					viso[1] += laik[1] - reg;
					laik[1] = 0;
					viet -= reg;
				}
			}
			else if (y == 2) {
				ll viet = s - dist;
				{
					int reg = min(laik[0], viet);
					viso[0] += laik[0] - reg;
					laik[0] = 0;
					viet -= reg;
					dist += reg;
				}
				laik[1] += dist;
			}
			else {
				laik[0] += dist;
			}

			last = degal[i].x.x;
		}
		else {
			vll laik2 = laik, viso2 = viso;
			{
				int reg = min(laik2[0], s - dist);
				viso2[0] += laik2[0] - reg;
				laik2[0] = 0;
				dist += reg;
			}
			{
				int reg = min(laik2[1], s - dist);
				viso2[1] += laik2[1] - reg;
				laik2[1] = 0;
				dist += reg;
			}
			ats[degal[i].y] = pll(viso2[0] + laik2[0], viso2[1] + laik2[1]);
		}

		debug(dist, viso, laik);
	}

	for (int i = 0; i < m; i++) {
		cout << ats[i].x << " " << ats[i].y << "\n";
	}
}