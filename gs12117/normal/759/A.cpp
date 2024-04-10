#include<stdio.h>
int n;
int a[200100];
int b[200100];
int chk[200100];
int ncnt;
int bsum;
int main() {
	scanf("%d", &n);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 1; i <= n; i++) {
		scanf("%d", &b[i]);
		bsum += b[i];
	}
	for (int i = 1; i <= n; i++) {
		if (chk[i] == 0) {
			ncnt++;
			int p = i;
			while (chk[p] == 0) {
				chk[p] = 1;
				p = a[p];
			}
		}
	}
	if (ncnt == 1)ncnt = 0;
	ncnt += (bsum + 1) % 2;
	printf("%d", ncnt);
	return 0;
}