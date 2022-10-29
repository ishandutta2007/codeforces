#include <cstdio>
#include <algorithm>
using namespace std;
const int M = 1010;
const int MAX = 100010;

int n, b[M], sum[MAX], ans = 200000000;

int main() {
	scanf("%d", &n);
	for (register int i = 1; i < M; i++) {
		b[i] = 10000;
	}
	for (register int i = 1; i <= n; i++) {
		int a;
		scanf("%d", &a);
		sum[i] = sum[i - 1] + a;
		for (register int j = 1; j < M && i > j; j++) {
			b[j] = min(b[j], abs(sum[i] - sum[i - j]));
		}
	}
	for (register int j = 1; j < M; j++) {
		ans = min(ans, j * j + b[j] * b[j]);
	}
	printf("%d\n", ans);
	return 0;
}