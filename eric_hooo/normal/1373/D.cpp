#include <bits/stdc++.h>
using namespace std;

int a[200010];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		long long sss = 0;
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			if (i % 2 == 0) sss += a[i];
		}
		long long res = sss;
		for (int p = 0; p <= 1; p++) {
			long long sum = 0, ans = 0;
			for (int i = p; i + 1 < n; i += 2) {
				int x = p ? a[i] - a[i + 1] : a[i + 1] - a[i];
				if (sum < 0) sum = 0;
				sum += x;
				ans = max(ans, sum);
			}
			res = max(res, sss + ans);
		}
		printf("%lld\n", res);
	}
	return 0;
}