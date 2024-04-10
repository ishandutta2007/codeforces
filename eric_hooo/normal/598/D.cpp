#include <bits/stdc++.h>
using namespace std;

char a[1010][1010];
int vis[1010][1010];
int ans[1010][1010];
int totot[1000010];
queue <int> qx, qy;
int n, m, k;
int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};

void bfs(int x, int y) {
	qx.push(x), qy.push(y), vis[x][y] = 1, ans[x][y] = x * m + y;
	int tot = 0;
	while (!qx.empty()) {
		int x = qx.front(), y = qy.front(); qx.pop(), qy.pop();
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx < 0 || yy < 0 || xx >= n || yy >= m) continue;
			if (a[xx][yy] == '*') {
				tot++;
				continue;
			}
			if (vis[xx][yy]) continue;
			qx.push(xx), qy.push(yy), vis[xx][yy] = 1, ans[xx][yy] = ans[x][y];
		}
	}
	totot[x * m + y] = tot;
}

int main () {
	scanf("%d%d%d", &n, &m, &k);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (vis[i][j]) continue;
			if (a[i][j] == '*') continue;
			bfs(i, j);
		}
	}
	while (k--) {
		int x, y; scanf("%d%d", &x, &y);
		x--, y--;
		printf("%d\n", totot[ans[x][y]]);
	}
	return 0;
}