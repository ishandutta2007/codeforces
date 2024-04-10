#include<cstdio>
int n, m;
int main() {
	scanf("%d", &n);
	scanf("%d", &m);
	int ans;
	if (n >= 30) {
		ans = m;
	}
	else {
		ans = m % (1 << n);
	}
	printf("%d\n", ans);
	return 0;
}