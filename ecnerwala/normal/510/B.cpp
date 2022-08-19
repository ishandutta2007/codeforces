#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	std::vector<std::string> G(N);
	for (auto& r : G) cin >> r;
	std::vector<int> par(N*M, -1);
	auto get_par = [&](int a) -> int {
		while (par[a] >= 0) {
			if (par[par[a]] >= 0) par[a] = par[par[a]];
			a = par[a];
		}
		return a;
	};
	auto merge = [&](int a, int b) -> bool {
		a = get_par(a), b = get_par(b);
		if (a == b) return false;
		if (par[a] > par[b]) std::swap(a, b);
		par[a] += par[b];
		par[b] = a;
		return true;
	};

	int ans = 0;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < M; j++) {
			if (i && G[i-1][j] == G[i][j]) {
				ans += !merge((i-1)*M+j, i*M+j);
			}
			if (j && G[i][j-1] == G[i][j]) {
				ans += !merge(i*M+(j-1), i*M+j);
			}
		}
	}
	cout << (ans ? "Yes" : "No") << '\n';

	return 0;
}