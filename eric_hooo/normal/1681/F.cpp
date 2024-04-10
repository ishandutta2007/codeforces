#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n;
vector <pii> G[500010];
int sz[500010];
long long f[500010], rt_f[500010];
long long *up[500010], *lst[500010];

void dfs(int x, int last) {
	sz[x] = 1;
	for (auto it : G[x]) {
		int v = it.fi, w = it.se;
		if (v == last) continue;
		up[v] = lst[w], lst[w] = f + v, dfs(v, x), sz[x] += sz[v], lst[w] = up[v];
	}
}

int main() {
	scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w);
		G[x].push_back(mp(y, w));
		G[y].push_back(mp(x, w));
	}
	for (int i = 1; i <= n; i++) {
		lst[i] = rt_f + i;
	}
	dfs(1, 1);
	for (int i = 1; i <= n; i++) {
		rt_f[i] = sz[1];
	}
	for (int i = 2; i <= n; i++) {
		f[i] = sz[i];
	}
	for (int i = 2; i <= n; i++) {
		*up[i] -= sz[i];
	}
	long long ans = 0;
	for (int i = 2; i <= n; i++) {
		ans += 1ll * *up[i] * f[i];
	}
	printf("%lld\n", ans);
	return 0;
}