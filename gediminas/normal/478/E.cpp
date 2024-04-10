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

ll n, k;
const int asize = 7;
const ll a10 = 10000000;
const ll aatim[] = {10000000, 1000000, 100000};
ll aint = 0;
vector<pii> liek[10][2];
vi sugener;
gp_hash_table<int, int> mapas[10][2];
void generuok(int i = 0, char fr = '0', bool pirm = true, int ch = +1) {
	if (i == asize) {
		if (aint == 0)
			return;

		if (aint >= aatim[1]) {
			liek[aint / aatim[1]][(ch + 1) / 2].emplace_back(aint % k, aint);
			mapas[aint / aatim[1]][(ch + 1) / 2][aint % k]++;
		}
		else if (aint >= aatim[2] and ch == +1) {
			liek[0][1].emplace_back(aint % k, aint);
			mapas[0][1][aint % k]++;
		}

		sugener.push_back(aint);

		if (aint % k == 0) {
			n--;

			if (n == 0) {
				cout << aint << endl;
				exit(0);
			}
		}

		return;
	}

	if (pirm) {
		aint = 0;
		generuok(i + 1);

		for (int j = '1'; j <= '9'; j++) {
			aint = j - '0';

			generuok(i + 1, j - 1, false, -1);

			if (i + 1 < asize) {
				generuok(i + 1, j + 1, false, +1);
			}
		}

		return;
	}

	if (ch == -1) {
		aint *= 10;

		for (char j = '0'; j <= fr; j++) {
			aint += j - '0';

			generuok(i + 1, j - ch, false, -ch);
			aint -= j - '0';
		}

		aint /= 10;
	}
	else {
		aint *= 10;

		for (char j = fr; j <= '9'; j ++) {
			aint += j - '0';

			generuok(i + 1, j - ch, false, -ch);
			aint -= j - '0';
		}

		aint /= 10;
	}
}
/*inputa
123 4
*/
/*inputa
100 1
*/
/*inputa
97461 457
*/
/*inputa
1 100000000000000
*/
/*input
100000000000000 100000000000000
*/

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);

	cin >> k >> n;

	generuok(0);

	for (int i = 0; i < 10; i++) {
		for (int j = 0; j < 2; j++) {
			sort(liek[i][j].begin(), liek[i][j].end());
		}
	}

	// cout << sugener.size() << endl;

	// cout << mapas[5][0][90252] << endl;
	// exit(0);

	for (ll x : sugener) {
		ll mm = (x * a10) % k;

		if (mm > 0)
			mm = k - mm;

		if(mm > 100000000)
			continue;

		// cout << x << " " << mm << endl;

		auto check = [&](int next, int ch) {
			if (ch == -1)
				ch = 0;

			ll temp = mapas[next][ch][mm];

			if (n <= temp) {
				auto it = lower_bound(liek[next][ch].begin(), liek[next][ch].end(), makep(mm, -1ll));

				while (it != liek[next][ch].end() and it->x == mm) {
					n--;

					if (n == 0) {
						cout << x << setfill('0') << setw(asize) << it->y << endl;
						exit(0);
					}

					it++;
				}
			}
			else {
				n -= temp;
				// auto it = lower_bound(liek[next][ch].begin(), liek[next][ch].end(), makep(mm, -1ll));

				// while (it != liek[next][ch].end() and it->x == mm) {
				// 	cout << x << setfill('0') << setw(asize) << it->y << endl;
				// 	temp--;
				// 	it++;
				// }

				// assert(temp == 0);
			}
		};

		if (x < 10) {
			for (int i = 0; i < x; i++) {
				check(i, +1);
			}

			for (int i = x + 1; i <= 9; i++) {
				check(i, -1);
			}
		}
		else {
			ll la = x % 10;
			ll pla = (x / 10) % 10;

			if (pla > la) {
				for (int i = la + 1; i <= 9; i++) {
					check(i, -1);
				}
			}
			else {
				for (int i = 0; i < la; i++) {
					check(i, +1);
				}
			}
		}

	}

	cout << -1;
}