#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, int> piii;

int dist[25][25][1 << 8];
int dir[4][2] = {1, 0, 0, 1, -1, 0, 0, -1};
int change[25][25];
char s[25][25];
int a[25][25];
int val[10];
queue <piii> q;

int main () {
	int n, m; scanf("%d%d", &n, &m);
	pii S; int cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'S') S = mp(i, j);
			else if (s[i][j] >= '1' && s[i][j] <= '8') cnt++;
		}
	}
	for (int i = 0; i < cnt; i++) {
		scanf("%d", &val[i]);
	}
	int totot = cnt;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'S' || s[i][j] == '.') a[i][j] = 0;
			else if (s[i][j] == '#') a[i][j] = -1;
			else if ('1' <= s[i][j] && s[i][j] <= '8') a[i][j] = s[i][j] - '0';
			else a[i][j] = ++cnt;
		}
	}
	assert(cnt <= 8);
	for (int i = 0; i < n; i++) {
		for (int j = m - 1; j >= 0; j--) {
			change[i][j] = change[i][j + 1];
			if (a[i][j] > 0) change[i][j] |= (1 << a[i][j] - 1);
		}
	}
	memset(dist, -1, sizeof(dist));
	q.push(mp(S, 0)), dist[S.fi][S.se][0] = 0;
	while (!q.empty()) {
		piii t = q.front(); q.pop();
		int x = t.fi.fi, y = t.fi.se, mask = t.se;
		for (int i = 0; i < 4; i++) {
			int xx = x + dir[i][0], yy = y + dir[i][1];
			if (xx < 0 || xx >= n || yy < 0 || y >= m) continue;
			if (a[xx][yy] != 0) continue;
			int nmask = mask;
			if (i == 0) nmask ^= change[x][y];
			if (i == 2) nmask ^= change[xx][yy]; 
			if (dist[xx][yy][nmask] != -1) continue;
			dist[xx][yy][nmask] = dist[x][y][mask] + 1;
			q.push(mp(mp(xx, yy), nmask));
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << totot); i++) {
		if (dist[S.fi][S.se][i] == -1) continue;
		int sum = 0;
		for (int j = 0; j < totot; j++) {
			if (i >> j & 1) sum += val[j];
		}
		ans = max(ans, sum - dist[S.fi][S.se][i]);
	}
	printf("%d\n", ans);
	return 0;
}