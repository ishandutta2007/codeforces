#include <bits/stdc++.h>

using namespace std;

int n, m, k, g[1010][1010], vis[1010][1010], ans[1000101], c = 1;
char s[1010];

int dx[] = {1, 0, -1, 0};
int dy[] = {0, 1, 0, -1};

void dfs(int x, int y, int comp) {
	if(vis[x][y] || !g[x][y]) return;
	vis[x][y] = comp;
	for(int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];
		if(!g[nx][ny]) ans[vis[x][y]]++;
		else dfs(nx, ny, comp);
	}
}

int main() {
	scanf("%d %d %d", &n, &m, &k);
	for(int i = 1; i <= n; i++) {
		scanf("%s", s);
		for(int j = 1; j <= m; j++)
			g[i][j] = (s[j-1] == '.');
	}
	
	for(int i = 1; i <= n; i++)
		for(int j = 1; j <= m; j++)
			if(g[i][j] && !vis[i][j])
				dfs(i, j, c++);
				
	for(int i = 0; i < k; i++) {
		int a, b;
		scanf("%d %d", &a, &b);
		printf("%d\n", ans[vis[a][b]]);
	}
	return 0;
}