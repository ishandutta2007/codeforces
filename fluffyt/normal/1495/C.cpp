#include <bits/stdc++.h>
using namespace std;
typedef long long LL;

const int MAXN = 505;
char s[MAXN][MAXN];
int T, n, m;

int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++)
			scanf("%s", s[i] + 1);
		for (int i = 1; i <= n; i += 3) {
			for (int j = 1; j <= m; j++) s[i][j] = 'X';
			if (i + 3 <= n) {
				if (m > 1 && (s[i + 1][2] == 'X' || s[i + 2][2] == 'X'))
					s[i + 1][2] = s[i + 2][2] = 'X';
				else s[i + 1][1] = s[i + 2][1] = 'X';
			} else if (i + 2 <= n) {
				for (int j = 1; j <= m; j++)
					if (s[i + 2][j] == 'X') s[i + 1][j] = 'X';
			}
		}
		for (int i = 1; i <= n; i++)
			puts(s[i] + 1);
	}
	return 0;
}