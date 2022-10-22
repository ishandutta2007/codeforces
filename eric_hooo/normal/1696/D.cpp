#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		static int a[250010];
		static int nxt[250010];
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		static deque <int> up, dw; up.clear(), dw.clear(), up.push_back(n + 1), dw.push_back(n + 1);
		for (int i = n; i >= 1; i--) {
			while (up.size() > 1 && a[i] > a[up.front()]) up.pop_front();
			while (dw.size() > 1 && a[i] < a[dw.front()]) dw.pop_front();
			if (i < n) {
				if (a[i + 1] < a[i]) {
					int p = up.front();
					nxt[i] = *--lower_bound(dw.begin(), dw.end(), p);
				} else {
					int p = dw.front();
					nxt[i] = *--lower_bound(up.begin(), up.end(), p);
				}
			}
			up.push_front(i), dw.push_front(i);
		}
		int ans = 0, cur = 1;
		while (cur < n) cur = nxt[cur], ans++;
		printf("%d\n", ans);
	}
	return 0;
}