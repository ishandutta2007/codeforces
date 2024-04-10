#include <bits/stdc++.h>
#define ll long long
#define maxn 200005 /*rem*/
#define mod 998244353
#define db double
#define vi vector<int>
#define pb push_back
#define mp make_pair
#define pi pair<int, int>
#define fi first
#define se second
using namespace std;
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
vi eg[maxn];
int dfn[maxn];
int sz;
int n, m, a, b;
int id[maxn][2];
int cnt[maxn][2];
void dfs(int x, int tp, int nid) {
	id[x][tp] = nid;
	if (x != a && x != b) sz++;
	dfn[x] = 1;
	for (auto v : eg[x]) {
		if (dfn[v]) continue;
		dfs(v, tp, nid);
	}
}		
ll c(int a) {
	return 1ll * a * (a - 1) / 2;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		scanf("%d%d%d%d", &n, &m, &a, &b);
		for (int i = 0; i <= n; i++)
			eg[i].clear(), dfn[i] = 0, cnt[i][0] = cnt[i][1] = 0;
		for (int i = 0; i < m; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			eg[u].pb(v), eg[v].pb(u);
		}
		ll ans = c(n - 2);
		for (int i = 0; i < 2; i++) {
			for (int i = 0; i <= n; i++)
				dfn[i] = 0;
			if (i == 0) dfn[a] = 1;
			else dfn[b] = 1;
			for (int j = 1; j <= n; j++) {
				if (dfn[j]) continue;
				dfs(j, i, j);
			}
		}
		for (int j = 1; j <= n; j++) {
			if (j != a && j != b)
				cnt[id[j][0]][0]++, 
				cnt[id[j][1]][1]++;
		}
		for (int i = 0; i < 2; i++)
			for (int j = 1; j <= n; j++)
				ans -= c(cnt[j][i]);
		map<pi, int> r;
		for (int i = 1; i <= n; i++)
			if (i != a && i != b)
				r[mp(id[i][0], id[i][1])]++;
		for (auto v : r)
			ans += c(v.se);
		
		printf("%lld\n", ans);
	}
	return 0;
}