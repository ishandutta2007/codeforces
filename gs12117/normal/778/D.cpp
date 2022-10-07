#include<stdio.h>
int n, m;
char s[55][55];
int ans[100100][2];
int ansn;
void ansp(int x, int y) {
	if (s[x + 1][y] == 'U') {
		if (s[x + 1][y + 1] == 'L') {
			ansp(x + 1, y + 1);
		}
		s[x + 1][y] = 'L';
		s[x + 1][y + 1] = 'R';
		s[x + 2][y] = 'L';
		s[x + 2][y + 1] = 'R';
		ans[ansn][0] = x + 2;
		ans[ansn][1] = y + 1;
		ansn++;
	}
	s[x][y] = 'U';
	s[x][y + 1] = 'U';
	s[x + 1][y] = 'D';
	s[x + 1][y + 1] = 'D';
	ans[ansn][0] = x + 1;
	ans[ansn][1] = y + 1;
	ansn++;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'L')ansp(i, j);
		}
	}
	int bansn = ansn;
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == 'L')ansp(i, j);
		}
	}
	printf("%d\n", ansn);
	for (int i = 0; i < bansn; i++) {
		printf("%d %d\n", ans[i][0], ans[i][1]);
	}
	for (int i = ansn - 1; i >= bansn; i--) {
		printf("%d %d\n", ans[i][0], ans[i][1]);
	}
	return 0;
}