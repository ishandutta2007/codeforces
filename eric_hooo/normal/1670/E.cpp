#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n, cur;
vector <pii> G[200000];
int a[200010], b[200010];

void dfs(int x, int last) {
	for (auto it : G[x]) {
		int v = it.fi, id = it.se;
		if (v == last) continue;
		b[id] = a[x] & n ? n + cur : cur;
		a[v] = a[x] & n ? cur : n + cur, cur++;
		dfs(v, x);
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n), n = 1 << n, cur = 1;
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			G[x].push_back(mp(y, i));
			G[y].push_back(mp(x, i));
		}
		a[1] = n, dfs(1, 1);
		printf("%d\n", 1);
		for (int i = 1; i <= n; i++) {
			printf("%d ", a[i]);
		}
		printf("\n");
		for (int i = 1; i < n; i++) {
			printf("%d ", b[i]);
		}
		printf("\n");
	}
	return 0;
}