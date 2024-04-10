#include<bits/stdc++.h>
using namespace std;

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

using ll = long long;

const int S = 1<<18;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	vector<int> A(N);
	for (int i = 0; i < N; i++) {
		cin >> A[i];
	}

	ll sum = 0;
	for (int i = 0; i < N; i++) {
		sum += A[i];
	}

	// the root
	N++;
	A.push_back(0);


	ll ans = 0;

	vector<int> par(N);
	iota(par.begin(), par.end(), 0);
	auto getPar = std::y_combinator([&](auto self, int a) -> int {
		if (par[a] == a) return a;
		return par[a] = self(par[a]);
	});

	// indices of 2 biggest subsets
	vector<vector<int>> closest(S);
	for (int v = 0; v < S; v++) closest[v].reserve(2);

	auto tryInsert = [&](int msk, int cnd) {
		if (closest[msk].size() >= 2) return;
		if (closest[msk].size() == 1 && par[closest[msk][0]] == par[cnd]) {
			return;
		}
		closest[msk].push_back(cnd);
	};

	for (int z = 0; true; z++) {
		int cntPar = 0;
		for (int i = 0; i < N; i++) {
			cntPar += (par[i] == i);
		}
		if (cntPar == 1) break;

		for (int v = 0; v < S; v++) closest[v].clear();

		// we break ties by bigger edge
		for (int i = N-1; i >= 0; i--) {
			tryInsert(A[i], i);
		}

		for (int i = 0; (1<<i) < S; i++) {
			for (int v = 0; v < S; v++) {
				if (v & (1<<i)) continue;
				for (auto cnd : closest[v]) {
					tryInsert(v | (1<<i), cnd);
				}
			}
		}

		vector<pair<pair<int, pair<int, int>>, int>> bestNxt(N);
		for (int i = 0; i < N; i++) {
			bestNxt[i] = {{-1, {-1, -1}}, -1};
		}

		for (int i = 0; i < N; i++) {
			for (auto j : closest[S-1-A[i]]) {
				if (par[j] == par[i]) continue;
				assert(!(A[i] & A[j]));
				bestNxt[par[i]] = max(bestNxt[par[i]], pair<pair<int, pair<int, int>>, int>({A[i]+A[j], {min(i, j), max(i, j)}}, par[j]));
				break;
			}
		}

		for (int i = 0; i < N; i++) {
			if (par[i] != i) continue;

			assert(bestNxt[i].second != -1);
			int j = bestNxt[i].second;
			if (par[j] == i) {
				// skip
			} else {
				ans += bestNxt[i].first.first;
				par[i] = j;
			}
		}

		for (int i = 0; i < N; i++) {
			getPar(i);
		}
	}

	cout << ans - sum << '\n';

	return 0;
}