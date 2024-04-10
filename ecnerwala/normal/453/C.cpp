#include<bits/stdc++.h>

using namespace std;

const int MAXN = 1e5 + 20;

int N, M;
vector<int> adj[MAXN];
int X[MAXN];

bool vis[MAXN];

const int MAXK = MAXN * 4;
int K = 0;
int P[MAXK];

//returns final X[i]
int dfs(int a) {
	vis[a] = true;
	X[a] = !X[a];
	P[K++] = a;
	for(int n : adj[a]) {
		if(vis[n]) continue;
		if(dfs(n)) {
			P[K++] = a;
			P[K++] = n;
			P[K++] = a;
		} else {
			X[a] = !X[a];
			P[K++] = a;
		}
	}
	return X[a];
}

int main() {
	cin >> N >> M;
	for(int i = 0; i < M; i++) {
		int l, r; cin >> l >> r;
		adj[l].push_back(r);
		adj[r].push_back(l);
	}
	for(int i = 1; i <= N; i++) {
		cin >> X[i];
	}
	for(int i = 1; i <= N; i++) {
		if(X[i]) {
			bool shift = dfs(i);
			for(int j = 1; j <= N; j++) {
				if(X[j] && !vis[j]) {
					cout << -1 << '\n';
					return 0;
				}
			}
			cout << K - shift << '\n';
			for(int i = shift; i < K; i++) {
				cout << P[i] << ' ';
			}
			cout << '\n';
			return 0;
		}
	}
	cout << 0 << '\n';
	return 0;
}