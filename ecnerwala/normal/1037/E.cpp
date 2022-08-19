#include<bits/stdc++.h>
using namespace std;

const int MAXN = 2.1e5;
const int MAXM = 2.1e5;
int N, M, K;

int deg[MAXN];
vector<int> adj[MAXN];
bool dead[MAXN];

int A[MAXM][2];

int res[MAXM];

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M >> K;
	for (int m = 0; m < M; m++) {
		cin >> A[m][0] >> A[m][1];
		adj[A[m][0]].push_back(A[m][1]);
		adj[A[m][1]].push_back(A[m][0]);
		deg[A[m][0]] ++;
		deg[A[m][1]] ++;
	}

	int cnt = N;
	stack<int> q;
	for (int i = 1; i <= N; i++) {
		if (deg[i] < K) {
			cnt--;
			dead[i] = true;
			q.push(i);
		}
	}
	while (!q.empty()) {
		int cur = q.top(); q.pop();
		for (int nxt : adj[cur]) {
			deg[nxt] --;
			if (deg[nxt] < K) {
				if (!dead[nxt]) {
					cnt--;
					dead[nxt] = true;
					q.push(nxt);
				}
			}
		}
	}
	for (int m = M - 1; m >= 0; m--) {
		res[m] = cnt;

		int x = A[m][0], y = A[m][1];
		assert(adj[x].back() == y);
		assert(adj[y].back() == x);
		adj[x].pop_back();
		adj[y].pop_back();
		// remove this edge
		if (dead[x] || dead[y]) {
			// edge has already been removed
		} else {
			deg[x] --;
			deg[y] --;
			if (deg[x] < K) {
				cnt --;
				dead[x] = true;
				q.push(x);
			}
			if (deg[y] < K) {
				cnt --;
				dead[y] = true;
				q.push(y);
			}
		}
		while (!q.empty()) {
			int cur = q.top(); q.pop();
			for (int nxt : adj[cur]) {
				deg[nxt] --;
				if (deg[nxt] < K) {
					if (!dead[nxt]) {
						cnt--;
						dead[nxt] = true;
						q.push(nxt);
					}
				}
			}
		}
	}
	for (int m = 0; m < M; m++) {
		cout << res[m] << '\n';
	}

	return 0;
}