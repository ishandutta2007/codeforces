#include <bits/stdc++.h>
using namespace std;
const int N = 3e5 + 5;
int T, inf, n, a[N], mx[N], pos[N], last[N];
int main() {
	for (scanf("%d", &T); T --; ) {
		scanf("%d", &n);
		memset(pos, 63, sizeof pos), inf = pos[1];
		memset(last, 0, sizeof last);
		memset(mx, 0, sizeof mx);
		for (int i = 1; i <= n; ++ i) {
			scanf("%d", a + i);
			mx[a[i]] = max(mx[a[i]], i - last[a[i]]), last[a[i]] = i;
		}
		for (int i = 1; i <= n; ++ i) mx[i] = max(mx[i], n + 1 - last[i]);
		for (int i = 1; i <= n; ++ i) pos[n - mx[i] + 1] = min(pos[n - mx[i] + 1], i);
		for (int i = n - 1; i; -- i) pos[i] = min(pos[i], pos[i + 1]);
		for (int i = n; i; -- i) if (pos[i] == inf) printf("-1 "); else printf("%d ", pos[i]);
		puts("");
	}
	return 0;
}