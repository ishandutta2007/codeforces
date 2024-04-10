#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const double PI = 4 * atan(1);

#define MAXN 300013
#define MOD 998244353
int T;
int N, M;
vector<int> adj[MAXN];
int color[MAXN];
int cnt[2];
bool bad;

LL pow2(int k) {
	if (!k) return 1;
	return 2 * pow2(k - 1) % MOD;
}

void dfs(int n, int b=0) {
	if (color[n] != -1) {
		if (color[n] != b)
			bad = true;
		return;
	}
	color[n] = b;
	cnt[b]++;
	for (int v : adj[n])
		dfs(v, !b);
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> T;
	while (T--) {
		cin >> N >> M;
		for (int i = 0; i < N; i++) {
			adj[i].clear();
			color[i] = -1;
		}
		for (int i = 0; i < M; i++) {
			int u, v;
			cin >> u >> v;
			--u; --v;
			adj[u].push_back(v);
			adj[v].push_back(u);
		}

		bad = false;
		LL ans = 1;
		for (int i = 0; i < N; i++) {
			if (color[i] == -1) {
				cnt[0] = cnt[1] = 0;
				dfs(i);
				if (bad) break;
				ans = (ans * (pow2(cnt[0]) + pow2(cnt[1]))) % MOD;
			}
		}

		if (bad)
			cout << 0 << '\n';
		else
			cout << ans << '\n';
	}

	cout.flush();
	return 0;
}