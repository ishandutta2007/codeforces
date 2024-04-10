#include <bits/stdc++.h>
using namespace std;
 
int n,m;
int r,c;
int x,y;

int dist[2100][2100];
char board[2100][2100];
queue<pair<int, int>> q1, q2;

int dx[] = {-1,1,0,0};
int dy[] = {0,0,-1,1};

int main() {
	memset(dist,-1,sizeof(dist));
	scanf("%d %d", &n, &m);
	scanf("%d %d", &r, &c);
	scanf("%d %d", &x, &y);

	for (int i = 0; i < n; i++) scanf("%s", board[i]);

	r--; c--;
	dist[r][c] = 0;
	int cd = 0;
	q1.push({r,c});

	while (!q1.empty() || !q2.empty()) {
		if (q1.empty()) {
			swap(q1,q2);
			cd++;
		}

		int cx = q1.front().first, cy = q1.front().second;
		q1.pop();

		if (dist[cx][cy] != cd) continue;

		for (int d = 0; d < 4; d++) {
			int nx = cx + dx[d], ny = cy + dy[d];
			if (nx < 0 || nx >= n || ny < 0 || ny >= m || board[nx][ny] == '*') continue;
			int nd = cd + (d == 3);

			if (dist[nx][ny] == -1 || nd < dist[nx][ny]) {
				dist[nx][ny] = nd;
				if (nd != cd) q2.push({nx,ny});
				else q1.push({nx,ny});
			}
		}
	}

	int ans = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) if (dist[i][j] != -1) {
			int used_left = c - j + dist[i][j];
			int used_right = dist[i][j];

			if (used_left <= x && used_right <= y) ans++;
		}
	}
	printf("%d\n", ans);
}