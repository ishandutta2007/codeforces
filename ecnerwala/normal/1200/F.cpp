#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e3;
const int MOD = 2520;

int N;
int K[MAXN];

const int MAXM = 12;
int M[MAXN];
int E[MAXN][MAXM];

const int MAXV = MAXN * MOD;
int V;
int nxt[MAXV];

int ans[MAXV];
int vis[MAXV];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N;
	for (int i = 0; i < N; i++) {
		cin >> K[i];
		K[i] %= MOD;
		if (K[i] < 0) K[i] += MOD;
	}

	for (int i = 0; i < N; i++) {
		cin >> M[i];
		for (int j = 0; j < M[i]; j++) {
			cin >> E[i][j];
			E[i][j] --;
		}
	}
	
	V = N * MOD;
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < MOD; j++) {
			int nj = (j + K[i]) % MOD;
			nxt[i * MOD + j] = E[i][nj % M[i]] * MOD + nj;
		}
	}

	for (int v = 0; v < V; v++) {
		vis[v] = -1;
	}
	for (int v = 0; v < V; v++) {
		if (ans[v]) continue;
		int t, h;
		for (t = nxt[v], h = nxt[nxt[v]]; ans[t] == 0 && t != h; t = nxt[t], h = nxt[nxt[h]]) { }

		if (!ans[t]) {
			for (int cur = nxt[t]; true; cur = nxt[cur]) {
				ans[t] += (vis[cur/MOD] != v);
				vis[cur/MOD] = v;
				if (cur == t) break;
			}

			for (int cur = nxt[t]; true; cur = nxt[cur]) {
				ans[cur] = ans[t];
				if (cur == t) break;
			}
		}

		for (int cur = v; cur != t; cur = nxt[cur]) {
			ans[cur] = ans[t];
		}
		assert(ans[v]);
	}

	int Q; cin >> Q;
	while (Q--) {
		int x, y; cin >> x >> y;
		x--; y %= MOD; if (y < 0) y += MOD;
		int v = x * MOD + y;
		cout << ans[v] << '\n';
	}

	return 0;
}