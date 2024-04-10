#include <algorithm>
#include <cstdio>
#include <cstdlib>
#include <cstring>
#include <iostream>

using namespace std;

const int MAXN = 205;

int a[MAXN], b[MAXN];

int main(void) {
	int t; scanf("%d", &t);
	for (int kase = 0; kase < t; kase++) {
		int n, k; scanf("%d%d", &n, &k);
//		memset(a, 0, sizeof a);
		memset(b, 0x7f, sizeof b);
		int ans = 0;
		for (int i = 0; i < k; i++) {
			scanf("%d", &a[i]);
			for (int j = a[i]; j > 0; j--) b[j] = min(b[j], a[i] - j + 1);
			for (int j = a[i]; j <= n; j++) b[j] = min(b[j], j - a[i] + 1);
		}
		for (int i = 1; i <= n; i++) {
//			printf("%d ", b[i]);
			ans = max(ans, b[i]);
		}
		printf("%d\n", ans);
	}
	return 0;
}