#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#define For(i,n) for (int i=0; i<n; i++)
#define FOR(i,a,b) for (int i=a; i<=b; i++)
#define Down(i,n) for (int i=n-1; i>=0; i--)
#define DOWN(i,a,b) for (int i=b; i>=a; i--)

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;
typedef vector<pt> pol;
typedef vector<int> vi;

const char nl = '\n';
const int INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-10;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

const int N = 1.5e5+1;

char val[N];
int par[N], depth[N], cmpr[N];
vector<int> tree[N];

int cnt[N][26], dp[N][26], sum[N];
int sz[N], height[N], parent[N];
bool bad[N];
vector<int> adj[N];

void compress(int u, int& id) {
	depth[u] = depth[par[u]] + 1;
	cmpr[u] = id;
	sz[id]++;
	if (val[u] && val[u] != '?') {
		cnt[id][val[u]-'a']++;
	}

	if (tree[u].size() == 1) {
		compress(tree[u][0], id);
	} else if (tree[u].size() == 2) {
		int cur = id;
		parent[++id] = cur;
		adj[cur].push_back(id);
		compress(tree[u][0], id);
		parent[++id] = cur;
		adj[cur].push_back(id);
		compress(tree[u][1], id);
		height[cur] = height[adj[cur][0]] + sz[adj[cur][0]];
	}
}

void precomp (int u) {
	sum[u] = 0;
	if (adj[u].empty()) {
		For(i,26) {
			dp[u][i] = cnt[u][i];
			sum[u] += dp[u][i];
		}
	} else {
		int l, r;
		precomp(l = adj[u][0]);
		precomp(r = adj[u][1]);
		int cur = 0;
		For(i,26) {
			dp[u][i] = max(dp[l][i], dp[r][i]);
			cur += dp[u][i];
			dp[u][i] += cnt[u][i];
			sum[u] += dp[u][i];
		}
		if (cur > height[u] || bad[l] || bad[r]) {
			bad[u] = true;
		}
	}
}

bool solve(int u) {
	for (; u; u=parent[u]) {
		sum[u] = 0;
		bad[u] = false;
		if (adj[u].empty()) {
			For(i,26) {
				dp[u][i] = cnt[u][i];
				sum[u] += dp[u][i];
			}
		} else {
			int l = adj[u][0];
			int r = adj[u][1];
			int cur = 0;
			For(i,26) {
				dp[u][i] = max(dp[l][i], dp[r][i]);
				cur += dp[u][i];
				dp[u][i] += cnt[u][i];
				sum[u] += dp[u][i];
			}
			if (cur > height[u] || bad[l] || bad[r]) {
				bad[u] = true;
			}
		}
	}
	return !bad[1];
}

//#define FILEIO
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); cout.tie(0);
	cout << fixed << setprecision(10);
#ifdef FILEIO
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
#endif

	int n, q;
	cin >> n >> q;

	FOR(i,2,n) {
		cin >> par[i] >> val[i];
		tree[par[i]].push_back(i);
	}
	compress(1, *(new int(1)));
	precomp(1);

	int dval = -1;
	bool same = true;
	FOR(i,1,n) {
		if (tree[i].size() == 0) {
			if (dval == -1) dval = depth[i];
			else if (dval != depth[i]) same = false;
		}
	}

	if (!same) {
		while (q--) {
			cout << "Fou" << nl;
		}
		return 0;
	}

	while (q--) {
		int u; char c;
		cin >> u >> c;
		if (val[u] != '?') cnt[cmpr[u]][val[u]-'a']--;
		val[u] = c;
		if (val[u] != '?') cnt[cmpr[u]][val[u]-'a']++;

		if (solve(cmpr[u])) {
			int ans = 0;
			For(i,26) {
				ans += (i+1) * (dp[1][i] + dval-1 - sum[1]);
				//cerr << i << " -> " << dp[1][i] << " + " << dval-1 << " - " << sum[1] << nl;
			}
			cout << "Shi" << " " << ans << nl;
		} else {
			cout << "Fou" << nl;
		}
	}

	return 0;
}