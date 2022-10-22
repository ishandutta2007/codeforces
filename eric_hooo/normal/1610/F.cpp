#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n, m;
vector <int> G[300010][2];
vector <pii> edg;
int vis[600010];
int fa[600010], del[600010];
int ans[600010];
int sum[600010];
int dead[600010];
vector <int> node;

void Flush(vector <int> &a) {while (a.size() && vis[a.back()]) a.pop_back();}

int dfs(int x, int y, int p) {
	if (x == y) return 600005;
	Flush(G[x][p]);
	if (G[x][p].size()) {
		int e = G[x][p].back();
		vis[e] = 1, del[e] = edg[e].se != x;
		return fa[e] = dfs(edg[e].fi + edg[e].se - x, y, p);
	}
	Flush(G[y][p]);
	if (G[y][p].size()) {
		int e = G[y][p].back();
		vis[e] = 1, del[e] = edg[e].fi != y;
		return fa[e] = dfs(x, edg[e].fi + edg[e].se - y, p);
	}
	int id = edg.size(); edg.push_back(mp(x, y));
	G[x][p].push_back(id), G[y][p].push_back(id);
	return id;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y, w; scanf("%d%d%d", &x, &y, &w), w--;
		edg.push_back(mp(x, y));
		G[x][w].push_back(i);
		G[y][w].push_back(i);
	}
	for (int i = 1; i <= n; i++) {
		for (int p = 0; p < 2; p++) {
			auto Calc = [&](int x) -> void {
				if (vis[x]) G[i][p].pop_back();
				else vis[x] = 1, fa[x] = dfs(edg[x].fi, edg[x].se, p), del[x] = 0;
			};
			while (G[i][p].size() > 1) Calc(G[i][p].back());
		}
	}
	for (int i = 1; i <= n; i++) {
		Flush(G[i][0]), Flush(G[i][1]);
	}
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		if (dead[i]) continue;
		int N = 0, E = 0; node.clear();
		auto dfs = [&](int x, auto dfs) -> void {
			dead[x] = 1, N++, E += G[x][0].size() + G[x][1].size(), node.push_back(x);
			for (auto e : G[x][0]) {
				int v = edg[e].fi + edg[e].se - x;
				if (!dead[v]) dfs(v, dfs);
			}
			for (auto e : G[x][1]) {
				int v = edg[e].fi + edg[e].se - x;
				if (!dead[v]) dfs(v, dfs);
			}
		};
		dfs(i, dfs);
		E /= 2;
		if (N == E) {
			int ban = G[i][0].back();
			sum[edg[ban].fi]--, sum[edg[ban].se]++, ans[ban] = 0;
			for (auto x : node) {
				if (G[x][0].back() == ban) G[x][0].pop_back();
			}
		}
		for (auto x : node) {
			dead[x] = 0;
		}
		auto GetAns = [&](int x, auto GetAns) -> void {
			dead[x] = 1;
			for (auto e : G[x][0]) if (!vis[e]) {
				int v = edg[e].fi + edg[e].se - x;
				if (!dead[v]) {
					if (sum[x] > 0) sum[x]--, sum[v]++, ans[e] = edg[e].fi != x;
					else sum[x]++, sum[v]--, ans[e] = edg[e].fi != v;
					if (abs(sum[x]) == 1) tot++;
					GetAns(v, GetAns);
					return ;
				}
			}
			for (auto e : G[x][1]) if (!vis[e]) {
				int v = edg[e].fi + edg[e].se - x;
				if (!dead[v]) {
					if (sum[x] > 0) sum[x] -= 2, sum[v] += 2, ans[e] = edg[e].fi != x;
					else sum[x] += 2, sum[v] -= 2, ans[e] = edg[e].fi != v;
					if (abs(sum[x]) == 1) tot++;
					GetAns(v, GetAns);
					return ;
				}
			}
			if (abs(sum[x]) == 1) tot++;
		};
		for (auto x : node) {
			if (G[x][0].size() + G[x][1].size() == 1) {
				GetAns(x, GetAns);
				break;
			}
		}
	}
	for (int i = edg.size() - 1; i >= 0; i--) {
		if (vis[i]) ans[i] = ans[fa[i]] ^ del[i];
	}
	printf("%d\n", tot);
	for (int i = 0; i < m; i++) {
		printf(ans[i] ? "2" : "1");
	}
	printf("\n");
	return 0;
}