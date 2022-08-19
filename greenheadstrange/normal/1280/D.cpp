#include <bits/stdc++.h>
using namespace std;
#define maxn 3010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, ll>
#define se second
#define mp make_pair
ll ksm(ll a, ll b) {
   if (!b) return 1;
   ll ns = ksm(a, b >> 1);
   ns = ns * ns % mod;
   if (b & 1) ns = ns * a % mod;
   return ns;
}
// head
int w[maxn], b[maxn], sz[maxn];
vi eg[maxn];
pi dp[maxn][maxn]; //   
pi add(pi a, pi b) {
	return mp(a.fi + b.fi, a.se + b.se);
}
const ll inf = 1e18;
void upd(int a) {
	dp[a][sz[a]] = mp(0, -inf);
	for (int i = sz[a] - 1; i >= 0; i--)
		dp[a][i + 1] = max(dp[a][i + 1], mp(dp[a][i].fi + (dp[a][i].se > 0), 0ll));
}
pi r[maxn];
void dfs(int a, int fa) {
//	cout << a << ' ' << w[a] << ' ' << fa << endl;
	dp[a][0] = mp(0, w[a]);
	sz[a] = 1;
	for (auto v : eg[a]) {
		if (v == fa) continue;
		dfs(v, a);
		upd(v);	
		for (int i = 0; i < sz[v] + sz[a]; i++)
			r[i] = mp(0, -inf);
		for (int i = 0; i <= sz[v]; i++)
			for (int j = 0; j < sz[a]; j++)
				r[i + j] = max(r[i + j], add(dp[v][i], dp[a][j]));	
		sz[a] += sz[v];
		for (int i = 0; i < sz[a]; i++)
			dp[a][i] = r[i];		
	}

}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int n, m;
		scanf("%d%d", &n, &m);
		for (int i = 1; i <= n; i++) {
			scanf("%d", &b[i]);
			eg[i].clear();
		}
		for (int i = 1; i <= n; i++)
			scanf("%d", &w[i]), w[i] -= b[i];
		for (int i = 1; i < n; i++) {
			int u, v;
			scanf("%d%d", &u, &v);
			eg[u].pb(v), eg[v].pb(u);
		}
		dfs(1, 0);
		int ans = dp[1][m - 1].fi + (dp[1][m - 1].se > 0);
		cout << ans << endl;
	}
	return 0;
}

/*
3
4 3
10 160 70 50
70 111 111 0
1 2
2 3
3 4
2 1
143 420
214 349
2 1
4 3
10 160 70 50
70 111 111 0
1 2
2 3
3 4
*/