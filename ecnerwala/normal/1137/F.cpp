#include<bits/stdc++.h>
namespace std {

template<class Fun>
class y_combinator_result {
	Fun fun_;
public:
	template<class T>
	explicit y_combinator_result(T &&fun): fun_(std::forward<T>(fun)) {}

	template<class ...Args>
	decltype(auto) operator()(Args &&...args) {
		return fun_(std::ref(*this), std::forward<Args>(args)...);
	}
};

template<class Fun>
decltype(auto) y_combinator(Fun &&fun) {
	return y_combinator_result<std::decay_t<Fun>>(std::forward<Fun>(fun));
}

} // namespace std
using namespace std;

namespace lct {

struct node {
	node* p = nullptr;
	node* c[2] = {nullptr, nullptr};
	// not root
	bool nr() const { return p && (this == p->c[0] || this == p->c[1]); }
	bool d() const { return this == p->c[1]; }

	bool flip = false;

	int sz = 1;
	friend int get_sz(node* n) { return n ? n->sz : 0; }

	int val1 = 0, val2 = 0;

	int range_lazy = 0;

	void update() {
		sz = 1 + get_sz(c[0]) + get_sz(c[1]);
	}

	void do_flip() {
		flip ^= 1;
	}

	void downdate_flip() {
		if (flip) {
			if (c[0]) c[0]->do_flip();
			if (c[1]) c[1]->do_flip();
			swap(c[0], c[1]);
			range_lazy = -range_lazy;
			flip = false;
		}
		assert(!flip);
	}

	void downdate() {
		downdate_flip();
		if (range_lazy) {
			assert(range_lazy == 1 || range_lazy == -1);
			if (c[0]) {
				c[0]->downdate_flip();
				c[0]->val1 = val1;
				c[0]->val2 = val2 - range_lazy * (1 + get_sz(c[0]->c[1]));
				c[0]->range_lazy = range_lazy;
			}
			if (c[1]) {
				c[1]->downdate_flip();
				c[1]->val1 = val1;
				c[1]->val2 = val2 + range_lazy * (1 + get_sz(c[1]->c[0]));
				c[1]->range_lazy = range_lazy;
			}
			range_lazy = 0;
		}
		assert(range_lazy == 0);
	}

	void rot() {
		assert(p);
		assert(!flip);
		assert(!p->flip);
		int x = d();
		node* pa = p;
		node* ch = c[!x];

		this->p = pa->p;
		if (pa->nr()) pa->p->c[pa->d()] = this;

		pa->c[x] = ch;
		if (ch) ch->p = pa;

		c[!x] = pa;
		pa->p = this;

		pa->update();
	}

	void downdate_all() {
		if (nr()) p->downdate_all();
		downdate();
	}

	// calls downdate, but not update
	void splay() {
		downdate_all();
		while (nr()) {
			if (p->nr()) {
				if (d() == p->d()) {
					p->rot();
				} else {
					rot();
				}
			}
			rot();
		}
	}

	node* expose() {
		splay();
		c[1] = nullptr; update();
		node* cur = this;
		assert(!cur->nr());
		while (cur->p) {
			cur->p->splay();
			cur->p->c[1] = cur;
			cur->p->update();
			cur = cur->p;
			assert(!cur->nr());
		}
		splay(); update();
		return cur;
	}

	void set_root() {
		expose(); do_flip(); downdate_flip();
	}
};

void dynalca_main() {
	int N, Q; cin >> N >> Q;
	node* nodes = new node[size_t(N + 1)];
	for (int q = 0; q < Q; q++) {
		string op; cin >> op;
		if (op == "link") {
			int A, B; cin >> A >> B;
			nodes[A].expose();
			assert(nodes[A].p == nullptr);
			assert(nodes[A].c[0] == nullptr);
			nodes[A].p = &nodes[B];
		} else if (op == "cut") {
			int A; cin >> A;
			nodes[A].expose();
			assert(nodes[A].p == nullptr);
			assert(nodes[A].c[0] != nullptr);
			if (nodes[A].c[0]) nodes[A].c[0]->p = nullptr;
			nodes[A].c[0] = nullptr;
			nodes[A].update();
		} else if (op == "lca") {
			int A, B; cin >> A >> B;
			nodes[A].expose();
			node* C = nodes[B].expose();
			cout << int(C - nodes) << '\n';
		} else assert(false);
	}
	delete[] nodes;
}

} // namespace lst

namespace splay {

struct node {
	node* p = nullptr;
	node* c[2] = {nullptr, nullptr};
	bool d() const { return this == p->c[1]; }
	bool nr() const { return bool(p); }

	~node() { delete c[0]; delete c[1]; }

	int sz = 1;
	friend inline int get_sz(node* n) { return n ? n->sz : 0; }

	int val1 = 0, val2min = 0, val2max = 0;

	void update() {
		sz = (val2max - val2min + 1) + get_sz(c[0]) + get_sz(c[1]);
	}

	void rot() {
		assert(p);
		int x = d();
		node* pa = p;
		node* ch = c[!x];

		this->p = pa->p;
		if (pa->nr()) pa->p->c[pa->d()] = this;

		pa->c[x] = ch;
		if (ch) ch->p = pa;

		c[!x] = pa;
		pa->p = this;

		pa->update();
	}

	// calls update
	void splay() {
		while (nr()) {
			if (p->nr()) {
				if (d() == p->d()) {
					p->rot();
				} else {
					rot();
				}
			}
			rot();
		}
		update();
	}
};

} // namespace splay

