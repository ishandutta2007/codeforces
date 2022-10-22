#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;

long long a[500010];
int cnt[70];

int main () {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		memset(cnt, 0, sizeof(cnt));
		for (int i = 0; i < n; i++) {
			scanf("%I64d", &a[i]);
			for (int j = 0; j < 60; j++) {
				if (a[i] >> j & 1) cnt[j]++;
			}
		}
		long long ans = 0;
		for (int i = 0; i < n; i++) {
			long long s1 = 0, s2 = 0, x = a[i];
			for (int j = 0; j < 60; j++) {
				if (x >> j & 1) s1 += cnt[j] * ((1ll << j) % mod), s2 += n * ((1ll << j) % mod);
				else s2 += cnt[j] * ((1ll << j) % mod);
			}
			ans = (ans + 1ll * (s1 % mod) * (s2 % mod)) % mod;
		}
		printf("%I64d\n", ans);
	}
	return 0;
}