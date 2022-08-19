#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	// we're trying to split this into a tree
	// maximum spanning tree
	int NA, NB; cin >> NA >> NB;
	vector<int64_t> A(NA); for (auto& a : A) cin >> a;
	vector<int64_t> B(NB); for (auto& b : B) cin >> b;


	struct edge_t {
		array<int, 2> x;
		int64_t v;
	};
	vector<edge_t> edges; edges.reserve(int(2.1e5));
	for (int i = 0; i < NA; i++) {
		int k; cin >> k;
		while (k--) {
			int j; cin >> j; j--;
			edges.push_back({{i, NA+j}, A[i] + B[j]});
		}
	}

	sort(edges.begin(), edges.end(), [](const edge_t& a, const edge_t& b) { return a.v > b.v; });

	vector<int> par(NA + NB, -1);
	auto get_par = [&](int a) {
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

	int64_t ans = 0;
	for (const auto& e : edges) {
		if (!merge(e.x[0], e.x[1])) {
			ans += e.v;
		}
	}
	cout << ans << '\n';

	return 0;
}