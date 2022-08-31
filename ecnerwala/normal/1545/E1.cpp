#include <bits/stdc++.h>

static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();

std::mt19937 mt{FIXED_RANDOM};

struct treap_node {
	std::array<treap_node*, 2> c = {nullptr, nullptr};
	treap_node *prv = nullptr, *nxt = nullptr;
	std::mt19937::result_type pri = mt();
	int k;
	int64_t v;
	~treap_node() { delete c[0]; delete c[1]; }

	int64_t get_min() {
		int64_t res = v;
		if (c[0]) res = std::min(res, c[0]->get_min());
		if (c[1]) res = std::min(res, c[1]->get_min());
		return res;
	}

};
void dump_tree(treap_node* a, int off) {
	if (!a) return;
	dump_tree(a->c[0], off);
	std::cerr << a->k+off << '=' << a->v << ' ';
	dump_tree(a->c[1], off);
}

treap_node* merge_node(treap_node* a, treap_node* b) {
	if (!b) return a;
	if (!a) return b;
	treap_node* r;
	assert(a->k < b->k);
	if (a->pri < b->pri) {
		r = a;
		r->c[1] = merge_node(a->c[1], b);
	} else {
		r = b;
		r->c[0] = merge_node(a, b->c[0]);
	}
	return r;
}

std::pair<treap_node*, treap_node*> split_node(treap_node* r, int k) {
	if (!r) return {nullptr, nullptr};
	treap_node* a;
	treap_node* b;
	if (r->k <= k) {
		a = r;
		std::tie(a->c[1], b) = split_node(r->c[1], k);
	} else {
		b = r;
		std::tie(a, b->c[0]) = split_node(r->c[0], k);
	}
	return {a, b};
}

struct treap {
	treap_node* rt = nullptr;
	treap_node* head = nullptr;
	treap_node* tail = nullptr;

	//~treap() { delete rt; }

	explicit operator bool() const { return bool(rt); }

	bool empty() const { return !rt; }

	treap_node& front() { assert(rt && head); return *head; }
	treap_node& back() { assert(rt && tail); return *tail; }

	void make_head_tail() {
		if (!rt) {
			head = tail = rt;
			return;
		}
		head = rt;
		while (head->c[0]) head = head->c[0];
		head->prv = nullptr;
		tail = rt;
		while (tail->c[1]) tail = tail->c[1];
		tail->nxt = nullptr;
	}

	void pop_front() {
		assert(rt);
		treap_node** cur = &rt;
		while ((*cur)->c[0]) cur = &((*cur)->c[0]);
		assert(*cur);
		assert(*cur == head);
		treap_node* old_head = head;
		*cur = std::exchange((*cur)->c[1], nullptr);
		head = head->nxt;
		if (head) head->prv = nullptr;
		if (!head) tail = nullptr;
		delete old_head;
	}

	void pop_back() {
		assert(rt);
		treap_node** cur = &rt;
		while ((*cur)->c[1]) cur = &((*cur)->c[1]);
		assert(*cur);
		assert(*cur == tail);
		treap_node* old_tail = tail;
		*cur = std::exchange((*cur)->c[0], nullptr);
		tail = tail->prv;
		if (tail) tail->nxt = nullptr;
		if (!tail) head = nullptr;
		delete old_tail;
	}

	void push_front(int k, int64_t v) {
		treap_node* n = new treap_node;
		n->k = k;
		n->v = v;
		n->nxt = head;
		if (head) head->prv = n;
		if (!rt) tail = n;
		head = n;
		rt = merge_node(n, rt);
	}

	void push_back(int k, int64_t v) {
		treap_node* n = new treap_node;
		n->k = k;
		n->v = v;
		n->prv = tail;
		if (tail) tail->nxt = n;
		if (!rt) head = n;
		tail = n;
		rt = merge_node(rt, n);
	}
};

treap merge_treaps(treap a, treap b) {
	if (!a) return b;
	if (!b) return a;
	treap r;
	a.tail->nxt = b.head;
	b.head->prv = a.tail;
	r.head = a.head;
	r.tail = b.tail;
	r.rt = merge_node(a.rt, b.rt);
	return r;
}

