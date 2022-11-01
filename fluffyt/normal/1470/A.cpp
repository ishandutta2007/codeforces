#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 300005;
int c[MAXN], k[MAXN], n, m, T;
int main() {
	scanf("%d", &T);
	while (T--) {
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) scanf("%d", k + i);
		for (int i = 1; i <= m; i++) scanf("%d", c + i);
		sort(k + 1, k + 1 + n);
		int p = 0;
		for (int i = n; i > 0; i--) {
			if (n - i + 1 <= k[i]) p = n - i + 1;
			else break;
		}
		LL ans = 0;
		for (int i = 1; i <= p; i++) ans += c[i];
		for (int i = 1; i <= n - p; i++) ans += c[k[i]];
		printf("%lld\n", ans);
	}
	return 0;
}