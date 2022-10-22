#include<bits/stdc++.h>
using namespace std;

#define fast ios::sync_with_stdio(false); cin.tie(NULL)
#define fi first
#define se second
#define pb push_back
#define eb emplace_back
#define all(v) (v).begin(), (v).end()
#define pre(a) cout<<fixed; cout.precision(a)

typedef long long ll;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
const int inf = 1e9;
const ll INF = 1e18;

int n, m, a, b;
vector<int> g[200010];
bool chk[200010];
int d[200010];
int p[200010];
int lo[200010];
ll sum[200010];

int dfs(int x, int y) {
	chk[x] = true;
	int ret = 1;

	for(auto i : g[x]) {
		if(chk[i] || i == y) continue;

		ret += dfs(i, y);
	}

	return ret;
}

int solve() {
	cin >> n >> m >> a >> b;

	for(int i=1; i<=n; i++) {
		g[i].clear();
		chk[i] = 0;
	}

	for(int i=0; i<m; i++) {
		int u, v;
		cin >> u >> v;
		g[u].pb(v);
		g[v].pb(u);
	}

	ll ans = (n - dfs(a, b) - 1);

	for(int i=1; i<=n; i++) chk[i] = false;
	
	ans *= (n - dfs(b, a) - 1);

	cout << ans << "\n";
}

int main() {
	fast;

	int t;
	cin >> t;
	while(t--) {
		solve();
	}
}