const int MAXN = 2.1e5;
const int MAXQ = 2.1e5;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N, Q; cin >> N >> Q;
	lct::node* nodes = new lct::node[size_t(N)];

	for (int i = 0; i < N; i++) {
		nodes[i].val1 = -1-i;
		nodes[i].val2 = 0;
	}

	splay::node* splay_root = nullptr;
	auto splay_append = [&](int val1, int val2min, int val2max) {
		//cerr << "append " << val1 << ' ' << val2min << ' ' << val2max << '\n';
		auto n = new splay::node();
		n->val1 = val1;
		n->val2min = val2min;
		n->val2max = val2max;

		n->c[0] = splay_root;
		if (n->c[0]) n->c[0]->p = n;
		n->update();

		splay_root = n;
	};

	auto splay_remove = [&](int val1, int val2min, int val2max) {
		//cerr << "remove " << val1 << ' ' << val2min << ' ' << val2max << '\n';
		if (val2min > val2max) swap(val2min, val2max);
		assert(val2min <= val2max);
		splay::node* cur = splay_root;
		while (true) {
			assert(cur);
			//cerr << cur << ' ' << cur->val1 << ' ' << cur->val1 << ' ' << cur->val2min << ' ' << cur->val2max << '\n';
			if (tie(val1, val2max) < tie(cur->val1, cur->val2min)) {
				cur = cur->c[0];
			} else if (tie(val1, val2min) > tie(cur->val1, cur->val2max)) {
				cur = cur->c[1];
			} else if (tie(cur->val1, cur->val2min) <= tie(val1, val2min) && tie(val1, val2max) <= tie(cur->val1, cur->val2max)) {
				if (cur->val2min == val2min) {
					cur->val2min = val2max + 1;
				} else if (cur->val2max == val2max) {
					cur->val2max = val2min - 1;
				} else {
					// split
					auto n = new splay::node();
					n->val1 = val1;
					n->val2min = val2max + 1;
					n->val2max = cur->val2max;
					cur->val2max = val2min - 1;

					n->c[1] = cur->c[1];
					if (n->c[1]) n->c[1]->p = n;
					cur->c[1] = n;
					n->p = cur;

					n->update();
				}
				cur->update();
				break;
			} else assert(false);
		}
		cur->splay();
		splay_root = cur;
	};

	auto splay_query = [&](int val1, int val2) -> int {
		int res = 0;
		splay::node* cur = splay_root;
		while (true) {
			assert(cur);
			if (tie(val1, val2) < tie(cur->val1, cur->val2min)) {
				cur = cur->c[0];
			} else if (tie(val1, val2) > tie(cur->val1, cur->val2max)) {
				res += get_sz(cur->c[0]);
				res += cur->val2max - cur->val2min + 1;
				cur = cur->c[1];
			} else {
				res += get_sz(cur->c[0]);
				res += val2 - cur->val2min + 1;
				break;
			}
		}
		cur->splay();
		splay_root = cur;
		return res;
	};

	for (int i = -N; i < 0; i++) {
		splay_append(i, 0, 0);
	}

	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		nodes[u].set_root();
		assert(nodes[u].p == nullptr);
		assert(nodes[u].flip == false && nodes[u].c[0] == nullptr);
		nodes[u].p = &nodes[v];
	}

	int ROOT = 0;
	nodes[ROOT].set_root();

	auto up = [&](int v) {
		//cerr << "up " << v << '\n';
		int u = ROOT; // last root
		ROOT = v;

		nodes[v].set_root();
		nodes[u].expose();

		assert(nodes[u].p == nullptr);
		assert(nodes[u].flip == false);
		assert(nodes[u].c[1] == nullptr);

		auto dfs = [&](const auto& rec, lct::node* cur) {
			if (!cur) return;
			cur->downdate_flip();
			if (cur->range_lazy) {
				splay_remove(
						cur->val1,
						cur->val2 - get_sz(cur->c[0]) * cur->range_lazy,
						cur->val2 + get_sz(cur->c[1]) * cur->range_lazy
				);
			} else {
				splay_remove(cur->val1, cur->val2, cur->val2);
				rec(rec, cur->c[0]);
				rec(rec, cur->c[1]);
			}
		};

		dfs(dfs, &nodes[u]);

		nodes[u].val1++;
		//cerr << "new val " << nodes[u].val1 << '\n';
		nodes[u].val2 = 0;
		nodes[u].range_lazy = -1;

		splay_append(nodes[u].val1, 0, nodes[u].sz - 1);
	};

	auto get_val = [&](int v) -> pair<int, int> {
		nodes[v].expose();
		return {nodes[v].val1, nodes[v].val2};
	};
	auto when = [&](int v) -> int {
		auto curVal = get_val(v);
		return splay_query(curVal.first, curVal.second);
		/*
		//cerr << "val " << v << ' ' << curVal.first << ' ' << curVal.second << '\n';
		int res = 0;
		for (int i = 0; i < N; i++) {
			res += (get_val(i) <= curVal);
		}
		return res;
		*/
	};
	auto compare = [&](int u, int v) -> int {
		return get_val(u) < get_val(v) ? u : v;
	};

	for (int i = 0; i < N; i++) {
		up(i);
	}

	for (int q = 0; q < Q; q++) {
		string op; cin >> op;
		if (op == "up") {
			int v; cin >> v; v--;
			up(v);
		} else if (op == "when") {
			int v; cin >> v; v--;
			cout << when(v) << '\n';
		} else if (op == "compare") {
			int u, v; cin >> u >> v; u--, v--;
			cout << compare(u, v) + 1 << '\n';
		} else assert(false);
	}

	delete[] nodes;
	delete splay_root;

	return 0;
}