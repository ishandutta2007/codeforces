#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 100005;
int T, n, p[MAXN];

int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%d", &n);
		LL ans = 0;
		int c = n - 1;
		for (int i = n - 1; i > 0; i--) {
			if (c > 0) --c, ans += (LL)i * i;
			if (c > 0) --c, ans += (LL)(i - 1) * (i - 1);
		}
		printf("%lld\n", ans);
		p[1] = n / 2 + 1;
		for (int i = n / 2 + 1; i < n; i++)
			p[i] = i + 1;
		p[n] = n / 2;
		for (int i = n / 2; i > 1; i--)
			p[i] = i - 1;
		for (int i = 1; i <= n; i++) printf("%d ", p[i]);
		puts("");
		printf("%d\n", n - 1);
		for (int i = n / 2 + 1; i < n; i++)
			printf("%d 1\n", i);
		for (int i = n / 2; i > 1; i--)
			printf("%d %d\n", i, n);
		printf("1 %d\n", n);
	}
	return 0;
}