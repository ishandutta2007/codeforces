#include<bits/stdc++.h>
using namespace std;

const int MAXN = 6000;
int N, M, K;
vector<int> adj[MAXN];
int lastTime[MAXN];
vector<int> captureVals[MAXN];

int A[MAXN];
int B[MAXN];
int C[MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M >> K;
	for (int i = 0; i < N; i++) {
		cin >> A[i] >> B[i] >> C[i];
	}
	for (int e = 0; e < M; e++) {
		int u, v; cin >> u >> v;
		u--, v--;
		assert(u > v);
		adj[v].push_back(u);
	}
	for (int i = N-1; i >= 0; i--) {
		lastTime[i] = i;
		for (int nxt : adj[i]) {
			lastTime[i] = max(lastTime[i], nxt);
		}
		captureVals[lastTime[i]].push_back(C[i]);
	}

	multiset<int> captured;
	for (int i = 0; i < N; i++) {
		if (K < A[i]) {
			cout << -1 << '\n';
			exit(0);
		}
		while (int(captured.size()) > K - A[i]) {
			captured.erase(captured.begin());
		}
		K += B[i];
		for (auto v : captureVals[i]) {
			captured.insert(v);
		}
	}
	while (int(captured.size()) > K) {
		captured.erase(captured.begin());
	}
	int ans = 0;
	for (int v : captured) ans += v;
	cout << ans << '\n';

	return 0;
}