#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 100013
int N;
int par[MAXN];
vector<int> adj[MAXN];
int S[MAXN];
LL ans = 0;

void dfs(int n) {
	if (S[n] != -1) {
		ans += S[n] - (n ? S[par[n]] : 0);
	}
	else {
		if (adj[n].empty())
			return;
		int k = S[adj[n].front()];
		for (int v : adj[n])
			k = min(k, S[v]);
		if (k < S[par[n]]) {
			cout << -1 << endl;
			exit(0);
		}
		ans += k - S[par[n]];
		S[n] = k;
	}
	for (int v : adj[n])
		dfs(v);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> N;
	for (int i = 1; i < N; i++) {
		cin >> par[i]; --par[i];
		adj[par[i]].push_back(i);
	}

	for (int i = 0; i < N; i++) {
		cin >> S[i];
	}

	dfs(0);

	cout << ans << endl;
	return 0;
}