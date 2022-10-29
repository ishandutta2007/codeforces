#include <cstdio>
#include <cstring>
#include <algorithm>
const int dx[4] = {-1, 0, 0, 1},
          dy[4] = {0, -1, 1, 0};
char s[101], a[51][51];
int n, m, xS, yS, len, p[4];

inline bool is_valid(int x, int y) {
	return 1 <= x && x <= n && 1 <= y && y <= m && a[x][y] != '#';
}

bool solve() {
	int curx = xS, cury = yS;
	for (int i = 0; i < len; ++i) {
		int nxtx = curx + dx[p[s[i] - '0']],
		    nxty = cury + dy[p[s[i] - '0']];
		if (!is_valid(nxtx, nxty))
			return false;
		else if (a[curx = nxtx][cury = nxty] == 'E')
			return true;
	}
	return false;
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 1; i <= n; ++i)
		scanf("%s", a[i] + 1);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j)
			if (a[i][j] == 'S')
				xS = i, yS = j;
	for (int i = 0; i < 4; ++i)
		p[i] = i;
	scanf("%s", s);
	len = strlen(s);
	int cnt = 0;
	for (int i = 0; i < 24; ++i) {
		cnt += solve();
		std::next_permutation(p, p + 4);
	}
	printf("%d", cnt);
}