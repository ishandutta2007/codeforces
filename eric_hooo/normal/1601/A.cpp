#include <bits/stdc++.h>
using namespace std;

int a[200010];
int cnt[40];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
			for (int j = 0; j < 30; j++) {
				if (a[i] >> j & 1) cnt[j]++;
			}
		}
		for (int i = 1; i <= n; i++) {
			for (int j = 0; j < 30; j++) {
				if (cnt[j] % i) goto BAD;
			}
			printf("%d ", i);
			BAD:;
		}
		printf("\n");
	}
	return 0;
}