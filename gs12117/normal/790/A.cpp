#include<stdio.h>
int n, m;
int a[1001000];
char tmp[50];
char nm[50];
int pname(int x) {
	nm[0] = 'A';
	for (int i = 1; i < 8; i++) {
		nm[i] = 'a' + x % 26;
		x /= 26;
	}
	nm[8] = 0;
	printf("%s ", nm);
}
int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		a[i] = i;
	}
	for (int i = 0; i <= n - m; i++) {
		scanf("%s", tmp);
		if (tmp[0] == 'N') {
			a[i + m - 1] = a[i];
		}
	}
	for (int i = 0; i < n; i++) {
		pname(a[i]);
	}
	return 0;
}