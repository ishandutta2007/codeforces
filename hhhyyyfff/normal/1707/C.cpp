#include <bits/stdc++.h>

using namespace std;
#define N 100001
#define M 200001

vector<pair<int, int>> e[N];
vector<int> member[N], edge[N], bel[N];
int n, m, f[N], u[M], v[M], deg[N], ed[N][2];
int tim, dfn[N], low[N], tp, st[N], cnt, tp2, st2[M * 2];
bool chosen[M], vis[N], up[N], down[N], ans[N];

bool gmin(int& x, int y) { return x > y ? x = y, 1 : 0; }
int gf(int x) { return f[x] == x ? x : f[x] = gf(f[x]); }

void dfs(int u) {
	dfn[u] = low[u] = ++tim;
	st[++tp] = u;
	vis[u] = 1;
	for (auto i : e[u]) {
		if (dfn[i.first] && !vis[i.first]) continue;
		st2[++tp2] = i.second;
		if (!dfn[i.first]) {
			dfs(i.first);
			gmin(low[u], low[i.first]);
			if (dfn[u] == low[i.first]) {
				do {
					member[cnt].push_back(st[tp]);
					bel[st[tp]].push_back(cnt);
					vis[st[tp--]] = 0;
				} while (st[tp + 1] != i.first);
				member[cnt].push_back(u);
				bel[u].push_back(cnt);
				while (tp2 && (!vis[::u[st2[tp2]]] || !vis[v[st2[tp2]]]))
					edge[cnt].push_back(st2[tp2--]);
				++cnt;
			}
		} else gmin(low[u], dfn[i.first]);
	}
}

void DP1(int x, int y) {
	up[x] = 1;
	for (int i : member[x])
		if (i != y)
			for (int j : bel[i])
				if (j != x) {
					DP1(j, i);
					if (!up[j] || ed[j][0] != i && ed[j][1] != i)
						up[x] = 0;
				}
}

void DP2(int x, int y) {
	for (int i = 0; i < 2; ++i)
		if (ed[x][i] != y) {
			int cur = ed[x][i];
			bool flag = 1;
			for (int j : member[x])
				if (j != y && j != cur) {
					for (int k : bel[j])
						if (k != x && (!up[k] ||
								ed[k][0] != j && ed[k][1] != j)) {
							flag = 0;
							break;
						}
					if (!flag) break;
				}
			if (!flag) continue;
			int tmp = 0;
			for (int j : bel[cur])
				if (j != x && (!up[j] ||
						ed[j][0] != cur && ed[j][1] != cur))
					if (tmp) break; else tmp = j;
			if (tmp) {
				down[tmp] = 1;
				DP2(tmp, cur);
			} else for (int j : bel[cur]) if (j != x) {
				down[j] = 1;
				DP2(j, cur);
			}
		}
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i) f[i] = i;
	for (int i = 1; i <= m; ++i) {
		scanf("%d%d", &u[i], &v[i]);
		e[u[i]].push_back(make_pair(v[i], i));
		e[v[i]].push_back(make_pair(u[i], i));
		int x = gf(u[i]), y = gf(v[i]);
		if (x != y) {
			f[x] = y;
			chosen[i] = 1;
		}
	}
	dfs(1);
	for (int i = 0; i < cnt; ++i) {
		sort(edge[i].begin(), edge[i].end());
		int lst = 0;
		for (int j : edge[i])
			if (chosen[j] && lst != j)
				++deg[u[j]], ++deg[v[j]], lst = j;
		int c = 0;
		for (int j : member[i]) {
			if (deg[j] >= 3) {
				for (int k = 0; k < n; ++k) putchar('0');
				return 0;
			} else if (deg[j] == 1 && c < 2) ed[i][c++] = j;
			deg[j] = 0;
		}
	}
	DP1(0, 0);
	down[0] = 1;
	DP2(0, 0);
	for (int i = 0; i < cnt; ++i)
		if (up[i] && down[i])
			ans[ed[i][0]] = ans[ed[i][1]] = 1;
	for (int i = 1; i <= n; ++i) putchar(ans[i] + '0');
	return 0;
}