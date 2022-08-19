#include <bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N; cin >> N;
	auto query = [&](int r) -> vector<int> {
		cout << '?' << ' ' << r+1 << '\n' << flush;
		vector<int> res(N);
		for (auto& d : res) cin >> d;
		return res;
	};

	vector<int> depth = query(0);
	vector<int> par(N, -1);
	par[0] = 0;
	for (int i = 0; i < N; i++) if (depth[i] == 1) par[i] = 0;

	auto do_query = [&](int a) -> void {
		assert(par[a] == -1);
		vector<int> path(depth[a]+1);
		vector<int> dist = query(a);
		for (int i = 0; i < N; i++) {
			if (depth[i] + dist[i] == depth[a]) {
				path[depth[i]] = i;
			}
		}
		for (int d = 1; d <= depth[a]; d++) {
			par[path[d]] = path[d-1];
		}
		for (int i = 0; i < N; i++) {
			if (depth[i] + dist[i] == depth[a] + 2) {
				par[i] = path[depth[i]-1];
			}
		}
	};
	for (int i = 1; i < N; i++) {
		if (par[i] == -1) do_query(i);
	}

	cout << '!' << '\n';
	for (int i = 1; i < N; i++) {
		cout << par[i]+1 << ' ' << i+1 << '\n';
	}
	cout << flush;

	return 0;
}