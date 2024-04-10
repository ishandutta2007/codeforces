#include <bits/stdc++.h>
#define MOD 998244353
using namespace std;

#define rep(i, a, b) for(int i = a; i < (b); ++i)
#define rrep(i, a, b) for(int i = (a-1); i >= (b); --i)
#define trav(a, x) for(auto& a : x)
#define all(x) begin(x), end(x)
#define sz(x) (int)(x).size()
typedef long long ll;
typedef pair<int, int> pii;
typedef vector<int> vi;

void solve() {
	int n;
	cin >> n;
	vector<vector<int>> adj(n);
	vector<int> deg(n);
	vector<bool> has_deg(n);
	ll tot = 1;
	rep(i,0,n-1) {
		tot = (tot * 2) % MOD;
		int u, v;
		cin >> u >> v;
		--u; --v;
		adj[u].push_back(v);
		adj[v].push_back(u);
		deg[u]++;
		deg[v]++;
	}
	vector<int> dis(n, n);
	queue<int> dfs;
	rep(i,0,n) {
		assert(sz(adj[i]) == deg[i]);
		if (deg[i] == 1) {
			dfs.push(i);
		}
	}
	auto deg_left = deg;
	int cur_dis = 1;
	while (!dfs.empty()) {
		queue<int> new_dfs;
		while (!dfs.empty()) {
			int cur = dfs.front();
			dis[cur] = cur_dis;
			dfs.pop();
			for (int to : adj[cur]) {
				--deg_left[to];
				if (deg_left[to] == 1) {
					new_dfs.push(to);
				}
			}
		}
		dfs = new_dfs;
		++cur_dis;
	}
	rep(i,0,n) {
		has_deg[deg[i]] = true;
		assert(dis[i] > 0);
		assert(deg[i] > 0);
	}
	auto deg_init = deg;
	vector<int> ans(n+1);
	ans[1] = tot;
	rep(g,2,n+1) {
		bool ok = false;
		for (int j = g; j < n; j += g) {
			if (has_deg[j])
				ok = true;
		}
		if (!ok)
			continue;
		deg = deg_init;
		priority_queue<pair<int, int>> q;
		rep(i,0,n) {
			assert(sz(adj[i]) == deg[i]);
			if (deg[i]%g == 0) {
				q.push(make_pair(-dis[i], i));
			}
		}
		vector<bool> erased(n);
		int erased_n = 0;
		while (!q.empty()) {
			int cur = q.top().second;
			q.pop();
			if (deg[cur]%g || erased[cur])
				continue;
			erased[cur] = true;
			++erased_n;
			int adjs = 0;
			for (int to : adj[cur]) {
				if (!erased[to]) {
					++adjs;
					--deg[to];
					assert(deg[to] >= 0);
					if (deg[to]%g == 0)
						q.push(make_pair(-dis[to], to));
				}
			}
			assert(adjs == deg[cur]);
			assert(adjs%g == 0);
		}
		if (erased_n == n) {
			ans[g] = 1;
		}
	}
	rep(g,2,n+1) {
		if (!ans[g])
			continue;
		for (int j = 2*g; j < n; j += g) {
			if (ans[j]) {
				ans[g] = 0;
				break;
			}
		}
	}
	ans[1] = tot;
	rep(g,2,n+1)
		ans[1] -= ans[g];
	ans[1] %= MOD;
	if (ans[1] < 0)
		ans[1] += MOD;
	rep(i,1,n+1) {
		cout << ans[i] << " ";
	}
	cout << endl;
}

int main() {
	cin.sync_with_stdio(0); cin.tie(0);
	cin.exceptions(cin.failbit);
	int t;
	cin >> t;
	while (t--) {
		solve();
	}
}