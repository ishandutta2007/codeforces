#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 2.1e5;
int N;
vector<pair<int, ll>> adj[MAXN];

int sz[MAXN];
int cnt[MAXN];
ll G;
ll B;

void dfs(int cur, int prv) {
	sz[cur] = 1;
	cnt[cur] = 1;
	for (auto it : adj[cur]) {
		int nxt = it.first;
		if (nxt == prv) continue;
		dfs(nxt, cur);
		sz[cur] += sz[nxt];
		cnt[cur] += cnt[nxt];
		G += it.second * cnt[nxt];
		B += it.second * min(sz[nxt], N - sz[nxt]);
	}
	cnt[cur] &= 1;
}

pair<ll, ll> go() {
	G = 0;
	B = 0;
	dfs(1, 0);
	return pair<ll, ll>(G, B);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> N; N *= 2;
		for (int i = 0; i < N-1; i++) {
			int a, b; ll v; cin >> a >> b >> v;
			adj[a].push_back({b, v});
			adj[b].push_back({a, v});
		}

		auto res = go();
		cout << res.first << ' ' << res.second << '\n';

		for (int i = 1; i <= N; i++) {
			adj[i] = {};
		}
	}

	return 0;
}