std::array<treap, 2> split_treap(treap r, int k) {
	treap a, b;
	std::tie(a.rt, b.rt) = split_node(r.rt, k);
	a.make_head_tail();
	b.make_head_tail();
	assert(!r.empty());
	assert(!a.empty() || !b.empty());
	if (a.empty()) a.push_back(b.front().k, b.front().v);
	else if (b.empty()) b.push_front(a.back().k, a.back().v);
	else {
		int ak = a.back().k; int64_t av = a.back().v;
		int bk = b.front().k; int64_t bv = b.front().v;
		a.push_back(bk, bv);
		b.push_front(ak, av);
	}
	return {a, b};
}

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	int X0; cin >> X0;
	const int INF = 1e7;
	vector<pair<pair<int, bool>, array<int, 2>>> evts; evts.reserve(2*N);
	for (int i = 0; i < N; i++) {
		int t0, t1, l, r; cin >> t0 >> t1 >> l >> r;
		t0--, t1++, l--, r++;
		assert(t0 < t1);
		assert(l < r);
		evts.push_back({{t0, true}, {l, r}});
		evts.push_back({{t1, false}, {l, r}});
	}
	sort(evts.begin(), evts.end());

	using mp_type = std::map<array<int, 2>, treap>;
	mp_type mp;

	std::multiset<int> rights;
	std::multiset<int> lefts;
	rights.insert(INF-1);
	lefts.insert(-INF+1);
	treap ST; ST.push_back(X0, 0);
	mp.insert({{-INF+1, INF-1}, ST});

	int cur_t = 0;
	auto advance = [&](mp_type::iterator it) -> void {
		auto [l, r] = it->first;
		auto& lst = it->second;
		assert(!lst.empty());
		l -= cur_t;
		r -= cur_t;
		while (lst.front().k < l) {
			int64_t v = lst.front().v + (l - lst.front().k);
			lst.pop_front();
			if (lst.empty() || (lst.front().k >= l && v < lst.front().v + (lst.front().k - l))) {
				lst.push_front(l, v);
			}
		}
		while (lst.back().k > r) {
			int64_t v = lst.back().v + (lst.back().k - r);
			lst.pop_back();
			if (lst.empty() || (lst.back().k <= r && v < lst.back().v + (r - lst.back().k))) {
				lst.push_back(r, v);
			}
		}
	};

	auto dump_mp = [&]() {
		cerr << "mp:" << '\n';
		for (auto it : mp) {
			cerr << it.first[0] << '-' << it.first[1] << ": ";
			dump_tree(it.second.rt, cur_t);
			cerr << '\n';
		}
	};
	//dump_mp();
	for (auto evt : evts) {
		auto [t, is_ins] = evt.first;
		auto [l, r] = evt.second;
		cur_t = t;

		//cerr << "process " << "t=" << t << " " << (is_ins ? "INS" : "REM") << " " << l << '-' << r << '\n';
		//cerr << "pre "; dump_mp();
		if (is_ins) {
			rights.insert(l);
			lefts.insert(r);
			// block off l and r
			auto it = mp.lower_bound({l+1, -INF});
			while (it != mp.end() && it->first[1] < r) it = mp.erase(it);
			assert(it != mp.begin());
			if (it != mp.end()) advance(it);
			advance(std::prev(it));
			if (it != mp.end() && it->first[0] < r) {
				assert(it->first[1] >= r);
				mp[{r, it->first[1]}] = std::move(it->second);
				it = mp.erase(it);
				assert(it->first[0] == r);
				advance(it);
			}
			assert(it != mp.begin());
			--it;
			if (it->first[1] > l) {
				if (it->first[1] >= r) {
					auto [a, b] = split_treap(it->second, l - cur_t);
					mp[{it->first[0], l}] = a;
					mp[{r, it->first[1]}] = b;
					it = mp.erase(it);
					//dump_mp();
					assert(it->first[0] == r);
					advance(it);
					--it;
					assert(it->first[1] == l);
					advance(it);
					goto done;
				}
				mp[{it->first[0], l}] = std::move(it->second);
				it = mp.erase(it);
				--it;
				assert(it->first[1] == l);
				advance(it);
			}
		} else {
			lefts.erase(lefts.find(r));
			rights.erase(rights.find(l));
			auto it = mp.lower_bound({r, -INF});
			assert(it != mp.begin());
			if (it != mp.end()) advance(it);
			auto pt = std::prev(it);
			advance(pt);

			if (it != mp.end() && it->first[0] == r) {
				int nr = *std::prev(lefts.upper_bound(r));
				if (nr <= l && pt->first[1] == l) {
					while (!pt->second.empty() && !it->second.empty()) {
						int dx = it->second.front().k - pt->second.back().k;
						assert(dx > 0);
						if (pt->second.back().v >= it->second.front().v + dx) pt->second.pop_back();
						else if (pt->second.back().v + dx <= it->second.front().v) it->second.pop_front();
						else break;
					}
					mp[{pt->first[0], it->first[1]}] = merge_treaps(pt->second, it->second);
					mp.erase(pt);
					mp.erase(it);
					goto done;
				}
				if (nr != r) {
					mp[{nr, it->first[1]}] = std::move(it->second);
					mp.erase(it);
				}
			}
			if (pt->first[1] == l) {
				int nl = *rights.lower_bound(l);
				if (nl != l) {
					mp[{pt->first[0], nl}] = std::move(pt->second);
					mp.erase(pt);
				}
			}
		}
		done:;
		//cerr << "post "; dump_mp();
	}
	assert(mp.size() == 1);

	int64_t ans = mp.begin()->second.rt->get_min();
	cout << ans << '\n';

	return 0;
}