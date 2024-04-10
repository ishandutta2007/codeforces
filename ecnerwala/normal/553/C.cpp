#include<bits/stdc++.h>
using namespace std;

const int MOD = 1e9 + 7;

const int MAXN = 2e5;
const int MAXM = 2e5;

int N;
int M;

vector<pair<int, int>> adj[MAXN];

int A[MAXM];
int B[MAXM];
int C[MAXM];

int vis[MAXN];

bool dfs(int a, int s = 1) {
	assert(s == 1 || s == -1);
	if(vis[a] == -s) {
		return false;
	} else if(vis[a] == s) {
		return true;
	} else {
		vis[a] = s;
		for(auto it : adj[a]) {
			if(!dfs(it.first, it.second ? s : -s)) return false;
		}
		return true;
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> N >> M;

	for(int i = 0; i < M; i++) {
		cin >> A[i] >> B[i] >> C[i];
		A[i] --;
		B[i] --;
		adj[A[i]].push_back(make_pair(B[i], C[i]));
		adj[B[i]].push_back(make_pair(A[i], C[i]));
	}

	int res = (MOD + 1) / 2;
	for(int a = 0; a < N; a++) {
		if(!vis[a]) {
			if(dfs(a)) {
				res *= 2;
				if(res >= MOD) res -= MOD;
			} else {
				res = 0;
				break;
			}
		}
	}
	cout << res % MOD << '\n';
	return 0;
}