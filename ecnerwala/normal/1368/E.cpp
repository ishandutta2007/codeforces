#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);

	int T; cin >> T;
	while (T--) {
		int N, M; cin >> N >> M;
		vector<vector<int>> adj(N);
		for (int e = 0; e < M; e++) {
			int x, y; cin >> x >> y; x--, y--;
			adj[y].push_back(x);
		}
		vector<int> ans; ans.reserve(N);
		vector<int> d(N);
		for (int i = 0; i < N; i++) {
			for (int j : adj[i]) {
				d[i] = max(d[i], d[j]+1);
			}
			if (d[i] == 2) {
				d[i] = -1;
				ans.push_back(i);
			}
		}
		cout << int(ans.size()) << '\n';
		for (int z = 0; z < int(ans.size()); z++) {
			cout << ans[z]+1 << " \n"[z+1==int(ans.size())];
		}
	}

	return 0;
}