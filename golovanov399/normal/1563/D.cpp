

#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())
#define imie(x) #x << ": " << x

using namespace std;


template <typename T>
istream& operator >>(istream& istr, vector<T>& vec) {
	for (auto& x : vec) {
		istr >> x;
	}
	return istr;
}

template <typename T, typename U>
istream& operator >>(istream& istr, pair<T, U>& pr) {
	return istr >> pr.first >> pr.second;
}

template <typename T = int>
T nxt(istream& istr = cin) {
	T x;
	istr >> x;
	return x;
}

template <typename T>
struct TypeModular {
	using Type = typename decay<decltype(T::value)>::type;
	Type val;

	static constexpr Type mod() {
		return T::value;
	}

	TypeModular(long long _val = 0) {
		if (_val < 0 || (_val > 0 && _val >= mod())) {
			val = _val % mod();
			if (val < 0) {
				val += mod();
			}
		} else {
			val = _val;
		}
	}

	friend TypeModular operator -(const TypeModular& a) {
		return {-a.val};
	}

	friend TypeModular operator +(const TypeModular& a, const TypeModular& b) {
		Type res = a.val + b.val;
		if (res >= mod()) {
			res -= mod();
		}
		return {res};
	}

	friend TypeModular operator -(const TypeModular& a, const TypeModular& b) {
		Type res = a.val - b.val;
		if (res < 0) {
			res += mod();
		}
		return {res};
	}

	friend TypeModular operator *(const TypeModular& a, const TypeModular& b) {
		return {1ll * a.val * b.val};
	}

	friend TypeModular operator /(const TypeModular& a, const TypeModular& b) {
		return a * b.inv();
	}

	TypeModular& operator +=(const TypeModular& b) {
		val += b.val;
		if (val >= mod()) {
			val -= mod();
		}
		return *this;
	}

	TypeModular& operator -=(const TypeModular& b) {
		val -= b.val;
		if (val < 0) {
			val += mod();
		}
		return *this;
	}

	TypeModular& operator *=(const TypeModular& b) {
		val = 1ll * val * b.val % mod();
		return *this;
	}

	TypeModular& operator /=(const TypeModular& b) {
		*this *= b.inv();
		return *this;
	}

	TypeModular& operator ++() {
		val += 1;
		if (val == mod()) {
			val = 0;
		}
		return *this;
	}

	TypeModular operator ++(int) {
		TypeModular tmp(*this);
		operator ++();
		return tmp;
	}

	friend bool operator ==(const TypeModular& a, const TypeModular& b) {
		return a.val == b.val;
	}

	friend bool operator !=(const TypeModular& a, const TypeModular& b) {
		return a.val != b.val;
	}

	TypeModular pow(long long b) const {
		TypeModular res{1}, a{*this};
		while (b) {
			if (b & 1ll) {
				res *= a;
			}
			b >>= 1;
			a *= a;
		}
		return res;
	}

	TypeModular inv() const {
		assert(val);
		return _inv(val, mod());
	}

	int _inv(int a, int b) const {
		return a == 1 ? a : b - 1ll * _inv(b % a, a) * b / a % b;
	}

	explicit operator Type() const {
		return val;
	}

	explicit operator bool() const {
		return val;
	}
};

template <typename T = int>
struct integral_variable {
	static T value;
};

template <typename T> T integral_variable<T>::value;

void set_prime(int p) {
	integral_variable<int>::value = p;
}

template <typename T>
ostream& operator <<(ostream& ostr, const TypeModular<T>& x) {
	return ostr << x.val;
}

template <typename T>
istream& operator >>(istream& istr, TypeModular<T>& x) {
	x = nxt(istr);
	return istr;
}

template <int mod>
using Modular = TypeModular<integral_constant<int, mod>>;

template <int mod>
struct InvfactStuff {
	using Mint = Modular<mod>;

	int n;
	vector<Mint> inv, fact, invfact;

	explicit InvfactStuff(int _n): n(_n + 1), inv(_n + 1, 1), fact(_n + 1, 1), invfact(_n + 1, 1) {
		for (int i = 2; i < n; ++i) {
			inv[i] = -inv[mod % i] * (mod / i);
			fact[i] = fact[i - 1] * i;
			invfact[i] = invfact[i - 1] * inv[i];
		}
	}

	Mint C(int n, int k) const {
		if (k < 0 || k > n) {
			return 0;
		}
		assert(n < this->n);
		return fact[n] * invfact[k] * invfact[n - k];
	}

	Mint binom(int n, int k) const {
		return C(n, k);
	}

	Mint factorial(int n) const {
		assert(n < this->n);
		return fact[n];
	}

