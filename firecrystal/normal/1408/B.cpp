#include <cstdio>
#include <iostream>
using namespace std;

typedef long long LL;

const int N = 105;

int n, K, a[N], cnt[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &K);
		for (int i = 0; i <= 100; i++) cnt[i] = 0;
		int s = 0;
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			if (!cnt[a[i]]) s++;
			cnt[a[i]] = 1;
		}
		if (K == 1) {
			if (s == 1) puts("1");
			else puts("-1");
		} else if (s == 1) {
			puts("1");
		} else {
			K --;
			int o = s - 1;
			printf("%d\n", (o + K - 1) / K);
		}
	}	
	return 0;
}