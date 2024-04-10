#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

int col[2010][1010];
int ttt[100010];
int sum[2010];
vector <pii> from[2010];
int ans;

void solve(int x, int y, int c1, int c2, int id) {
	int tmp = col[y][c1];
	col[x][c1] = col[y][c1] = id;
	if (tmp == 0) {
		col[y][c2] = 0;
		return ;
	}
	solve(y, sum[tmp] - y, c2, c1, tmp);
}

int main () {
	int n, m, q;
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= q; i++) {
		int x, y; scanf("%d%d", &x, &y), y += n;
		from[x].push_back(mp(y, i)), from[y].push_back(mp(x, i));
		sum[i] = x + y;
	}
	for (int i = 1; i <= n + m; i++) {
		ans = max(ans, (int)from[i].size());
	}
	for (int x = 1; x <= n; x++) {
		for (int j = 0; j < from[x].size(); j++) {
			int y = from[x][j].fi, id = from[x][j].se;
			int p1 = 1, p2 = 1;
			while (col[x][p1]) p1++;
			while (col[y][p2]) p2++;
			if (p1 == p2) {
				col[x][p1] = col[y][p2] = id;
				continue;
			}
			solve(x, y, p1, p2, id);
		}
	}
	printf("%d\n", ans);
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= ans; j++) {
			ttt[col[i][j]] = j;
		}
	}
	for (int i = 1; i <= q; i++) {
		printf("%d ", ttt[i]);
	}
	printf("\n");
	return 0;
}