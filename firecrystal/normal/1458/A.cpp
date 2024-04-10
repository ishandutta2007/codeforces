#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

typedef long long LL;

const int N = 2e5 + 5;

int n, m;

LL a[N], b[N];

LL gcd(LL a, LL b) {
	return b ? gcd(b, a % b) : a;
}

int main() {
	scanf("%d%d", &n, &m);	
	LL d = 0;
	for (int i = 1; i <= n; i++) {
		scanf("%lld", a + i);
	}
	for (int i = 1; i < n; i++)
		d = gcd(d, abs(a[i] - a[i + 1]));
	for (int i = 1; i <= m; i++) {
		scanf("%lld", b + i);
		printf("%lld ", gcd(d, a[1] + b[i]));
	}
	return 0;
}