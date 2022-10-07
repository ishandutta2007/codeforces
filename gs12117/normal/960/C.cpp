#include<cstdio>
int x, d;
int ansn;
long long int ans[10100];
int main() {
	scanf("%d%d", &x, &d);
	long long int p = 1;
	while (x > 0) {
		int l = 0;
		while ((1 << (l + 1)) - 1 <= x)l++;
		for (int i = 0; i < l; i++) {
			ans[ansn + i] = p;
		}
		ansn += l;
		x -= (1 << l) - 1;
		p += d;
	}
	printf("%d\n", ansn);
	for (int i = 0; i < ansn; i++) {
		printf("%lld ", ans[i]);
	}
	return 0;
}