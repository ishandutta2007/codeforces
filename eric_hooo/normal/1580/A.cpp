#include <bits/stdc++.h>
using namespace std;

char s[410][410];
int sum[410][410];
int a[410], b[410];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, m; scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%s", s[i] + 1);
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= m; j++) {
				sum[i][j] = sum[i][j - 1] + (s[i][j] == '1');
			}
		}
		int ans = 0x3f3f3f3f;
		for (int l = 1; l <= m; l++) {
			for (int r = l + 3; r <= m; r++) {
				for (int i = 1; i <= n; i++) {
					a[i] = r - l - 1 - sum[i][r - 1] + sum[i][l];
					b[i] = sum[i][r - 1] - sum[i][l] + (s[i][l] == '0') + (s[i][r] == '0');
					b[i] += b[i - 1];
				}
				int minj = 0x3f3f3f3f;
				for (int i = 5; i <= n; i++) {
					minj = min(minj, a[i - 4] - b[i - 4]);
					ans = min(ans, minj + a[i] + b[i - 1]);
				}
			}
		}
		printf("%d\n", ans);
	}
	return 0;
}