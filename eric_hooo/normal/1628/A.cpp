#include <bits/stdc++.h>
using namespace std;

int a[200010];
vector <int> all[200010];
vector <int> b;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i <= n; i++) {
			all[i].clear();
		}
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			all[a[i]].push_back(i);
		}
		b.clear();
		int cur = 1;
		while (cur <= n) {
			int x = 0, nxt = cur;
			while (1) {
				auto it = lower_bound(all[x].begin(), all[x].end(), cur);
				if (it == all[x].end()) break;
				nxt = max(nxt, *it), x++;
			}
			b.push_back(x), cur = nxt + 1;
		}
		printf("%d\n", (int)b.size());
		for (auto it : b) {
			printf("%d ", it);
		}
		printf("\n");
	}
	return 0;
}