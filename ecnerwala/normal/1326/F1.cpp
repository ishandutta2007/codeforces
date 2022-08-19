#include<bits/stdc++.h>
using namespace std;

using ll = long long;
bool adj[14][14];
int dp[1<<14][14][1<<7];

int rev[1<<14];
long long ans[1<<13];

int main() {
	ios_base::sync_with_stdio(0), cin.tie(0), cout.tie(0);
	int N; cin >> N;
	for (int i = 0; i < N; i++) {
		string s; cin >> s;
		for (int j = 0; j < N; j++) {
			assert(s[j] == '0' || s[j] == '1');
			adj[i][j] = s[j] - '0';
		}
	}

	for (int i = 0; i < N; i++) {
		dp[1<<i][i][0]++;
	}

	for (int m = 1; m < (1<<N); m++) {
		int pc = __builtin_popcount(m);
		if (pc >= N/2+1) continue;
		for (int i = 0; i < N; i++) {
			if (!(m&(1<<i))) continue;
			for (int j = 0; j < N; j++) {
				if (m & (1<<j)) continue;
				for (int v = 0; v < (1<<(pc-1)); v++) {
					dp[m|(1<<j)][j][v*2+adj[i][j]] += dp[m][i][v];
				}
			}
		}
	}

	int revLen = N - (N/2+1);
	assert(revLen >= 0);
	for (int v = 0; v < 1<<revLen; v++) {
		rev[v] = 0;
		for (int a = v, i = 0; i < revLen; i++) {
			rev[v] <<= 1;
			rev[v] += a&1;
			a /= 2;
		}
	}

	for (int m = 0; m < (1<<N); m++) {
		int pc = __builtin_popcount(m);
		if (pc == N/2+1) {
			for (int i = 0; i < N; i++) {
				if (!(m & (1<<i))) continue;

				for (int v = 0; v < (1<<(pc-1)); v++) {
					for (int u = 0; u < (1<<(N-pc)); u++) {
						ans[(v<<(N-pc))|rev[u]] += 1ll * dp[m][i][v] * dp[(1<<N)-1-m+(1<<i)][i][u];
					}
				}
			}
		}
	}
	for (int i = 0; i < (1<<(N-1)); i++) {
		cout << ans[i] << ' ';
	}
	cout << '\n';

	return 0;
}