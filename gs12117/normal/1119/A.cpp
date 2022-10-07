#include<cstdio>
int c[300100];
int main() {
	int n;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
	}
	int ans = 0;
	for (int i = 0; i < n; i++) {
		if (c[i] != c[0] && ans < i)ans = i;
		if (c[i] != c[n - 1] && ans < n - 1 - i)ans = n - 1 - i;
	}
	printf("%d", ans);
	return 0;
}