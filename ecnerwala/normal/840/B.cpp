#include<bits/stdc++.h>
using namespace std;

const int MAXN = 4e5;
int N, M;
int D[MAXN];

// second one is index
vector<pair<int, int>> adj[MAXN];

vector<int> res;

bool vis[MAXN];

bool dfs(int cur, int prv = -1) {
	vis[cur] = true;
	bool sum = 0;
	for (auto it : adj[cur]) {
		int nxt = it.first, e = it.second;
		if (vis[nxt]) continue;
		if (dfs(nxt, cur)) {
			res.push_back(e);
			sum = !sum;
		}
	}
	if (D[cur] == -1) {
		sum = 0;
	} else {
		sum = sum ^ D[cur];
	}
	if (prv == -1) assert(sum == 0);
	return sum;
}

int main() {
	scanf("%d %d", &N, &M);
	for (int i = 0; i < N; i++) {
		scanf("%d", &D[i]);
	}
	for (int i = 1; i <= M; i++) {
		int u, v;
		scanf("%d %d", &u, &v);
		u--, v--;
		adj[u].emplace_back(v, i);
		adj[v].emplace_back(u, i);
	}
	bool has_neg = false;
	for (int i = 0; i < N; i++) {
		if (D[i] == -1) {
			has_neg = true;
			dfs(i);
		}
	}
	if (!has_neg) {
		int sum = 0;
		for (int i = 0; i < N; i++) {
			sum ^= D[i];
		}
		if (sum) {
			printf("-1\n");
			return 0;
		} else {
			dfs(0);
		}
	}
	sort(res.begin(), res.end());
	printf("%d\n", int(res.size()));
	for (int e : res) printf("%d\n", e);
	return 0;
}