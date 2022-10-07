#include<cstdio>
int tcn;
int n;
int a[1001000];
int nxt[1001000];
int chk[1001000];
int ans[1001000];
int ansl;
int main() {
	scanf("%d", &tcn);
	for (int tc = 0; tc < tcn; tc++) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			chk[i] = 0;
		}
		int p = 0;
		while (chk[p] == 0) {
			chk[p] = 1;
			p = p - a[p];
		}
		ansl = 0;
		while (chk[p] == 1) {
			ans[ansl] = p;
			ansl++;
			chk[p] = 2;
			p = p - a[p];
		}
		printf("%d\n", ansl);
		for (int i = 0; i < ansl; i++) {
			printf("%d ", ans[i] + 1);
		}
		printf("\n");
	}
	return 0;
}