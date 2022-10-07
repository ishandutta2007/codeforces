#include<cstdio>
#include<map>
#include<vector>
int n, q;
int a[300300];
int edge[300300][2];
std::vector<int> el[300300];
int prt[22][300300];
int chk[300300];
int dep[300300];
struct pd {
	int x, y;
	bool operator<(const pd&r)const {
		if (x == r.x)return y < r.y;
		return x < r.x;
	}
};
pd ps[16000000];
std::map<pd, int> revps;
int pcnt;
int b[300300];
int crnode(int x, int y) {
	pd t;
	t.x = x;
	t.y = y;
	std::map<pd, int>::iterator ite = revps.find(t);
	if (ite != revps.end()) {
		return ite->second;
	}
	else {
		ps[pcnt] = t;
		revps[t] = pcnt;
		pcnt++;
		return pcnt - 1;
	}
}
int flipone(int x, int loc, int sz) {
	if (sz == 0)return x ^ 1;
	int hsz = 1 << (sz - 1);
	if (loc >= hsz) {
		return crnode(ps[x].x, flipone(ps[x].y, loc - hsz, sz - 1));
	}
	else {
		return crnode(flipone(ps[x].x, loc, sz - 1), ps[x].y);
	}
}
void dfs(int x) {
	//printf("d %d %d\n", x, b[x]);
	chk[x] = 1;
	for (int i = 0; i < el[x].size(); i++) {
		int y = el[x][i];
		if (chk[y] == 0) {
			dep[y] = dep[x] + 1;
			prt[0][y] = x;
			for (int j = 0; j < 20; j++) {
				prt[j + 1][y] = prt[j][prt[j][y]];
			}
			b[y] = flipone(b[x], a[y], 19);
			dfs(y);
		}
	}
}
int lca(int x, int y) {
	if (dep[x] > dep[y])return lca(y, x);
	int t = dep[y] - dep[x];
	for (int i = 20; i >= 0; i--) {
		if ((t >> i) % 2 == 1) {
			y = prt[i][y];
		}
	}
	for (int i = 20; i >= 0; i--) {
		if (prt[i][x] != prt[i][y]) {
			x = prt[i][x];
			y = prt[i][y];
		}
	}
	while (x != y) {
		x = prt[0][x];
		y = prt[0][y];
	}
	return x;
}
int finddiff(int x, int y, int l, int r, int cl, int cr, int invt) {
	//printf("z %d %d %d %d %d %d\n", x, y, l, r, cl, cr);
	if (x == y && (invt < cl || invt >= cr))return -1;
	if (r <= cl || l >= cr)return -1;
	if (cl + 1 == cr) {
		if (invt == cl && x != y)return -1;
		return cl;
	}
	int ch = (cl + cr) / 2;
	int tres = finddiff(ps[x].x, ps[y].x, l, r, cl, ch, invt);
	if (tres != -1)return tres;
	return finddiff(ps[x].y, ps[y].y, l, r, ch, cr, invt);
}
int main() {
	scanf("%d%d", &n, &q);
	for (int i = 1; i <= n; i++) {
		scanf("%d", &a[i]);
	}
	for (int i = 0; i < n - 1; i++) {
		scanf("%d%d", &edge[i][0], &edge[i][1]);
		el[edge[i][0]].push_back(edge[i][1]);
		el[edge[i][1]].push_back(edge[i][0]);
	}
	pcnt = 2;
	b[1] = 0;
	dep[1] = 0;
	pd t;
	t.x = 0;
	t.y = 0;
	revps[t] = 0;
	dfs(1);
	for (int i = 0; i < q; i++) {
		int u, v, l, r;
		scanf("%d%d%d%d", &u, &v, &l, &r);
		int d = lca(u, v);
		int x = b[u];
		int y = b[v];
		//printf("aaa%d %d %d\n", x, y, d);
		int ans = finddiff(x, y, l, r + 1, 0, 1 << 19, a[d]);
		printf("%d\n", ans);
	}
	return 0;
}