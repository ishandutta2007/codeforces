#include <bits/stdc++.h>

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

template <typename T> void setmin(T& a, T b) { if (b < a) a = b; }
template <typename T> void setoptmin(std::optional<T>& a, std::optional<T> b) { if (b && (!a || *b < *a)) a = b; }
template <typename T> void setoptmin(std::optional<T>& a, T b) { if (!a || b < *a) a = b; }

std::mt19937 mt(48);

struct treap_node {
	std::array<treap_node*, 2> c{nullptr, nullptr};
	std::mt19937::result_type pri = mt();
	int d;
	int tiebreak;
	int cnt;
	int lazy;
	std::optional<int> left_d, right_d, mid;

	std::pair<int, int> key() const {
		return {d, tiebreak};
	}

	void apply_lazy(int l) {
		assert(l >= 0);
		lazy += l;

		if (cnt < 0) d -= l;
		else if (cnt > 0) d += l;
		else assert(false);

		if (left_d) *left_d -= l;
		if (right_d) *right_d += l;
		if (mid) *mid -= 2 * l;
	}

	void downdate() {
		if (lazy) {
			if (c[0]) c[0]->apply_lazy(lazy);
			if (c[1]) c[1]->apply_lazy(lazy);
			lazy = 0;
		}
	}

	void update() {
		assert(!lazy);

		if (cnt > 0) {
			left_d = std::nullopt;
			right_d = d;
			mid = std::nullopt;
		} else {
			left_d = d;
			right_d = std::nullopt;
			mid = std::nullopt;
		}

		if (c[0]) {
			setoptmin(mid, c[0]->mid);
			if (c[0]->right_d && left_d) setoptmin(mid, *left_d - *c[0]->right_d);
			left_d = c[0]->left_d;
		}
		if (c[1]) {
			setoptmin(mid, c[1]->mid);
			if (right_d && c[1]->left_d) setoptmin(mid, *c[1]->left_d - *right_d);
			right_d = c[1]->right_d;
		}
	}
};

treap_node* merge(treap_node* a, treap_node* b) {
	if (!b) return a;
	if (!a) return b;
	treap_node* r;
	if (a->pri < b->pri) {
		a->downdate();
		r = a;
		r->c[1] = merge(a->c[1], b);
	} else {
		b->downdate();
		r = b;
		r->c[0] = merge(a, b->c[0]);
	}
	r->update();
	return r;
}

void resolve_conflicts(treap_node*& r, bool all) {
	if (!(r && r->mid && (all || *r->mid < 0))) return;
	r->downdate();
	resolve_conflicts(r->c[0], all);
	resolve_conflicts(r->c[1], all);
	r->update();
	std::vector<treap_node*> a, b;
	if (r->cnt < 0) {
		if (r->c[0]) {
			a.push_back(r->c[0]);
			a.back()->downdate();
			r->c[0] = nullptr;
			r->update();
		}
		b.push_back(r);
		r = nullptr;
	} else {
		if (r->c[1]) {
			b.push_back(r->c[1]);
			b.back()->downdate();
			r->c[1] = nullptr;
			r->update();
		}
		a.push_back(r);
		r = nullptr;
	}

	while (!a.empty() && !b.empty() && a.back()->right_d && b.back()->left_d && (all || *b.back()->left_d - *a.back()->right_d < 0)) {
		while (a.back()->c[1]) {
			auto v = std::exchange(a.back()->c[1], nullptr);
			a.back()->update();
			a.push_back(v);
			a.back()->downdate();
		}
		while (b.back()->c[0]) {
			auto v = std::exchange(b.back()->c[0], nullptr);
			b.back()->update();
			b.push_back(v);
			b.back()->downdate();
		}
		assert(a.back()->cnt > 0);
		assert(b.back()->cnt < 0);
		assert(all || a.back()->d > b.back()->d);

		int v = std::min(a.back()->cnt, -b.back()->cnt);
		a.back()->cnt -= v;
		if (a.back()->cnt == 0) {
			a.back() = a.back()->c[0];
			if (!a.back()) a.pop_back();
			else a.back()->downdate();
		}
		b.back()->cnt += v;
		if (b.back()->cnt == 0) {
			b.back() = b.back()->c[1];
			if (!b.back()) b.pop_back();
			else b.back()->downdate();
		}
	}
	r = nullptr;
	while (!a.empty() || !b.empty()) {
		if (!a.empty() && (b.empty() || a.back()->pri > b.back()->pri)) {
			a.back()->c[1] = merge(a.back()->c[1], r);
			r = a.back();
			a.pop_back();
		} else {
			b.back()->c[0] = merge(r, b.back()->c[0]);
			r = b.back();
			b.pop_back();
		}
		r->update();
	}
}

std::pair<treap_node*, treap_node*> split(treap_node* r, std::pair<int, int> v) {
	if (!r) return {nullptr, nullptr};
	r->downdate();
	treap_node *a, *b;
	if (r->key() < v) {
		a = r;
		std::tie(a->c[1], b) = split(r->c[1], v);
	} else {
		b = r;
		std::tie(a, b->c[0]) = split(r->c[0], v);
	}
	r->update();
	return {a, b};
}

treap_node* meld(treap_node* a, treap_node* b) {
	if (!b) return a;
	if (!a) return b;
	if (a->pri > b->pri) {
		std::swap(a, b);
	}
	a->downdate();
	auto [x, y] = split(b, a->key());
	a->c[0] = meld(a->c[0], x);
	a->c[1] = meld(a->c[1], y);
	a->update();
	return a;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<vector<pair<int, int>>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v, l; cin >> u >> v >> l; u--, v--;
		adj[u].push_back({v, l});
		adj[v].push_back({u, l});
	}

	int K; cin >> K;
	vector<vector<pair<int, int>>> observations(N);
	for (int k = 0; k < K; k++) {
		int d, f, p; cin >> d >> f >> p; p--;
		observations[p].push_back({d, f});
	}

	vector<treap_node> nodes(2*K);
	int cur_node = 0;
	int cur_tiebreak = K+1;

	auto dfs = std::y_combinator([&](auto self, int cur, int prv) -> treap_node* {
		treap_node* res = nullptr;
		for (auto [nxt, l] : adj[cur]) {
			if (nxt == prv) continue;
			treap_node* ch = self(nxt, cur);
			if (ch) ch->apply_lazy(l);
			resolve_conflicts(ch, false);
			res = meld(res, ch);
		}
		for (auto [d, f] : observations[cur]) {
			treap_node* a = &nodes[cur_node++];
			treap_node* b = &nodes[cur_node++];
			a->d = b->d = d;
			a->cnt = -f;
			b->cnt = +f;
			assert(cur_tiebreak > 0);
			a->tiebreak = cur_tiebreak;
			b->tiebreak = -cur_tiebreak;
			cur_tiebreak--;

			a->update();
			b->update();
			res = meld(res, merge(a, b));
		}
		return res;
	});

	auto root_res = dfs(0, -1);
	resolve_conflicts(root_res, true);

	int ans_neg = 0;
	int ans_pos = 0;
	std::y_combinator([&](auto self, treap_node* r) -> void {
		if (!r) return;
		self(r->c[0]);
		if (r->cnt < 0) ans_neg += -r->cnt;
		else ans_pos += r->cnt;
		self(r->c[1]);
	})(root_res);

	assert(ans_neg == ans_pos);
	cout << ans_neg << '\n';

	return 0;
}