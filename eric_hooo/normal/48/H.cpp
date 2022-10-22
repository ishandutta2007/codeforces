#include <bits/stdc++.h>
using namespace std;

char s[110][110];

int main () {
	int n, m, a, b, c; scanf("%d%d%d%d%d", &n, &m, &a, &b, &c);
	int x = 0, y = 0;
	while (a--) {
		s[x][y] = 'B', y++;
		if (y == m) x++, y = 0;
	}
	int p = x, q = y, tmp = m; c -= m;
	while (tmp--) {
		s[x][y] = x == p ? y - q & 1 ? '2' : '1' : q - y & 1 ? '1' : '2';
		y++;
		if (y == m) x++, y = 0;
	}
	while (b--) {
		s[x][y] = 'W', y++;
		if (y == m) x++, y = 0;
	}
	while (x != n) {
		int up = s[x - 1][y] == 'B' || s[x - 1][y] == '3' || s[x - 1][y] == '4';
		if (up) {
			if (y == 0) s[x][y] = '2';
			else if (s[x][y - 1] == 'B' || s[x][y - 1] == '2' || s[x][y - 1] == '3') s[x][y] = '1';
			else s[x][y] = '2';
		} else {
			if (y == 0) s[x][y] = '4';
			else if (s[x][y - 1] == 'W' || s[x][y - 1] == '4' || s[x][y - 1] == '1') s[x][y] = '3';
			else s[x][y] = '4';
		}
		y++;
		if (y == m) x++, y = 0;
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '1') printf("#/");
			else if (s[i][j] == '2') printf("\\#");
			else if (s[i][j] == '3') printf("./");
			else if (s[i][j] == '4') printf("\\.");
			else if (s[i][j] == 'W') printf("..");
			else printf("##");
		}
		printf("\n");
		for (int j = 0; j < m; j++) {
			if (s[i][j] == '1') printf("/.");
			else if (s[i][j] == '2') printf(".\\");
			else if (s[i][j] == '3') printf("/#");
			else if (s[i][j] == '4') printf("#\\");
			else if (s[i][j] == 'W') printf("..");
			else printf("##");
		}
		printf("\n");
	}
	return 0;
}