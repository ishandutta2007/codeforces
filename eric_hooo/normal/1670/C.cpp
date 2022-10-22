#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

int n;
int a[100010], b[100010], c[100010];
int p[100010], q[100010];
vector <int> G[100010];
int vis[100010];

void dfs(int x) {
	vis[x] = 1;
	for (auto v : G[x]) {
		if (!vis[v]) dfs(v);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			p[a[i]] = i;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
			q[b[i]] = i;
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &c[i]);
		}
		for (int i = 1; i <= n; i++) {
			G[i].clear(), vis[i] = 0;
		}
		for (int i = 1; i <= n; i++) {
			G[p[i]].push_back(q[i]);
			G[q[i]].push_back(p[i]);
		}
		for (int i = 1; i <= n; i++) {
			if (c[i] && !vis[i]) {
				dfs(i);
			}
		}
		int ans = 1;
		for (int i = 1; i <= n; i++) {
			if (!vis[i]) {
				dfs(i);
				if (a[i] != b[i]) ans = (ans + ans) % mod;
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}