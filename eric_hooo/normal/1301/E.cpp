#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, pii> ppp;
typedef pair <ppp, int> pppp;

char a[510][510];
int nxt[510][510];
int sum[4][510][510];
short T[501][501][501];
int n, m;
int last;

void modify(int x, int y, int z, int val) {
	for (int nx = x; nx <= m; nx += nx & -nx) {
		for (int ny = y; ny <= n; ny += ny & -ny) {
			for (int nz = z; nz <= m; nz += nz & -nz) {
				if (T[nx][ny][nz] < val) T[nx][ny][nz] = val;
			}
		}
	}
}

int query(int x, int y, int z) {
	int res = 0;
	for (int nx = x; nx; nx -= nx & -nx) {
		for (int ny = y; ny; ny -= ny & -ny) {
			for (int nz = z; nz; nz -= nz & -nz) {
				if (res < T[nx][ny][nz]) res = T[nx][ny][nz];
			}
		}
	}
	return res;
}

int get_sum(int sum[510][510], int a, int b, int c, int d) {
	return sum[c][d] - sum[a - 1][d] - sum[c][b - 1] + sum[a - 1][b - 1];
}

int check(int x, int y) {
	if (a[x][y] != 'R') return -1;
	int len = nxt[x][y] - y;
	if (x + len + len - 1 > n || y + len + len - 1 > m) return -1;
	int s1 = get_sum(sum[0], x, y, x + len - 1, y + len - 1);
	int s2 = get_sum(sum[1], x, y + len - 1, x + len - 1, y + len + len - 1);
	int s3 = get_sum(sum[2], x + len - 1, y, x + len + len - 1, y + len - 1);
	int s4 = get_sum(sum[3], x + len - 1, y + len - 1, x + len + len - 1, y + len + len - 1);
	return s1 == len * len && s2 == len * len && s3 == len * len && s4 == len * len ? len : -1;
}

int ans[300010];

int main () {
	int q; scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
		for (int j = m; j >= 1; j--) {
			nxt[i][j] = a[i][j] == a[i][j + 1] ? nxt[i][j + 1] : j + 1;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			for (int k = 0; k < 4; k++) {
				sum[k][i][j] = sum[k][i - 1][j] + sum[k][i][j - 1] - sum[k][i - 1][j - 1];
			}
			if (a[i][j] == 'R') sum[0][i][j]++;
			else if (a[i][j] == 'G') sum[1][i][j]++;
			else if (a[i][j] == 'Y') sum[2][i][j]++;
			else if (a[i][j] == 'B') sum[3][i][j]++;
		}
	}
	vector <pppp> all;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int len = check(i, j);
			if (len != -1) {
				all.push_back(mp(mp(mp(n - i + 1, m - j + 1), mp(i + 2 * len - 1, j + 2 * len - 1)), len));
			}
		}
	}
	sort(all.begin(), all.end());
	vector <pppp> que;
	for (int i = 0; i < q; i++) {
		int a, b, c, d; scanf("%d%d%d%d", &a, &b, &c, &d);
		que.push_back(mp(mp(mp(n - a + 1, m - b + 1), mp(c, d)), i));
	}
	sort(que.begin(), que.end());
	int p1 = 0, p2 = 0;
	for (int it = 1; it <= n; it++) {
		while (p1 < all.size() && all[p1].fi.fi.fi == it) {
			modify(all[p1].fi.fi.se, all[p1].fi.se.fi, all[p1].fi.se.se, all[p1].se);
			p1++;
		}
		while (p2 < que.size() && que[p2].fi.fi.fi == it) {
			ans[que[p2].se] = query(que[p2].fi.fi.se, que[p2].fi.se.fi, que[p2].fi.se.se);
			p2++;
		}
	}
	for (int i = 0; i < q; i++) {
		printf("%d\n", 4 * ans[i] * ans[i]);
	}
	return 0;
}