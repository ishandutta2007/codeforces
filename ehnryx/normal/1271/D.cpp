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

const int N = 5e3+1;
int a[N], b[N], c[N], last[N];
int dp[N][N];
vector<int> adj[N];

int main() {
	ios::sync_with_stdio(0); cin.tie(0);
	cout << fixed << setprecision(10);

	int n, m, k;
	cin >> n >> m >> k;
	for(int i=1; i<=n; i++) {
		cin >> a[i] >> b[i] >> c[i];
		last[i] = i;
	}
	for(int i=1; i<=m; i++) {
		int u, v;
		cin >> u >> v;
		last[v] = max(last[v], u);
	}

	for(int i=1; i<=n; i++) {
		adj[last[i]].push_back(c[i]);
	}
	for(int i=1; i<=n; i++) {
		sort(adj[i].begin(), adj[i].end(), greater<>());
	}

	fill(&dp[0][0], &dp[0][0]+N*N, -INF);
	dp[0][k] = 0;
	for(int i=1; i<=n; i++) {
		for(int j=a[i]; j<N; j++) {
			if(dp[i-1][j] < 0) continue;
			int nj = j + b[i];
			dp[i][nj] = max(dp[i][nj], dp[i-1][j]);
			for(int t=1, add=0; t<=nj && t<=adj[i].size(); t++) {
				add += adj[i][t-1];
				dp[i][nj-t] = max(dp[i][nj-t], dp[i-1][j] + add);
			}
		}
	}

	int res = -1;
	for(int j=0; j<N; j++) {
		res = max(res, dp[n][j]);
	}
	cout << res << nl;

	return 0;
}