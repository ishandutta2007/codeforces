#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		goto BEG;
		END:;
		continue;
		BEG:;
		int n, k; scanf("%d%d", &n, &k);
		static int a[1000010];
		static int cnt[1000010], pre[1000010];
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = n; i > n - k; i--) {
			if (a[i] == -1) a[i] = 0;
			if (a[i] != 0) {
				printf("0\n");
				goto END;
			}
		}
		long long ans = 1;
		for (int i = 1; i <= k; i++) {
			ans = ans * i % mod;
		}
		for (int i = 1; i <= n - k; i++) {
			if (a[i] == 0) ans = ans * (k + 1) % mod;
			else if (a[i] == -1) ans = ans * (k + 1 + max(0, k + i - 1 - k)) % mod;
			else if (k + a[i] > k + i - 1) ans = ans * 0 % mod;
		}
		printf("%lld\n", ans);
	}
	return 0;
}