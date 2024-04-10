#include <iostream>
#include <cstdio>

#define fi first
#define se second
#define mp make_pair
#define pb push_back

using namespace std;

typedef long long LL;

const int N = 1e3 + 5;

int n, a[N];

void out(int n) {
	printf("2 %d %d\n", n - 1, n);
	printf("1 %d %d\n", n - 1, n);
	printf("1 %d %d\n", n - 1, n);
	printf("2 %d %d\n", n - 1, n);
	printf("1 %d %d\n", n - 1, n);
	printf("1 %d %d\n", n - 1, n);
}

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		printf("%d\n", n / 2 * 6);
		for (int i = 2; i <= n; i += 2) out(i);
	}
	return 0;
}