#include <stdio.h>

int main() {
	int d2, d3, d5, d6, p32, p256;
	scanf("%d %d %d %d", &d2, &d3, &d5, &d6);
	if (d2 < d5 && d2 < d6) {
		printf("%d\n", 256*d2);
		return 0;
	}
	p256 = (d5 < d6) ? d5 : d6;
	d2 -= p256;
	printf("%d\n", 256*p256 + 32*((d2 < d3) ? d2 : d3));
	return 0;
}