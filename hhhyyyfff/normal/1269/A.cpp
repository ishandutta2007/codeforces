#include <cstdio>

using namespace std;

int n;

int main() {
	scanf("%d", &n);
	if (n == 1) {
		puts("9 8");
	} else {
		printf("%d %d\n", 3 * n, 2 * n);
	}
    return 0;
}