#include <bits/stdc++.h>
using namespace std;
int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, k; scanf("%d%d", &n, &k);
		if (k == n - 1) {
			if (n == 4) {
				printf("-1\n");
			} else {
				printf("%d %d\n", n - 1, n - 2);
				printf("%d %d\n", 1, 3);
				printf("%d %d\n", 0, n - 4);
				for (int i = 0; i < n; i++) {
					int j = n - 1 ^ i;
					if (i < j) {
						if (i != 0 && i != 1 && i != 3) {
							printf("%d %d\n", i, j);
						}
					}
				}
			}
			continue;
		}
		printf("%d %d\n", k, n - 1);
		if (k) printf("%d %d\n", (n - 1) ^ k, 0);
		for (int i = 0; i < n; i++) {
			int j = n - 1 ^ i;
			if (i < j) {
				if (i && i != k && j != k) {
					printf("%d %d\n", i, j);
				}
			}
		}
	}
	return 0;
}