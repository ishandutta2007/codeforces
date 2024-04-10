#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <int, pii> piii;

vector <int> from[3010];
int n;
long long dp[3010][3010];
int dist[3010][3010], size[3010][3010];

long long dfs(int x, int y) {
	if (dist[x][y] == 1) return (size[x][x] - size[x][y]) * (size[y][y] - size[y][x]);
	if (~dp[x][y]) return dp[x][y];
	long long &res = dp[x][y] = 0;
	int sx = 1, sy = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (dist[v][y] == dist[x][y] + 1) {
			sx += size[x][v];
			continue;
		}
		res = max(res, dfs(v, y));
	}
	for (int i = 0; i < from[y].size(); i++) {
		int v = from[y][i];
		if (dist[x][v] == dist[x][y] + 1) {
			sy += size[y][v];
			continue;
		}
		res = max(res, dfs(x, v));
	}
	res += sx * sy;
	return res;
}

void get_dist(int x, int last, int dist[3010], int size[3010]) {
	size[x] = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (v == last) continue;
		dist[v] = dist[x] + 1, get_dist(v, x, dist, size), size[x] += size[v];
	}
}

int main () {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v; scanf("%d%d", &u, &v);
		from[u].push_back(v);
		from[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) {
		get_dist(i, i, dist[i], size[i]);
	}
	long long ans = 0;
	memset(dp, -1, sizeof(dp));
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			ans = max(ans, dfs(i, j));
		}
	}
	printf("%I64d\n", ans);
	return 0;
}