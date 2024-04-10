#include <bits/stdc++.h>
#define REV(x) swap(T0[x], T1[x]), rev[x] ^= 1
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;

const int INF = 0x3f3f3f3f;

int D[500010];
int rt[2];
int node[2][500010];
int dep[2][500010], id[2][500010], dist[2][500010], num[2][500010], sz[2][500010];
int tot;
vector <pii> from[500010];

pii dfs(int x, int last, int d = 0) {
	pii maxj = mp(d, x);
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi;
		if (v == last) continue;
		maxj = max(maxj, dfs(v, x, d + 1));
	}
	return maxj;
}

void get_node_dep(int x, int last, int *node, int *dep, int *id, int *dist, int *num, int *sz) {
	id[x] = ++tot, num[tot] = x, sz[x] = 1;
	for (int i = 0; i < from[x].size(); i++) {
		int v = from[x][i].fi, d = from[x][i].se;
		if (v == last) continue;
		node[d] = v, dep[v] = dep[x] + 1, dist[v] = dist[x] ^ D[d];
		get_node_dep(v, x, node, dep, id, dist, num, sz);
		sz[x] += sz[v];
	}
}

struct Segment_tree {
	int T1[2000010], T0[2000010], rev[2000010];
	void pushup(int now) {
		T1[now] = max(T1[now << 1], T1[now << 1 | 1]);
		T0[now] = max(T0[now << 1], T0[now << 1 | 1]);
	}
	void pushdown(int now) {
		if (!rev[now]) return ;
		REV(now << 1), REV(now << 1 | 1);
		rev[now] = 0;
	}
	void Build(int now, int l, int r, int *num, int *dist, int *dep) {
		rev[now] = 0;
		if (l == r) {
			if (dist[num[l]]) T1[now] = dep[num[l]], T0[now] = -INF;
			else T0[now] = dep[num[l]], T1[now] = -INF;
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid, num, dist, dep), Build(now << 1 | 1, mid + 1, r, num, dist, dep);
		pushup(now);
	}
	void Update(int now, int l, int r, int L, int R) {
		if (l == L && r == R) {
			REV(now);
			return ;
		}
		pushdown(now);
		int mid = l + r >> 1;
		if (R <= mid) Update(now << 1, l, mid, L, R);
		else if (L > mid) Update(now << 1 | 1, mid + 1, r, L, R);
		else Update(now << 1, l, mid, L, mid), Update(now << 1 | 1, mid + 1, r, mid + 1, R);
		pushup(now);
	}
	int Query() {return T0[1];}
}seg[2];

int main () {
	int n; scanf("%d", &n);
	for (int i = 1; i < n; i++) {
		int x, y, d; scanf("%d%d%d", &x, &y, &d);
		D[i] = d;
		from[x].push_back(mp(y, i));
		from[y].push_back(mp(x, i));
	}
	int q; scanf("%d", &q);
	rt[0] = dfs(1, 1).se, rt[1] = dfs(rt[0], rt[0]).se;
	for (int i = 0; i < 2; i++) {
		tot = 0, get_node_dep(rt[i], rt[i], node[i], dep[i], id[i], dist[i], num[i], sz[i]);
		seg[i].Build(1, 1, n, num[i], dist[i], dep[i]);
	}
	while (q--) {
		int x; scanf("%d", &x);
		D[x] ^= 1;
		for (int i = 0; i < 2; i++) {
			int v = node[i][x];
			seg[i].Update(1, 1, n, id[i][v], id[i][v] + sz[i][v] - 1);
		}
		printf("%d\n", max(seg[0].Query(), seg[1].Query()));
	}
	return 0;
}