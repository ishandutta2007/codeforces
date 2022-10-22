#include <bits/stdc++.h>
using namespace std;

int a[100010];

void exgcd(int a, int b, long long &x, long long &y) {
	if (!b) {
		y = 0, x = 1;
		return ;
	}
	exgcd(b, a % b, y, x), y -= a / b * x;
}

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	if (n == 1) {
		for (int i = 0; i < 3; i++) {
			printf("%d %d\n%d\n", 1, 1, i ? 0 : -a[1]);
		}
		return 0;
	}
	long long k1 = -1, k2 = 1;
	printf("%d %d\n", 1, n);
	for (int i = 1; i <= n; i++) {
		printf("%lld ", k1 * a[i] * n);
	}
	printf("\n");
	printf("%d %d\n", 1, n - 1);
	for (int i = 1; i <= n - 1; i++) {
		printf("%lld ", k2 * a[i] * (n - 1));
	}
	printf("\n");
	printf("%d %d\n", 2, n);
	for (int i = 2; i <= n; i++) {
		if (i == n) printf("%lld ", k2 * a[i] * (n - 1));
		else printf("0 ");
	}
	printf("\n");
	return 0;
}