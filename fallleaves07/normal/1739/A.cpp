#include<bits/stdc++.h>
using namespace std;
using LL = long long;

void solve() {
	int n, m;
	cin >> n >> m;
	const int dr[2][8] = {{-1, -1, 1, 1, -2, -2, 2, 2}, {-2, 2, -2, 2, -1, 1, -1, 1}};
	int ansx = 1, ansy = 1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int cnt = 0;
			for (int d = 0; d < 8; d++) {
				int x = i + dr[0][d], y = j + dr[1][d];
				if (x >= 1 && x <= n && y >= 1 && y <= n) {
					++cnt;
				}
			}
			if (!cnt) {
				ansx = i, ansy = j;
			}
		}
	}
	printf("%d %d\n", ansx, ansy);
}

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr), cout.tie(nullptr);
	int T;
	cin >> T;
	while (T--) {
		solve();
	}
    return 0;
}