#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 605;
LL mp[MAXN][MAXN];
int n, m, Q, val[MAXN][MAXN], mat[MAXN][MAXN], ans[MAXN][MAXN];

int main() {
	int n, m; scanf("%d%d", &n, &m);
	memset(mp, 0x3f, sizeof(mp));
	for (int i = 1; i <= m; i++) {
		int u, v, w; scanf("%d%d%d", &u, &v, &w);
		mp[u][v] = mp[v][u] = w;
		mat[u][v] = mat[v][u] = w;
	}
	for (int i = 1; i <= n; i++) mp[i][i] = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j <= n; j++)
	for (int k = 1; k <= n; k++)
		mp[j][k] = min(mp[j][k], mp[i][j] + mp[i][k]);
	scanf("%d", &Q);
	for (int i = 1; i <= Q; i++) {
		int u, v, l; scanf("%d%d%d", &u, &v, &l);
		val[u][v] = max(val[u][v], l);
		val[v][u] = max(val[v][u], l);
	}
	for (int u = 1; u <= n; u++) {
		for (int i = 1; i <= n; i++) {
			LL mx = 0;
			for (int v = 1; v <= n; v++) if (val[u][v])
				mx = max(mx, val[u][v] - mp[i][v]);
			for (int j = 1; j < i; j++) if (mat[i][j]) {
				ans[i][j] |= mat[i][j] + mp[u][j] <= mx;
			}
		}
	}
	int sum = 0;
	for (int i = 1; i <= n; i++)
	for (int j = 1; j < i; j++) sum += ans[i][j];
	printf("%d\n", sum);
	return 0;
}