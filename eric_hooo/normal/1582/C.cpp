#include <bits/stdc++.h>
using namespace std;

char s[100010];
char t[100010];
int a[100010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		scanf("%s", s);
		int ans = 0x3f3f3f3f;
		for (char c = 'a'; c <= 'z'; c++) {
			int m = 0, cnt = 0;
			for (int i = 0; i < n; i++) {
				if (s[i] != c) a[m] = cnt, cnt = 0, t[m++] = s[i];
				else cnt++;
			}
			a[m] = cnt, cnt = 0;
			int ok = 1;
			for (int i = 0; i < m; i++) {
				if (t[i] != t[m - i - 1]) ok = 0;
			}
			if (!ok) continue;
			int sum = 0;
			for (int i = 0; i < m; i++) {
				int j = m - i - 1;
				if (i > j + 1) break;
				if (i == j + 1) sum += 0;
				else {
					sum += a[i] + a[j + 1] - 2 * min(a[i], a[j + 1]);
				}
			}
			ans = min(ans, sum);
		}
		if (ans == 0x3f3f3f3f) ans = -1;
		printf("%d\n", ans);
	}
	return 0;
}