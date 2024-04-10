#include <bits/stdc++.h>
using namespace std;

const int mod = 998244353;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

void SUB(int &x, int y) {
	x -= y;
	if (x < 0) x += mod;
}

int main() {
	int n; cin >> n;
	int m; cin >> m;
	static int G[20], up[20];
	{
		for (int i = 0; i < m; i++) {
			int x, y; cin >> x >> y;
			if (x > y) swap(x, y);
			G[x] |= 1 << y, G[y] |= 1 << x;
			up[x] |= 1 << y;
		}
	}
	static int f[1 << 10]; f[0] = 1;
	for (int i = 0; i < n; i++) {
		static int g[1 << 10];
		for (int mask = 0; mask < (1 << 10); mask++) {
			for (int i = 0; i < 10; i++) {
				if (mask & up[i]) continue;
				ADD(g[(mask & G[i]) | 1 << i], f[mask]);
			}
		}
		for (int mask = 0; mask < (1 << 10); mask++) {
			f[mask] = g[mask], g[mask] = 0;
		}
	}
	int ans = 0;
	for (int i = 0; i < (1 << 10); i++) {
		ADD(ans, f[i]);
	}
	printf("%d\n", ans);
	return 0;
}