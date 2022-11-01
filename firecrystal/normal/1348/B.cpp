#include <cstdio>
#include <iostream>

using namespace std;

typedef long long LL;

const int N = 105;

int n, K, a[N], cnt[N], b[N], tot;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &K);
		for (int i = 1; i <= n; i++) cnt[i] = 0;
		for (int i = 1; i <= n; i++) scanf("%d", a + i), cnt[a[i]]++;
		int res = 0;
		for (int i = 1; i <= n; i++)
			if (cnt[i]) res++;
		if (K < res) puts("-1");
		else {
			tot = 0;

			for (int i = 1; i <= n; i++) {
				if (cnt[i]) b[++tot] = i;
				else if (K > res) K--, b[++tot] = i;
			}
			printf("%d\n", tot * n);
			for (int i = 1; i <= n; i++) {
				for (int j = 1; j <= tot; j++) printf("%d ", b[j]);
			}
			puts("");
		}
	}
	return 0;
}