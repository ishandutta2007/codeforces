#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 2e5 + 10, P = 998244353;

int n, m, ans, fact[N], infact[N];

int power(int a, int b) {
	int res = 1;
	while (b) {
		if (b & 1) res = (LL)res * a % P;
		a = (LL)a * a % P;
		b >>= 1;
	}
	return res;
}

int C(int a, int b) {
	if (a < b) return 0;
	return (LL)fact[a] * infact[b] % P * infact[a - b] % P;
}

int main() {
	scanf("%d%d", &n, &m);
	infact[0] = fact[0] = 1;
	for (int i = 1; i <= m; i++) fact[i] = (LL)fact[i - 1] * i % P;
	infact[m] = power(fact[m], P - 2);
	for (int i = m - 1; i; i--) infact[i] = (LL)infact[i + 1] * (i + 1) % P;
	if (n == 2) {
		puts("0");
	} else {
		for (int i = 1; i <= m; i++) {
			if (i - 1 < n - 2) continue;
			ans = (ans + (LL)C(i - 1, n - 2) * (n - 2) % P * power(2, n - 3)) % P;
		}
		printf("%d\n", ans);
	}
	return 0;
}