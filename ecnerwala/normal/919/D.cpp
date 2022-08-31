#include<bits/stdc++.h>

int main() {
	using namespace std;
	ios_base::sync_with_stdio(false), cin.tie(nullptr);
	int N, M; cin >> N >> M;
	string S; cin >> S;

	vector<vector<int>> adj(N);
	vector<int> inDeg(N);
	for (int e = 0; e < M; e++) {
		int x, y; cin >> x >> y;
		x--, y--;
		adj[x].push_back(y);
		inDeg[y]++;
	}

	vector<int> q; q.reserve(N);
	for (int i = 0; i < N; i++) {
		if (inDeg[i] == 0) q.push_back(i);
	}

	vector<array<int, 26>> dp(N, array<int, 26>({0,}));

	int ans = 0;
	for (int z = 0; z < int(q.size()); z++) {
		int cur = q[z];
		ans = max(ans, ++dp[cur][S[cur]-'a']);
		for (int nxt : adj[cur]) {
			for (int v = 0; v < 26; v++) {
				dp[nxt][v] = max(dp[nxt][v], dp[cur][v]);
			}
			if (!--inDeg[nxt]) {
				q.push_back(nxt);
			}
		}
	}

	if (int(q.size()) < N) {
		cout << -1 << '\n';
	} else {
		cout << ans << '\n';
	}

	return 0;
}