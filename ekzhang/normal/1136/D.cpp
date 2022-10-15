#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013
int N, M;
int Pi[MAXN];
vector<int> adj[MAXN];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		int k; cin >> k;
		Pi[k] = i;
	}

	for (int i = 0; i < M; i++) {
		int u, v;
		cin >> u >> v;
		u = Pi[u], v = Pi[v];
		if (u < v)
			adj[u].push_back(v);
	}

	unordered_set<int> fail;
	fail.insert(N - 1);
	int ans = 0;
	for (int i = N - 2; i >= 0; i--) {
		int cnt = fail.size();
		for (int v : adj[i]) {
			if (fail.count(v))
				--cnt;
		}
		if (cnt)
			fail.insert(i);
		else
			++ans;
	}

	cout << ans << endl;
	return 0;
}