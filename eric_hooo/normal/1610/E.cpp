#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a, a + n);
		int ans = -1;
		for (int i = 0; i < n; i++) {
			int cur = i, lst = -1, cnt = 1;
			cur = lower_bound(a, a + n, a[i] + 1) - a - 1, cnt = cur - i + 1;
			while (1) {
				int nxt = lower_bound(a + cur + 1, a + n, a[cur] + lst) - a;
				if (nxt == n) break;
				lst = a[nxt] - a[i], cnt++, cur = nxt;
			}
			ans = max(ans, cnt);
		}
		printf("%d\n", n - ans);
	}
	return 0;
}