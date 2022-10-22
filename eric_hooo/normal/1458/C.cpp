#include <bits/stdc++.h>
#define REAL(x) (((((x) - 1) % n + n) % n) + 1)
using namespace std;

int a[1010][1010], ans[1010][1010];
char s[100010];
int p[3], q[3];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		scanf("%s", s);
		p[0] = 0, p[1] = 1, p[2] = 2, q[0] = q[1] = q[2] = 0;
		for (int i = 0; i < m; i++) {
			if (s[i] == 'L') q[1]--;
			else if (s[i] == 'R') q[1]++;
			else if (s[i] == 'U') q[0]--;
			else if (s[i] == 'D') q[0]++;
			else if (s[i] == 'I') swap(p[1], p[2]), swap(q[1], q[2]);
			else if (s[i] == 'C') swap(p[0], p[2]), swap(q[0], q[2]);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				int val[3] = {i, j, a[i][j]};
				int x = REAL(val[p[0]] + q[0]), y = REAL(val[p[1]] + q[1]), z = REAL(val[p[2]] + q[2]);
				ans[x][y] = z;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				printf("%d ", ans[i][j]);
			}
			printf("\n");
		}
	}
	return 0;
}