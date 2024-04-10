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

using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N, M; cin >> N >> M;
	vector<string> G(N);
	for (int i = 0; i < N; i++) {
		cin >> G[i];
	}

	bool emptyRow = false;
	for (int i = 0; i < N; i++) {
		char last = '.';
		int numDiff = 0;
		for (int j = 0; j < M; j++) {
			if (G[i][j] != last) numDiff++;
			last = G[i][j];
		}
		numDiff += (last != '.');
		if (numDiff == 0) {
			// empty
			emptyRow = true;
		} else if (numDiff > 2) {
			cout << -1 << '\n';
			exit(0);
		}
	}
	bool emptyCol = false;
	for (int j = 0; j < M; j++) {
		char last = '.';
		int numDiff = 0;
		for (int i = 0; i < N; i++) {
			if (G[i][j] != last) numDiff++;
			last = G[i][j];
		}
		numDiff += (last != '.');
		if (numDiff == 0) {
			// empty
			emptyCol = true;
		} else if (numDiff > 2) {
			cout << -1 << '\n';
			exit(0);
		}
	}

	if (emptyRow != emptyCol) {
		cout << -1 << '\n';
		exit(0);
	}

	int V = N * M;
	vector<int> par(V, -1);
	auto get_par = std::y_combinator([&](auto self, int a) -> int { return par[a] < 0 ? a : (par[a] = self(par[a])); });
	auto merge = [&](int a, int b) {
		a = get_par(a), b = get_par(b);
		if (a == b) return false;
		if (par[b] < par[a]) swap(a, b);
		par[a] += par[b];
		par[b] = a;
		return true;
	};
	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			ans += G[i][j] == '#';
			if (j+1 < M && G[i][j] == '#' && G[i][j+1] == '#') {
				ans -= merge(i*M+j, i*M+(j+1));
			}
			if (i+1 < N && G[i][j] == '#' && G[i+1][j] == '#') {
				ans -= merge(i*M+j, (i+1)*M+j);
			}
		}
	}
	cout << ans << '\n';

	return 0;
}