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

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;

		vector<vector<int>> adj(N);
		for (int e = 0; e < M; e++) {
			int u, v; cin >> u >> v; u--, v--;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
		vector<vector<int>> ch(N);
		vector<bool> vis(N, false);
		std::y_combinator([&](auto self, int cur) -> void {
			assert(!vis[cur]);
			vis[cur] = true;
			for (int nxt : adj[cur]) {
				if (vis[nxt]) continue;
				ch[cur].push_back(nxt);
				self(nxt);
			}
		})(0);

		vector<int> sz(N);
		std::y_combinator([&](auto self, int cur) -> void {
			sz[cur] = 1;
			for (int nxt : ch[cur]) {
				self(nxt);
				sz[cur] += sz[nxt];
			}
			sort(ch[cur].begin(), ch[cur].end(), [&](int a, int b) { return sz[a] > sz[b]; });
		})(0);


		const int PATH_TARGET = (N+1)/2;
		const int PAIRING_TARGET = PATH_TARGET + (PATH_TARGET % 2);
		vector<int> path;
		vector<int> pairing;
		int cur = 0;
		assert(int(path.size()) < PATH_TARGET);
		assert(int(pairing.size()) < PAIRING_TARGET);
		while (true) {
			path.push_back(cur);
			if (int(path.size()) >= PATH_TARGET) {
				break;
			}
			assert(!ch[cur].empty());
			int first_ch = ch[cur][0];
			for (int z = 1; z < int(ch[cur].size()); z++) {
				std::y_combinator([&](auto self, int a) -> void {
					pairing.push_back(a);
					for (int b : ch[a]) self(b);
				})(ch[cur][z]);
			}
			int cur_sz = int(pairing.size());
			if (cur_sz + min(sz[first_ch], cur_sz) >= PAIRING_TARGET) {
				int lim = cur_sz;
				std::y_combinator([&](auto self, int a) -> void {
					if (!lim) return;
					pairing.push_back(a);
					lim--;
					for (int b : ch[a]) self(b);
				})(first_ch);
				break;
			}
			cur = first_ch;
		}

		if (int(path.size()) >= PATH_TARGET) {
			cout << "PATH" << '\n';
			cout << path.size() << '\n';
			for (int i = 0; i < int(path.size()); i++) {
				cout << path[i]+1 << " \n"[i+1==int(path.size())];
			}
		} else if (int(pairing.size()) >= PAIRING_TARGET) {
			cout << "PAIRING" << '\n';
			cout << int(pairing.size()) / 2 << '\n';
			for (int i = 0; i < int(pairing.size()) / 2; i++) {
				cout << pairing[i]+1 << ' ' << pairing[i+(int(pairing.size())/2)]+1 << '\n';
			}
		} else assert(false);
	}

	return 0;
}