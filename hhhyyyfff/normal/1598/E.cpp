#include <bits/stdc++.h>

using namespace std;

int n, m, q, x, y, tail[1002][1002][2];
bool state[1002][1002];
long long ans;

int main() {
	scanf("%d%d%d", &n, &m, &q);
	for (int i = 1; i <= n; ++i)
		for (int j = 1; j <= m; ++j) {
			tail[i][j][0] = tail[i][j - 1][1] + 1;
			tail[i][j][1] = tail[i - 1][j][0] + 1;
			ans += tail[i][j][0] + tail[i][j][1] - 1;
		}
	for (int i = 1; i <= n; ++i) state[i][0] = state[i][m + 1] = 1;
	for (int i = 1; i <= m; ++i) state[0][i] = state[n + 1][i] = 1;
	while (q--) {
		scanf("%d%d", &x, &y);
		if (!state[x][y]) {
			int tx = x, ty = y, cnt1 = 0, cnt2 = 0;
			for (int i = 0; !state[x][y]; i ^= 1) {
				++cnt1;
				if (i) --x; else --y;
			}
			x = tx, y = ty;
			for (int i = 1; !state[x][y]; i ^= 1) {
				++cnt2;
				if (i) ++x; else ++y;
			}
			ans -= cnt1 * cnt2;
			x = tx, y = ty, cnt1 = 0, cnt2 = 0;
			for (int i = 1; !state[x][y]; i ^= 1) {
				++cnt1;
				if (i) --x; else --y;
			}
			x = tx, y = ty;
			for (int i = 0; !state[x][y]; i ^= 1) {
				++cnt2;
				if (i) ++x; else ++y;
			}
			ans -= cnt1 * cnt2 - 1;
			state[tx][ty] = 1;
		} else {
			state[x][y] = 0;
			int tx = x, ty = y, cnt1 = 0, cnt2 = 0;
			for (int i = 0; !state[x][y]; i ^= 1) {
				++cnt1;
				if (i) --x; else --y;
			}
			x = tx, y = ty;
			for (int i = 1; !state[x][y]; i ^= 1) {
				++cnt2;
				if (i) ++x; else ++y;
			}
			ans += cnt1 * cnt2;
			x = tx, y = ty, cnt1 = 0, cnt2 = 0;
			for (int i = 1; !state[x][y]; i ^= 1) {
				++cnt1;
				if (i) --x; else --y;
			}
			x = tx, y = ty;
			for (int i = 0; !state[x][y]; i ^= 1) {
				++cnt2;
				if (i) ++x; else ++y;
			}
			ans += cnt1 * cnt2 - 1;
		}
		printf("%lld\n", ans);
	}
	return 0;
}