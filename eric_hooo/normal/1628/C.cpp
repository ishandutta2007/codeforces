#include <bits/stdc++.h>
using namespace std;

int a[1010][1010];

int dir[4][2] = {0, 1, 1, 0, 0, -1, -1, 0};
int vis[1010][1010];

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				vis[i][j] = 0;
			}
		}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				scanf("%d", &a[i][j]);
			}
		}
		int ans = 0;
		auto Solve = [&]() -> void {
			int cur = 1;
			auto Calc = [&](int x, int y) -> void {
				if ((x + y) % 2 == 0) return ;
				for (int i = 0; i < 4; i++) {
					int xx = x + dir[i][0], yy = y + dir[i][1];
					if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
					if (vis[xx][yy]) return ;
				}
				ans ^= a[x][y];
				for (int i = 0; i < 4; i++) {
					int xx = x + dir[i][0], yy = y + dir[i][1];
					if (xx < 0 || yy < 0 || xx >= n || yy >= n) continue;
					vis[xx][yy] = 1;
				}
			};
			for (int i = 0; i < n; i++) {
				Calc(0, i);
			}
			for (int i = 0; i < n; i++) {
				Calc(i, n - 1);
			}
			for (int i = n - 1; i >= 0; i--) {
				Calc(n - 1, i);
			}
			for (int i = n - 1; i >= 0; i--) {
				Calc(i, 0);
			}
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					Calc(i, j);
				}
			}
		};
		Solve();
		for (int i = 0; i < n; i++) {
			reverse(a[i], a[i] + n), reverse(vis[i], vis[i] + n);
		}
		Solve();
		printf("%d\n", ans);
	}
	return 0;
}