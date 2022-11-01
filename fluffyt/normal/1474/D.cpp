#include <bits/stdc++.h>
typedef long long LL;
using namespace std;
template<typename T> inline void chkmin(T &a, const T &b) { a = a < b ? a : b; }
template<typename T> inline void chkmax(T &a, const T &b) { a = a > b ? a : b; }

const int MAXN = 200005;
int a[MAXN], n, T;
LL sum[MAXN], suf[MAXN][2];

int main() {
	for (scanf("%d", &T); T--;) {
		scanf("%d", &n);
		for (int i = 1; i <= n; i++) scanf("%d", a + i);
		LL s = 0, t = 0;
		bool ans = 0;
		for (int i = 1; i <= n; i++) {
			if (i & 1) s += a[i];
			else s -= a[i];
			sum[i] = s;
		}
		suf[n + 1][0] = -1e18, suf[n + 1][1] = 1e18;
		for (int i = n; i > 0; i--) {
			suf[i][0] = suf[i + 1][0];
			suf[i][1] = suf[i + 1][1];
			if (i & 1) chkmin(suf[i][1], sum[i]);
			else chkmax(suf[i][0], sum[i]);
		}
		if (s == 0 && suf[1][0] <= 0 && suf[1][1] >= 0) ans = 1;
		for (int i = 1; i < n; i++) {
			if (i & 1) {
				int d = 2 * a[i + 1] - 2 * a[i];
				if (s + d == 0 && t + a[i + 1] >= 0 && t + a[i + 1] - a[i] <= 0
					&& suf[i + 1][0] + d <= 0 && suf[i + 1][1] + d >= 0) { ans = 1; break; }
				t += a[i];
				if (t < 0) break;
			} else {
				int d = 2 * a[i] - 2 * a[i + 1];
				if (s + d == 0 && t - a[i + 1] <= 0 && t - a[i + 1] + a[i] >= 0
					&& suf[i + 1][0] + d <= 0 && suf[i + 1][1] + d >= 0) { ans = 1; break; }
				t -= a[i];
				if (t > 0) break;
			}
		}
		puts(ans ? "YES" : "NO");
	}
	return 0;
}