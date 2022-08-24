#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()

#ifdef ONLINE_JUDGE
    inline int pidorand() {
        return ((rand() & 32767) << 15) | (rand() & 32767);
    }
    #define rand pidorand
#endif	// ONLINE_JUDGE

#ifdef OLBOEB
	#define return std::cerr << __FUNCTION__ << "\n"; return
#endif  // OLBOEB

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

/*struct SegmentTree {
	int n;
	vector<int> ad;
	vector<int> tree;

	SegmentTree(int nn) {
		n = 1;
		while (n < nn) {
			n *= 2;
		}
		ad.assign(n + n, 0);
		tree.assign(n + n, 1e9);
	}

	void _add(int v, int l1, int r1, int l, int r, int x) {
		if (l >= r1 || l1 >= r) {
			return;
		}
		if (l < l1) {
			l = l1;
		}
		if (r > r1) {
			r = r1;
		}
		if (l == l1 && r == r1) {
			ad[v] += x;
			return;
		}

		int mid = (l1 + r1) / 2;
		ad[v + v] += ad[v];
		ad[v + v + 1] += ad[v];
		ad[v] = 0;
		_add(v + v, l1, mid, l, r, x);
		_add(v + v + 1, mid, r1, l, r, x);
		tree[v] = min(tree[v + v] + ad[v + v], tree[v + v + 1] + ad[v + v + 1]);
	}

	void add(int l, int r, int x) {
		_add(1, 0, n, l, r, x);
	}

	int _get(int v, int l1, int r1, int l, int r) {
		if (l >= r1 || l1 >= r) {
			return 1e9;
		}
		if (l < l1) {
			l = l1;
		}
		if (r > r1) {
			r = r1;
		}
		if (l == l1 && r == r1) {
			return tree[v] + ad[v];
		}

		int mid = (l1 + r1) / 2;
		return ad[v] + min(_get(v + v, l1, mid, l, r), _get(v + v + 1, mid, r1, l, r));
	}

	int get(int l, int r) {
		return _get(1, 0, n, l, r);
	}

	int getLeft(int x) {
		int v = 1;
		int cur = 0;
		while (v < n) {
			x -= ad[v];
			int w = v * 2;
			if (tree[w] + ad[w] <= x) {
				v = w;
			} else {
				v = w + 1;
			}
		}
		return v - n;
	}
};

const int N = 5e5 + 10;
*/

void remax(int& x, int y) {
	x = max(x, y);
}

void remin(int& x, int y) {
	x = min(x, y);
}

template <typename T>
struct Cartesian {
	struct Node {
		T data;
		int prior;
		int size;
		Node *left, *right;
		bool rev;

		int max_ak_plus_k;
		int min_ak_minus_k;

		explicit Node(const T& val) {
			data = val;
			prior = rand();
			left = right = nullptr;
			size = 1;
			max_ak_plus_k = val + 1;
			min_ak_minus_k = val - 1;
			rev = false;
		}

		~Node() {
			if (left) {
				delete left;
			}
			if (right) {
				delete right;
			}
		}
	};

	void relax(Node* node) {
		node->size = 1;

		int lsz = 0;
		node->max_ak_plus_k = -1e9;
		node->min_ak_minus_k = 1e9;

		if (node->left) {
			node->size += node->left->size;
			lsz = node->left->size;
			remax(node->max_ak_plus_k, node->left->max_ak_plus_k);
			remin(node->min_ak_minus_k, node->left->min_ak_minus_k);
		}
		if (node->right) {
			node->size += node->right->size;
			remax(node->max_ak_plus_k, node->right->max_ak_plus_k + lsz + 1);
			remin(node->min_ak_minus_k, node->right->min_ak_minus_k - lsz - 1);
		}

		remax(node->max_ak_plus_k, node->data + lsz + 1);
		remin(node->min_ak_minus_k, node->data - lsz - 1);
	}

	void relax_rev(Node* node) {
		if (node->rev) {
			swap(node->left, node->right);
			if (node->left) {
				node->left->rev ^= 1;
			}
			if (node->right) {
				node->right->rev ^= 1;
			}
			node->rev = 0;
		}
	}

	pair<Node*, Node*> split(Node* node, const T& val) { // (<=, >)
		if (!node) {
			return {nullptr, nullptr};
		}
		// no reverse!
		if (node->data <= val) {
			auto tmp = split(node->right, val);
			node->right = tmp.first;
			relax(node);
			return {node, tmp.second};
		} else {
			auto tmp = split(node->left, val);
			node->left = tmp.second;
			relax(node);
			return {tmp.first, node};
		}
	}

