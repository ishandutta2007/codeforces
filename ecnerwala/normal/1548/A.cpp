#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	int num_alive = N;
	std::vector<int> cnt_bigger(N);
	auto add_edge = [&](int u, int v) {
		if (u > v) swap(u, v);
		num_alive -= cnt_bigger[u] == 0;
		cnt_bigger[u]++;
	};
	auto del_edge = [&](int u, int v) {
		if (u > v) swap(u, v);
		cnt_bigger[u]--;
		num_alive += cnt_bigger[u] == 0;
	};
	for (int e= 0; e < M; e++) {
		int u, v; cin >> u >> v; u--, v--;
		add_edge(u, v);
	}
	int Q; cin >> Q;
	while (Q--) {
		int op; cin >> op;
		if (op == 1) {
			int u, v; cin >> u >> v; u--, v--;
			add_edge(u, v);
		} else if (op == 2) {
			int u, v; cin >> u >> v; u--, v--;
			del_edge(u, v);
		} else if (op == 3) {
			cout << num_alive << '\n';
		} else assert(false);
	}

	return 0;
}