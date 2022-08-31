#include <cstdio>
#include <cstring>

#include <algorithm>
#include <numeric>

const int N = 1000010;

int p[N];

int main() {
	int n, a, b, x, y;
	scanf("%d%d%d", &n, &a, &b);
	for (x = 0; x * a <= n; ++x)
		if ((n - x * a) % b == 0) {
			y = (n - x * a) / b;
			break;
		}
	if (x * a > n) {
		puts("-1");
		return 0;
	}
	for (int i = 0; i < x; ++i)
		for (int j = 1; j <= a; ++j)
			p[i * a + j] = i * a + j % a + 1;
	int cur = x * a;
	for (int i = 0; i < y; ++i)
		for (int j = 1; j <= b; ++j)
			p[cur + i * b + j] = cur + i * b + j % b + 1;
	for (int i = 1; i < n; ++i)
		printf("%d ", p[i]);
	printf("%d\n", p[n]);
	return 0;
}