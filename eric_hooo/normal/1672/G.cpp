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

int n, m;
char s[2010][2010];

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < n; i++) {
		scanf("%s", s[i]);
	}
	if (n % 2 + m % 2 == 0) {
		int ans = 1;
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '?') ans = ans * 2 % mod;
			}
		}
		printf("%d\n", ans);
		return 0;
	}
	if (n % 2 + m % 2 == 1) {
		if (m % 2 == 0) {
			static char t[2010][2010];
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					t[j][i] = s[i][j];
				}
			}
			swap(n, m);
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < m; j++) {
					s[i][j] = t[i][j];
				}
			}
		}
		int ans = 1, need = -1;
		for (int i = 0; i < n; i++) {
			int has = 0, rel = 0;
			for (int j = 0; j < m; j++) {
				if (s[i][j] == '?') has++;
				else rel ^= s[i][j] == '1';
			}
			if (!has) {
				if (need == -1) need = rel;
				if (need != rel) {
					printf("0\n");
					return 0;
				}
			} else {
				has--;
				while (has--) ans = ans * 2 % mod;
			}
		}
		if (need == -1) ans = ans * 2 % mod;
		printf("%d\n", ans);
		return 0;
	}
	static char old[2010][2010]; memcpy(old, s, sizeof(s));
	auto Solve = [&](int Z) -> int {
		// cerr << " Solve:" << endl;
		memcpy(s, old, sizeof(s));
		auto Upd = [&](char &x, char y) {
			x = x == '?' ? '?' : '0' + (x ^ y);
		};
		static vector <int> G[4010]; for (int i = 0; i <= 4005; i++) G[i].clear();
		for (int i = 1; i < n; i++) {
			for (int j = 1; j < m; j++) {
				if (s[i][j] != '?') {
					Upd(s[i][0], s[i][j]);
					Upd(s[0][j], s[i][j]);
					Upd(s[0][0], s[i][j]);
					s[i][j] = '-';
				} else {
					G[i].push_back(n + j), G[n + j].push_back(i);
				}
			}
		}
		static int vis[4010], dep[4010], fa[4010]; memset(vis, 0, sizeof(vis));
		static vector <int> node;
		auto S = [&](int x) -> char {return x == 0 ? s[0][0] : x < n ? s[x][0] : s[0][x - n];};
		function <void(int, int)> dfs;
		dfs = [&](int x, int last) {
			vis[x] = 1, fa[x] = last, node.push_back(x);
			for (auto v : G[x]) if (!vis[v]) {
				dep[v] = dep[x] + 1, dfs(v, x);
			}
		};
		static int f[2]; f[0] = 1, f[1] = 0;
		for (int i = 1; i < n + m; i++) if (!vis[i] && i != n) {
			node.clear(), dep[i] = 0, dfs(i, i);
			int dim1 = 0, dim2 = 0;
			static vector <int> p; p.clear();
			for (auto x : node) {
				// cerr << "       x:" << x << endl;
				if (S(x) == '1' - Z) dim1 ^= 1, dim2 ^= dep[x] & 1;
				if (S(x) == '?') p.push_back(1 << 1 | (dep[x] & 1));
				for (auto v : G[x]) if (v != fa[x] && fa[v] != x && dep[x] < dep[v]) {
					p.push_back(0 << 1 | (dep[x] + dep[v] + 1 & 1));
				}
			}
			// cerr << "        dim:" << dim1 << " " << dim2 << endl;
			static int dp[4]; memset(dp, 0, sizeof(dp)), dp[dim1 << 1 | dim2] = 1;
			for (auto x : p) {
				// cerr << "       x:" << x << endl;
				static int ndp[4]; memcpy(ndp, dp, sizeof(ndp));
				for (int i = 0; i < 4; i++) {
					ADD(ndp[i ^ x], dp[i]);
				}
				memcpy(dp, ndp, sizeof(dp));
			}
			{
				// cerr << "      dp:" << dp[0] << " " << dp[1] << endl;
				static int nf[2]; memset(nf, 0, sizeof(nf));
				for (int i = 0; i < 2; i++) {
					for (int j = 0; j < 2; j++) {
						ADD(nf[i ^ j], 1ll * f[i] * dp[j] % mod);
					}
				}
				memcpy(f, nf, sizeof(f));
			}
		}
		int ans = 0;
		if (S(0) != '1') ADD(ans, f[0 ^ Z]);
		if (S(0) != '0') ADD(ans, f[1 ^ Z]);
		return ans;
	};
	int ans = 0;
	ADD(ans, Solve(0));
	// for (int i = 0; i < n; i++) {
	// 	for (int j = 0; j < m; j++) {
	// 		if (old[i][j] != '?') old[i][j] = old[i][j] == '0' ? '1' : '0';
	// 	}
	// }
	ADD(ans, Solve(1));
	printf("%d\n", ans);
	return 0;
}