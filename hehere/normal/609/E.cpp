#include <bits/stdc++.h>
using std::cin; using std::pair; using std::vector;
typedef pair<int, int> pii;
typedef long long LL;
const int maxN = 200000 + 233;
const int maxM = 200000 + 233;
int n, m;
struct Edge {
	int x, y, z, id;
	Edge() {}
	Edge(int x, int y, int z, int id) : x(x), y(y), z(z), id(id) {}
	bool operator < (const Edge &rhs) const {
		return z < rhs.z;
	}
}edges[maxM];
vector<pii> G[maxN];
int f[20][maxN], g[20][maxN], dep[maxN];
int ans[maxM];

int pa[maxN];
int findset(int x) {
	return pa[x] != x ? pa[x] = findset(pa[x]) : x;
}

void DFS(int u, int fa) {
	for(vector<pii>::iterator p = G[u].begin(); p != G[u].end(); ++p) {
		int v = p->first, w = p->second;
		if(v == fa) continue;
		f[0][v] = u; g[0][v] = w; dep[v] = dep[u] + 1;
		DFS(v, u);
	}
}

bool chmax(int &a, const int &b) {
	return a < b ? a = b, true : false;
}

int LCA(int x, int y) {
	if(dep[x] < dep[y]) std::swap(x, y);
	int dif = dep[x] - dep[y], ans = 0;
	for(int i = 0; i < 20; ++i) if(dif >> i & 1)
		chmax(ans, g[i][x]), x = f[i][x];
	if(x == y) return ans;
	for(int i = 19; i >= 0; --i) if(f[i][x] != f[i][y])
		chmax(ans, g[i][x]), chmax(ans, g[i][y]),
		x = f[i][x], y = f[i][y];
	chmax(ans, g[0][x]); chmax(ans, g[0][y]);
	return ans;
}

int main() {
	std::ios::sync_with_stdio(false);
	cin >> n >> m;
	for(int i = 1; i <= m; ++i) {
		int x, y, z; cin >> x >> y >> z;
		edges[i] = Edge(x, y, z, i);
	}
	memset(ans, 0, sizeof(ans));
	std::sort(edges + 1, edges + m + 1);
	LL tot = 0;
	int cnt = 0;
	for(int u = 1; u <= n; ++u) pa[u] = u;
	for(int i = 1; i <= m; ++i) {
		int x = edges[i].x, y = edges[i].y;
		int fx = findset(x), fy = findset(y);
		if(fx == fy) continue; else ++cnt;
		pa[fx] = fy;
		tot += edges[i].z;
		ans[edges[i].id] = -1;
		G[x].push_back(pii(y, edges[i].z));
		G[y].push_back(pii(x, edges[i].z));
	}
	assert(cnt == n - 1);
	f[0][1] = 0; g[0][1] = 0; dep[1] = 1;
	DFS(1, -1);
	for(int k = 1; k < 20; ++k)
		for(int u = 1; u <= n; ++u)
			f[k][u] = f[k - 1][f[k - 1][u]],
			g[k][u] = std::max(g[k - 1][u], g[k - 1][f[k - 1][u]]);
	for(int i = 1; i <= m; ++i) {
		int o = edges[i].id;
		if(ans[o] == -1) ans[o] = 0;
		else ans[o] = -LCA(edges[i].x, edges[i].y) + edges[i].z;
	}
	for(int i = 1; i <= m; ++i) {
		printf("%lld\n", tot + ans[i]);
	}
	return 0;
}