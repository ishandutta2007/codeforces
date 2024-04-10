#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 505, MOD = 998244353;
vector<int> edge[MAXN];
int que[MAXN], d[MAXN][MAXN], cnt[MAXN], n, m;

void bfs(int s, int *d) {
	int he = 1, ta = 0;
	que[++ta] = s;
	for (int i = 1; i <= n; i++) d[i] = -1;
	d[s] = 0;
	while (he <= ta) {
		int u = que[he++];
		for (int v : edge[u]) {
			if (d[v] < 0) d[que[++ta] = v] = d[u] + 1;
		}
	}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v; scanf("%d%d", &u, &v);
		edge[u].push_back(v);
		edge[v].push_back(u);
	}
	for (int i = 1; i <= n; i++) bfs(i, d[i]);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int dij = d[i][j];
			memset(cnt, 0, sizeof(cnt));
			LL mul = 1;
			for (int k = 1; k <= n; k++) if (k != i && k != j) {
				if (d[i][k] + d[j][k] == dij) ++cnt[d[i][k]];
				else {
					int c = 0;
					for (int v : edge[k]) {
						if (d[i][v] + 1 == d[i][k] && d[j][v] + 1 == d[j][k])
							++c;
					}
					mul = mul * c % MOD;
				}
			}
			for (int k = 1; k < dij; k++) if (cnt[k] > 1) mul = 0;
			printf("%lld ", mul);
		}
		puts("");
	}
	return 0;
}