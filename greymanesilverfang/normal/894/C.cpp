#include <cstdio>
#include <algorithm>
using namespace std;
int a[1000];

int main() {
	int n; scanf("%d", &n);
	for (int i = 0; i < n; ++i) {
		scanf("%d", &a[i]);
		if (a[i] % a[0]) {
			printf("-1");
			exit(0);
		}
	}
	printf("%d\n", n << 1);
	for (int i = 0; i < n; ++i)
		printf("%d %d ", a[0], a[i]);
}