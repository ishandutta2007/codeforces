#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second

//#pragma GCC optimize ("O3")
//#pragma GCC target("tune=native")

//mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
//#include <ext/pb_ds/assoc_container.hpp>
//#include <ext/pb_ds/tree_policy.hpp>
//using namespace __gnu_pbds;
//typedef tree<int, null_type, less_equal<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

using namespace std;
using ll = long long;
using pi = pair<int, int>;
using vi = vector<int>;

const int nax = 200 * 1000 + 10;
int t;
int n;
vi V[nax];
int topo[nax], nr;
bool vis[nax];
int dp[nax];
int inv[nax];

void dfs(int x) {
	vis[x] = true;
	for(auto nbh : V[x]) if(!vis[nbh]) {
		dfs(nbh);
	}
	topo[nr++] = x;
	inv[x] = nr - 1;
}


int main() {
	ios_base::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while(t--) {
		cin >> n;
		for(int i = 1; i <= n; ++i) {
			V[i].clear();
		}
		for(int i = 1; i <= n; ++i) {
			vis[i] = false;
			int k;
			cin >> k;
			for(int x, j = 1; j <= k; ++j) {
				cin >> x;
				V[i].PB(x);
			}
		}
		nr = 1;
		for(int i = 1; i <= n; ++i) {
			if(!vis[i]) {
				dfs(i);
			}
		}
		bool ok = true;
		for(int i = 1; i <= n; ++i) {
			int mx = 1;
			int u = topo[i];
			for(auto nbh : V[u]) {
				mx = max(mx, dp[nbh] + (nbh > u));
				if(inv[nbh] > inv[u]) {
					ok = false;
				}
			}
			dp[u] = mx;
		}
		if(!ok) {
			cout << "-1\n";
			continue;
		}
		int ans = 0;
		for(int i = 1; i <= n; ++i) {
			ans = max(ans, dp[i]);
		}
		cout << ans << "\n";
	}
}