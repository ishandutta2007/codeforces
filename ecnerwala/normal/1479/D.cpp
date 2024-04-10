#include <bits/extc++.h>

struct splitmix64_hash {
	static uint64_t splitmix64(uint64_t x) {
		// http://xorshift.di.unimi.it/splitmix64.c
		x += 0x9e3779b97f4a7c15;
		x = (x ^ (x >> 30)) * 0xbf58476d1ce4e5b9;
		x = (x ^ (x >> 27)) * 0x94d049bb133111eb;
		return x ^ (x >> 31);
	}

	size_t operator()(uint64_t x) const {
		static const uint64_t FIXED_RANDOM = std::chrono::steady_clock::now().time_since_epoch().count();
		return splitmix64(x + FIXED_RANDOM);
	}
};

template <typename K, typename V, typename Hash = splitmix64_hash>
using hash_map = __gnu_pbds::gp_hash_table<K, V, Hash>;

template <typename K, typename Hash = splitmix64_hash>
using hash_set = hash_map<K, __gnu_pbds::null_type, Hash>;

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

namespace ecnerwala {

using std::swap;

struct level_ancestor {
	int N;
	std::vector<int> preorder;
	std::vector<int> idx;
	std::vector<std::pair<int, int>> heavyPar; // heavy parent, distance
	level_ancestor() : N(0) {}

	level_ancestor(const std::vector<int>& par) : N(int(par.size())), preorder(N), idx(N), heavyPar(N) {
		std::vector<std::vector<int>> ch(N);
		for (int i = 0; i < N; i++) {
			if (par[i] != -1) ch[par[i]].push_back(i);
		}
		std::vector<int> sz(N);
		int nxt_idx = 0;
		for (int i = 0; i < N; i++) {
			if (par[i] == -1) {
				std::y_combinator([&](auto self, int cur) -> void {
					sz[cur] = 1;
					for (int nxt : ch[cur]) {
						self(nxt);
						sz[cur] += sz[nxt];
					}
					if (!ch[cur].empty()) {
						auto mit = max_element(ch[cur].begin(), ch[cur].end(), [&](int a, int b) { return sz[a] < sz[b]; });
						swap(*ch[cur].begin(), *mit);
					}
				})(i);
				std::y_combinator([&](auto self, int cur, int isRoot = true) -> void {
					preorder[idx[cur] = nxt_idx++] = cur;
					if (isRoot) {
						heavyPar[idx[cur]] = {par[cur] == -1 ? -1 : idx[par[cur]], 1};
					} else {
						assert(idx[par[cur]] == idx[cur]-1);
						heavyPar[idx[cur]] = heavyPar[idx[cur]-1];
						heavyPar[idx[cur]].second++;
					}
					bool chRoot = false;
					for (int nxt : ch[cur]) {
						self(nxt, chRoot);
						chRoot = true;
					}
				})(i);
			}
		}
	}

	int get_ancestor(int a, int k) const {
		assert(k >= 0);
		a = idx[a];
		while (a != -1 && k) {
			if (k >= heavyPar[a].second) {
				k -= heavyPar[a].second;
				assert(heavyPar[a].first <= a - heavyPar[a].second);
				a = heavyPar[a].first;
			} else {
				a -= k;
				k = 0;
			}
		}
		if (a == -1) return -1;
		else return preorder[a];
	}

