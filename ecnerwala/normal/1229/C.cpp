#include<bits/stdc++.h>
using namespace std;

using ll = long long;

const int MAXN = 1.1e5;
const int MAXM = 1.1e5;
int N, M;
int X[MAXN];
vector<int> adj[MAXN];
vector<int> loses[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int e = 0; e < M; e++) {
		int a, b; cin >> a >> b; a--, b--;
		assert(a != b);
		if (a > b) swap(a,b);
		assert(a < b);
		adj[a].push_back(b);
		adj[b].push_back(a);
		loses[a].push_back(b);
	}
	ll ans = 0;
	for (int i = 0; i < N; i++) {
		ans += ll(int(adj[i].size()) - int(loses[i].size())) * ll(int(loses[i].size()));
	}
	cout << ans << '\n';
	int Q; cin >> Q;

	for (int q = 0; q < Q; q++) {
		int i; cin >> i; i--;
		ans -= ll(int(adj[i].size()) - int(loses[i].size())) * ll(int(loses[i].size()));
		for (int j : loses[i]) {
			ans -= ll(int(adj[j].size()) - int(loses[j].size())) * ll(int(loses[j].size()));
			loses[j].push_back(i);
			ans += ll(int(adj[j].size()) - int(loses[j].size())) * ll(int(loses[j].size()));
		}
		loses[i] = {};
		cout << ans << '\n';
	}

	return 0;
}