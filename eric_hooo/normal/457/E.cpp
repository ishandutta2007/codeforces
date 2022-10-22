#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 2100000000;

int n, m;
int X[200010], Y[200010], W[200010], B[200010];
int vis[200010];
int dist[200010], col[200010];
int minj[200010], maxj[200010];
vector <pii> G[200010];

bool dfs(int x) {
	vis[x] = 1, maxj[col[x]] = max(maxj[col[x]], dist[x]), minj[col[x]] = min(minj[col[x]], dist[x]);
	for (auto it : G[x]) {
		int v = it.fi, w = it.se;
		if (vis[v]) {
			if (dist[v] != dist[x] + w) return 1;
			continue;
		}
		col[v] = col[x], dist[v] = dist[x] + w;
		if (dfs(v)) return 1;
	}
	return 0;
}

int Check(int m) {
	for (int i = 1; i <= n; i++) {
		vis[i] = 0, G[i].clear();
	}
	for (int i = 0; i < m; i++) {
		G[X[i]].push_back(mp(Y[i], B[i] * W[i]));
		G[Y[i]].push_back(mp(X[i], -B[i] * W[i]));
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		col[i] = i, dist[i] = 0, minj[i] = INF, maxj[i] = -INF;
		if (dfs(i)) return -1;
	}
	for (int i = 1; i <= n; i++) {
		if (i != 1 && col[i] == col[1] && dist[i] <= dist[1]) return -1;
		if (i != n && col[i] == col[n] && dist[i] >= dist[n]) return -1;
	}
	if (col[1] == col[n]) {
		for (int i = 1; i <= n; i++) {
			if (col[i] != col[1]) {
				if (maxj[col[i]] - minj[col[i]] >= dist[n] - dist[1]) return -1;
			}
		}
	}
	return col[1] == col[n] ? dist[n] - dist[1] : 0;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d%d", &X[i], &Y[i], &W[i], &B[i]);
	}
	int l = 0, r = m;
	while (l < r) {
		int mid = l + r + 1 >> 1;
		if (Check(mid) >= 0) l = mid;
		else r = mid - 1;
	}
	if (l == m) {
		int ans = Check(l);
		if (ans == 0) printf("UNKNOWN\n");
		else printf("%d\n", ans);
	} else printf("BAD %d\n", l + 1);
	return 0;
}