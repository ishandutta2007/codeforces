#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	scanf("%d", &x);
	return x;
}

struct Node {
	pair<int, int> val;
	int add;

	Node(): val(-1e9, 0), add(0) {}
	explicit Node(const pair<int, int>& p): val(p), add(0) {}
	void push(Node& ot) {
		ot.add += add;
		ot.val.first += add;
	}
	void clear_after_push() {
		add = 0;
	}
	void update(int x) {
		add += x;
		val.first += x;
	}
};

Node merge(const Node& a, const Node& b) {
	return Node(max(a.val, b.val));
}

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
		a[pos].update(forward<Args>(args)...);
		while (pos > 1) {
			pos /= 2;
			a[pos] = merge(a[pos * 2], a[pos * 2 + 1]);
		}
	}

	template <typename... Args>
	void update(int l, int r, Args&&... args) {
		_update(1, 0, n, l, r, forward<Args>(args)...);
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
			a[v].update(forward<Args>(args)...);
			return;
		}
		push(v);
		int m = (l1 + r1) / 2;
		_update(v + v, l1, m, l, r, forward<Args>(args)...);
		_update(v + v + 1, m, r1, l, r, forward<Args>(args)...);
		a[v] = merge(a[v + v], a[v + v + 1]);
	}
};

const int N = 202'202;

vector<int> a[N];
int par[N];
int tin[N], tout[N];
int order[N];
int timer = 0;
int h[N];

void dfs(int v, int p) {
	par[v] = p;
	order[timer] = v;
	tin[v] = timer++;
	for (int x : a[v]) {
		if (x != p) {
			h[x] = h[v] + 1;
			dfs(x, v);
		}
	}
	tout[v] = timer;
}

void solve() {
	int n = nxt(), k = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	h[0] = 1;
	dfs(0, 0);
	vector<pair<int, int>> initial(n);
	for (int i = 0; i < n; ++i) {
		initial[i] = {0, i};
	}
	SegTree<Node> tree(initial);
	for (int i = 0; i < n; ++i) {
		tree.update(tin[i], tout[i], 1);
	}
	vector<int> w(n + 1);
	vector<char> used(n);
	for (int i = 0; i < n; ++i) {
		auto [cur, v] = tree.get(0, n).val;
		w[i + 1] = w[i] + cur - 1;
		v = order[v];
		while (!used[v]) {
			used[v] = 1;
			tree.update(tin[v], tout[v], -1);
			v = par[v];
		}
	}
	// for (int x : w) {
	// 	cerr << x << " ";
	// }
	// cerr << "\n";
	long long ans = -1e18;
	for (int i = 0; i <= k; ++i) {
		int b = min(n - i - w[i], n / 2);
		ans = max(ans, 1ll * (n - i - b) * (i - b));
	}
	cout << ans << "\n";
}

int main() {
	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}