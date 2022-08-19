#include<bits/stdc++.h>
using namespace std;

template <typename T> void setmax(T& a, T b) { if (b > a) a = b; }

using ll = long long;

const int MAXN = 4000;
int N, M;
ll V[MAXN];
vector<int> adj[MAXN];

pair<int, ll> dp[MAXN][MAXN];
int sz[MAXN];

pair<int, ll> tmp[MAXN];

void dfs(int cur, int prv) {
	dp[cur][0] = {0, V[cur]};
	sz[cur] = 1;
	for (int nxt : adj[cur]) {
		if (nxt == prv) continue;
		dfs(nxt, cur);
		for (int i = 0; i < sz[cur] + sz[nxt]; i++) {
			tmp[i] = {-1, 0};
		}
		for (int a = 0; a < sz[cur]; a++) {
			for (int b = 0; b < sz[nxt]; b++) {
				// don't cut
				setmax(tmp[a+b], {dp[cur][a].first + dp[nxt][b].first, dp[cur][a].second + dp[nxt][b].second});
				setmax(tmp[a+b+1], {dp[cur][a].first + dp[nxt][b].first + (dp[nxt][b].second > 0), dp[cur][a].second});
			}
		}
		for (int i = 0; i < sz[cur] + sz[nxt]; i++) {
			dp[cur][i] = tmp[i];
		}
		sz[cur] += sz[nxt];
	}
}

int go() {
	dfs(0, -1);
	auto res = dp[0][M-1];
	return res.first + (res.second > 0);
}

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int T; cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			V[i] = 0;
		}
		for (int i = 0; i < N; i++) {
			int b; cin >> b;
			V[i] -= b;
		}
		for (int i = 0; i < N; i++) {
			int w; cin >> w;
			V[i] += w;
		}

		for (int i = 0; i < N-1; i++) {
			int x, y; cin >> x >> y; x--, y--;
			adj[x].push_back(y);
			adj[y].push_back(x);
		}

		int ans = go();
		cout << ans << '\n';

		for (int i = 0; i < N; i++) {
			adj[i] = {};
		}
	}

	return 0;
}