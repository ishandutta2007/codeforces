#include <bits/stdc++.h>
using namespace std;

int a[100010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int ok = 0;
		for (int i = 2; i <= n - 1; i++) {
			if (a[i] > 1) ok = 1;
		}
		if (!ok) {
			printf("-1\n");
			continue;
		}
		if (n == 3 && (a[2] & 1)) {
			printf("-1\n");
			continue;
		}
		long long need = 0;
		for (int i = 2; i <= n - 1; i++) {
			need += a[i];
			if (a[i] & 1) need++;
		}
		printf("%lld\n", need / 2);
	}
	return 0;
}