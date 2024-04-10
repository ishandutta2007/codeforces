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

using namespace std;
//max
struct Node {
	Node *left = NULL, *right = NULL;
	int from, to;
	long long ma = 0, lazy = 0;
	Node(int from, int to): from(from), to(to) {
		if (from == to)
			return;

		left = new Node(from, (from + to) / 2);
		right = new Node((from + to) / 2 + 1, to);
	}
	Node(int from, int to, long long mas[]): from(from), to(to) {
		if (from == to) {
			ma = mas[from];
			return;
		}

		left = new Node(from, (from + to) / 2, mas);
		right = new Node((from + to) / 2 + 1, to, mas);
		ma = max(left->ma, right->ma);
	}
	void fix() {
		ma += lazy;

		if (from != to) {
			left->lazy += lazy;
			right->lazy += lazy;
		}

		lazy = 0;
	}
	long long get(int fr, int t) {
		fix();

		if (fr <= from and to <= t)
			return ma;

		if (t < from or to < fr)
			return -100000000000000000ll;

		return max(left->get(fr, t), right->get(fr, t));
	}
	void update(int fr, int t, long long delta) {
		fix();

		if (t < from or to < fr)
			return;

		if (fr <= from and to <= t) {
			lazy += delta;
			fix();
		}
		else {
			left->update(fr, t, delta);
			right->update(fr, t, delta);
			ma = max(left->ma, right->ma);
		}
	}
	~Node() {
		if (left) {
			delete left;
			delete right;
		}
	}
};

/*link https://codeforces.com/contest/1220/problem/F */
/*input
4
1 2 3 4
*/
/*output
3 2
*/
/*input
7
2 4 1 3 7 6 5
*/

vi a;
vi gyliai;
struct skaicius;
vector<skaicius *> skaiciai;
Node gylmed(0, 400100);
struct skaicius {
	skaicius *left = NULL, *right = NULL, *par = NULL;
	int i;
	skaicius(int i) : i(i) {
		skaiciai[i] = this;
	}
	void updateGyl(int g = 1) {
		gyliai[i] = g;

		if (left)
			left->updateGyl(g + 1);

		if (right)
			right->updateGyl(g + 1);
	}
};

int main () {
	ios_base::sync_with_stdio(false), cin.tie(0), cout.tie(0);
	int n;
	cin >> n;
	a.resize(n);
	gyliai.resize(n);
	skaiciai.resize(2 * n);
	cin >> a;
	skaicius *root = NULL;
	set<pair<int, skaicius *>> vis;

	for (int i = 0; i < n; i++) {
		auto it = vis.lower_bound(pair<int, skaicius *>(a[i], nullptr));

		skaicius *d = new skaicius(i);

		if (it == vis.begin()) {
			d->left = root;

			if (root)
				root->par = d;

			root = d;
			vis.clear();
		}
		else {
			it--;
			skaicius *p = it->y;

			if (p->right)
				p->right->par = d;

			d->left = p->right;
			d->par = p;
			p->right = d;
			it++;
			vis.erase(it, vis.end());
		}

		vis.emplace(a[i], d);
	}

	root->updateGyl();

	debug(gyliai);

	for (int i = 0; i < n; i++) {
		gylmed.update(i, i, gyliai[i]);
	}

	int gylis = gylmed.get(0, 2 * n);
	int shift = 0;

	for (int i = 0; i + 1 < n; i++) {
		skaicius *d = skaiciai[i];
		skaicius *p = d->par;

		if (p) {
			debug("rem", p->i);
			p->left = d->right;

			if (d->right)
				d->right->par = p;

			d->right = nullptr;
			gylmed.update(0, p->i - 1, -1);
		}
		else {
			if (d->right)
				d->right->par = NULL;

			gylmed.update(i, n + i - 1, -1);
		}

		#ifdef LOCAL
			for(int i = 0; i < 2*n; i++) {
				cout << gylmed.get(i,i) << " ";
			}
			cout << endl;
		#endif

		vis.erase(pair<int, skaicius *>(a[i], skaiciai[i]));
		auto it = vis.lower_bound(pair<int, skaicius *>(a[i], nullptr));
		d = new skaicius(i + n);

		debug(vis);

		if (it == vis.begin()) {
			root = vis.begin()->y;
			d->left = root;

			if (root)
				root->par = d;

			root = d;
			gylmed.update(i + 1, n + i, +1);
			vis.clear();
		}
		else {
			it--;
			skaicius *p = it->y;
			debug(p);
			debug(p->i);

			if (p->right)
				p->right->par = d;

			d->left = p->right;
			d->par = p;
			p->right = d;
			gylmed.update(p->i + 1, n + i - 1, +1);
			gylmed.update(n + i, n + i, gylmed.get(p->i, p->i) + 1);
			it++;
			vis.erase(it, vis.end());
		}

		vis.emplace(a[i], d);
		gylmed.update(i, i, -gylmed.get(i, i));

		#ifdef LOCAL
			for(int i = 0; i < 2*n; i++) {
				cout << gylmed.get(i,i) << " ";
			}
			cout << endl;
		#endif

		int gylis2 = gylmed.get(0, 2 * n);

		if (gylis2 < gylis) {
			gylis = gylis2;
			shift = i + 1;
		}
	}

	cout << gylis << " " << shift;
}