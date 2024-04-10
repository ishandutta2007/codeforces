#include<cstdio>
int n;
int a[300100];
int main() {
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	long long int ans = 0;
	long long int uodd = 0;
	for (int i = n - 1; i >= 0; i--) {
		if (a[i] <= 1 && uodd == 0) {
			continue;
		}
		ans += a[i];
		uodd += a[i] / 2;
		if (a[i] % 2 == 1)uodd--;
	}
	printf("%lld", ans / 3);
	return 0;
}