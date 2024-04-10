#include <bits/stdc++.h>
using namespace std;
using i64 = long long;
constexpr int N = 2e5 + 10;
int n, k, fa[N], s[N];
map<int, i64> mp[N];
vector<int> G[N];
void dfs(int u, int k) {
	if(mp[u].count(k)) return ;
	if(G[u].empty()) {
		mp[u][k] = 1ll * k * s[u];
		return ;
	} 
	i64 &ans = mp[u][k];
	int a = k / G[u].size(), r = k % G[u].size();
	vector<i64> vec;
	for(auto v : G[u]) {
		dfs(v, a);
		if(r) {
			dfs(v, a + 1);
			vec.emplace_back(mp[v][a] - mp[v][a + 1]);
		}
		ans += mp[v][a];
	}
	nth_element(vec.begin(), vec.begin() + r, vec.end());
	for(int i = 0; i < r; i ++) ans -= vec[i];
	ans += 1ll * k * s[u];
}
int main() {
// 	freopen("in.txt", "r", stdin);
	ios::sync_with_stdio(false), cin.tie(0);
	int T;
	for(cin >> T; T; T --) {
		cin >> n >> k;
		for(int i = 2; i <= n; i ++) {
			cin >> fa[i];
			G[fa[i]].emplace_back(i);
		}
		for(int i = 1; i <= n; i ++) cin >> s[i];
		dfs(1, k);
		cout << mp[1][k] << '\n';
		for(int i = 1; i <= n; i ++) G[i].clear(), mp[i].clear();
	}
	return 0;
}