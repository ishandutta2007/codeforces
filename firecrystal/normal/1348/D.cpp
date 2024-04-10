#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

int n, ans[1000];

int main() {
	for (int i = 1; i <= 100; i++) {
		ans[i] = 1 + i;
		int s = 1;
		for (int j = 1; j <= i; j++) {
			ans[i] += s * (i - j + 1);
			s *= 2;
		}
	}
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		int m;
		for (int i = 1; i <= n; i++) {
			if (n <= ans[i]) { m = i; break; }
		}
		printf("%d\n", m);
		int s = 1;
		n -= 1 + m;
		for (int i = 1; i <= m; i++) {
			int t = min(s, n / (m - i + 1));
			printf("%d ", t);
			n -= t * (m - i + 1);
			s += t;
		}
		puts("");
	}
	return 0;
}