#include <bits/stdc++.h>
#include <cmath>

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

struct seg {
	seg* c[2] = {nullptr, nullptr};
	int val;
};
const int L = 17;
const int S = 1 << L;

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, ROOT; cin >> N >> ROOT; ROOT--;
	vector<int> A(N); for (auto& a : A) cin >> a;
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	auto build_pt_seg = std::y_combinator([&](auto self, int a, int v, int l = L) -> seg* {
		seg* res = new seg();
		res->val = v;
		if (l == 0) {
			return res;
		}
		l--;
		bool d = (a >> l) & 1;
		res->c[d] = self(a, v, l);
		return res;
	});

	const int INF = 1.1e9;
	auto merge_segs = std::y_combinator([&](auto self, seg* a, seg* b, int l = L) -> seg* {
		if (!a) return b;
		if (!b) return a;
		if (l == 0) {
			return (a->val <= b->val) ? a : b;
		}
		l--;
		seg* res = new seg();
		res->c[0] = self(a->c[0], b->c[0], l);
		res->c[1] = self(a->c[1], b->c[1], l);
		res->val = min((res->c[0] ? res->c[0]->val : INF), (res->c[1] ? res->c[1]->val : INF));
		return res;
	});

	auto get_min = std::y_combinator([&](auto self, seg* a, int hi, int l = L) -> int {
		if (!a) return INF;
		if (hi <= 0) return INF;
		if (hi >= (1 << l)) return a->val;
		assert(l > 0);
		l--;
		return min(self(a->c[0], hi, l), self(a->c[1], hi-(1<<l), l));
	});

	auto dump_seg = std::y_combinator([&](auto self, seg* a, int c = 0, int l = L) -> void {
		if (!a) return;
		if (l == 0) {
			cerr << "(" << c << ':' << a->val << ")" << ' ';
			return;
		}
		l--;
		self(a->c[0], c, l);
		self(a->c[1], c + (1 << l), l);
	});

	vector<seg*> nodes(N);
	vector<int> depth(N);
	depth[ROOT] = 0;
	std::y_combinator([&](auto self, int cur, int prv) -> void {
		nodes[cur] = build_pt_seg(depth[cur], A[cur]);
		for (int nxt : adj[cur]) {
			if (nxt == prv) continue;
			depth[nxt] = depth[cur] + 1;
			self(nxt, cur);
			nodes[cur] = merge_segs(nodes[cur], nodes[nxt]);
		}
		/*
		cerr << "cur " << cur << '\n';
		cerr << depth[cur] << '\n';
		dump_seg(nodes[cur]);
		cerr << '\n';
		*/
	})(ROOT, -1);

	int Q; cin >> Q;
	int last = 0;
	while (Q--) {
		int p, q; cin >> p >> q;
		int x = (p + last) % N + 1;
		int k = (q + last) % N;
		//cerr << x << ' ' << k << '\n';
		x--, k++;
		last = get_min(nodes[x], depth[x] + k);
		cout << last << '\n';
	}

	return 0;
}