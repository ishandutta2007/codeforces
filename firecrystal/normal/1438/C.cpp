#include <cstdio>
#include <iostream>
using namespace std;
 
typedef long long LL;
 
const int N = 105;
 
int n, m, a[N][N];
 
int dx[4] = { 1, -1, 0, 0 };
int dy[4] = { 0, 0, -1, 1 };
 
int vis[N][N];
 
void inline dfs(int x, int y, int c) {
	vis[x][y] = c;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i], ny = y + dy[i];
		if (nx < 1 || nx > n || ny < 1 || ny > m || vis[nx][ny] != -1) continue;
		if (a[nx][ny] == a[x][y]) dfs(nx, ny, 1 - c);
		else if (a[nx][ny] == a[x][y] + 1 && c == 1) dfs(nx, ny, 1);
		else if (a[nx][ny] + 1 == a[x][y] && c == 0) dfs(nx, ny, 0); 
	}
}
 
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				scanf("%d", &a[i][j]);
				vis[i][j] = -1;
			}
		}		
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (vis[i][j] == -1) dfs(i, j, 0);
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) printf("%d ", a[i][j] + vis[i][j]);
			puts("");
		}
	}	
	return 0;
}