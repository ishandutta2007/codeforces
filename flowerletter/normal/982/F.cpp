#include <bits/stdc++.h>
using namespace std;
constexpr int N = 1e5 + 10;
int n, m, vis[N], id[N], c[N], deg[N], in[N];
vector<int> G[N], stk;
int bad[N];
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m;
	for(int i = 1; i <= m; i ++) {
		int u, v; cin >> u >> v;
		G[u].emplace_back(v);
	}
	vector<int> cir;
	function<bool(int)> dfs = [&] (int u) {
		vis[u] = in[u] = 1;
		stk.emplace_back(u);
		for(auto v : G[u]) {
			if(in[v]) {
				cir = vector<int> (find(stk.begin(), stk.end(), v), stk.end());
				return true;
			}
			if(!vis[v] && dfs(v)) return true;
		}
		in[u] = 0;
		stk.pop_back();
		return false;
	};
	for(int i = 1; i <= n; i ++) if(!vis[i]) if(dfs(i)) break;
	fill(vis + 1, vis + n + 1, 0);
	for(int i = 0; i < cir.size(); i ++) id[cir[i]] = i + 1, vis[cir[i]] = 2;//, cout << cir[i] << ' '; cout << '\n';
	auto add = [&] (int u, int v) {
		// cout << u << ' ' << v << '\n';
		c[0] --;
		if(u <= v) c[u] ++, c[v + 1] --;
		else c[0] ++, c[v + 1] --, c[u] ++;
	};
	for(int u = 1; u <= n; u ++) {
		for(auto v : G[u]) if(!(id[u] || id[v])) {
			deg[v] ++;
		}
	}
	queue<int> q;
	for(int i = 1; i <= n; i ++) if(!deg[i]) q.emplace(i);
	while(!q.empty()) {
		int u = q.front(); q.pop();
		for(auto v : G[u]) if(!(id[u] || id[v])) {
			if(--deg[v] == 0) q.emplace(v);
		}
	}
	if(*max_element(deg + 1, deg + n + 1) > 0) {
		cout << -1 << '\n';
		return 0;
	}
	fill(vis + 1, vis + n + 1, 0);
	for(int t : {0, 1}) {
		for(int i = cir.size() - 1; i >= 0; i --) {
			function<void(int)> dfs = [&] (int u) {
				vis[u] = 1;
				for(auto v : G[u]) if(!(id[u] && id[v] && id[u] % cir.size() == id[v] - 1)) {
					if(id[v]) add(id[v] - 1, i);
					if(!vis[v] && !id[v]) dfs(v);
				}
			};
			dfs(cir[i]);
		}
	}
	auto chk = [&] (int ans) {
		for(int u = 1; u <= n; u ++) {
			for(auto v : G[u]) if(u != ans && v != ans) {
				deg[v] ++;
			}
		}
		queue<int> q;
		for(int i = 1; i <= n; i ++) if(!deg[i]) q.emplace(i);
		while(!q.empty()) {
			int u = q.front(); q.pop();
			for(auto v : G[u]) if(u != ans && v != ans) {
				if(--deg[v] == 0) q.emplace(v);
			}
		}
		if(*max_element(deg + 1, deg + n + 1) > 0) {
			return false;
		}
		return true;
	};
	for(int i = 1; i < cir.size(); i ++) c[i] += c[i - 1];
	for(int i = 0; i < cir.size(); i ++) if(c[i] == 0) {
		if(chk(cir[i])) cout << cir[i] << '\n';
		else cout << -1 << '\n';
		return 0;
	}
	cout << -1 << '\n';
	return 0;
}