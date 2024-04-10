#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

struct UF {
	int fa[3010];
	void clear(int n) {
		for (int i = 1; i <= n; i++) {
			fa[i] = i;
		}
	}
	int find(int x) {
		if (fa[x] == x) return x;
		return fa[x] = find(fa[x]);
	}
	void merge(int x, int y) {
		x = find(x), y = find(y);
		if (x == y) return ;
		fa[y] = x;
	}
}uf;

vector <int> ans;
vector <pii> all;
int G[3010][3010], in[3010], cnt[3010], nin[3010];
int n, m;

void dfs(int x) {
	for (int i = 1; i <= n; i++) {
		if (!G[x][i]) continue;
		G[x][i] = G[i][x] = 0;
		dfs(i);
	}
	ans.push_back(x);
}

void print() {
	reverse(ans.begin(), ans.end());
	printf("%d\n", ans.size());
	for (int i = 0; i < ans.size(); i++) {
		printf("%d ", ans[i]);
	}
	printf("\n");
}

int main() {
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		int x, y; scanf("%d%d", &x, &y);
		G[x][y] = G[y][x] = 1, in[x]++, in[y]++;
		all.push_back(mp(x, y));
	}
	int tot = 0;
	for (int i = 1; i <= n; i++) {
		tot += in[i] & 1;
	}
	if (tot <= 2) {
		int rt = 1;
		for (int i = 1; i <= n; i++) {
			if (in[i] & 1) {
				rt = i;
				break;
			}
		}
		dfs(rt);
		print();
		return 0;
	}
	for (int i = 1; i <= n; i++) {
		if (in[i] % 2 == 0) continue;
		for (int j = 1; j <= n; j++) {
			if (G[i][j] || i == j) cnt[j]++;
		}
	}
	for (int i = 1; i <= n; i++) {
		if (cnt[i] < tot - 1) continue;
		for (int j = 1; j <= n; j++) {
			if (i == j) continue;
			if (cnt[i] == tot - 1 && G[i][j]) continue;
			if (in[j] % 2 == 0) continue;
			uf.clear(n);
			for (int i = 1; i <= n; i++) {
				nin[i] = 0;
			}
			for (int k = 0; k < all.size(); k++) {
				int x = all[k].fi, y = all[k].se;
				if ((x == i || y == i) && x + y - i != j && in[x + y - i] & 1) continue;
				uf.merge(x, y);
				nin[x]++, nin[y]++;
			}
			int eq = -1;
			for (int k = 1; k <= n; k++) {
				if (!nin[k]) continue;
				int val = uf.find(k);
				if (eq == -1) eq = val;
				if (eq != val) goto END;
			}
			for (int k = 1; k <= n; k++) {
				if (k == i || k == j) continue;
				if (in[k] & 1) {
					G[i][k] = G[k][i] = 0;
					ans.push_back(i);
					ans.push_back(k);
				}
			}
			ans.push_back(-1);
			dfs(j);
			print();
			return 0;
			END:;
		}
	}
	printf("0\n");
	return 0;
}