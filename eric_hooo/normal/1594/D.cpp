#include <bits/stdc++.h>
using namespace std;

char buf[20];
vector <int> from[200010], G[200010];
int col[200010];
int cnt[2];
vector <int> node;

int dfs(int x, int c) {
	col[x] = c, cnt[c]++, node.push_back(x);
	for (auto it : from[x]) {
		int v = it >> 1, w = it & 1, nc = c ? w : w ^ 1;
		if (col[v] == -1) {
			if (!dfs(v, nc)) return 0;
		}
		if (col[v] != nc) return 0;
	}
	for (auto it : G[x]) {
		int v = it >> 1, w = it & 1, nc = (c == w);
		if (col[v] == -1) {
			if (!dfs(v, nc)) return 0;
		}
		if (col[v] != nc) return 0;
	}
	return 1;
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			from[i].clear(), col[i] = -1, G[i].clear();
		}
		for (int i = 1; i <= m; i++) {
			int x, y; scanf("%d%d%s", &x, &y, buf);
			if (buf[0] == 'i') from[x].push_back(y << 1 | 0), G[y].push_back(x << 1 | 0);
			else from[x].push_back(y << 1 | 1), G[y].push_back(x << 1 | 1);
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			if (col[i] == -1) {
				int maxj = -1;
				cnt[0] = cnt[1] = 0, node.clear();
				if (dfs(i, 0)) maxj = max(maxj, cnt[0]);
				for (auto it : node) {
					col[it] = -1;
				}
				cnt[0] = cnt[1] = 0, node.clear();
				if (dfs(i, 1)) maxj = max(maxj, cnt[0]);
				if (maxj == -1) {
					printf("-1\n");
					goto END;
				}
				ans += maxj;
			}
		}
		printf("%d\n", ans);
		END:;
	}
	return 0;
}