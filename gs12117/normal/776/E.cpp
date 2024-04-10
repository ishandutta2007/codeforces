#include<stdio.h>
long long int phi(long long int n) {
	long long int res = 1;
	for (long long int i = 2; i*i <= n; i++) {
		if (n%i == 0) {
			n /= i;
			res *= i - 1;
			while (n%i == 0) {
				n /= i;
				res *= i;
			}
		}
	}
	if (n != 1)res *= n - 1;
	return res;
}
int main() {
	long long int n, m;
	scanf("%I64d%I64d", &n, &m);
	m = (m + 1) / 2;
	for (int i = 0; i < m; i++) {
		n = phi(n);
		if (n == 1)break;
	}
	n %= 1000000007;
	printf("%I64d", n);
}