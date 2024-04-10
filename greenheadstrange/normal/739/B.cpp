#include <bits/stdc++.h>
#define ll long long
#define maxn 400005 /*rem*/
#define mod 1000000007 
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
vi eg[maxn];
ll dep[maxn];
int dfn[maxn], sz[maxn];
int a[maxn];
int p[maxn], w[maxn];
int dfcnt = 0;
int fa[maxn][20];
void dfs(int a) {
	sz[a] = 1, dfn[a] = ++dfcnt;
	for (auto v : eg[a]) {
		if (v == p[a]) continue;
		fa[v][0] = a;
		for (int i = 1; i < 20; i++)
			fa[v][i] = fa[fa[v][i - 1]][i - 1];
		dep[v] = dep[a] + w[v];
		dfs(v);
		sz[a] += sz[v];
	}
}
ll ud[maxn];
vi qs[maxn];
int d[maxn];
int lb(int x) {
	return x & -x;
}
void upd(int pl, int x) {
	//cout << "U" << pl << ' ' << x << endl;
	while (pl < maxn)
		d[pl] += x, pl += lb(pl);
}
int q(int pl) {
	int ans = 0;
	while (pl) ans += d[pl], pl -= lb(pl);
//	cout << "Q" << pl << ' ' << ans << endl;
	return ans;
}
int ans[maxn];
int main() {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	for (int i = 2; i <= n; i++) {
		scanf("%d%d", &p[i], &w[i]);
		eg[p[i]].pb(i);
	}
	dfs(1);
	dep[0] = -1e18;
	for (int i = 1; i <= n; i++) {
		int v = i;
		for (int j = 19; j >= 0; j--) {
			int t = fa[v][j];
			if (dep[t] >= dep[i] - a[i]) v = t;
		}
	//	cout << i << ' ' << v << endl;
		if (p[v]) upd(dfn[p[v]], -1);
		upd(dfn[i], 1);
	}
	for (int i = 1; i <= n; i++)  
		ans[i] = q(dfn[i] + sz[i] - 1) - q(dfn[i] - 1);
	for (int i = 1; i <= n; i++)
		printf("%d ", ans[i] - 1);
 	return 0;
}