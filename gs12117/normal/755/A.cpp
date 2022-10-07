#include<stdio.h>
int n;
int main() {
	scanf("%d", &n);
	if (n + 2 > 1000) {
		printf("1");
		return 0;
	}
	printf("%d", n + 2);
	return 0;
}