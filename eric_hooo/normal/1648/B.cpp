#include <bits/stdc++.h>
using namespace std;

int a[1000010];
int sum[1000010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n, C; scanf("%d%d", &n, &C);
		for (int i = 1; i <= C; i++) {
			a[i] = 0;
		}
		for (int i = 0; i < n; i++) {
			int x; scanf("%d", &x);
			a[x] = 1;
		}
		for (int i = 1; i <= C; i++) {
			sum[i] = sum[i - 1] + a[i];
		}
		for (int i = 1; i <= C; i++) {
			if (a[i]) continue;
			for (int j = 1; i * j <= C; j++) {
				if (!a[j]) continue;
				if (sum[i * j - 1] != sum[min(C, i * j + j - 1)]) {
					printf("No\n");
					goto END;
				}
			}
		}
		printf("Yes\n");
		END:;
	}
	return 0;
}