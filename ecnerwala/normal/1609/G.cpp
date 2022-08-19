#include <bits/stdc++.h>

std::mt19937 mt(48);

using val_t = std::pair<int64_t, bool>;

struct range_t {
	int sz = 0;
	int64_t sum = 0;
	int64_t sz_sum = 0;

	range_t() {}
	explicit range_t(val_t v) {
		sz = 1;
		sum = sz_sum = v.first;
	}
	range_t(range_t a, range_t b) {
		sz = a.sz + b.sz;
		sum = a.sum + b.sum;
		sz_sum = a.sz_sum + a.sum * b.sz + b.sz_sum;
		//std::cerr << a << '+' << b << '=' << *this << '\n';
	}
	friend std::ostream& operator << (std::ostream& o, range_t r) {
		return o << "(" << "sz=" << r.sz << ", " << "sum=" << r.sum << ", " << "sz_sum=" << r.sz_sum << ")";
	}
};

struct op_t {
	int64_t lazy = 0;
	op_t apply(op_t o) {
		o.lazy += lazy;
		return o;
	}
	range_t apply(range_t r) {
		r.sum += r.sz * lazy;
		r.sz_sum += int64_t(r.sz) * int64_t(r.sz + 1) / 2 * lazy;
		return r;
	}
	val_t apply(val_t v) {
		v.first += lazy;
		return v;
	}
};

struct treap_node {
	std::array<treap_node*, 2> c{nullptr, nullptr};
	val_t v;
	std::mt19937::result_type pri = mt();
	range_t r;
	op_t lazy;

	void apply_op(op_t o) {
		v = o.apply(v);
		r = o.apply(r);
		lazy = o.apply(lazy);
	}

	void update() {
		r = range_t(v);
		if (c[0]) {
			r = range_t(c[0]->r, r);
		}
		if (c[1]) {
			r = range_t(r, c[1]->r);
		}
	}

	void downdate() {
		if (c[0]) c[0]->apply_op(lazy);
		if (c[1]) c[1]->apply_op(lazy);
		lazy = op_t{};
	}
};

std::pair<treap_node*, treap_node*> split_sz(treap_node* a, int r_sz) {
	if (r_sz == 0) { return {a, nullptr}; }
	assert(a);
	if (r_sz == a->r.sz) { return {nullptr, a}; }
	a->downdate();
	treap_node *x, *y;
	if (a->c[1] && r_sz <= a->c[1]->r.sz) {
		x = a;
		std::tie(x->c[1], y) = split_sz(a->c[1], r_sz);
	} else {
		y = a;
		std::tie(x, y->c[0]) = split_sz(a->c[0], r_sz - (a->c[1] ? a->c[1]->r.sz : 0) - 1);
	}
	a->update();
	return {x, y};
}

std::pair<treap_node*, treap_node*> split_val(treap_node* a, val_t v) {
	if (!a) return {nullptr, nullptr};
	a->downdate();
	treap_node *x, *y;
	if (a->v < v) {
		x = a;
		std::tie(x->c[1], y) = split_val(a->c[1], v);
	} else {
		y = a;
		std::tie(x, y->c[0]) = split_val(a->c[0], v);
	}
	a->update();
	return {x, y};
}

treap_node* merge(treap_node* a, treap_node* b) {
	if (!b) return a;
	if (!a) return b;
	treap_node *r;
	if (a->pri < b->pri) {
		r = a;
		r->downdate();
		r->c[1] = merge(a->c[1], b);
	} else {
		r = b;
		r->downdate();
		r->c[0] = merge(a, b->c[0]);
	}
	r->update();
	return r;
}

range_t melded(treap_node* a, treap_node* b) {
	if (!a && !b) return range_t{};
	if (!a) return b->r;
	if (!b) return a->r;

	if (a->pri > b->pri) std::swap(a, b);

	a->downdate();

	auto [x, y] = split_val(b, a->v);
	range_t lo = melded(x, a->c[0]);
	range_t hi = melded(y, a->c[1]);
	b = merge(x, y);

	range_t m = range_t(a->v);
	//std::cerr << lo << '+' << m << '+' << hi << '\n';
	return range_t(range_t(lo, m), hi);
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M, Q; cin >> N >> M >> Q;
	std::vector<int64_t> A(N);
	for (auto& a : A) cin >> a;
	std::vector<int64_t> B(M);
	for (auto& b : B) cin >> b;

	N--, M--;

	int64_t V0 = A[0] + B[0];

	std::vector<treap_node> nodes(N + M);
	treap_node* a_root = nullptr;
	for (int i = 0; i < N; i++) {
		nodes[i].v = {A[i+1] - A[i], false};
		nodes[i].update();
		a_root = merge(a_root, &nodes[i]);
		//cerr << a_root->r << '\n';
	}

	treap_node* b_root = nullptr;
	for (int j = 0; j < M; j++) {
		nodes[N+j].v = {B[j+1] - B[j], true};
		nodes[N+j].update();
		b_root = merge(b_root, &nodes[N+j]);
		//cerr << b_root->r << '\n';
	}

	for (int q = 0; q < Q; q++) {
		int type, K; int64_t D; cin >> type >> K >> D;
		type--;
		{
			treap_node *&r = (type ? b_root : a_root);
			assert(K <= r->r.sz+1);
			if (K > r->r.sz) {
				K--;
				V0 += D;
			}
			auto [x, y] = split_sz(r, K);
			y->apply_op(op_t{D});
			r = merge(x, y);
		}
		//cerr << a_root->r << ' ' << b_root->r << '\n';
		range_t r = melded(a_root, b_root);
		//cerr << r << '\n';
		cout << V0 * (N+M+1) + r.sz_sum << '\n';
	}

	return 0;
}