#include<cstdio>
#include<algorithm>
int n, m;
int a[1010];
int b[1010];
int para(int x) {
	if (x <= 0)return 1;
	if (x > n)return 0;
	for (int i = 0; i < x; i++) {
		b[i] = a[i];
	}
	std::sort(b, b + x);
	int res = 0;
	for (int i = x - 1; i >= 0; i -= 2) {
		res += b[i];
		if (res > m)return 0;
	}
	return 1;
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
	}
	int ans = 0;
	for (int i = 12; i >= 0; i--) {
		ans += 1 << i;
		if (para(ans) == 0)ans -= 1 << i;
	}
	printf("%d", ans);
	return 0;
}