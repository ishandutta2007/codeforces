#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		int lst = 0, ans = 0;
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			if (x == 0) {
				ans += lst + 1 != i;
				lst = i;
			}
		}
		ans += lst + 1 != n + 1;
		ans = min(ans, 2);
		printf("%d\n", ans);
	}
	return 0;
}