#include <stdio.h>
const char* str[] = {"Red", "Blue", "Yellow", "Purple"};

int N;

int main() {
	puts("YES");
	for(scanf("%d", &N);N--;) {
		int x, y; scanf("%d%d%*d%*d", &x, &y);
		printf("%d\n", 1 + (((x%2)*2 + (y%2) + 400) % 4));
	}
	return 0;
}