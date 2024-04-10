#include<cstdio>
#include<cstring>
int n, m;
char a[55][55];
char s[110];
int sl;
int dir[4][2] = { {1,0},{0,1},{-1,0},{0,-1} };
int sx, sy;
int dmap[4];
int ans;
int invalid_place(int x, int y) {
	if (x < 0 || y < 0 || x >= n || y >= m || a[x][y] == '#')return 1;
	return 0;
}
void search() {
	int x = sx;
	int y = sy;
	for (int i = 0; i < sl; i++) {
		int d = dmap[s[i] - '0'];
		x += dir[d][0];
		y += dir[d][1];
		if (invalid_place(x, y))break;
		if (a[x][y] == 'E') {
			ans++;
			break;
		}
	}
}
void btrk(int dep) {
	if (dep == 4) {
		search();
	}
	else {
		for (int i = 0; i < 4; i++) {
			int flag = 0;
			for (int j = 0; j < dep; j++) {
				if (dmap[j] == i) {
					flag = 1;
				}
			}
			if (flag == 0) {
				dmap[dep] = i;
				btrk(dep + 1);
			}
		}
	}
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", a[i]);
	}
	scanf("%s", s);
	sl = strlen(s);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (a[i][j] == 'S') {
				sx = i;
				sy = j;
			}
		}
	}
	ans = 0;
	btrk(0);
	printf("%d", ans);
	return 0;
}