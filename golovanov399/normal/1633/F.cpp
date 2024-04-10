#include <bits/stdc++.h>
// #include <sys/resource.h>

#define all(x) (x).begin(), (x).end()
#define itn int
#define make_unique(x) sort((x).begin(), (x).end()); (x).erase(unique((x).begin(), (x).end()), (x).end())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

struct Node {
	array<int, 2> cnt;
	array<long long, 2> sum;
	int add;

	Node(): cnt({0, 0}), sum({0, 0}), add(0) {}
	explicit Node(int): cnt({0, 0}), sum({0, 0}), add(0) {}
	void push(Node& ot) {
		if (add) {
			swap(ot.cnt[0], ot.cnt[1]);
			swap(ot.sum[0], ot.sum[1]);
			ot.add ^= add;
		}
	}
	void clear_after_push() {
		add = 0;
	}
	void update(int type, int arg, int idx) {
		if (type == 1) {
			if (arg) {
				swap(cnt[0], cnt[1]);
				swap(sum[0], sum[1]);
			}
			add ^= arg;
		} else {
			cnt[arg] += 1;
			sum[arg] += idx;
		}
	}
};

Node merge(const Node& a, const Node& b) {
	Node res;
	res.cnt[0] = a.cnt[0] + b.cnt[0];
	res.cnt[1] = a.cnt[1] + b.cnt[1];
	res.sum[0] = a.sum[0] + b.sum[0];
	res.sum[1] = a.sum[1] + b.sum[1];
	return res;
}


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

	vector<int> edges() {
		push_all(1);
		vector<int> res;
		for (int i = 0; i < n; ++i) {
			if (a[n + i].cnt[1]) {
				res.push_back(a[n + i].sum[1]);
			}
		}
		sort(all(res));
		return res;
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
	void push_all(int v) {
		push(v);
		if (v < n) {
			push_all(v * 2);
			push_all(v * 2 + 1);
		}
	}

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

const int N = 202'222;
vector<int> a[N];
int sz[N];
int huipar[N];
int par[N];

SegTree<Node> tree(N);

void dfs(int v, int p = -1) {
	huipar[v] = p;
	sz[v] = 1;
	if (p > -1) {
		a[v].erase(find(all(a[v]), p));
	}
	for (int x : a[v]) {
		dfs(x, v);
		sz[v] += sz[x];
	}
	sort(all(a[v]), [&](int i, int j) {
		return sz[i] > sz[j];
	});
}

vector<int> order;
int pr[N];
int tout[N];
void build_order(int v) {
	int idx = order.size();
	int s = pr[order.size()];
	order.push_back(v);
	bool first = true;
	for (int x : a[v]) {
		pr[order.size()] = first ? s : order.size();
		first = false;
		build_order(x);
	}
	tout[idx] = order.size();
}

int pos[N];
int pid[N];

long long sum_odd_ids = 0;

void flip_seg(int l, int r) {
	tree.update(l, r + 1, 1, 1, -1);
}

void activate(int v) {
	{
		auto nd = tree.get(v, tout[v]);
		tree.update_point(v, 2, (nd.cnt[0] + nd.cnt[1]) % 2, pid[v]);
	}
	while (v > -1) {
		flip_seg(pr[v], v);
		v = par[pr[v]];
	}
}

int main() {
	// struct rlimit rl;
	// const rlim_t kStackSize = 512L * 1024L * 1024L;
	// assert(!getrlimit(RLIMIT_STACK, &rl));
	// rl.rlim_cur = kStackSize;
	// assert(!setrlimit(RLIMIT_STACK, &rl));

	int n = nxt();
	vector<pair<int, int>> edges;
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		edges.push_back({u, v});
		a[u].push_back(v);
		a[v].push_back(u);
	}
	dfs(0);
	build_order(0);
	for (int i = 0; i < n; ++i) {
		pos[order[i]] = i;
	}
	for (auto& [u, v] : edges) {
		if (sz[u] < sz[v]) {
			swap(u, v);
		}
		u = pos[u];
		v = pos[v];
	}
	for (int i = 0; i < n - 1; ++i) {
		pid[edges[i].second] = i + 1;
	}
	par[0] = -1;
	for (int i = 1; i < n; ++i) {
		par[pos[i]] = pos[huipar[i]];
	}

	int added = 1;
	auto show_indices = [&]() {
		auto nd = tree.get(0, n);
		if (nd.cnt[0] != nd.cnt[1]) {
			cout << "0" << endl;
			return;
		}
		cout << nd.cnt[0];
		auto res = tree.edges();
		for (int x : res) {
			cout << " " << x;
		}
		cout << endl;
	};

	int type;
	activate(0);
	while (cin >> type) {
		if (type == 3) {
			break;
		}
		if (type == 1) {
			++added;
			int v = pos[nxt() - 1];
			activate(v);
			auto nd = tree.get(0, n);
			cout << (nd.cnt[0] == nd.cnt[1] ? nd.sum[1] : 0) << endl;
		} else {
			show_indices();
		}
	}

	return 0;
}