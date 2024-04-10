#include <bits/stdc++.h>
#define fi first
#define se second
#define mp make_pair
using namespace std;

typedef pair <int, int> pii;
typedef pair <pii, pii> ppp;

ppp e[200010];
long long ans[200010];
vector <pii> from[200010];
int fa[200010], size[200010];
int deep[200010];
int n, m;

int find(int x) {return x == fa[x] ? x : fa[x] = find(fa[x]);}

int head[200010], to[400010], nxt[400010], www[400010];
int tot, cnt;
int son[200010], top[200010], num[200010], id[200010];
int weight[200010];

void add(int u, int v, int w) {
	to[tot] = v, nxt[tot] = head[u], www[tot] = w, head[u] = tot++;
}

void dfs1(int x, int last) {
	fa[x] = last, size[x] = 1;
	for (int i = head[x]; ~i; i = nxt[i]) {
		int v = to[i], w = www[i];
		if (v == last) continue;
		deep[v] = deep[x] + 1, weight[v] = w, dfs1(v, x);
		if (son[x] == -1 || size[son[x]] < size[v]) son[x] = v;
		size[x] += size[v];
	}
}

void dfs2(int x, int t) {
	id[x] = ++cnt, num[cnt] = x, top[x] = t;
	if (!son[x]) return ;
	dfs2(son[x], t);
	for (int i = head[x]; ~i; i = nxt[i]) {
		int v = to[i];
		if (v == fa[x] || v == son[x]) continue;
		dfs2(v, v);
	}
}

struct Segment_tree {
	int maxj[800010];
	void Build(int now, int l, int r) {
		if (l == r) {
			maxj[now] = weight[num[l]];
			return ;
		}
		int mid = l + r >> 1;
		Build(now << 1, l, mid), Build(now << 1 | 1, mid + 1, r);
		maxj[now] = max(maxj[now << 1], maxj[now << 1 | 1]); 
	}
	int Query(int now, int l, int r, int L, int R) {
		if (L > R) return 0;
		if (l == L && r == R) return maxj[now];
		int mid = l + r >> 1;
		if (R <= mid) return Query(now << 1, l, mid, L, R);
		if (L > mid) return Query(now << 1 | 1, mid + 1, r, L, R);
		return max(Query(now << 1, l, mid, L, mid), Query(now << 1 | 1, mid + 1, r, mid + 1, R));
	}
}seg;

void get_pre() {
	dfs1(1, 1), dfs2(1, 1), seg.Build(1, 1, n);
}

int LCA(int x, int y) {
	int ans = 0;
	while (top[x] != top[y]){
		if (deep[top[x]] < deep[top[y]]) swap(x, y);
		ans = max(ans, seg.Query(1, 1, n, id[top[x]], id[x]));
		x = fa[top[x]];
	}
	ans = max(ans, seg.Query(1, 1, n, min(id[x], id[y]) + 1, max(id[x], id[y])));
	return ans;
}

int main() {
	memset(head, -1, sizeof(head));
	scanf("%d%d", &n, &m);
	for (int i = 0; i < m; i++) {
		scanf("%d%d%d", &e[i].se.fi, &e[i].se.se, &e[i].fi.fi);
		e[i].fi.se = i;
	}
	sort(e, e + m);
	for (int i = 1; i <= n; i++) {
		fa[i] = i;
	}
	long long cost = 0;
	for (int i = 0; i < m; i++) {
		int u = e[i].se.fi, v = e[i].se.se, w = e[i].fi.fi, id = e[i].fi.se;
		if (find(u) == find(v)) continue;
		add(u, v, w), add(v, u, w);
		fa[find(u)] = find(v);
		cost += w, ans[id] = -1;
	}
	get_pre();
	for (int i = 0; i < m; i++) {
		int u = e[i].se.fi, v = e[i].se.se, w = e[i].fi.fi, id = e[i].fi.se;
		if (ans[id] == -1) ans[id] = cost;
		else ans[id] = cost - LCA(u, v) + w;
	}
	for (int i = 0; i < m; i++) {
		printf("%I64d\n", ans[i]);
	}
	return 0;
}