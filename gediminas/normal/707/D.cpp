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

template<class T>
struct reversed {
	T &iterable;
	reversed(T &iterable): iterable(iterable) {
	}
	auto begin() {
		return rbegin(iterable);
	}
	auto end() {
		return rend(iterable);
	}
};

template<class T>
struct indexed {
	T &iterable;
	template<class IT>
	struct indexed_iterator {
		IT iterator;
		int val = 0;
		indexed_iterator(IT i) : iterator(i) {}
		pair<typename IT::value_type, int> operator*() {
			return {*iterator, val};
		}
		void operator++() {
			val++;
			iterator++;
		}
		bool operator!=(const indexed_iterator &o) const {
			return iterator != o.iterator;
		}
	};
	indexed(T &iterable): iterable(iterable) {
	}
	indexed_iterator<typename T::iterator> begin() {
		return indexed_iterator{iterable.begin()};
	}
	indexed_iterator<typename T::iterator> end() {
		return indexed_iterator{iterable.end()};
	}
};

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

//sum
struct Node {
	Node *left = NULL, *right = NULL;
	int from, to;
	long long sum = 0, lazy = 0;
	Node() {}
	Node(int from, int to): from(from), to(to) {
		if (from == to)
			return;

		left = new Node(from, (from + to) / 2);
		right = new Node((from + to) / 2 + 1, to);
	}
	Node(int from, int to, long long mas[]): from(from), to(to) {
		if (from == to) {
			sum = mas[from];
			return;
		}

		left = new Node(from, (from + to) / 2, mas);
		right = new Node((from + to) / 2 + 1, to, mas);
		sum = left->sum + right->sum;
	}
	ll lazy_get(int la = 0) {
		if ((la ^ lazy) == 0)
			return sum;
		else
			return to - from + 1 - sum;
	}
	long long get(int fr, int t, int la = 0) {
		if (fr <= from and to <= t)
			return lazy_get(la);

		if (t < from or to < fr)
			return 0;

		return left->get(fr, t, la ^ lazy) + right->get(fr, t, la ^ lazy);
	}
	Node *update(int fr, int t) {
		auto it = new Node();
		*it = *this;
		it->updateh(fr, t);
		return it;
	}
	void updateh(int fr, int t) {
		if (t < from or to < fr)
			return;

		if (fr <= from and to <= t) {
			lazy ^= 1;
		}
		else {
			left = left->update(fr, t);
			right = right->update(fr, t);
			left->lazy ^= lazy;
			right->lazy ^= lazy;
			sum = left->lazy_get() + right->lazy_get();
			lazy = 0;
		}
	}
	~Node() {
		if (left) {
			delete left;
			delete right;
		}
	}
};

/*link https://codeforces.com/contest/707/problem/D */
/*input
2 3 3
1 1 1
3 2
4 0
*/
/*output
1
4
0
*/
/*input
4 2 6
3 2
2 2 2
3 3
3 2
2 2 2
3 2
*/
/*output
2
1
3
3
2
4
*/
/*input
2 2 2
3 2
2 2 1
*/
/*output
2
1
*/
int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n, m, q;
	cin >> n >> m >> q;
	vector<Node *> rez;
	rez.push_back(new Node(0, n * m - 1));

	auto ind = [&](int i, int j) -> int {
		return i * m + j;
	};

	for (int qqq = 0; qqq < q; qqq++) {
		int t, i;
		cin >> t >> i;
		Node *dab = rez.back();

		if (t == 1) {
			int j;
			cin >> j;
			i--, j--;

			if (dab->get(ind(i, j), ind(i, j)) == 0) {
				dab = dab->update(ind(i, j), ind(i, j));
			}
		}
		else if (t == 2) {
			int j;
			cin >> j;
			i--, j--;

			if (dab->get(ind(i, j), ind(i, j)) == 1) {
				dab = dab->update(ind(i, j), ind(i, j));
			}
		}
		else if (t == 3) {
			i--;
			dab = dab->update(ind(i, 0), ind(i, m - 1));
		}
		else {
			dab = rez[i];
		}

		cout << dab->get(0, n * m - 1) << "\n";
		rez.push_back(dab);
	}

}