#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod = 3;
int T, n, m;
int id[70][70];
int e[270][270];
int col[270], rid[270], ans[270], cnt;
struct node {
	int a, b, c;
};
vector < node > qwq;
void rmain() {
	memset(id, 0, sizeof id);
	memset(e, 0, sizeof e);
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v;
		scanf("%d%d%d", &u, &v, col + i);
		id[u][v] = id[v][u] = i;
	}
	cnt = 0;
	for (int i = 1; i <= m; i++) if (col[i] == -1) rid[i] = ++cnt, ans[rid[i]] = col[i];
	for (int i = 1; i <= m; i++) if (col[i] != -1) rid[i] = ++cnt, ans[rid[i]] = col[i];
	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++) id[i][j] = rid[id[i][j]];
	qwq.clear();
	for (int a = 1; a <= n; a++)
		for (int b = a + 1; b <= n; b++)
			for (int c = b + 1; c <= n; c++) {
				if (id[a][b] && id[b][c] && id[c][a]) qwq.push_back({id[a][b], id[b][c], id[c][a]});
			}
	for (int i = 1; i <= m; i++) {
		for (auto j : qwq) {
			int a = j.a, b = j.b, c = j.c;
			int cur = e[a][i] + e[b][i] + e[c][i];
			cur = 9 - cur;
			cur += (a == i) + (b == i) + (c == i);
			cur %= 3;
			if (cur == 0) continue;
			e[i][a] = e[i][b] = e[i][c] = 1;
			for (int x = 1; x < i; x++) {
				if (e[i][x]) {
					assert(e[x][x]);
					int k = 3 - e[i][x];
					for (int j = x; j <= m; j++) e[i][j] = (e[i][j] + e[x][j] * k) % mod;
				}
			}
			assert(e[i][i]);
			if (e[i][i] == 2) {
				for (int j = i; j <= m; j++) e[i][j] = e[i][j] * 2 % mod;
			}
			for (int x = 1; x < i; x++) {
				if (e[x][i]) {
					int k = 3 - e[x][i];
					for (int j = i; j <= m; j++) e[x][j] = (e[x][j] + e[i][j] * k) % mod;
				}
			}
		}
		// for (int i = 1; i <= m; i++)
		// 	for (int j = 1; j <= m; j++) cerr << e[i][j] << " \n"[j == m];
		// cerr << endl;
	}
	for (int i = m; i > 0; i--) {
		if (ans[i] == -1) ans[i] = e[i][m + 1];
		for (int j = i; j > 0; j--) e[j][m + 1] = (e[j][m + 1] + mod * mod - ans[i] * e[j][i]) % mod;
		if (e[i][m + 1]) {
			puts("-1");
			return;
		}
	}
	for (int i = 1; i <= m; i++) col[i] = ans[rid[i]] == 0 ? 3 : ans[rid[i]];
	for (int i = 1; i <= m; i++) printf("%d%c", col[i], " \n"[i == m]);
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}