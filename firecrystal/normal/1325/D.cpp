#include <iostream>
#include <cstdio>

using namespace std;

typedef long long LL;

const int N = 1e6 + 5;

int n;
LL u, v, ans[N];

int main() {
	scanf("%lld%lld", &u, &v);
	if (u == 0 && v == 0) {
		puts("0");
		return 0;
	}
	if (u > v) {
		puts("-1");
		return 0;
	}
	if (u == v) {
		printf("%d\n%lld\n", 1, u);
		return 0;
	}
	LL k = v - u;
	if (k & 1) {
		puts("-1");
		return 0;
	}
	
	LL s = 0;
	for (int i = 1; i <= 60; i++) {
		if (k >> i & 1) {
			s += 1ll << (i - 1);
		}
	}
	if ((s ^ u) == s + u) {
		ans[++n] = s + u, ans[++n] = s;
	} else {
		ans[++n] = u;
		ans[++n] = s;
		ans[++n] = s;
	}
	printf("%d\n", n);
	for (int i = 1; i <= n; i++) printf("%lld ", ans[i]);
	return 0;
}