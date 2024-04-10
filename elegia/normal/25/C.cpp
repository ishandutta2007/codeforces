#include <cstdio>

#include <algorithm>
#include <numeric>

using namespace std;

typedef long long ll;

const int N = 410;

int n, k;
ll g[N][N];

int main() {
	scanf("%d", &n, &k);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			scanf("%d", &g[i][j]);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= n; ++j)
			for (int k = 1; k <= n; ++k)
				g[j][k] = min(g[j][k], g[j][i] + g[i][k]);
	scanf("%d", &k);
	while (k--) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		for (int i = 1; i <= n; ++i)
			for (int j = 1; j <= n; ++j)
				g[i][j] = min(g[i][j], min(g[i][u] + w + g[v][j], g[i][v] + w + g[u][j]));
		ll ans = 0;
		for (int i = 1; i <= n; ++i)
			ans += accumulate(g[i] + i, g[i] + n + 1, 0);
		printf("%lld\n", ans);
	}
	return 0;
}