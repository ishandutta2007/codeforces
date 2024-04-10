#include <bits/stdc++.h>
using namespace std;

int a[30];

int gcd(int x, int y) {
	return !y ? x : gcd(y, x % y);
}

int main () {
	int n; scanf("%d", &n);
	int g = 0, cnt = 0;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		g = gcd(g, a[i]);
		cnt += a[i] & 1;
	}
	if (cnt > 1) {
		printf("0\n");
		for (int i = 0; i < n; i++) {
			while (a[i]--) printf("%c", char(i + 'a'));
		}
		printf("\n");
	} else {
		printf("%d\n", g);
		if (cnt == 1) {
			for (int it = 0; it < g; it++) {
				for (int i = 0; i < n; i++) {
					if (a[i] % 2 == 0) {
						for (int j = 0; j < a[i] / 2 / g; j++) {
							printf("%c", char(i + 'a'));
						}
					}
				}
				for (int i = 0; i < n; i++) {
					if (a[i] % 2 == 1) {
						for (int j = 0; j < a[i] / g; j++) {
							printf("%c", char(i + 'a'));
						}
					}
				}
				for (int i = n - 1; i >= 0; i--) {
					if (a[i] % 2 == 0) {
						for (int j = 0; j < a[i] / 2 / g; j++) {
							printf("%c", char(i + 'a'));
						}
					}
				}
			}
			printf("\n");
		} else {
			while (g) {
				if (g & 1) {
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < a[i] / g; j++) {
							printf("%c", char(i + 'a'));
						}
						a[i] -= a[i] / g;
					}
				} else {
					for (int i = n - 1; i >= 0; i--) {
						for (int j = 0; j < a[i] / g; j++) {
							printf("%c", char(i + 'a'));
						}
						a[i] -= a[i] / g;
					}
				}
				g--;
			}
			printf("\n");
		}
	}
	return 0;
}