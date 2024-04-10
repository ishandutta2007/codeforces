#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	struct edge_t {
		array<int, 2> V;
		int W;
	};
	vector<edge_t> edges(M);
	vector<set<int>> adj(N);
	int totW = 0;
	for (auto& e : edges) {
		cin >> e.V[0] >> e.V[1] >> e.W; e.V[0]--, e.V[1]--;
		totW ^= e.W;
		adj[e.V[0]].insert(e.V[1]);
		adj[e.V[1]].insert(e.V[0]);
	}
	sort(edges.begin(), edges.end(), [&](const auto& a, const auto& b) { return a.W < b.W; });

	int64_t num_unassigned = int64_t(N) * int64_t(N-1) / 2 - M;

	vector<int> par(N, -1);
	auto reset_par = [&]() -> void { fill(par.begin(), par.end(), -1); };
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
		if (par[a] > par[b]) swap(a, b);
		par[a] += par[b];
		par[b] = a;
		return true;
	};

	{
		int nm = 0;
		for (int z = 0; z < M; z++) {
			edge_t e = edges[z];
			if (merge(e.V[0], e.V[1])) {
				edges[nm++] = e;
			}
		}
		M = nm;
		edges.resize(M);
	}

	reset_par();

	vector<int> unvis(N); iota(unvis.begin(), unvis.end(), 0);
	vector<int> q; q.reserve(N);
	while (!unvis.empty()) {
		q.push_back(unvis.back()); unvis.pop_back();
		for (int z = int(q.size())-1; z < int(q.size()); z++) {
			int cur = q[z];
			int b = 0;
			for (int a = 0; a < int(unvis.size()); a++) {
				int nxt = unvis[a];
				if (adj[cur].count(nxt)) {
					unvis[b++] = nxt;
				} else {
					merge(cur, nxt);
					num_unassigned--;
					q.push_back(nxt);
				}
			}
			unvis.resize(b);
		}
	}

	int64_t ans = 0;
	for (auto e : edges) {
		if (merge(e.V[0], e.V[1])) {
			ans += e.W;
		} else if (num_unassigned == 0) {
			ans += min(totW, e.W);
			num_unassigned = -1;
		}
	}

	if (num_unassigned == 0) {
		ans += totW;
		num_unassigned = -1;
	}
	cout << ans << '\n';

	return 0;
}