#include <bits/stdc++.h>
using namespace std;
typedef long long LL;
typedef pair<int, int> P;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 105;
int T, n, a[MAXN];

int main() {
	for (scanf("%d", &T); T--;) {
		int n, d, f = 1;
		scanf("%d%d", &n, &d);
		for (int i = 1; i <= n; i++) {
			scanf("%d", a + i);
			if (a[i] > d) f = 0;
		}
		if (f == 1) {
			puts("YES");
			continue;
		}
		sort(a + 1, a + 1 + n);
		if (a[1] + a[2] <= d) puts("YES");
		else puts("NO");
	}
	return 0;
}