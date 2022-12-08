#include <bits/stdc++.h>

using namespace std;

int t, n, si, ans;

int main() {
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		ans = -1;
		for (int i = 1, lst = 0; i <= n; ++i) {
			scanf("%1d", &si);
			if (si != lst) ++ans;
			lst = si;
		}
		printf("%d\n", max(ans, 0));
	}
	return 0;
}