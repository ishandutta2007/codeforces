#include <bits/stdc++.h>
using namespace std;

char a[5010][5010];
short ll[5010][5010], rr[5010][5010], uu[5010][5010], dd[5010][5010];
int n, m;

void erase(int x, int y) {
	if (~uu[x][y]) dd[uu[x][y]][y] = dd[x][y];
	if (~dd[x][y]) uu[dd[x][y]][y] = uu[x][y];
	if (~ll[x][y]) rr[x][ll[x][y]] = rr[x][y];
	if (~rr[x][y]) ll[x][rr[x][y]] = ll[x][y];
}

int calc(int x, int y) {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			ll[i][j] = j == 1 ? -1 : a[i][j - 1] == '.' ? ll[i][j - 1] : j - 1;
			uu[i][j] = i == 1 ? -1 : a[i - 1][j] == '.' ? uu[i - 1][j] : i - 1;
		}
	}
	for (int i = n; i >= 1; i--) {
		for (int j = m; j >= 1; j--) {
			rr[i][j] = j == m ? -1 : a[i][j + 1] == '.' ? rr[i][j + 1] : j + 1;
			dd[i][j] = i == n ? -1 : a[i + 1][j] == '.' ? dd[i + 1][j] : i + 1;
		}
	}
	int cnt = 1;
	while (1) {
		if (a[x][y] == 'U') {
			if (uu[x][y] == -1) break;
			erase(x, y), x = uu[x][y];
		} else if (a[x][y] == 'D') {
			if (dd[x][y] == -1) break;
			erase(x, y), x = dd[x][y];
		} else if (a[x][y] == 'L') {
			if (ll[x][y] == -1) break;
			erase(x, y), y = ll[x][y];
		} else {
			if (rr[x][y] == -1) break;
			erase(x, y), y = rr[x][y];
		}
		cnt++;
	}
	return cnt;
}

int main () {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; i++) {
		scanf("%s", a[i] + 1);
	}
	int ans = -1, cnt = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i][j] == '.') continue;
			int tmp = calc(i, j);
			if (ans < tmp) ans = tmp, cnt = 1;
			else if (ans == tmp) cnt++;
		}
	}
	printf("%d %d\n", ans, cnt);
	return 0;
}