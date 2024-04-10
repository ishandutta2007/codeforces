#include <bits/stdc++.h>
using namespace std;

int last[5010][5010];
bool dp[5010][5010];
int vis[5010], TT[5010], CC[5010][2];
int cnt[2];
vector <int> from[5010];
int A, B, C;

bool dfs(int x, int col) {
	vis[x] = col, cnt[col]++;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (vis[v] != -1 && vis[v] == vis[x]) return 1;
		if (vis[v] == -1) {
			if (dfs(v, col ^ 1)) return 1;
		}
	}
	return 0;
}

void color(int x, int c, int CCC) {
	if (c == CCC) vis[x] = 2;
	else {
		if (A) A--, vis[x] = 1;
		else vis[x] = 3;
	}
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i];
		if (~vis[v]) continue;
		color(v, c ^ 1, CCC);
	}
}

int main () {
	memset(vis, -1, sizeof(vis));
	int n, m; scanf("%d%d", &n, &m);
	scanf("%d%d%d", &A, &B, &C);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		from[x].push_back(y);
		from[y].push_back(x);
	}
	dp[0][0] = 1; int now = 0;
	for (int i = 1; i <= n; i++) {
		if (~vis[i]) continue;
		cnt[0] = cnt[1] = 0;
		if (dfs(i, 0)) {
			printf("NO\n");
			return 0;
		}
		for (int j = 0; j <= n; j++) {
			if (!dp[now][j]) continue;
			dp[now + 1][j + cnt[0]] = 1;
			last[now + 1][j + cnt[0]] = 0;
			dp[now + 1][j + cnt[1]] = 1;
			last[now + 1][j + cnt[1]] = 1;
		}
		now++;
		CC[now][0] = cnt[0], CC[now][1] = cnt[1];
	}
	if (!dp[now][B]) {
		printf("NO\n");
		return 0;
	}
	printf("YES\n");
	int x = now, y = B;
	while (x) {
		TT[x] = last[x][y];
		y -= CC[x][last[x][y]];
		x--;
	}
	memset(vis, -1, sizeof(vis));
	now = 0;
	for (int i = 1; i <= n; i++) {
		if (~vis[i]) continue;
		++now;
		color(i, 0, TT[now]);
	}
	for (int i = 1; i <= n; i++) {
		printf("%d", vis[i]);
	}
	printf("\n");
	return 0;
}