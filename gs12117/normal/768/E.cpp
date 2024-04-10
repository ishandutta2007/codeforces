#include<stdio.h>
int n;
int s[1001000];
int pn[200];
int main() {
	int x = 0;
	for (int i = 0; x < 100; i++) {
		for (int j = 0; j <= i; j++) {
			pn[x] = i;
			x++;
		}
	}
	int ans = 0;
	scanf("%d", &n);
	for (int i = 0; i < n; i++) {
		scanf("%d", &s[i]);
		ans ^= pn[s[i]];
	}
	if (ans != 0)printf("NO");
	else printf("YES");
	return 0;
}