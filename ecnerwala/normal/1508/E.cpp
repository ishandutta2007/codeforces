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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	vector<int> A(N); for (auto& a : A) { cin >> a; a--; }
	vector<vector<int>> adj(N);
	for (int e = 0; e < N-1; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> B(N);
	vector<int> par(N);
	vector<int> depth(N);
	vector<int> C(N);
	{
		par[0] = -1;
		depth[0] = 0;
		int cur_idx = 0;
		int cur_post_idx = 0;
		std::y_combinator([&](auto self, int cur) -> void {
			B[cur] = cur_idx++;
			sort(adj[cur].begin(), adj[cur].end(), [&](int a, int b) { return A[a] < A[b]; });
			for (int nxt : adj[cur]) {
				par[nxt] = cur;
				adj[nxt].erase(std::find(adj[nxt].begin(), adj[nxt].end(), cur));
				depth[nxt] = depth[cur]+1;
				self(nxt);
			}
			C[cur] = cur_post_idx++;
		})(0);
		assert(cur_idx == N);
		assert(cur_post_idx == N);
	}

	int64_t T = 0;
	bool is_good = [&]() -> bool {
		if (A[0] == 0) {
			return A == B;
		}
		int last_move = A[0] - 1;
		int cur_loc = 0;
		while (A[cur_loc] != last_move) cur_loc++;
		// We'll just extend the process a little bit
		while (true) {
			auto it = adj[cur_loc].begin();
			while (it != adj[cur_loc].end() && !(A[cur_loc] < A[*it])) ++it;
			if (it == adj[cur_loc].end()) break;
			std::swap(A[cur_loc], A[*it]);
			cur_loc = *it;
			T--;
		}

		//for (int i = 0; i < N; i++) { cerr << A[i] << " \n"[i+1==N]; }

		// Now, A must equal the known state, i.e. the prefix of size A[0] must be in postorder, and the rest are in preorder
		vector<int> V(N);
		{
			int cur_idx = last_move+1;
			std::y_combinator([&](auto self, int cur) -> void {
				if (C[cur] <= last_move) {
					T += depth[cur];
					V[cur] = C[cur];
				} else {
					V[cur] = cur_idx++;
				}
				for (int nxt : adj[cur]) {
					self(nxt);
				}
			})(0);
			assert(cur_idx == N);
		}
		//for (int i = 0; i < N; i++) { cerr << V[i] << " \n"[i+1==N]; }
		return A == V;
	}();

	if (is_good) {
		cout << "YES" << '\n';
		cout << T << '\n';
		for (int i = 0; i < N; i++) {
			cout << B[i]+1 << " \n"[i+1==N];
		}
	} else {
		cout << "NO" << '\n';
	}

	return 0;
}