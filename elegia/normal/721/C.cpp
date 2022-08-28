#include <cstdio>

#include <vector>

using namespace std;

const int N = 5010;

int n, m, t;
bool vis[N];
pair<int, int> dp[N][N];

vector<pair<int, int> > g[N];

void dfs(int u);
void out(int u, int k) {
	if (k == 0) {
		printf("%d\n", u);
		return;
	}
	printf("%d ", u);
	out(dp[u][k].second, k - 1);
}

int main() {
	scanf("%d%d%d", &n, &m, &t);
	fill(*dp, dp[n] + n + 1, make_pair(t + 1, -1));
	while (m--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].emplace_back(v, w);
	}
	dp[n][0] = make_pair(0, -1);
	vis[n] = true;
	dfs(1);
	for (int i = n; i; --i)
		if (dp[1][i].first <= t) {
			printf("%d\n", i + 1);
			out(1, i);
			return 0;
		}
	return 0;
}

void dfs(int u) {
	if (vis[u])
		return;
	vis[u] = true;
	for (const auto& e : g[u]) {
		dfs(e.first);
		for (int i = 0; i < n; ++i)
			dp[u][i + 1] = min(dp[u][i + 1], make_pair(dp[e.first][i].first + e.second, e.first));
	}
}