#include<stdio.h>
int n;
int p[100100];
int main() {
	scanf("%d", &n);
	if (n < 3) {
		printf("1\n");
	}
	else {
		printf("2\n");
	}
	for (int i = 2; i <= n + 1; i++) {
		printf("%d ", p[i] + 1);
		if (p[i] == 0) {
			for (int j = i; j <= n + 1; j += i) {
				p[j] = 1;
			}
		}
	}
	printf("\n");
	return 0;
}