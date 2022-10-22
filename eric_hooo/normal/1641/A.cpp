#include <bits/stdc++.h>
using namespace std;

int a[200010];
multiset <int> all;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, x; scanf("%d%d", &n, &x);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		sort(a + 1, a + n + 1);
		int need = n;
		all.clear();
		for (int i = 1; i <= n; i++) {
			int cur = a[i];
			if (cur % x == 0 && all.count(cur / x)) all.erase(all.find(cur / x)), need -= 2;
			else all.insert(cur);
		}
		printf("%d\n", need);
	}
	return 0;
}