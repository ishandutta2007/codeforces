#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 200013
int N;
vector<pair<int, bool> > adj[MAXN];
int cpt[MAXN][2];
bool vis[MAXN][2];
int C = 0;
int sz[2 * MAXN];

void dfs(int n, int b) {
	if (vis[n][b])
		return;
	vis[n][b] = true;
	cpt[n][b] = C;
	sz[C]++;
	for (auto p : adj[n])
		if (p.second == b)
			dfs(p.first, b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 0; i < N - 1; i++) {
		int x, y, c;
		cin >> x >> y >> c;
		--x, --y;
		adj[x].emplace_back(y, c);
		adj[y].emplace_back(x, c);
	}

	LL ans = 0;

	for (int i = 0; i < N; i++) {
		if (!vis[i][0]) {
			dfs(i, 0);
			ans += (LL) sz[C] * (sz[C] - 1);
			++C;
		}
	}

	for (int i = 0; i < N; i++) {
		if (!vis[i][1]) {
			dfs(i, 1);
			ans += (LL) sz[C] * (sz[C] - 1);
			++C;
		}
	}

	for (int i = 0; i < N; i++) {
		ans += (LL) (sz[cpt[i][0]] - 1) * (sz[cpt[i][1]] - 1);
	}

	cout << ans << endl;
	return 0;
}