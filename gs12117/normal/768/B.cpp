#include<stdio.h>
int digit(long long int n) {
	if (n == 1)return 1;
	return digit(n / 2) + 1;
}
long long int find_ans(long long int n, long long int l, long long int r) {
	if (n == 0)return 0;
	if (n == 1) {
		if (l == 0 && r == 1)return 1;
		return 0;
	}
	long long int len = 1LL << digit(n);
	len--;
	long long int hlen = len / 2;
	if (l == 0 && r == len) {
		return n;
	}
	if (l <= hlen&&r > hlen) {
		return n % 2 + find_ans(n / 2, l, hlen) + find_ans(n / 2, 0, r - hlen - 1);
	}
	else if (r <= hlen) {
		return find_ans(n / 2, l, r);
	}
	else {
		return find_ans(n / 2, l - hlen - 1, r - hlen - 1);
	}
}
int main() {
	long long int n, l, r;
	scanf("%I64d%I64d%I64d", &n, &l, &r);
	printf("%I64d", find_ans(n, l - 1, r));
	return 0;
}