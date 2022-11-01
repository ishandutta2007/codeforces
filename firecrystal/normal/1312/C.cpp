#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;

typedef long long LL;

const int N = 35;

int n, k, cnt[63];
LL a[N];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		memset(cnt, 0, sizeof cnt);
		scanf("%d%d", &n, &k);
		bool ok = true;
		for (int i = 1; i <= n; i++) {
			scanf("%lld", a + i);
			LL x = a[i];
			int s = 0;
			while (x) {
				if ((x % k) > 1) {
					ok = false;
					break;
				}
				cnt[s] += x % k;
				x /= k;
				s++;
			}
		}
		for (int i = 0; i < 63; i++)
			if (cnt[i] > 1) {
				ok = false; break;
			}
		puts(ok ? "YES" : "NO");
	}
	return 0;
}