	pair<Node*, Node*> split_by_cnt(Node* node, int cnt) { // (cnt, n - cnt)
		if (!node) {
			assert(cnt == 0);
			return {nullptr, nullptr};
		}
		relax_rev(node);
		int lsz = (node->left ? node->left->size : 0);
		if (cnt > lsz) {
			auto tmp = split_by_cnt(node->right, cnt - lsz - 1);
			node->right = tmp.first;
			relax(node);
			return {node, tmp.second};
		} else {
			auto tmp = split_by_cnt(node->left, cnt);
			node->left = tmp.second;
			relax(node);
			return {tmp.first, node};
		}
	}

	Node* merge(Node* first, Node* second) {
		if (!first) {
			return second;
		} else if (!second) {
			return first;
		} else {
			if (first->prior < second->prior) {
				relax_rev(first);
				first->right = merge(first->right, second);
				relax(first);
				return first;
			} else {
				relax_rev(second);
				second->left = merge(first, second->left);
				relax(second);
				return second;
			}
		}
	}

	template <typename Callback>
	void in_order(Node* node, Callback callback) {
		if (!node) {
			return;
		}
		relax_rev(node);
		in_order(node->left, callback);
		callback(node->data);
		in_order(node->right, callback);
	}

	void show_min_ak_minus_k(Node* node) {
		cerr << "(";
		if (node->left) {
			show_min_ak_minus_k(node->left);
		}
		cerr << " " << node->min_ak_minus_k << " ";
		if (node->right) {
			show_min_ak_minus_k(node->right);
		}
		cerr << ")";
	}

	// Cartesian interface starts here

	Node *root;

	Cartesian() {
		root = nullptr;
	}

	~Cartesian() {
		delete root;
	}

	void append(const T& val) {
		auto new_node = new Node(val);
		root = merge(root, new_node);
	}

	void push_back(const T& val) {
		append(val);
	}

	void add(const T& val, int pos) {
		auto p = split_by_cnt(root, pos);
		root = merge(p.first, merge(new Node(val), p.second));
	}

	void insert(const T& val) {
		auto p = split(root, val);
		root = merge(p.first, merge(new Node(val), p.second));
	}

	void reverse(int l, int r) { // [l, r)
		if (r <= l) {
			return;
		}
		auto p = split_by_cnt(root, r);
		auto q = split_by_cnt(p.first, l);
		q.second->rev ^= 1;
		root = merge(merge(q.first, q.second), p.second);
	}

	vector<T> get_all() {
		vector<T> result;
		in_order(root, [&result](const T& data){
			result.push_back(data);
		});
		return result;
	}

	int get_k() {
		Node *cur = root;
		// max {k: a_k + k <= 0}
		// min {k: a_k + k > 0} - 1
		int res = 0;
		while (cur) {
			int lsz = (cur->left ? cur->left->size : 0);
			if (cur->left && cur->left->max_ak_plus_k + res > 0) {
				cur = cur->left;
			} else if (cur->data + res + lsz + 1 > 0) {
				return res + lsz;
			} else {
				res += lsz + 1;
				cur = cur->right;
			}
		}
		return (root ? root->size : 0);
	}

	int get_ans(int k) {
		auto p = split_by_cnt(root, k);
		// show_min_ak_minus_k(p.second);
		// cerr << "\n";
		// in_order(p.second, [](int x) {cerr << x << " ";});
		// cerr << "\n";
		int res = p.second ? p.second->min_ak_minus_k - k : -2 * k;
		remin(res, -2 * k);
		root = merge(p.first, p.second);
		return root->size + res;
	}
};


int main(){
	int n = nxt();
	vector<int> a(n);
	for (int i = 0; i < n; ++i) {
		a[i] = nxt();
	}

	vector<pair<int, int>> tmp(n);
	for (int i = 0; i < n; ++i) {
		tmp[i] = {a[i], i};
	}

	sort(all(tmp));
	vector<int> p(n);
	for (int i = 0; i < n; ++i) {
		p[tmp[i].second] = i;
	}

	Cartesian<int> tree;
	for (int i = 0; i < n; ++i) {
		tree.insert(a[i]);
		// tree.show_min_ak_minus_k(tree.root);
		// cerr << "\n";
		// tree.in_order(tree.root, [](int x) {cerr << x << " ";});
		// cerr << "\n";
		int k = tree.get_k();
		// cerr << "-- " << k << " --\n";
		// first k are decreases, then non-decrease
		printf("%d\n", tree.get_ans(k));
	}

	return 0;
}