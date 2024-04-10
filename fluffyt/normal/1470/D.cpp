#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 300005;
vector<int> gra[MAXN];
int T, n, m, vis[MAXN], clr[MAXN];
void dfs(int u) {
	int t = 0;
	for (int v : gra[u])
		if (clr[v]) t = 1;
	if (!t) clr[u] = 1;
	vis[u] = 1;
	for (int v : gra[u]) {
		if (vis[v]) continue;
		dfs(v);
	}
}

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= m; i++) {
			int u, v; scanf("%d%d", &u, &v);
			gra[u].push_back(v);
			gra[v].push_back(u);
		}
		dfs(1);
		int flag = 1;
		for (int i = 1; i <= n; i++) if (!vis[i]) flag = 0;
		if (!flag) puts("NO");
		else {
			puts("YES");
			int c = 0;
			for (int i = 1; i <= n; i++) c += clr[i];
			printf("%d\n", c);
			for (int i = 1; i <= n; i++) {
				if (clr[i]) printf("%d ", i);
			}
			puts("");
		}
		for (int i = 1; i <= n; i++) clr[i] = vis[i] = 0;
		for (int i = 1; i <= n; i++) gra[i].clear();
	}
	return 0;
}