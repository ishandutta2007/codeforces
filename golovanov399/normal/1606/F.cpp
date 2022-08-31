#include <bits/stdc++.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

struct Query {
	int idx;
	int k;
};

struct Point {
	int x, y;

	Point operator -(const Point& ot) const {
		return {x - ot.x, y - ot.y};
	}

	Point operator +(const Point& ot) const {
		return {x + ot.x, y + ot.y};
	}

	Point& operator +=(const Point& ot) {
		x += ot.x;
		y += ot.y;
		return *this;
	}
};

long long cross(const Point& p, const Point& q) {
	return 1ll * p.x * q.y - 1ll * p.y * q.x;
}

long long operator <=>(const Point& p, const Point& q) {
	return cross(p, q);
}

struct Treap {
	struct Node {
		Node *left, *right;
		Point key;
		Point sum;
		int prior;
		int size;

		Node(const Point& _key): left(nullptr), right(nullptr), key(_key), sum(_key), prior(rand()), size(1) {}
	};

	int get_size(Node* node) const {
		return node ? node->size : 0;
	}

	Point get_sum(Node* node) const {
		return node ? node->sum : Point{0, 0};
	}

	void recalc(Node* node) {
		node->size = 1 + get_size(node->left) + get_size(node->right);
		node->sum = node->key + get_sum(node->left) + get_sum(node->right);
	}

	void split_by_key(Node* v, Node*& l, Node*& r, const Point& key) {
		if (!v) {
			l = r = nullptr;
			return;
		}
		if (v->key <= key) {
			split_by_key(v->right, v->right, r, key);
			l = v;
		} else {
			split_by_key(v->left, l, v->left, key);
			r = v;
		}
		recalc(v);
	}

	// void split_by_size(Node* v, Node*& l, Node*& r, int size) {
	// 	if (!v) {
	// 		l = r = nullptr;
	// 		return;
	// 	}
	// 	if (get_size(v->left) < size) {
	// 		split_by_size(v->right, v->right, r, size - 1 - get_size(v->left));
	// 		l = v;
	// 	} else {
	// 		split_by_size(v->left, l, v->left, size);
	// 		r = v;
	// 	}
	// 	recalc(v);
	// }

	Node* merge(Node* l, Node* r) {
		if (!l) {
			return r;
		}
		if (!r) {
			return l;
		}
		if (l->prior < r->prior) {
			l->right = merge(l->right, r);
			recalc(l);
			return l;
		} else {
			r->left = merge(l, r->left);
			recalc(r);
			return r;
		}
	}

	Node* root;

	Treap(): root(nullptr) {}

	void insert_by_key(const Point& key) {
		insert_by_key(new Node(key));
	}

	void insert_by_key(Node* node) {
		insert_by_key(root, node);
	}

	void insert_by_key(Node*& node, Node* to_ins) {
		if (!node) {
			node = to_ins;
			return;
		}
		if (node->prior < to_ins->prior) {
			if (node->key > to_ins->key) {
				insert_by_key(node->left, to_ins);
			} else {
				insert_by_key(node->right, to_ins);
			}
			recalc(node);
		} else {
			Node *left, *right;
			split_by_key(node, left, right, to_ins->key);
			node = to_ins;
			node->left = left;
			node->right = right;
			recalc(node);
		}
	}

	void erase_by_pos(int pos) {
		erase_by_pos(root, pos);
	}

	void erase_by_pos(Node*& node, int pos) {
		if (!node) {
			return;
		}
		if (get_size(node->left) == pos) {
			auto left = node->left, right = node->right;
			node->left = node->right = nullptr;
			recalc(node);
			node = merge(left, right);
		} else if (get_size(node->left) < pos) {
			erase_by_pos(node->right, pos - get_size(node->left) - 1);
			recalc(node);
		} else {
			erase_by_pos(node->left, pos);
			recalc(node);
		}
	}

	Point leftmost() const {
		assert(root);
		auto node = root;
		while (node->left) {
			node = node->left;
		}
		return node->key;
	}

	void traverse(Node* node, const function<void(const Point&)>& f) {
		if (!node) {
			return;
		}
		traverse(node->left, f);
		f(node->key);
		traverse(node->right, f);
	}

	size_t size() const {
		return get_size(root);
	}

	void swap(Treap& ot) {
		std::swap(root, ot.root);
	}

	Point sum_leq(const Point& p) {
		Node *left, *right;
		split_by_key(root, left, right, p);
		auto res = get_sum(left);
		root = merge(left, right);
		return res;
	}
};

struct Hull {
	Point p;
	Treap vecs;

	void shift(int x) {
		p.x += x;
	}

	void add(int x, int y) {
		Point nw{x, y};
		while (vecs.size()) {
			auto l = vecs.leftmost();
			if (cross(p - nw, l) >= 0) {
				vecs.erase_by_pos(0);
				p += l;
			} else {
				break;
			}
		}
		vecs.insert_by_key(p - nw);
		p = nw;
	}

	size_t size() const {
		return vecs.size();
	}

	void swap(Hull& ot) {
		::swap(p, ot.p);
		vecs.swap(ot.vecs);
	}

	long long get(int k) {
		Point dir{1, k};
		auto s = vecs.sum_leq(dir) + p;
		// cerr << k << ": " << s.x << " " << s.y << "\n";
		return s.y - 1ll * s.x * k;
	}
};

const int N = 202'222;
vector<int> a[N];
vector<Query> qrs[N];
long long ans[N];

Hull hulls[N];

void dfs(int v, int p) {
	hulls[v].p = {0, 0};
	for (int x : a[v]) {
		if (x == p) {
			continue;
		}
		dfs(x, v);
		// merge-huerge
		// 0 -> 1
		// 1 -> f(0)
		// 2 -> f(1), ...
		hulls[x].shift(1);
		hulls[x].add(0, 1);
		if (hulls[x].size() > hulls[v].size()) {
			hulls[v].swap(hulls[x]);
		}
		hulls[v].p += hulls[x].p;
		hulls[x].vecs.traverse(hulls[x].vecs.root, [&](const Point& vec) {
			hulls[v].vecs.insert_by_key(vec);
		});
	}
	// cerr << v + 1 << ": (" << hulls[v].p.x << " " << hulls[v].p.y << "),";
	// hulls[v].vecs.traverse(hulls[v].vecs.root, [](const Point& p) {
	// 	cerr << " (" << p.x << " " << p.y << ")";
	// });
	// cerr << "\n";
	for (const auto& qr : qrs[v]) {
		ans[qr.idx] = hulls[v].get(qr.k);
	}
}

void solve() {
	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}

	int q = nxt();
	for (int i = 0; i < q; ++i) {
		int v = nxt() - 1, k = nxt();
		qrs[v].push_back({i, k});
	}

	dfs(0, 0);
	for (int i = 0; i < q; ++i) {
		cout << ans[i] << "\n";
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}