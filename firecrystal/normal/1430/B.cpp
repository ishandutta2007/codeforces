#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;

typedef long long LL;

const int N = 200005;

int n, K, a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &K);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		sort(a + 1, a + 1 + n);
		LL ans = 0;
		for (int i = n - K; i <= n; i++) ans += a[i];
		printf("%lld\n", ans);
	}	
	return 0;
}