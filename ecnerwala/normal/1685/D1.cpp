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

	int T; cin >> T;
	while (T--) {
		int N; cin >> N;
		std::vector<int> P(N);
		for (auto& p : P) { cin >> p; p--; }

		std::vector<int> par(N, -1);
		auto get_par = [&](int a) {
			while (par[a] >= 0) {
				if (par[par[a]] >= 0) par[a] = par[par[a]];
				a = par[a];
			}
			return a;
		};
		auto merge = [&](int a, int b) {
			a = get_par(a);
			b = get_par(b);
			if (a == b) return false;
			if (par[a] > par[b]) std::swap(a, b);
			par[a] += par[b];
			par[b] = a;
			return true;
		};

		for (int i = 0; i < N; i++) {
			merge(i, P[i]);
		}

		std::vector<std::vector<int>> outEdges(N);
		for (int i = 0; i < N; i++) {
			outEdges[P[i]].push_back(i);
		}
		for (int i = 0; i+1 < N; i++) {
			if (merge(i, i+1)) {
				outEdges[i].push_back(i+1);
				outEdges[i+1].push_back(i);
			}
		}

		std::vector<int> Q; Q.reserve(N);
		std::y_combinator([&](auto self, int cur) -> void {
			while (!outEdges[cur].empty()) {
				int nxt = outEdges[cur].back();
				outEdges[cur].pop_back();
				bool is_perm_edge = outEdges[cur].empty();
				self(nxt);
				if (is_perm_edge) {
					Q.push_back(nxt);
				}
			}
		})(0);
		std::reverse(Q.begin(), Q.end());

		for (int i = 0; i < N; i++) {
			cout << Q[i]+1 << " \n"[i+1==N];
		}
	}

	return 0;
}