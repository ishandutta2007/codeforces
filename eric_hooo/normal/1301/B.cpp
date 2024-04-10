#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		int ans = 0;
		vector <int> all;
		for (int i = 1; i < n; i++) {
			if (a[i] != -1 && a[i - 1] != -1) {
				ans = max(ans, abs(a[i] - a[i - 1]));
			} else if (a[i] != -1) {
				all.push_back(a[i]);
			} else if (a[i - 1] != -1) {
				all.push_back(a[i - 1]);
			}
		}
		sort(all.begin(), all.end());
		if (all.size()) ans = max(ans, all.back() - all[0] + 1 >> 1);
		printf("%d ", ans);
		if (!all.size()) printf("0\n");
		else printf("%d\n", all[0] + all.back() >> 1);
	}
	return 0;
}