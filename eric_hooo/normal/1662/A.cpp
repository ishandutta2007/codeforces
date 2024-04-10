#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		static int maxj[20]; memset(maxj, -1, sizeof(maxj));
		for (int i = 0; i < n; i++) {
			int x, y; scanf("%d%d", &x, &y);
			maxj[y] = max(maxj[y], x);
		}
		int ans = 0;
		for (int i = 1; i <= 10; i++) {
			if (maxj[i] == -1) {
				printf("MOREPROBLEMS\n");
				goto END;
			}
			ans += maxj[i];
		}
		printf("%d\n", ans);
		END:;
	}
	return 0;
}