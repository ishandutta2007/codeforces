#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 5.1e5;
int N, K;
vector<pair<int, ll>> adj[MAXN];

pair<ll, ll> dfs(int cur, int prv) {
	pair<ll, ll> ans;
	vector<ll> cnds;
	for (auto e : adj[cur]) {
		int nxt = e.first;
		ll w = e.second;
		if (nxt == prv) continue;
		auto chVal = dfs(nxt, cur);
		chVal.second += w;

		ans.first += chVal.first;
		ans.second += chVal.first;
		if (chVal.second > chVal.first) {
			cnds.push_back(chVal.second - chVal.first);
		}
	}
	sort(cnds.begin(), cnds.end(), greater<int>());
	for (int i = 0; i < int(cnds.size()) && i < K-1; i++) {
		ans.second += cnds[i];
	}
	for (int i = 0; i < int(cnds.size()) && i < K; i++) {
		ans.first += cnds[i];
	}
	//cerr << cur << ' ' << prv << ' ' << ans.first << ' ' << ans.second << '\n';
	return ans;
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;
	while (Q--) {
		cin >> N >> K;
		for (int i = 0; i < N-1; i++) {
			int u, v; ll w; cin >> u >> v >> w; u--, v--;
			adj[u].emplace_back(v, w);
			adj[v].emplace_back(u, w);
		}

		cout << dfs(0,-1).first << '\n';

		for (int i = 0; i < N; i++) adj[i] = {};
	}

	return 0;
}