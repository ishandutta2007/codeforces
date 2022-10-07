#include<cstdio>
int n;
long long int a[100100];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%lld", &a[i]);
	}
	if (n != 1) {
		printf("%d %d\n", 1, n);
		for (int i = 0; i < n; i++) {
			printf("%lld ", -a[i] * n);
		}
		printf("\n");
		printf("%d %d\n", 1, n - 1);
		for (int i = 0; i < n - 1; i++) {
			printf("%lld ", a[i] * (n - 1));
		}
		printf("\n");
		printf("%d %d\n", n, n);
		for (int i = n - 1; i < n; i++) {
			printf("%lld ", a[i] * (n - 1));
		}
		printf("\n");
	}
	else {
		printf("%d %d\n", 1, n);
		for (int i = 0; i < n; i++) {
			printf("%lld ", -a[i] * n);
		}
		printf("\n");
		printf("%d %d\n", 1, n);
		for (int i = 0; i < n; i++) {
			printf("%lld ", a[i] * 1);
		}
		printf("\n");
		printf("%d %d\n", n, n);
		for (int i = n - 1; i < n; i++) {
			printf("%lld ", a[i] * (n - 2));
		}
		printf("\n");
	}
	return 0;
}