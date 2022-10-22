#include <bits/stdc++.h>
using namespace std;
#define _USE_MATH_DEFINES

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
template <typename T>
using ordered_set = tree<T, null_type, less<T>, rb_tree_tag, tree_order_statistics_node_update>;

typedef long long ll;
typedef long double ld;
typedef pair<int,int> pii;
typedef pair<ll,ll> pll;
typedef pair<ld,ld> pdd;
typedef complex<ld> pt;

const char nl = '\n';
const ll INF = 0x3f3f3f3f;
const ll INFLL = 0x3f3f3f3f3f3f3f3f;
const ll MOD = 1e9+7;
const ld EPS = 1e-13;
mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

struct Item {
	int cnt; ll val;
	bool operator < (const Item& o) const {
		if(cnt != o.cnt) return cnt < o.cnt;
		else return val < o.val;
	}
	Item combine(const Item& o) const {
		return { cnt + o.cnt, val + o.val };
	}
	Item cut(const Item& o) const {
		return { cnt + o.cnt + (o.val > 0), val };
	}
};

const int N = 3e3+1;
vector<int> adj[N];
int a[N], b[N];
int sz[N];
vector<Item> dp[N], ndp[N];

void init(int n) {
	for(int i=1; i<=n; i++) {
		adj[i].clear();
		dp[i].clear();
	}
}

int solve(int u, int p, int k) {
	sz[u] = 1;
	for(int v:adj[u]) {
		if(v == p) continue;
		sz[u] += solve(v, u, k);
	}
	int len = min(k, sz[u]);
	dp[u].resize(len, {0, -INFLL});
	dp[u][0] = {0, b[u]-a[u]};
	for(int v:adj[u]) {
		if(v == p) continue;
		ndp[u].clear();
		ndp[u].resize(len, {0, -INFLL});
		for(int i=0; i<len && dp[u][i].val!=-INFLL; i++) {
			for(int j=0; i+j<len && j<dp[v].size(); j++) {
				ndp[u][i+j] = max(ndp[u][i+j], dp[u][i].combine(dp[v][j]));
				//cerr<<"combine -> "<<ndp[u][i+j].cnt<<" "<<ndp[u][i+j].val<<nl;
				//cerr<<" from "<<dp[u][i].cnt<<" "<<dp[u][i].val<<" and "<<dp[v][j].cnt<<" "<<dp[v][j].val<<nl;
				if(i+j+1<len) {
					//cerr<<"cut "<<u<<" "<<v<<nl;
					ndp[u][i+j+1] = max(ndp[u][i+j+1], dp[u][i].cut(dp[v][j]));
				}
			}
		}
		swap(dp[u], ndp[u]);
	}
	//cerr<<"@ node "<<u<<nl; for(int i=0; i<len; i++) {
	//cerr<<" dp "<<i<<" = "<<dp[u][i].cnt<<" "<<dp[u][i].val<<nl; }
	//cerr<<nl;
	return sz[u];
}

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int T;
	cin >> T;
	while (T--) {
		int n, k;
		cin >> n >> k;
		init(n);
		for(int i=1; i<=n; i++) {
			cin >> a[i];
		}
		for(int i=1; i<=n; i++) {
			cin >> b[i];
		}
		for(int i=1; i<n; i++) {
			int x, y;
			cin >> x >> y;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}
		solve(1, 0, k);
		int ans = dp[1][k-1].cnt + (dp[1][k-1].val > 0);
		cout << ans << nl;
	}

	return 0;
}