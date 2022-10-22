#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int n, m;
int a[200010];
int d[200010], len[200010];
int vis[200010];
vector <int> ans;
vector <pii> G[200010];
int val[200010];
set <int> S[3];
int X[200010], Y[200010];

void Modify(int x, int v) {
	S[val[x]].erase(x), val[x] += v, S[val[x]].insert(x);
}

int GetDist(int x, int y) {
	return d[x] < d[y] ? d[y] - d[x] : d[y] + len[x] - d[x];
}

void Flush(int x) {
	G[x].pop_back();
	if (G[x].size()) Modify(G[x].back().se, 1);
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		X[i] = x, Y[i] = y;
		G[x].push_back(mp(y, i));
		G[y].push_back(mp(x, i));
		S[0].insert(i);
	}
	for (int i = 1; i <= n; i++) {
		if (vis[i]) continue;
		int cur = i, cnt = 0; while (!vis[cur]) vis[cur] = 1, d[cur] = cnt, cnt++, cur = a[cur];
		cur = i; while (vis[cur] == 1) vis[cur] = 2, len[cur] = cnt, cur = a[cur];
	}
	for (int i = 1; i <= n; i++) {
		sort(G[i].begin(), G[i].end(), [&](auto x, auto y) -> bool {return GetDist(i, x.fi) > GetDist(i, y.fi);});
		if (G[i].size()) Modify(G[i].back().se, 1);
	}
	while (S[2].size()) {
		int id = *S[2].begin(); S[2].erase(S[2].begin());
		ans.push_back(id);
		Flush(X[id]), Flush(Y[id]);
	}
	for (auto it : ans) {
		printf("%d ", it);
	}
	printf("\n");
	return 0;
}