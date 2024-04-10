#include <cstdio>
#include <cstdlib>
#include <cstring>

#include <algorithm>
#include <tuple>
#include <vector>

#define LOG(FMT...) fprintf(stderr, FMT)

using namespace std;

const int N = 1010;

int n, rt;
int deg[N], leaf[N], pw[N], prt[N], sw[N];
bool vis[N];
vector<pair<int, int> > g[N];
vector<pair< pair<int, int>, int> > ans;

void gg() {
	puts("NO");
	exit(0);
}

void dfs(int u) {
	vis[u] = true;
	if (u != rt) {
		if (deg[prt[u]] == 2) {
			if (pw[u] != pw[prt[u]]) gg();
			prt[u] = prt[prt[u]];
		}
	}
	if (u != rt && deg[u] == 1) {
		leaf[u] = u;
		ans.push_back(make_pair(make_pair(rt, u), pw[u]));
	} else {
		int leaf1 = 0, leaf2 = 0;
		for (int i = 0; i < g[u].size(); ++i) {
			int v, w;
			tie(v, w) = g[u][i];
			if (!vis[v]) {
				pw[v] = w;
				prt[v] = u;
				dfs(v);
				if (!leaf1) {
					leaf1 = leaf[v];
				} else
					leaf2 = leaf[v];
			}
		}
		leaf[u] = leaf1;
		if (leaf2) {
			int goal = pw[u] - sw[u];
			ans.push_back(make_pair(make_pair(leaf1, leaf2), -goal / 2));
			ans.push_back(make_pair(make_pair(leaf1, rt), goal / 2));
			ans.push_back(make_pair(make_pair(rt, leaf2), goal / 2));
		}
	}
	if (deg[u] != 2)
		sw[prt[u]] += pw[u];
}

int main() {
//	freopen("a2.in", "r", stdin);
	scanf("%d", &n);
	for (int rep = 1; rep < n; ++rep) {
		int u, v, w;
		scanf("%d%d%d", &u, &v, &w);
		g[u].push_back(make_pair(v, w));
		g[v].push_back(make_pair(u, w));
		++deg[u]; ++deg[v];
	}
	rt = find(deg + 1, deg + n + 1, 1) - deg;
	dfs(rt);
	puts("YES");
	printf("%lu\n", ans.size());
	for (int i = 0; i < ans.size(); ++i)
		printf("%d %d %d\n", ans[i].first.first, ans[i].first.second, ans[i].second);
	return 0;
}