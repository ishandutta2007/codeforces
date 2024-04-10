#include <bits/stdc++.h>
using namespace std;

vector <int> JT;
vector <int> all[2010];
int f[2010], g[2010], pf[2010], pre[2010], suc[2010];
int n, a[2010];
int pg[2010], dg[2010];

int DST(int x, int y) {
	return min((x - y + n) % n, (y - x + n) % n);
}

vector <int> path;

void PTH(int x, int y) {
	int d1 = (y - x + n) % n, d2 = (x - y + n) % n;
	if (d1 < d2) path.push_back(d1);
	else path.push_back(-d2);
}

int main () {
	int S; scanf("%d%d", &n, &S), S--;
	for (int i = 0; i < n; i++) {
		scanf("%d", &a[i]);
		JT.push_back(a[i]);
	}
	for (int i = 0; i < n; i++) {
		int x = (i - 1 + n) % n;
		while (a[x] != a[i]) x = (x - 1 + n) % n;
		pre[i] = x;
		x = (i + 1) % n;
		while (a[x] != a[i]) x = (x + 1) % n;
		suc[i] = x;
	}
	sort(JT.begin(), JT.end()), JT.resize(unique(JT.begin(), JT.end()) - JT.begin());
	for (int i = 0; i < n; i++) {
		a[i] = lower_bound(JT.begin(), JT.end(), a[i]) - JT.begin() + 1;
		all[a[i]].push_back(i);
	}
	int N = JT.size();
	memset(f, 0x3f, sizeof(f)), memset(g, 0x3f, sizeof(g));
	for (int i = 0; i < all[1].size(); i++) {
		f[all[1][i]] = DST(all[1][i], S), pf[all[1][i]] = -1;
	}
	for (int it = 1; it <= N; it++) {
		if (all[it].size() == 1) g[all[it][0]] = f[all[it][0]];
		else {
			for (int i = 0; i < all[it].size(); i++) {
				int x = all[it][i];
				for (int dx = -1; dx <= 1; dx += 2) {
					int y = all[it][(i + dx + (int)all[it].size()) % all[it].size()];
					int dist = dx < 0 ? (y - x + n) % n : (x - y + n) % n;
					if (g[y] > f[x] + dist) g[y] = f[x] + dist, pg[y] = x, dg[y] = dx;
				}
			}
		}
		if (it == N) break;
		for (int i = 0; i < all[it].size(); i++) {
			int x = all[it][i];
			for (int j = 0; j < all[it + 1].size(); j++) {
				int y = all[it + 1][j];
				if (f[y] > g[x] + DST(x, y)) f[y] = g[x] + DST(x, y), pf[y] = x;
			}
		}
	}
	int ans = 0x3f3f3f3f, cur;
	for (int i = 0; i < all[N].size(); i++) {
		int x = all[N][i];
		cerr << "                g:" << x << " " << g[x] << endl;
		if (g[x] < ans) ans = g[x], cur = x;
	}
	printf("%d\n", ans);
	int isf = 0, num = N;
	while (1) {
		if (isf) {
			assert(cur >= 0 && cur < n);
			if (pf[cur] == -1) break;
			PTH(pf[cur], cur);
			cur = pf[cur], isf ^= 1, num--;
		} else {
			if (all[num].size() == 1) {
				isf ^= 1;
				continue;
			}
			int x = pg[cur], y = cur;
			if (dg[cur] < 0) {
				while (y != x) {
					int ny = pre[y];
					path.push_back(((y - ny + n) % n));
					y = ny;
				}
			} else {
				while (y != x) {
					int ny = suc[y];
					path.push_back(-(ny - y + n) % n);
					y = ny;
				}
			}
			cur = x, isf ^= 1;
		}
	}
	PTH(S, cur);
	reverse(path.begin(), path.end());
	for (int i = 0; i < path.size(); i++) {
		int x = path[i];
		if (x == 0) printf("+0\n");
		else if (x > 0) printf("+%d\n", x);
		else printf("%d\n", x);
	}
	return 0;
}