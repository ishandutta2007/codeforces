#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

vector <pii> G[200010];
int dp[200010];
vector <int> ord[200010];
int alive[200010];
int X[200010], Y[200010];
queue <int> q;

void Flush(int x) {
	if (!ord[x].size()) return ;
	alive[ord[x].back()]++;
	if (alive[ord[x].back()] == 2) q.push(ord[x].back());
}

void dfs(int x, int last) {
	for (auto it : G[x]) if (it.fi != last) {
		dfs(it.fi, x);
	}
	static int cnt[4]; memset(cnt, 0, sizeof(cnt));
	for (auto it : G[x]) if (it.fi != last) {
		cnt[dp[it.fi]]++;
	}
	int k = G[x].size() >> 1;
	if (cnt[0]) dp[x] = 0;
	else dp[x] = (cnt[2] <= k && cnt[2] + cnt[3] >= k) | (int)(cnt[2] <= k - 1 && cnt[2] + cnt[3] >= k - 1) << 1;
}

void rec(int x, int last, int up) {
	ord[x].resize(G[x].size());
	int need = G[x].size() / 2 - up, p = 0, q = 1;
	for (auto it : G[x]) {
		if (it.fi != last) {
			int v = it.fi;
			if (dp[v] == 1) rec(v, x, 0), ord[x][p] = it.se, p += 2;
			else if (dp[v] == 2) rec(v, x, 1), ord[x][q] = it.se, q += 2;
			else if (need) rec(v, x, 1), need--, ord[x][q] = it.se, q += 2;
			else rec(v, x, 0), ord[x][p] = it.se, p += 2;
		} else {
			if (up) ord[x][q] = it.se, q += 2;
			else ord[x][p] = it.se, p += 2;
		}
	}
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			G[i].clear();
		}
		for (int i = 1; i < n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			G[x].push_back(mp(y, i)), G[y].push_back(mp(x, i));
			X[i] = x, Y[i] = y, alive[i] = 0;
		}
		dfs(1, 1);
		if (!(dp[1] & 1)) {
			printf("NO\n");
			continue;
		}
		printf("YES\n");
		rec(1, 1, 0);
		for (int i = 1; i <= n; i++) {
			Flush(i);
		}
		while (!q.empty()) {
			int id = q.front(); q.pop();
			int x = X[id], y = Y[id];
			printf("%d %d\n", x, y);
			ord[x].pop_back(), Flush(x), ord[y].pop_back(), Flush(y);
		}
	}
	return 0;
}