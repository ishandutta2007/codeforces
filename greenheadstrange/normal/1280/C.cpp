#include <bits/stdc++.h>
using namespace std;
#define maxn 200010
#define ll long long
#define db double
#define vi vector<int>
#define pb push_back
#define mod 998244353
#define fi first
#define pi pair<int, int>
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
vi eg[maxn], c[maxn];
ll g, b;
int sz[maxn];
int n;
void dfs(int a, int fa, int fl) {
	sz[a] = 1;
	for (int i = 0; i < eg[a].size(); i++) 
	{
		int v = eg[a][i], w = c[a][i];
		if (v == fa) continue;
		dfs(v, a, w);
		sz[a] += sz[v];
	}
	if (sz[a] & 1) g += fl;
	b += 1ll * min(sz[a], n - sz[a]) * fl;
}
int main() {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int k;
		cin >> k;
		n = 2 * k;
		g = b = 0;
		for (int j = 1; j <= n; j++)
			eg[j].clear(), c[j].clear();
		for (int j = 1; j < n; j++) {
			int u, v, w;
			scanf("%d%d%d", &u, &v, &w);
			eg[u].pb(v), eg[v].pb(u);
			c[u].pb(w), c[v].pb(w);
		}
		dfs(1, 0, 0);
		cout << g << ' ' << b << endl;
	}
	return 0;
}