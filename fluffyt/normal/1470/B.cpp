#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 300005, MAXM = 1000005;
int a[MAXN], cnt[MAXM], num[MAXN], T, n, Q;

int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		for (int i = 1; i <= n; i++) {
			int x = a[i], k = 1;
			for (int j = 2; j * j <= x; j++) if (x % j == 0) {
				int c = 0;
				while (x % j == 0) x /= j, ++c;
				if (c & 1) k *= j;
			}
			if (x > 1) k *= x;
			num[i] = k;
			++cnt[k];
		}
		int a0 = 0, a1 = 0;
		for (int i = 1; i <= n; i++) a0 = max(a0, cnt[num[i]]);
		for (int i = 1; i <= n; i++) {
			if (num[i] == 1) continue;
			if (~cnt[num[i]] & 1) cnt[1] += cnt[num[i]], cnt[num[i]] = 0;
		}
		a1 = max(a0, cnt[1]);
		for (int i = 1; i <= n; i++) cnt[num[i]] = 0;
		cnt[1] = 0;
		scanf("%d", &Q);
		while (Q--) {
			LL w; scanf("%lld", &w);
			if (w == 0) printf("%d\n", a0);
			else printf("%d\n", a1);
		}
	}
	return 0;
}