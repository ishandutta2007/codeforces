#include<bits/stdc++.h>
using namespace std;

const int MAXN = 3.1e5;
int N;
int A[MAXN];

using ll = long long;

const int MAXV = MAXN;
int V;
int cnt[MAXV];
unordered_map<int, int> adj[MAXV];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int Q; cin >> Q;
	while (Q--) {
		cin >> N;
		for (int i = 0; i < N; i++) {
			cin >> A[i];
		}

		ll ans = 0;
		V = 1;
		int ROOT = 0;
		cnt[ROOT]++;

		for (int i = 0; i < N; i++) {
			if (!adj[ROOT].count(A[i])) {
				adj[ROOT][A[i]] = V;
				adj[V][A[i]] = ROOT;
				V++;
			}
			ROOT = adj[ROOT][A[i]];
			ans += cnt[ROOT];

			cnt[ROOT]++;
		}
		for (int v = 0; v < V; v++) {
			cnt[v] = 0;
			adj[v] = {};
		}
		cout << ans << '\n';
	}

	return 0;
}