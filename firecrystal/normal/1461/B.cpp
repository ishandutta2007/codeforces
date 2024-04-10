#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 505;

int n, m, s[N][N];

char g[N][N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", g[i] + 1);
			for (int j = 1; j <= m; j++) {
				s[i][j] = s[i][j - 1] + (g[i][j] == '.');
			}
		}
		int ans = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				if (g[i][j] == '*') {
					int k = 1;
					while (i + k <= n && j - k > 0 && j + k <= m && s[i + k][j + k] - s[i + k][j - k - 1] == 0) 
						k++;
					ans += k;
				}
			}
		}
		printf("%d\n", ans);
	}	
	return 0;
}