#include<bits/stdc++.h>
using namespace std;

const int MAXN = 15;
int N, M;
bool adj[MAXN][MAXN];

bool isEar[1 << MAXN][MAXN][MAXN];
int prvEar[1 << MAXN][MAXN][MAXN];

int dp[1 << MAXN];
pair<int, pair<int, int>> prv[1 << MAXN];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> M;
	for (int i = 0; i < M; i++) {
		int u, v; cin >> u >> v; u--, v--;
		adj[u][v] = adj[v][u] = true;
	}

	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++) {
			if (adj[i][j]) isEar[0][i][j] = true;
		}
	}

	for (int m = 1; m < (1 << N); m++) {
		for (int i = 0; i < N; i++) {
			if (m & (1 << i)) continue;
			for (int j = 0; j < N; j++) {
				if (m & (1 << j)) continue;
				for (int k = 0; k < N; k++) {
					if (!(m & (1 << k))) continue;
					if (isEar[m ^ (1 << k)][i][k] && adj[k][j] && ((m ^ (1 << k)) || i != j)) {
						//cerr << "ear " << m << ' ' << i << ' ' << j << '\n';
						isEar[m][i][j] = true;
						prvEar[m][i][j] = k;
					} 
				}
			}
		}
	}

	memset(dp, -1, sizeof(dp));
	dp[1] = 0;
	// always include 1
	for (int m = 2; m < (1 << N); m ++) {
		for (int k = (m-1) & m; ; k = (k-1) & m) {
			for (int i = 0; i < N; i++) {
				if (!(k & (1 << i))) continue;
				for (int j = 0; j < N; j++) {
					if (!(k & (1 << j))) continue;
					if (isEar[m ^ k][i][j]) {
						if (dp[k] != -1 && (dp[m] == -1 || dp[k]+1 < dp[m])) {
							//cerr << "graph " << m << ' ' << k << ' ' << i << ' ' << j << '\n';
							dp[m] = dp[k]+1;
							prv[m].first = m^k;
							prv[m].second = make_pair(i, j);
						}
					}
				}
			}
			if (k == 0) break;
		}
	}

	assert(dp[(1<<N)-1] != -1);
	cout << dp[(1 << N) - 1] + N-1 << '\n';
	for (int cur = (1 << N) - 1; cur != 1; ) {
		assert(dp[cur] != -1);
		int m = prv[cur].first;
		int i, j; tie(i,j) = prv[cur].second;
		assert((m & cur) == m);
		//cerr << "Out ear " << cur << ' ' << m << ' ' << i << ' ' << j << '\n';

		cur ^= m;

		while (m) {
			assert(isEar[m][i][j]);
			int k = prvEar[m][i][j];
			assert(m & (1 << k));
			cout << j+1 << ' ' << k+1 << '\n';
			j = k;
			m ^= (1 << k);
		}
		cout << i+1 << ' ' << j+1 << '\n';
	}

	return 0;
}