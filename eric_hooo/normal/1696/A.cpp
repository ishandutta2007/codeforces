#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, z; scanf("%d%d", &n, &z);
		int ans = -1;
		for (int i = 1; i <= n; i++) {
			int x; scanf("%d", &x);
			ans = max(ans, z | x);
		}
		printf("%d\n", ans);
	}
	return 0;
}