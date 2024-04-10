#include<bits/stdc++.h>
using namespace std;

int main() {
	ios_base::sync_with_stdio(false), cin.tie(nullptr), cout.tie(nullptr);
	int N, M; cin >> N >> M;
	vector<vector<int>> succ(N);
	vector<vector<int>> pred(N);
	for (int e = 0; e < M; e++) {
		int u, v; cin >> u >> v; u--, v--;
		succ[u].push_back(v);
		pred[v].push_back(u);
	}

	vector<int> indeg(N);
	for (int i = 0; i < N; i++) {
		indeg[i] = int(size(pred[i]));
	}

	vector<int> toposort; toposort.reserve(N);
	for (int i = 0; i < N; i++) {
		if (indeg[i] == 0) {
			toposort.push_back(i);
		}
	}
	for (int z = 0; z < int(toposort.size()); z++) {
		int cur = toposort[z];
		for (int nxt : succ[cur]) {
			if (!--indeg[nxt]) {
				toposort.push_back(nxt);
			}
		}
	}
	if (int(toposort.size()) < N) {
		cout << -1 << '\n';
		exit(0);
	}

	vector<int> min_succ(N); iota(min_succ.begin(), min_succ.end(), 0);
	for (int z = N-1; z >= 0; z--) {
		int cur = toposort[z];
		for (int nxt : succ[cur]) {
			min_succ[cur] = min(min_succ[cur], min_succ[nxt]);
		}
	}

	vector<int> min_pred(N); iota(min_pred.begin(), min_pred.end(), 0);
	for (int z = 0; z < N; z++) {
		int cur = toposort[z];
		for (int nxt : pred[cur]) {
			min_pred[cur] = min(min_pred[cur], min_pred[nxt]);
		}
	}

	int cnt = 0;
	string ans(N, 'E');
	for (int i = 0; i < N; i++) {
		if (min(min_succ[i], min_pred[i]) == i) {
			cnt++;
			ans[i] = 'A';
		}
	}
	cout << cnt << '\n';
	cout << ans << '\n';

	return 0;
}