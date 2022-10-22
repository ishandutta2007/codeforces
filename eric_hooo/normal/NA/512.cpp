#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <pii> from[5010];
long long dp[5010], dist[5010];
int size[5010];

void dfs(int x, int last) {
	dp[x] = 0, size[x] = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, c = from[x][i].se;
		if (v == last) continue;
		dfs(v, x), dp[x] += dp[v] + 1ll * size[v] * c, size[x] += size[v]; 
	}
	return ;
}

void dfs2(int x, int last, long long out, int root) {
	dist[x] = dp[x] + out;
	long long sum = 0;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, c = from[x][i].se;
		if (v == last) continue;
		sum += 1ll * c * size[v] + dp[v]; 
	}
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, c = from[x][i].se;
		if (v == last) continue;
		dfs2(v, x, out + sum - 1ll * c * size[v] - dp[v] + 1ll * (size[root] - size[v]) * c, root);
	}
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int u, v, c; scanf("%d%d%d", &u, &v, &c);
		from[u].push_back(mp(v, c));
		from[v].push_back(mp(u, c));
	}
	long long ans = 0x3f3f3f3f3f3f3f3f;
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j < from[i].size(); j++) {
			int v = from[i][j].fi;
			if (v > i) continue;
			memset(dist, -1, sizeof(dist));
			dfs(i, v), dfs2(i, v, 0, i);
			int x = -1;
			long long sum = 0;
			for (int k = 1; k <= n; k++) {
				if (dist[k] == -1) continue;
				if (x == -1 || dist[k] < dist[x]) x = k;
				if (dist[k] != -1) sum += dist[k];
			}
			long long dx = dist[x];
			memset(dist, -1, sizeof(dist));
			dfs(v, i), dfs2(v, i, 0, v);
			int y = -1;
			for (int k = 1; k <= n; k++) {
				if (dist[k] == -1) continue;
				if (y == -1 || dist[k] < dist[y]) y = k;
				if (dist[k] != -1) sum += dist[k];
			}
			sum /= 2;
			ans = min(ans, sum + dx * size[v] + size[i] * dist[y] + 1ll * size[i] * size[v] * from[i][j].se);
		}
	}
	printf("%lld\n", ans);
	return 0;
}