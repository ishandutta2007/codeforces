#include<cstdIo>
int tcn;
int n;
int a[400100];
int main() {
	scanf("%d", &tcn);
	while (tcn--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		a[n] = -1;
		int g, s, b;
		g = n;
		for (int i = 0; i < n; i++) {
			if (a[i] != a[i + 1]) {
				g = i + 1;
				break;
			}
		}
		s = n;
		for (int i = 2 * g; i < n; i++) {
			if (a[i] != a[i + 1]) {
				s = i + 1 - g;
				break;
			}
		}
		b = n;
		for (int i = 2 * g + s; i < n; i++) {
			if (a[i] != a[i + 1] && (i + 1) * 2 <= n) {
				b = i + 1 - g - s;
			}
		}
		if ((g + s + b) * 2 > n) {
			g = 0;
			s = 0;
			b = 0;
		}
		printf("%d %d %d\n", g, s, b);
	}
	return 0;
}