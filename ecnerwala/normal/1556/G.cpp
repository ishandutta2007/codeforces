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

struct union_find {
	std::vector<int> par;
	union_find() {}
	union_find(int N) : par(N, -1) {}
	int get_par(int a) {
		while (par[a] >= 0) {
			if (par[par[a]] >= 0) par[a] = par[par[a]];
			a = par[a];
		}
		return a;
	}
	bool merge(int a, int b) {
		a = get_par(a), b = get_par(b);
		if (a == b) return false;
		if (par[a] > par[b]) std::swap(a, b);
		par[a] += par[b];
		par[b] = a;
		return true;
	}
	bool merge(std::array<int, 2> a) { return merge(a[0], a[1]); }
};

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int B, Q; cin >> B >> Q;
	std::vector<std::tuple<bool, int64_t, int64_t>> ops(Q);
	for (auto& op : ops) {
		string s; int64_t a, b; cin >> s >> a >> b;
		if (s == "ask") {
			op = {true, a, b};
		} else if (s == "block") {
			op = {false, a, b+1};
		} else assert(false);
	}
	std::reverse(ops.begin(), ops.end());

	auto p2 = [](int i) -> int64_t { return int64_t(1) << i; };

	std::vector<int64_t> boundaries; boundaries.reserve(4*Q+10);
	boundaries.push_back(0);
	boundaries.push_back(p2(B));
	for (auto [op, a, b] : ops) {
		if (op == false) {
			boundaries.push_back(a);
			boundaries.push_back(b);
		}
	}

	std::sort(boundaries.begin(), boundaries.end());
	boundaries.resize(std::unique(boundaries.begin(), boundaries.end()) - boundaries.begin());

	boundaries.resize(boundaries.size()*2-1);
	for (int i = int(boundaries.size())-1; i >= 0; i -= 2) {
		boundaries[i] = boundaries[i/2];
		if (i+2 < int(boundaries.size())) {
			int64_t l = boundaries[i], r = boundaries[i+2];
			assert(l < r);
			int64_t m = r & -p2(63 - __builtin_clzll(l ^ r));
			assert(l < m && m <= r);
			boundaries[i+1] = m;
		}
	}
	boundaries.resize(std::unique(boundaries.begin(), boundaries.end()) - boundaries.begin());

	std::vector<int> live_time(int(boundaries.size())-1, -1);
	for (int q = 0; q < Q; q++) {
		auto [op, a, b] = ops[q];
		if (op == false) {
			int x = int(std::lower_bound(boundaries.begin(), boundaries.end(), a) - boundaries.begin());
			for (; boundaries[x] < b; x++) {
				live_time[x] = q;
			}
		}
	}

	std::vector<std::vector<std::array<int, 2>>> edges(Q);

	union_find uf(int(boundaries.size())-1);

	auto add_edge = [&](int a, int b) -> void {
		if (a == b) return;
		assert(0 <= a && a+1 < int(boundaries.size()));
		assert(0 <= b && b+1 < int(boundaries.size()));
		int t = max(live_time[a], live_time[b]);
		if (t == -1) uf.merge(a, b);
		else edges[t].push_back({a, b});
	};

	std::y_combinator([&](auto self, int b, int lo, int hi) -> void {
		if (hi - lo == 1) {
			return;
		}
		assert(hi - lo >= 2);
		assert(b >= 0);
		int64_t blo = boundaries[lo];
		int64_t bhi = boundaries[hi];
		assert(!(blo & (p2(b+1)-1)));
		assert(!(bhi & (p2(b+1)-1)));
		assert(bhi - blo == p2(b+1));
		int64_t bmi = blo + p2(b);
		if (boundaries[lo+1] > bmi) {
			for (int i = lo+1; i < hi; i++) {
				add_edge(lo, i);
			}
			boundaries[lo] = bmi;
			self(b-1, lo, hi);
			boundaries[lo] = blo;
		} else if (boundaries[hi-1] < bmi) {
			for (int i = lo; i < hi-1; i++) {
				add_edge(i, hi-1);
			}
			boundaries[hi] = bmi;
			self(b-1, lo, hi);
			boundaries[hi] = bhi;
		} else {
			int mi = lo+1;
			while (mi < hi && boundaries[mi] != bmi) mi++;
			assert(mi != hi);
			for (int i = lo, j = mi; i < mi && j < hi; ) {
				assert(max(boundaries[i], boundaries[j]-p2(b)) < min(boundaries[i+1], boundaries[j+1]-p2(b)));
				add_edge(i, j);
				if (boundaries[i+1] == boundaries[j+1]-p2(b)) {
					i++, j++;
				} else if (boundaries[i+1] < boundaries[j+1]-p2(b)) {
					i++;
				} else if (boundaries[i+1] > boundaries[j+1]-p2(b)) {
					j++;
				} else assert(false);
			}

			self(b-1, lo, mi);
			self(b-1, mi, hi);
		}
	})(B-1, 0, int(boundaries.size())-1);

	std::vector<bool> output; output.reserve(Q);
	for (int q = 0; q < Q; q++) {
		auto [op, a, b] = ops[q];
		if (op == false) {
			for (auto e : edges[q]) uf.merge(e);
		} else {
			assert(edges[q].empty());
			int ba = int(std::upper_bound(boundaries.begin(), boundaries.end(), a) - boundaries.begin()) - 1;
			int bb = int(std::upper_bound(boundaries.begin(), boundaries.end(), b) - boundaries.begin()) - 1;
			assert(live_time[ba] <= q);
			assert(live_time[bb] <= q);
			output.push_back(uf.get_par(ba) == uf.get_par(bb));
		}
	}

	std::reverse(output.begin(), output.end());
	for (bool b : output) cout << int(b) << '\n';
	return 0;
}