	Mint inverse_factorial(int n) const {
		assert(n < this->n);
		return invfact[n];
	}

	Mint inverse(int n) const {
		assert(n < this->n);
		return inv[n];
	}

	Mint falling(int n, int k) const {
		if (k > n) {
			return 0;
		}
		assert(n < this->n);
		return fact[n] * invfact[n - k];
	}
};

template <typename Func>
void rec_pythagorean(long long x, long long y, long long z, long long n, const Func& f) {
	if (z > n) {
		return;
	}
	f(x, y, z);
	rec_pythagorean(
		1 * x - 2 * y + 2 * z,
		2 * x - 1 * y + 2 * z,
		2 * x - 2 * y + 3 * z,
		n, f);
	rec_pythagorean(
		1 * x + 2 * y + 2 * z,
		2 * x + 1 * y + 2 * z,
		2 * x + 2 * y + 3 * z,
		n, f);
	rec_pythagorean(
		-1 * x + 2 * y + 2 * z,
		-2 * x + 1 * y + 2 * z,
		-2 * x + 2 * y + 3 * z,
		n, f);
}

template <typename Func>
void for_all_pythagorean_triples(long long n, const Func& f) {
	rec_pythagorean(3, 4, 5, n, f);
}
#include <random>

mt19937 rr;
mt19937_64 rr64;

inline std::uint_fast32_t custom_rand() {
	return rr();
}

inline std::uint_fast64_t custom_rand64() {
	return rr64();
}

#define rand custom_rand
#define rand64 custom_rand64
#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())


inline int nxt() {
	int x;
	cin >> x;
	return x;
}

constexpr int mod = 998'244'353;
using Mint = Modular<mod>;

const int N = 222'222;
InvfactStuff<mod> stuff(N * 3);

struct Node {
	Node *left, *right;
	int key;
	int prior;
	int sz;
	int add;

	explicit Node(int x): left(nullptr), right(nullptr), key(x), prior(rand()), sz(1), add(0) {}
	Node(): left(nullptr), right(nullptr), key(0), prior(rand()), sz(0), add(0) {}
};

Node nodes[N];
int sz = 0;

Node* new_node(int x) {
	nodes[sz++] = Node(x);
	return &nodes[sz - 1];
}

int getsize(Node* node) {
	return node ? node->sz : 0;
}

void add(Node* node, int add) {
	if (node) {
		node->key += add;
		node->add += add;
	}
}

void push(Node* node) {
	if (node) {
		add(node->left, node->add);
		add(node->right, node->add);
		node->add = 0;
	}
}

void recalc(Node* node) {
	if (node) {
		node->sz = 1 + getsize(node->left) + getsize(node->right);
	}
}

void split(Node* node, int key, Node*& l, Node*& r) {
	if (!node) {
		l = r = nullptr;
		return;
	}
	push(node);
	if (node->key <= key) {
		split(node->right, key, node->right, r);
		l = node;
	} else {
		split(node->left, key, l, node->left);
		r = node;
	}
	recalc(node);
}

Node* merge(Node* a, Node* b) {
	if (!a) {
		return b;
	}
	if (!b) {
		return a;
	}
	if (a->prior < b->prior) {
		push(a);
		a->right = merge(a->right, b);
		recalc(a);
		return a;
	} else {
		push(b);
		b->left = merge(a, b->left);
		recalc(b);
		return b;
	}
}

Node* leftmost(Node* node) {
	while (node && node->left) {
		node = node->left;
	}
	return node;
}

void clear() {
	sz = 0;
}

void show_all(Node* node, int pre = 0) {
	if (!node) {
		return;
	}
	show_all(node->left, pre + node->add);
	cerr << node->key + pre << " ";
	show_all(node->right, pre + node->add);
}

void solve() {
	clear();
	Node* treap = nullptr;
	int n = nxt(), m = nxt();
	for (int i = 0; i < m; ++i) {
		[[maybe_unused]] int x = nxt(), y = nxt();
		Node *l, *r;
		split(treap, y - 1, l, r);
		// show_all(l);
		// cerr << "| ";
		// show_all(r);
		// cerr << "\n";
		if (auto nd = leftmost(r); !nd || nd->key != y) {
			// cerr << "adding " << y << "\n";
			r = merge(new_node(y), r);
		}
		add(r, 1);
		treap = merge(l, r);
		// cerr << x << " " << y << ": ";
		// show_all(treap, 0);
		// cerr << "\n";
	}
	const int tot = getsize(treap);
	cout << stuff.C(2 * n - 1 - tot, n - 1 - tot) << "\n";
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = nxt();
	while (t--) {
		solve();
	}

	return 0;
}