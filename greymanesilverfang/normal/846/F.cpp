#include <cstdio>
long long n, p[1000001], sum = 0, s = 0;
int main() {
	scanf("%lld", &n);
	for (long long tmp = 0, i = 0; (p[tmp] = i) < n;)
		scanf("%d", &tmp), --sum += s += ++i - p[tmp] << 1;
	printf("%f", (double) sum / n / n);
}