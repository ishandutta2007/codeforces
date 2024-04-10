#include<bits/stdc++.h>
using namespace std;

const int MAXN = 1.1e5;
int N;
char W[MAXN];
int nxt[MAXN][26];

const int MAXL = 260;
int L[3];
char R[3][MAXL];
int dp[MAXL][MAXL][MAXL];

const int MAXQ = 1100;
int Q;

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	cin >> N >> Q;
	cin >> W;
	for (int d = 0; d < 26; d++) nxt[N][d] = nxt[N+1][d] = N+1; // cycle at N+1
	for (int i = N-1; i >= 0; i--) {
		for (int d = 0; d < 26; d++) {
			nxt[i][d] = nxt[i+1][d];
		}
		nxt[i][W[i] - 'a'] = i+1;
	}

	for (int q = 0; q < Q; q++) {
		char op; cin >> op;
		int z; cin >> z; z--;
		if (op == '+') {
			cin >> R[z][L[z]];
			L[z]++;
			//cerr << "extending " << z << ' ' << L[z] << '\n';
			for (int i = (z == 0 ? L[0] : 0); i <= L[0]; i++) {
				for (int j = (z == 1 ? L[1] : 0); j <= L[1]; j++) {
					for (int k = (z == 2 ? L[2] : 0); k <= L[2]; k++) {
						//cerr << "recomputing " << i << ' ' << j << ' ' << k << '\n';
						dp[i][j][k] = N+1;
						if (i == 0 && j == 0 && k == 0) dp[i][j][k] = 0;
						if (i) {
							dp[i][j][k] = min(dp[i][j][k], nxt[dp[i-1][j][k]][R[0][i-1] - 'a']);
						}
						if (j) {
							dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j-1][k]][R[1][j-1] - 'a']);
						}
						if (k) {
							dp[i][j][k] = min(dp[i][j][k], nxt[dp[i][j][k-1]][R[2][k-1] - 'a']);
						}
					}
				}
			}
		} else if (op == '-') {
			L[z] --;
		} else assert(false);
		//cerr << dp[L[0]][L[1]][L[2]] << '\n';
		cout << (dp[L[0]][L[1]][L[2]] <= N ? "YES" : "NO") << '\n';
	}

	return 0;
}