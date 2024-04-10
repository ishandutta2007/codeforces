#include <bits/stdc++.h>
using namespace std;

int n;
int sg[300010];
vector <int> G[300010];
int vis[300010], fa[300010];

void dfs(int x, int last) {
	sg[x] = 0, fa[x] = last;
	for (auto v : G[x]) if (v != last) {
		dfs(v, x), sg[x] ^= sg[v] + 1;
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y; scanf("%d%d", &x, &y);
		G[x].push_back(y);
		G[y].push_back(x);
	}
	dfs(1, 1);
	int ans = sg[1]; vis[1] = 1;
	printf(ans == 0 ? "2" : "1");
	for (int i = 2; i <= n; i++) {
		int x = i;
		while (!vis[x]) ans ^= sg[x] ^ sg[x] + 1 ^ 1, vis[x] = 1, x = fa[x];
		printf(ans == 0 ? "2" : "1");
	}
	printf("\n");
	return 0;
}