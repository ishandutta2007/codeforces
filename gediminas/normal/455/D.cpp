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

/*link https://codeforces.com/group/nIDHK2OChY/contest/252493/problem/D */
/*input
7
6 6 2 7 4 2 5
7
1 3 6
2 2 4 2
2 2 4 7
2 2 2 5
1 2 6
1 1 4
2 1 7 3
*/
/*output
2
1
0
0
*/
/*input
8
8 4 2 2 7 7 8 8
8
1 8 8
2 8 1 7
1 8 1
1 7 3
2 8 8 3
1 1 4
1 2 7
1 4 5
*/
/*output
2
0
*/

// #define GENERATE_TEST

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
#ifndef GENERATE_TEST
	cin >> n;
#else
	n = 100000;
#endif
	vector<int> ind[n];
	vector<int> blogi[n];
	vi a(n);
	vector<bool> leon(n, false);

	for (int i = 0; i < n; i++) {
#ifndef GENERATE_TEST
		cin >> a[i];
#else
		a[i] = rand() % n + 1;
#endif
		a[i]--;
		ind[a[i]].push_back(i);
	}

	int q;
#ifndef GENERATE_TEST
	cin >> q;
#else
	q = 100000;
#endif
	int lastans = 0;
	vector<pii> nekeisti;
	seti<pii> posl, posl2;
	int antanas = 0;

	for (int i = 0; i < n; i++) {
		posl.insert({i, antanas++});
	}

	posl2 = posl;

	auto fix = [&]() -> void {
		vi aa(n);

		for (int i = 0; i < n; i++) {
			ind[i].clear();
			blogi[i].clear();
		}

		for (int i = 0; i < n; i++) {
			int j = posl[i].x;

			if (0 <= j and j < n) {
				aa[i] = a[j];
			}
		}

		for (auto && [i, x] : nekeisti) {
			aa[i] = x;
		}

		a = aa;

		for (int i = 0; i < n; i++) {
			ind[a[i]].push_back(i);
		}

		leon = vector<bool>(n, false);
		nekeisti.clear();
		posl = posl2;
	};

	for (int qqq = 0; qqq < q; qqq++) {
		int t, l, r;
#ifndef GENERATE_TEST
		cin >> t >> l >> r;
#else
		t = rand() % 2 + 1;
		r = rand() % n + 1;
		l = rand() % n + 1;
#endif
		l = (l + lastans - 1) % n;
		r = (r + lastans - 1) % n;

		if (r < l)
			swap(l, r);

		if (t == 2) {
			int k;
#ifndef GENERATE_TEST
			cin >> k;
#else
			k = rand() % n + 1;
#endif
			k = (k + lastans - 1) % n;
			int lll = l;

			while (lll < n and leon[lll])
				lll++;

			int rrr = r;

			while (rrr >= 0 and leon[rrr])
				rrr--;

			int ll = (lll < n ? posl[lll].x : n);
			int rr = (rrr >= 0 ? posl[rrr].x : -1);

			if (lll > r) {
				ll = 0;
				rr = -1;
			}

			int ats = lower_bound(ind[k].begin(), ind[k].end(), rr + 1) - lower_bound(ind[k].begin(), ind[k].end(), ll);

			for (auto && i : blogi[k]) {
				if (ll <= i and i <= rr) {
					ats--;
				}
			}

			for (auto && [i, x] : nekeisti) {
				if (l <= i and i <= r and x == k) {
					ats++;
				}
			}

			cout << (lastans = ats) << "\n";
		}
		else {
			if (l == r)
				continue;

			if (nekeisti.size() > 700) {
				fix();
			}

			int ll = posl[l].x;
			int rr = posl[r].x;

			if (ll < 0)
				ll = 0;

			if (rr < ll)
				rr = ll;

			int sk = -1;

			if (0 <= rr and rr < n)
				sk = a[rr];

			if (leon[r]) {
				for (auto && [i, x] : nekeisti) {
					if (i == r) {
						sk = x;
						break;
					}
				}

				leon[r] = false;
			}
			else {
				blogi[sk].push_back(rr);
			}

			for (auto && [i, x] : nekeisti) {
				leon[i] = false;
			}

			vector<pii> nekeisti2;

			nekeisti2.emplace_back(l, sk);
			posl.erase(posl.lower_bound({rr, -1}));
			posl.insert({ll, antanas++});

			for (auto && [i, x] : nekeisti) {
				if (l <= i and i < r)
					nekeisti2.emplace_back(i + 1, x);
				else if (i != r) {
					nekeisti2.emplace_back(i, x);
				}
			}

			swap(nekeisti, nekeisti2);

			for (auto && [i, x] : nekeisti) {
				leon[i] = true;
			}
		}
	}


}