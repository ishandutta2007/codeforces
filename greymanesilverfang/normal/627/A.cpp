#include <cstdio>

int main() {
	long long a, b, c, ans = 1; 
	scanf("%lld%lld", &a, &b); 
	a = c = a - b; if (a < 0 || a & 1) {
		printf("0");
		return 0;
	} else a >>= 1;
	while (b > 0) {
		if (a & 1 && b & 1) {
			printf("0");
			return 0;
		} else {
			ans <<= b & 1;
			a >>= 1, b >>= 1;
		}
	}
	printf("%lld", ans -= !c << 1);
}