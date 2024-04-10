#include<stdio.h>
int n, m;
int main() {
	scanf("%d%d", &n, &m);
	if (m == 2) {
		if (n < 5) {
			printf("-1");
			return 0;
		}
		printf("%d\n", n - 1);
		for (int i = 0; i < n - 1; i++) {
			printf("%d %d\n", i + 1, i + 2);
		}
	}
	else if (m == 3) {
		if (n < 4) {
			printf("-1");
			return 0;
		}
		printf("%d\n", 2 * n - 5);
		for (int i = 0; i < 3; i++) {
			printf("%d %d\n", i + 1, i + 2);
		}
		for (int i = 5; i <= n; i++) {
			printf("%d %d\n", 2, i);
			printf("%d %d\n", 3, i);
		}
	}
	else {
		printf("-1");
		return 0;
	}
	return 0;
}