#include <bits/stdc++.h>
using namespace std;

int T;
int n;
int a[110];
int vis[100010];

int main() {
	vis[0] = vis[1] = 1;
	for (int i = 2; i <= 100000; i++) {
		for (int j = i + i; j <= 100000; j += i) {
			vis[j] = 1;
		}
	}
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int sum = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
			sum += a[i];
		}
		if (vis[sum]) {
			printf("%d\n", n);
			for (int i = 1; i <= n; i++) {
				printf("%d ", i);
			}
			printf("\n");
		} else {
			for (int i = 1; i <= n; i++) {
				if (vis[sum - a[i]]) {
					printf("%d\n", n - 1);
					for (int j = 1; j <= n; j++) {
						if (i == j) continue;
						printf("%d ", j);
					}
					printf("\n");
					break;
				}
			}
		}
	}
	return 0;
}