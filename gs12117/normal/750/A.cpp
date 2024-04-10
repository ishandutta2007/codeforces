#include<stdio.h>
int main() {
	int n, m, i;
	scanf("%d%d", &n, &m);
	for (i = 0; i < n; i++) {
		if ((i + 1)*(i + 2) / 2 * 5 > 240 - m)break;
	}
	printf("%d", i);
	return 0;
}