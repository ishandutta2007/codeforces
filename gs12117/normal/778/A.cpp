#include<stdio.h>
int n, m;
char a[200100];
char b[200100];
int c[200100];
int chk[200100];
int para(int x) {
	if (x >= n)return 0;
	for (int i = 0; i < n; i++) {
		chk[i] = 0;
	}
	for (int i = 0; i < x; i++) {
		chk[c[i]] = 1;
	}
	int j = 0;
	for (int i = 0; i < n; i++) {
		if (chk[i] == 0 && a[i] == b[j])j++;
		if (j == m)return 1;
	}
	return 0;
}
int main() {
	scanf("%s", a);
	scanf("%s", b);
	while (a[n])n++;
	while (b[m])m++;
	for (int i = 0; i < n; i++) {
		scanf("%d", &c[i]);
		c[i]--;
	}
	int ans = 0;
	for (int i = 20; i >= 0; i--) {
		ans += 1 << i;
		if (para(ans) == 0)ans -= 1 << i;
	}
	printf("%d", ans);
	return 0;
}