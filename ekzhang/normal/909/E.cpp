#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N, M;
vector<int> adj[MAXN];
int E[MAXN];
int dp[MAXN];
bool visited[MAXN];
int ans;

void dfs(int n) {
	if (visited[n]) return;
	visited[n] = true;
	int vale = 0, val = 0;
	for (int v : adj[n]) {
		dfs(v);
		if (E[v]) vale = max(vale, dp[v]);
		else val = max(val, dp[v]);
	}
	if (E[n]) {
		dp[n] = max(vale, val + 1);
	}
	else {
		dp[n] = max(val, vale);
	}
	ans = max(ans, dp[n]);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N >> M;
	for (int i = 0; i < N; i++) {
		cin >> E[i];
	}

	for (int i = 0; i < M; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b);
	}

	for (int i = 0; i < N; i++) {
		dfs(i);
	}

	cout << ans << endl;
	return 0;
}