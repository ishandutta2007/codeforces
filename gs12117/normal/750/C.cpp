#include<stdio.h>
int n;
int c[200100];
int d[200100];
int ans;
int main() {
	int i;
	scanf("%d", &n);
	ans = 0;
	int p = 1;
	for (i = 0; i < n; i++) {
		scanf("%d%d", &c[i], &d[i]);
		if (p < d[i])p = d[i];
	}
	if (p == 1) {
		puts("Infinity");
		return 0;
	}
	int mp = -1000000000;
	p = 0;
	for (i = 0; i < n; i++) {
		if (d[i] == 2) {
			if (mp < p)mp = p;
		}
		p += c[i];
	}
	ans = 1899 - mp;
	p = ans;
	for (i = 0; i < n; i++) {
		if (d[i] == 1 && p < 1900)break;
		if (d[i] == 2 && p >= 1900)break;
		p += c[i];
	}
	if (i != n) {
		puts("Impossible");
	}
	else {
		printf("%d", p);
	}
	return 0;
}