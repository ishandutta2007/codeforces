#include<iostream>
#include<string>
#include<cstdio>
#include<vector>
#include<cmath>
#include<algorithm>
#include<functional>
#include<iomanip>
#include<queue>
#include<ciso646>
#include<random>
#include<map>
#include<set>
#include<complex>
#include<bitset>
#include<stack>
#include<unordered_map>
#include<utility>
using namespace std;
typedef long long ll;
typedef unsigned int ui;
const ll mod = 998244353;
const ll INF = (ll)1000000007 * 1000000007;
typedef pair<int, int> P;
#define stop char nyaa;cin>>nyaa;
#define rep(i,n) for(int i=0;i<n;i++)
#define per(i,n) for(int i=n-1;i>=0;i--)
#define Rep(i,sta,n) for(int i=sta;i<n;i++)
#define rep1(i,n) for(int i=1;i<=n;i++)
#define per1(i,n) for(int i=n;i>=1;i--)
#define Rep1(i,sta,n) for(int i=sta;i<=n;i++)
typedef long double ld;
typedef complex<ld> Point;
const ld eps = 1e-2;
const ld pi = acos(-1.0);
typedef pair<ll, ll> LP;
const int mn = 300001;
int n,k;
int a[mn];
vector<int> G[mn];
bool used[mn];
vector<int> c[mn];

//lca
int root = 0;
int par[19][mn];
int depth[mn];
void dfs(int v, int p, int d) {
	par[0][v] = p;
	depth[v] = d;
	for (int i = 0; i < (int)G[v].size(); i++) {
		if (G[v][i] != p)dfs(G[v][i], v, d + 1);
	}
}
void init(int V) {
	dfs(root, -1, 0);
	for (int k = 0; k + 1 < 19; k++) {
		for (int v = 0; v < V; v++) {
			if (par[k][v] < 0)par[k + 1][v] = -1;
			else par[k + 1][v] = par[k][par[k][v]];
		}
	}
}
int lca(int u, int v) {
	if (depth[u] > depth[v])swap(u, v);
	for (int k = 0; k < 19; k++) {
		if ((depth[v] - depth[u]) >> k & 1) {
			v = par[k][v];
		}
	}
	if (u == v)return u;
	for (int k = 18; k >= 0; k--) {
		if (par[k][u] != par[k][v]) {
			u = par[k][u];
			v = par[k][v];
		}
	}
	return par[0][u];
}
bool comp(int a, int b) {
	return depth[a] > depth[b];
}
int col[mn];

bool vanish[mn];
//
bool dfs2(int id) {
	used[id] = true;
	bool res = false;
	if (a[id] == 0)res = true;
	rep(j, G[id].size()) {
		int to = G[id][j];
		if (used[to])continue;
		if (dfs2(to))vanish[to] = true;
		else res = false;
	}
	return res;
}

ll ans = 1;
ll dp[mn][2];

ll mod_inverse(ll x) {
	ll n = mod - 2; ll res = 1;
	while (n) {
		if (n % 2)res = res * x%mod;
		x = x * x%mod; n >>= 1;
	}
	return res;
}
//
void calc(int id) {
	used[id] = true;
	if (col[id] > 0) {
		dp[id][1] = 1;
		rep(j, G[id].size()) {
			int to = G[id][j];
			if (used[to]||vanish[to])continue;
			calc(to);
			if (col[id] != col[to]) {
				//if (dp[to][0] + dp[to][1] == 0)continue;
				ans = ans * (dp[to][0] + dp[to][1]) % mod;
			}
		}
	}
	else {
		vector<LP> vv;
		dp[id][0] = 1;
		rep(j, G[id].size()) {
			int to = G[id][j];
			if (used[to]||vanish[to])continue;
			calc(to);
			vv.push_back({ (dp[to][0]+dp[to][1])%mod,dp[to][1] });
		}
		ll s = 1;
		rep(j, vv.size()) {
			(dp[id][0] *= vv[j].first) %= mod;
			(s *= vv[j].first) %= mod;
		}
		rep(j, vv.size()) {
			(dp[id][1] += s * mod_inverse(vv[j].first) % mod*vv[j].second%mod) %= mod;
		}
	}
}
int main() {
	cin.tie(0);
	ios::sync_with_stdio(false);
	cin >> n>>k;
	rep(i, n) {
		cin >> a[i];
		if (a[i] > 0) {
			c[a[i]].push_back(i);
		}
		col[i] = a[i];
	}
	rep(i, n - 1) {
		int u, v; cin >> u >> v; u--; v--;
		G[u].push_back(v);
		G[v].push_back(u);
	}
	bool valid = true;
	init(n);
	rep1(i, k) {
		int z = c[i][0];
		rep1(j, c[i].size() - 1) {
			z = lca(z, c[i][j]);
		}
		if (col[z] > 0 && col[z] != i)valid = false;
		col[z] = i;
		sort(c[i].begin(), c[i].end(), comp);
		int len = c[i].size();
		rep(j, len) {
			int r = c[i][j];
			while (r!=z) {
				if (col[r] > 0 && col[r] != i)valid = false;
				if (col[r] > 0&&r!=c[i][j])break;
				col[r] = i; r = par[0][r];
			}
		}
	}
	dfs2(c[1][0]);
	fill(used, used + n, false);
	calc(c[1][0]);
	if (!valid)ans = 0;
	cout << ans << endl;
	//stop
	return 0;
}