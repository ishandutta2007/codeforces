#include <bits/stdc++.h>
using namespace std;

int n;
int a[110], b[110];
int f[10010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			scanf("%d", &a[i]);
		}
		for (int i = 0; i < n; i++) {
			scanf("%d", &b[i]);
		}
		memset(f, 0, sizeof(f));
		f[0] = 1;
		int sum = 0, tot = 0;
		long long oth = 0;
		for (int i = 0; i < n; i++) {
			sum += max(a[i], b[i]), tot += a[i] + b[i];
			oth += a[i] * a[i] + b[i] * b[i];
			for (int j = sum; j >= 0; j--) {
				int qwq = 0;
				if (j >= a[i]) qwq |= f[j - a[i]];
				if (j >= b[i]) qwq |= f[j - b[i]];
				f[j] = qwq;
			}
		}
		long long ans = 0x3f3f3f3f3f3f3f3f;
		for (int i = 0; i <= sum; i++) {
			if (!f[i]) continue;
			int j = tot - i;
			ans = min(ans, 1ll * i * i + 1ll * j * j - oth + (n - 1) * oth);
		}
		printf("%lld\n", ans);
	}
	return 0;
}