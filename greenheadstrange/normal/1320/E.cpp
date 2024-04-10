#include <bits/stdc++.h>
#define ll long long
#define maxn 500005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
vi eg[maxn];
int dep[maxn], dfn[maxn], sz[maxn];
int fa[maxn][20];
int dfcnt = 0;
void dfs(int a) {
	dfn[a] = ++dfcnt;
	sz[a] = 1;
	for (auto v : eg[a]) {
		if (v == fa[a][0]) continue;
		fa[v][0] = a;
		for (int i = 1; i < 20; i++)
			fa[v][i] = fa[fa[v][i - 1]][i - 1];
		dep[v] = dep[a] + 1;
		dfs(v);
		sz[a] += sz[v]; 
	}
}
vi ceg[maxn]; // 
int v[maxn], s[maxn];
int k, m;
int t[maxn];
bool chk(int a, int b) {
	return dfn[b] >= dfn[a] && dfn[b] <= dfn[a] + sz[a] - 1;
}
int lca(int a, int b) {
	if (dep[a] < dep[b]) swap(a, b);
	for (int i = 19; i >= 0; i--)
		if (dep[fa[a][i]] >= dep[b]) a = fa[a][i];
	for (int i = 19; i >= 0; i--)
		if (fa[a][i] != fa[b][i])
			a = fa[a][i], b = fa[b][i];
	if (a != b) return fa[a][0];
	return a;
}
int dis(int a, int b) {
	int lc = lca(a, b);
	return dep[a] + dep[b] - 2 * dep[lc];
}
pi cal(int pl, int type) {
	int nd = dis(pl, v[type]);
	int cu = nd / s[type];
	if (nd % s[type]) cu++;
	return mp(cu, type);
}
pi dp[maxn];
int st[maxn], top;
int id[maxn]; //  
void wk1(int a) {
	if (id[a]) dp[a] = cal(a, id[a]);
	else dp[a] = mp(1e9, 0);
	for (auto v : ceg[a]) {
		wk1(v);
		if (dp[v].se)
			dp[a] = min(dp[a], cal(a, dp[v].se));
	}
//	cout << a << ' ' << dp[a].fi << ' ' << dp[a].se << endl;
} 
void wk2(int a) {
	for (auto v : ceg[a]) {
		dp[v] = min(dp[v], cal(v, dp[a].se));
		wk2(v);
	}
}
void work() {
	vector<pi> cur;
	for (int i = 1; i <= k; i++)
		cur.pb(mp(dfn[v[i]], v[i])), 
		id[v[i]] = i;
	for (int i = 1; i <= m; i++)
		cur.pb(mp(dfn[t[i]], t[i]));
	sort(cur.begin(), cur.end());
	vector<pi> fn = cur;
	fn.pb(mp(dfn[1], 1));
	for (int i = 0; i < cur.size() - 1; i++) {
		int g = lca(cur[i].se, cur[i + 1].se);
		fn.pb(mp(dfn[g], g));
	}
	sort(fn.begin(), fn.end());
	vi nid;
	for (int i = 0; i < fn.size(); i++)
		if (i == 0 || fn[i].se != fn[i - 1].se)
			nid.pb(fn[i].se);
	st[top++] = 1;
	for (int i = 1; i < nid.size(); i++) {
		while (top && !chk(st[top - 1], nid[i])) top--;
		ceg[st[top - 1]].pb(nid[i]);
	//	cout << "DAE" << st[top - 1] << ' ' << nid[i] << endl; 
		st[top++] = nid[i];
	}
	wk1(1);
	wk2(1);
	for (int i = 1; i <= m; i++)
		printf("%d ", dp[t[i]].se);
	printf("\n");
	for (auto v : nid)
		id[v] = 0, ceg[v].clear();
		
}
int main() {
	int n;
	cin >> n;
	dep[1] = 1;
	for (int i = 1; i < n; i++) {
		int x, y;
		scanf("%d%d", &x, &y);
		eg[x].pb(y), eg[y].pb(x);
	}
	dfs(1);
	int q;
	cin >> q;
	for (int i = 1; i <= q; i++) {
		scanf("%d%d", &k, &m);
		for (int i = 1; i <= k; i++) 
			scanf("%d%d", &v[i], &s[i]);
		for (int i = 1; i <= m; i++)	
			scanf("%d", &t[i]);
		work();
	}
	return 0;
}
/*
CHHOCH
*/