#include <bits/stdc++.h>

#include <vector>
#include <utility>

using std::vector;

/*
	Node struct must have:
	- Node::Node()
	- Node::Node(const T&)
	- void Node::push(Node&)
	- void Node::clear_after_push()	
	- void Node::update(Args...)
	- Node merge(const Node&, const Node&)
*/
template <typename Node>
class SegTree {
public:
	explicit SegTree(int _n) {
		n = 1;
		while (n < _n) {
			n *= 2;
		}
		a.resize(n + n);
		for (int i = n - 1; i > 0; --i) {
			a[i] = merge(a[i + i], a[i + i + 1]);
		}
	}

	template <typename T>
	explicit SegTree(const vector<T>& ar) {
		n = 1;
		while (n < (int)ar.size()) {
			n *= 2;
		}
		a.resize(n + n);
		for (int i = 0; i < (int)ar.size(); ++i) {
			a[n + i] = Node(ar[i]);
		}
		for (int i = n - 1; i > 0; --i) {
			a[i] = merge(a[i + i], a[i + i + 1]);
		}
	}

	Node get(int l, int r) {
		return get(1, 0, n, l, r);
	}

	template <typename... Args>
	void update_point(int pos, Args&&... args) {
		{
			int v = 1, l = 0, r = n;
			while (v < n) {
				push(v);
				int m = (l + r) / 2;
				if (pos < m) {
					v *= 2;
					r = m;
				} else {
					v = v * 2 + 1;
					l = m;
				}
			}
		}
		pos += n;
		a[pos].update(std::forward<Args>(args)...);
		while (pos > 1) {
			pos /= 2;
			a[pos] = merge(a[pos * 2], a[pos * 2 + 1]);
		}
	}

	template <typename... Args>
	void update(int l, int r, Args&&... args) {
		_update(1, 0, n, l, r, std::forward<Args>(args)...);
	}

protected:
	int n;
	vector<Node> a;

	void push(int v) {
		if (v + v < n + n) {
			for (int t : {0, 1}) {
				a[v].push(a[v + v + t]);
			}
			a[v].clear_after_push();
		}
	}

private:
	Node get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return Node{};
		}
		if (l <= l1 && r >= r1) {
			return a[v];
		}
		push(v);
		int m = (l1 + r1) / 2;
		return merge(get(v + v, l1, m, l, r), get(v + v + 1, m, r1, l, r));
	}

	template <typename... Args>
	void _update(int v, int l1, int r1, int l, int r, Args&&... args) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l <= l1 && r >= r1) {
			a[v].update(std::forward<Args>(args)...);
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		_update(v + v, l1, m, l, r, std::forward<Args>(args)...);
		_update(v + v + 1, m, r1, l, r, std::forward<Args>(args)...);
		a[v] = merge(a[v + v], a[v + v + 1]);
	}
};

using std::vector;

template <typename V = int>
struct Fenwick {
	int n;
	vector<V> a;

	Fenwick(int _n): n(_n), a(_n) {}

	void add(int pos, const V& x) {
		while (pos < n) {
			a[pos] += x;
			pos |= pos + 1;
		}
	}

	V get(int pos) const {
		V res = V{};
		while (pos >= 0) {
			res += a[pos];
			pos = (pos & (pos + 1)) - 1;
		}
		return res;
	}

	V get(int l, int r) const {
		return get(r - 1) - get(l - 1);
	}

	int get_min_atleast(V x) const {
		int res = 0;
		for (int i = 1 << (31 - __builtin_clz(n)); i; i >>= 1) {
			if (res + i > n) {
				continue;
			}
			if (a[res + i - 1] < x) {
				res += i;
				x -= a[res - 1];
			}
		}
		return res;
	}

	int get_max_atmost(V x) const {
		int res = 0;
		for (int i = 1 << (31 - __builtin_clz(n)); i; i >>= 1) {
			if (res + i > n) {
				continue;
			}
			if (a[res + i - 1] <= x) {
				res += i;
				x -= a[res - 1];
			}
		}
		return res - 1;
	}
};

#define all(x) (x).begin(), (x).end()
// #define make_unique(x) sort(all(x)); x.resize(unique(all(x)) - x.begin())

using namespace std;

inline int nxt() {
	int x;
	// scanf("%d", &x);
	cin >> x;
	return x;
}

struct Vec {
	long long a[3];

	Vec() {
		memset(a, 0, sizeof(a));
	}

	Vec operator +(const Vec& ot) const {
		Vec res;
		for (int i = 0; i < 3; ++i) {
			res.a[i] = a[i] + ot.a[i];
		}
		return res;
	}
};

struct Mat {
	long long a[3][3];

	Mat() {
		for (int i = 0; i < 3; ++i) {
			memset(a[i], 0, sizeof(a[i]));
		}
	}

	Mat operator *(const Mat& ot) const {
		Mat res;
		for (int i = 0; i < 3; ++i) {
			for (int k = 0; k < 3; ++k) {
				for (int j = 0; j < 3; ++j) {
					res.a[i][k] += a[i][j] * ot.a[j][k];
				}
			}
		}
		return res;
	}

	Mat& operator *=(const Mat& ot) {
		return *this = *this * ot;
	}
};

Vec operator *(const Mat& m, const Vec& v) {
	Vec res;
	for (int i = 0; i < 3; ++i) {
		for (int j = 0; j < 3; ++j) {
			res.a[i] += m.a[i][j] * v.a[j];
		}
	}
	return res;
}

const Mat id = []() { Mat m; for (int i = 0; i < 3; ++i) m.a[i][i] = 1; return m; }();
const Mat add_one = []() { Mat m; for (int i = 0; i < 3; ++i) { m.a[i][i] = 1; if (i) m.a[i][i - 1] = 1; } return m; }();
const Mat sub_one = []() { Mat m; for (int i = 0; i < 3; ++i) { m.a[i][i] = 1; if (i) m.a[i][i - 1] = -1; } m.a[2][0] = 1; return m; }();

struct Node {
	Vec v;
	Mat m;

	Node(): v(), m(id) {}
	Node(const Vec& _v, const Mat& _m): v(_v), m(_m) {}
	void push(Node& ot) const {
		ot.m = m * ot.m;
		ot.v = m * ot.v;
	}
	void clear_after_push() {
		m = id;
	}
	void update(const Mat& mat) {
		v = mat * v;
		m = mat * m;
	}
	void update(const Vec& vec) {
		v = vec;
		m = id;
	}
};

Node merge(const Node& a, const Node& b) {
	return {a.v + b.v, id};
}

void solve() {
	const int N = 1 << 18;
	SegTree<Node> tree(N);
	Fenwick<int> f(N);
	vector<char> on(N);
	int q = nxt(), d = nxt();
	while (q--) {
		int x = nxt();
		if (on[x]) {
			tree.update(x - d, x, sub_one);
			tree.update_point(x, Vec());
		} else {
			tree.update(x - d, x, add_one);
			int cnt = f.get(min(N - 1, x + d)) - f.get(x);
			// cerr << x << ": " << cnt << "\n";
			Vec v;
			v.a[0] = 1;
			v.a[1] = cnt;
			v.a[2] = 1ll * cnt * (cnt - 1) / 2;
			tree.update_point(x, v);
		}
		f.add(x, on[x] ? -1 : 1);
		on[x] ^= 1;
		cout << tree.get(0, N).v.a[2] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	for (int i = 1; i <= t; ++i) {
		// cout << "Case #" << i << ": ";
		solve();
	}

	return 0;
}