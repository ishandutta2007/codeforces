#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int N, M; cin >> N >> M;
	vector<vector<int>> adj(N);
	for (int e = 0; e < M; e++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	vector<int> T(N);
	for (int i = 0; i < N; i++) {
		cin >> T[i]; T[i]--;
	}
	vector<pair<int, int>> P(N);
	for (int i = 0; i < N; i++) {
		P[i] = {T[i], i};
	}
	sort(P.begin(), P.end());

	vector<int> mex(N, 0);

	for (auto [v, i] : P) {
		if (mex[i] != v) {
			cout << -1 << '\n';
			exit(0);
		}
		for (auto j : adj[i]) {
			if (T[j] == T[i]) {
				cout << -1 << '\n';
				exit(0);
			}
			if (T[j] < T[i]) {
				continue;
			}

			if (v > mex[j]) {
				cout << -1 << '\n';
				exit(0);
			}
			if (v == mex[j]) {
				mex[j] = v+1;
			}
		}
	}
	for (int i = 0; i < N; i++) {
		cout << P[i].second+1 << " \n"[i+1==N];
	}

	return 0;
}