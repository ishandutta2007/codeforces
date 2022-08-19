#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	std::string S(M, '0');
	std::vector<std::pair<int, int>> edges; edges.reserve(M);
	for (int i = 0; i < M; i++) {
		S[i] = '1';
		cout << '?' << ' ' << S << '\n' << flush;
		S[i] = '0';

		int v; cin >> v;
		edges.push_back({v, i});
	}
	std::sort(edges.begin(), edges.end());

	int cur_v = 0;
	for (auto [v, i] : edges) {
		S[i] = '1';
		cout << '?' << ' ' << S << '\n' << flush;
		int nxt_v; cin >> nxt_v;
		if (nxt_v == cur_v + v) {
			cur_v = nxt_v;
		} else {
			S[i] = '0';
		}
	}

	cout << '!' << ' ' << cur_v << '\n' << flush;

	return 0;
}