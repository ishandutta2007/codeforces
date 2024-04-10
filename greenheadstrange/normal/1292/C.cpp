#include <bits/stdc++.h>
#define ll long long
#define maxn 3005 /*rem*/
#define mod 1000000007
#define db double
#define vi vector<int>
#define pb push_back
#define pi pair<int, int>
#define mp make_pair
#define fi first
#define se second
using namespace std;
vi eg[maxn];
int sz[maxn], dfn[maxn], fa[maxn], dep[maxn], dfcnt;
void dfs(int a) {
	dfn[a] = ++dfcnt;
	sz[a] = 1;
	for (auto v : eg[a]) {
		if (v == fa[a]) continue;
		fa[v] = a, 
		dep[v] = dep[a] + 1;
		dfs(v);
		sz[a] += sz[v];
	}
} 
int u[maxn], v[maxn];
ll dp[maxn][maxn];
bool check(int a, int b) {
	return (dfn[b] >= dfn[a] && dfn[b] < dfn[a] + sz[a]);
}
int main() {
	int n;
	cin >> n;
	for (int i = 1; i < n; i++) {
		scanf("%d%d", &u[i], &v[i]);
		eg[u[i]].pb(v[i]), 
		eg[v[i]].pb(u[i]);
	}
	vector<pair<int, pi> > s;
	for (int i = 1; i <= n; i++) {
		dep[i] = 0, fa[i] = 0, dfcnt = 0, 
		dfs(i);
		for (int j = i + 1; j <= n; j++)
			s.pb(mp(dep[j], mp(i, j))), 
			s.pb(mp(dep[j], mp(j, i)));
		//	cout << "!!!" << i << ' ' << j << ' ' << dep[j] << endl;
	}
//	for (int i = 1; i <= n; i++)
//		cout << sz[i] << ' ' << dep[i] << ' ' << dfn[i] << ' ' << fa[i] << endl;
	sort(s.begin(), s.end());
	memset(dp, -1, sizeof(dp));
	for (int i = s.size() - 1; i >= 0; i--) {
		int nu = s[i].se.fi, nv = s[i].se.se;
		if (dp[nv][nu] != -1) {
			dp[nu][nv] = dp[nv][nu];
			continue;
		}
		dp[nu][nv] = 0;
		for (auto x : eg[nu])
			dp[nu][nv] = max(dp[nu][nv], dp[x][nv]);
		for (auto x : eg[nv])
			dp[nu][nv] = max(dp[nu][nv], dp[nu][x]);
		ll tt = 0;
		int rr = nu, gg = nv;
		if (dfn[nu] > dfn[nv]) swap(nu, nv);
		if (!check(nu, nv)) tt = sz[nu] * sz[nv];
		else {
			tt = sz[nv];
			for (auto x : eg[nu]) {
				if (x == fa[nu]) continue;
				else if (check(x, nv))
					tt *= (n - sz[x]);
			}
		}
	//	cout << "!!!" << nu << ' ' << nv << ' ' << tt << endl;
		dp[rr][gg] += tt;
	}
	ll ans = 0;
	for (int i = 1; i < n; i++)
		ans = max(ans, dp[u[i]][v[i]]);
	cout << ans << endl;
	return 0;
}
/*
1 2
..
*/