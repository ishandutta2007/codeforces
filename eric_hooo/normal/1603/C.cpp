#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int mod = 998244353;

void ADD(int &x, int y) {
	x += y;
	if (x >= mod) x -= mod;
}

int dp[100010];
int a[100010];
vector <pii> all, lst;
vector <int> f, g;

int main() {
	int T; scanf("%d", &T);
	while (T--) {
		int n; scanf("%d", &n);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &a[i]);
		}
		int ans = 0;
		lst.clear(), g.clear();
		for (int i = n; i >= 1; i--) {
			int x = a[i];
			all.clear();
			for (int l = 1; l <= x; ) {
				int v = x / l, r = x / v;
				all.push_back(mp(v + (v * l != x), l));
				if (l < r && v * r == x) all.push_back(mp(v, r));
				l = r + 1;
			}
			f.clear(), f.resize(all.size(), 0);
			int pos = 0;
			for (int j = 0; j < all.size(); j++) {
				int x = all[j].fi, v = all[j].se - 1;
				while (pos < lst.size() && lst[pos].fi >= x) ADD(f[j], g[pos]), pos++;
				if (j == 0) ADD(f[0], 1);
				ADD(ans, 1ll * i * f[j] % mod * v % mod);
			}
			for (auto &it : all) {
				if (it.fi * it.se != x) it.fi--;
			}
			swap(all, lst), swap(f, g);
		}
		printf("%d\n", ans);
	}
	return 0;
}