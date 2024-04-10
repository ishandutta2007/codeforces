#include<bits/stdc++.h>
#include<bits/extc++.h>

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

namespace kactl {
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

// https://github.com/kth-competitive-programming/kactl/blob/master/content/graph/EulerWalk.h
vi eulerWalk(vector<vector<pii>>& gr, int nedges, int src=0) {
	int n = sz(gr);
	vi D(n), its(n), eu(nedges), ret; vector<pair<int, int>> s = {{src, -1}};
	D[src]++; // to allow Euler paths, not just cycles
	while (!s.empty()) {
		int x = s.back().first, y, e = s.back().second, &it = its[x], end = sz(gr[x]);
		if (it == end){ ret.push_back(e); s.pop_back(); continue; }
		tie(y, e) = gr[x][it++];
		if (!eu[e]) {
			D[x]--, D[y]++;
			eu[e] = 1; s.push_back({y, e});
		}}
	for (int x : D) if (x < 0 || sz(ret) != nedges+1) return {};
	return {ret.rbegin()+1, ret.rend()};
}
}

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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<pair<int, int>> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i].first >> A[i].second;
	}
	auto is_good = [&](int bits) -> bool {
		hash_map<int, int> deg;
		hash_map<int, int> par;
		auto get_par = std::y_combinator([&](auto self, int a) -> int {
			auto it = par.find(a);
			if (it == par.end()) {
				return a;
			} else {
				return par[a] = self(it->second);
			}
		});
		auto merge = [&](int u, int v) {
			u = get_par(u);
			v = get_par(v);
			if (u == v) return false;
			par[u] = v;
			return true;
		};
		int numE = 0;
		for (int i = 0; i < N; i++) {
			int u = A[i].first & ((1 << bits) - 1);
			int v = A[i].second & ((1 << bits) - 1);

			deg[u]++;
			deg[v]++;
			numE += merge(u, v);
		}
		for (auto it : deg) {
			if (it.second % 2) return false;
		}
		int numCC = int(deg.size()) - numE;
		if (numCC > 1) {
			return false;
		}

		return true;
	};

	int mi = 0;
	int ma = 21;
	while (ma - mi > 1) {
		int md = (mi + ma) / 2;
		if (is_good(md)) {
			mi = md;
		} else {
			ma = md;
		}
	}

	vector<vector<pair<int, int>>> adj;
	hash_map<int, int> inds;
	auto get_ind = [&](int v) {
		auto it = inds.find(v);
		if (it == inds.end()) {
			int a = int(inds.size());
			inds.insert({v, a});
			adj.emplace_back();
			return a;
		} else {
			return it->second;
		}
	};
	for (int i = 0; i < N; i++) {
		int u = A[i].first = get_ind(A[i].first & ((1 << mi) - 1));
		int v = A[i].second = get_ind(A[i].second & ((1 << mi) - 1));
		adj[u].push_back({v, i});
		adj[v].push_back({u, i});
	}
	vector<int> edges = kactl::eulerWalk(adj, N, 0);
	int cur = 0;
	vector<int> ans; ans.reserve(2*N);
	for (auto e : edges) {
		if (A[e].first == cur) {
			ans.push_back(2*e+0);
			ans.push_back(2*e+1);
			cur = A[e].second;
		} else if (A[e].second == cur) {
			ans.push_back(2*e+1);
			ans.push_back(2*e+0);
			cur = A[e].first;
		} else assert(false);
	}
	assert(cur == 0);
	cout << mi << '\n';
	for (int i = 0; i < 2*N; i++) {
		cout << ans[i]+1 << " \n"[i+1==2*N];
	}

	return 0;
}