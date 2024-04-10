#include <bits/stdc++.h>

std::mt19937 mt(48);

struct treap_node {
	std::array<treap_node*, 2> c{nullptr, nullptr};
	int64_t val;
	std::mt19937::result_type pri;
	int cnt;
	int64_t sum;
	uint64_t sum_mult;

	void update() {
		cnt = 1;
		if (c[0]) cnt += c[0]->cnt;
		if (c[1]) cnt += c[1]->cnt;
		sum = val;
		if (c[0]) sum += c[0]->sum;
		if (c[1]) sum += c[1]->sum;
		sum_mult = (c[0] ? c[0]->sum_mult : 0) + uint64_t(c[0] ? c[0]->cnt : 0) * uint64_t(val);
		if (c[1]) {
			sum_mult += (uint64_t(c[0] ? c[0]->cnt : 0) + 1) * uint64_t(c[1]->sum) + c[1]->sum_mult;
		}
	}
};

std::pair<treap_node*, treap_node*> split_val(treap_node* a, int64_t val) {
	if (!a) return {nullptr, nullptr};
	treap_node *l, *r;
	if (a->val < val) {
		l = a;
		std::tie(l->c[1], r) = split_val(a->c[1], val);
	} else {
		r = a;
		std::tie(l, r->c[0]) = split_val(a->c[0], val);
	}
	a->update();
	return {l, r};
}

std::pair<treap_node*, treap_node*> split_cnt(treap_node* a, int c) {
	if (!a) return {nullptr, nullptr};
	assert(0 <= c && c <= a->cnt);

	// faster break
	if (c == 0) return {nullptr, a};
	if (c == a->cnt) return {a, nullptr};

	treap_node *l, *r;
	int lcnt = (a->c[0] ? a->c[0]->cnt : 0);
	if (lcnt + 1 <= c) {
		l = a;
		std::tie(l->c[1], r) = split_cnt(a->c[1], c - lcnt - 1);
	} else {
		r = a;
		std::tie(l, r->c[0]) = split_cnt(a->c[0], c);
	}
	a->update();
	return {l, r};
}

int64_t split_cnt_sum(treap_node* a, int c) {
	if (!a) return 0;
	assert(0 <= c && c <= a->cnt);

	// faster break
	if (c == 0) return 0;
	if (c == a->cnt) return a->sum;

	int lcnt = (a->c[0] ? a->c[0]->cnt : 0);
	if (lcnt + 1 <= c) {
		return (a->c[0] ? a->c[0]->sum : 0) + a->val + split_cnt_sum(a->c[1], c - lcnt - 1);
	} else {
		return split_cnt_sum(a->c[0], c);
	}
}

treap_node* merge(treap_node* a, treap_node* b) {
	if (!b) return a;
	if (!a) return b;
	treap_node* r;
	if (a->pri < b->pri) {
		r = a;
		r->c[1] = merge(a->c[1], b);
	} else {
		r = b;
		r->c[0] = merge(a, b->c[0]);
	}
	r->update();
	return r;
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;

	treap_node* root = nullptr;
	auto query = [&]() -> int64_t {
		if (!root) return 0;
		int tot_cnt = root->cnt;
		assert(tot_cnt >= 1);

		int mi = 0; // biggest 0 < smallest 0+1
		int ma = (tot_cnt + 1) / 2; // we want k < (tot_cnt+1)/2
		while (ma - mi > 1) {
			int md = (mi + ma) / 2;

			assert(md > 0);

			int64_t small_sum = split_cnt_sum(root, md+1);
			int64_t big_sum = root->sum - split_cnt_sum(root, tot_cnt - md);

			if (big_sum < small_sum) {
				mi = md;
			} else {
				ma = md;
			}
		}

		int64_t ans = root->sum;
		if (2 * mi + 1 == tot_cnt) {
			// we special case the middle one because it's counted only once
			treap_node *l, *r;
			tie(l, r) = split_cnt(root, mi+1);
			int64_t small_sum = l->sum;
			root = merge(l, r);

			tie(l, r) = split_cnt(root, tot_cnt - mi);
			int64_t big_sum = r ? r->sum : 0;
			root = merge(l, r);

			assert(big_sum < small_sum);
			ans -= small_sum - big_sum;
			mi--;
		}

		// k = [0,mi]
		// (mi+1) * a[0] + mi * a[1] + ... + 1 * a[mi]
		// - (mi * a[tot_cnt-1] + ... + 1 * a[tot_cnt-mi])
		if (mi >= 0) {
			treap_node *l, *r;
			tie(l, r) = split_cnt(root, mi+1);
			assert(l->cnt == mi+1);
			uint64_t small_val = uint64_t(l->sum) * uint64_t(mi+1) - l->sum_mult;
			root = merge(l, r);

			tie(l, r) = split_cnt(root, tot_cnt - mi);
			assert((r ? r->cnt : 0) == mi);
			uint64_t big_val = r ? uint64_t(r->sum) + r->sum_mult : 0;
			root = merge(l, r);

			ans -= 2 * int64_t(small_val - big_val);
		}
		return ans;
	};

	vector<treap_node> node_pool(N+Q);
	int node_pool_idx = 0;
	auto insert_val = [&](int64_t v) -> void {
		assert(node_pool_idx < int(node_pool.size()));
		treap_node* n = &node_pool[node_pool_idx++];
		n->pri = mt();
		n->val = v;
		n->update();
		treap_node *l, *r;
		tie(l, r) = split_val(root, v);
		l = merge(l, n);
		root = merge(l, r);
	};
	auto remove_val = [&](int64_t v) -> void {
		treap_node *l, *m, *r;
		tie(l, r) = split_val(root, v);
		tie(m, r) = split_val(r, v+1);
		assert(m);
		root = merge(l, r);
	};

	for (int i = 0; i < N; i++) {
		int64_t s; cin >> s;
		insert_val(s);
	}
	cout << query() << '\n';
	for (int q = 0; q < Q; q++) {
		int op; int64_t v; cin >> op >> v;
		if (op == 1) {
			insert_val(v);
		} else if (op == 2) {
			remove_val(v);
		} else assert(false);
		cout << query() << '\n';
	}

	return 0;
}

// suitable iff for some k (exactly 1), sum of biggest k <= x < sum of smallest k+1
//  or sum of all <= x or x < 0
// These ranges are concave with k: the gaps get smaller then bigger
//
// Answer is sum of smallest