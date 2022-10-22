#include <bits/stdc++.h>
using namespace std;

vector <int> G[100010];
int a[100010];

void dfs(int x, int last, int d) {
	a[x] = d & 1 ? (int)G[x].size() : -(int)G[x].size();
	for (auto v : G[x]) if (v != last) {
		dfs(v, x, d + 1);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			G[x].push_back(y);
			G[y].push_back(x);
		}
		dfs(1, 1, 0);
		for (int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
	}
	return 0;
}