	int lca(int a, int b) const {
		a = idx[a], b = idx[b];
		while (true) {
			if (a > b) swap(a, b);
			assert(a <= b);
			if (a > b - heavyPar[b].second) {
				return preorder[a];
			}
			b = heavyPar[b].first;
			if (b == -1) return -1;
		}
	}
};

} // namespace ecnerwala

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, Q; cin >> N >> Q;
	vector<int> A(N); for (auto& a : A) { cin >> a; a--; }
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	int S = 1; while (S < N) S *= 2;

	hash_map<uint64_t, int> mp;
	vector<pair<int, int>> nodes; nodes.reserve(int(1e7));
	nodes.push_back({0,0});
	nodes.push_back({1,1});

	auto get_node = [&](pair<int, int> a) -> int {
		uint64_t key = (uint64_t(a.first) << 32) | uint64_t(a.second);
		auto it = mp.find(key);
		if (it != mp.end()) return it->second;
		int i = int(nodes.size());
		nodes.push_back(a);
		mp.insert({key, i});
		return i;
	};

	int EMPTY_TREE = std::y_combinator([&](auto self, int lo, int hi) -> int {
		if (hi - lo == 1) return 0;
		int md = (lo + hi) / 2;
		return get_node({self(lo, md), self(md, hi)});
	})(0, S);

	auto flip = std::y_combinator([&](auto self, int cur_tree, int x, int lo, int hi) -> int {
		assert(lo <= x && x < hi);
		if (hi - lo == 1) {
			assert(cur_tree == 0 || cur_tree == 1);
			return cur_tree ^ 1;
		}
		int md = (lo + hi) / 2;
		auto cur = nodes[cur_tree];
		if (x < md) {
			cur.first = self(cur.first, x, lo, md);
		} else {
			cur.second = self(cur.second, x, md, hi);
		}
		return get_node(cur);
	});

	auto dump_tree = [&](int root) {
		std::y_combinator([&](auto self, int a) -> void {
			if (a == 0 || a == 1) {
				cerr << a;
				return;
			}
			self(nodes[a].first);
			self(nodes[a].second);
		})(root);
		cerr << '\n';
	};

	vector<int> segs(N);
	vector<int> par(N);
	std::y_combinator([&](auto self, int cur, int prv, int cur_tree) -> void {
		par[cur] = prv;
		cur_tree = flip(cur_tree, A[cur], 0, S);
		segs[cur] = cur_tree;
		//cerr << cur << ' '; dump_tree(segs[cur]);
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			self(nxt, cur, cur_tree);
		}
	})(0, -1, EMPTY_TREE);

	ecnerwala::level_ancestor anc(par);

	auto check_range = std::y_combinator([&](auto self, int t1, int t2, int lo, int hi, int l, int r) -> optional<int> {
		if (r <= lo || hi <= l) {
			return nullopt;
		}
		if (t1 == t2) return nullopt;
		if (hi - lo == 1) {
			return lo;
		}
		int md = (lo + hi) / 2;
		auto c1 = nodes[t1];
		auto c2 = nodes[t2];
		{
			auto x = self(c1.first, c2.first, lo, md, l, r);
			if (x) return x;
		}
		{
			auto x = self(c1.second, c2.second, md, hi, l, r);
			if (x) return x;
		}
		return nullopt;
	});

	for (int q = 0; q < Q; q++) {
		int u, v, l, r; cin >> u >> v >> l >> r; u--, v--, l--;

		int c = anc.lca(u, v);

		std::optional<int> ans;
		if (l <= A[c] && A[c] < r) {
			if (l < A[c]) {
				ans = check_range(segs[u], segs[v], 0, S, l, A[c]);
				if (ans) goto found;
			}
			// check exactly this
			if (std::y_combinator([&](auto self, int t1, int t2, int lo, int hi, int x) -> bool {
				if (hi - lo == 1) return t1 == t2;
				int md = (lo + hi) / 2;
				auto c1 = nodes[t1];
				auto c2 = nodes[t2];
				if (x < md) {
					return self(c1.first, c2.first, lo, md, x);
				} else {
					return self(c1.second, c2.second, md, hi, x);
				}
			})(segs[u], segs[v], 0, S, A[c])) {
				ans = A[c];
				goto found;
			}
			if (A[c]+1 < r) {
				ans = check_range(segs[u], segs[v], 0, S, A[c]+1, r);
			}
		} else {
			ans = check_range(segs[u], segs[v], 0, S, l, r);
		}

found:
		if (ans) cout << *ans+1 << '\n';
		else cout << -1 << '\n';
	}

	return 0;
}