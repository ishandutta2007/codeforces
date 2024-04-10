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
		//cerr << "Start case" << '\n';
		//for (int p : P) { cerr << p << ' '; } cerr << '\n';

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
		auto reset_par = [&]() {
			for (int i = 0; i < N; i++) par[i] = -1;
		};

		std::vector<std::vector<int>> outEdges(N);
		for (int i = 0; i < N; i++) {
			outEdges[P[i]].push_back(i);
		}

		// we start at the P[0] -> 0 edge
		std::vector<int> Q; Q.reserve(N);
		Q.push_back(0);

		std::vector<bool> used(N);
		used[0] = true;

		std::vector<int> num_up(N-1);
		std::vector<int> num_down(N-1);

		for (int z = 1; z < N; z++) {
			for (int cnd = 0; true; cnd++) {
				assert(cnd < N);
				if (used[cnd]) continue;
				// get from Q.back() to P[i]
				// just check this scenario in linear time...
				Q.push_back(cnd);
				used[cnd] = true;
				if ([&]() -> bool {
					//cerr << "checking sequence" << ' '; for (int i : Q) { cerr << P[i] << '-' << i << ' '; } cerr << '\n';

					for (int i = 0; i+1 < N; i++) {
						num_up[i] = num_down[i] = 0;
					}
					for (int t = 0; t+1 < int(Q.size()); t++) {
						int st = Q[t];
						int en = P[Q[t+1]];
						if (st < en) {
							for (int i = st; i+1 <= en; i++) {
								if (num_up[i]) return false;
								num_up[i]++;
							}
						} else if (st > en) {
							for (int i = st; i-1 >= en; i--) {
								if (num_down[i-1]) return false;
								num_down[i-1]++;
							}
						}
					}

					reset_par();
					for (int i = 0; i < N; i++) {
						merge(i, P[i]);
					}
					for (int i = 0; i+1 < N; i++) {
						if (num_up[i] || num_down[i]) {
							if (!merge(i, i+1)) {
								return false;
							}
						}
					}

					std::vector<bool> is_main(N);
					for (int i = 0; i < N; i++) {
						is_main[i] = (get_par(P[0]) == get_par(i));
					}

					std::vector<bool> has_edge(N);
					reset_par();
					for (int i = 0; i < N; i++) {
						if (!used[i]) {
							merge(i, P[i]);
							has_edge[i] = has_edge[P[i]] = true;
						}
					}
					for (int i = 0; i+1 < N; i++) {
						if (num_up[i] ^ num_down[i]) {
							merge(i, i+1);
							has_edge[i] = has_edge[i+1] = true;
						}
					}

					std::vector<bool> is_dead(N);
					for (int i = 0; i < N; i++) {
						is_dead[i] = is_main[i] && (get_par(P[0]) != get_par(i));
					}

					for (int i = 0; i+1 < N; i++) {
						if (is_dead[i] || is_dead[i+1]) continue;
						merge(i, i+1);
					}
					for (int i = 0; i < N; i++) {
						if (has_edge[i] && get_par(i) != get_par(P[0])) {
							return false;
						}
					}

					return true;
				}()) {
					//cerr << "append " << cnd << '\n';
					break;
				} else {
					Q.pop_back();
					used[cnd] = false;
				}
			}
		}

		for (int i = 0; i < N; i++) {
			cout << Q[i]+1 << " \n"[i+1==N];
		}
	}

	return 0;
}