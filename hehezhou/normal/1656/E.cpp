#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
int T;
int n;
int ans[100010];
vector < int > son[100010];
void dfs(int cur, int fa, int dep = 0) {
	if (dep == 0) ans[cur] = son[cur].size();
	else ans[cur] = -(int)son[cur].size();
	for (auto i : son[cur]) if (i != fa) dfs(i, cur, dep ^ 1);
}
void rmain() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) son[i].clear();
	for (int i = 1; i < n; i++) {
		int u, v;
		scanf("%d%d", &u, &v);
		son[u].push_back(v);
		son[v].push_back(u);
	}
	dfs(1, 0);
	for (int i = 1; i <= n; i++) printf("%d%c", ans[i], " \n"[i == n]);
}
int main() {
	scanf("%d", &T);
	while (T--) rmain();
}