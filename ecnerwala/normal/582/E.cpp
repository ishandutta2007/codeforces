#include<bits/stdc++.h>
using namespace std;

typedef long long ll;

const int MOD = 1e9 + 7;

const int V = 4;

int L;
char S[600];
// stored by a
int dp[510][(1 << 16) + 10];

int tmp[(1 << 16) + 10];

// [a,b]
void dfs(int a, int b) {
	// S[a,b] is a valid expression
	assert(a <= b);
	if(a == b) {
		assert(S[a] == '?' || ('A' <= S[a] && S[a] <= 'D') || ('a' <= S[a] && S[a] <= 'd'));
		if(S[a] == 'A' || S[a] == '?') dp[a][0b1111111100000000] = 1;
		if(S[a] == 'B' || S[a] == '?') dp[a][0b1111000011110000] = 1;
		if(S[a] == 'C' || S[a] == '?') dp[a][0b1100110011001100] = 1;
		if(S[a] == 'D' || S[a] == '?') dp[a][0b1010101010101010] = 1;
		if(S[a] == 'a' || S[a] == '?') dp[a][0b0000000011111111] = 1;
		if(S[a] == 'b' || S[a] == '?') dp[a][0b0000111100001111] = 1;
		if(S[a] == 'c' || S[a] == '?') dp[a][0b0011001100110011] = 1;
		if(S[a] == 'd' || S[a] == '?') dp[a][0b0101010101010101] = 1;
	} else {
		// dfs
		int m = a;
		for(int i = 0; true; m++) {
			if(S[m] == '(') i++;
			else if(S[m] == ')') i--;
			else if(i == 0) break;
		}
		assert(S[m] == '?' || S[m] == '&' || S[m] == '|');
		dfs(a + 1, m - 2);
		dfs(m + 2, b - 1);
		int l = a + 1, r = m + 2;
		if(S[m] == '&' || S[m] == '?') {
			for(int i = 0; i < 16; i++) {
				for(int s = 0; s < (1 << 16); s++) {
					if(!(s & (1 << i))) {
						dp[l][s] += dp[l][s + (1 << i)];
						dp[l][s] %= MOD;
						dp[r][s] += dp[r][s + (1 << i)];
						dp[r][s] %= MOD;
					}
				}
			}
			for(int s = 0; s < (1 << 16); s++) {
				tmp[s] = (ll(dp[l][s]) * ll(dp[r][s])) % MOD;
			}
			for(int i = 0; i < 16; i++) {
				for(int s = 0; s < (1 << 16); s++) {
					if(!(s & (1 << i))) {
						tmp[s] -= tmp[s + (1 << i)];
						tmp[s] %= MOD;
						dp[l][s] -= dp[l][s + (1 << i)];
						dp[l][s] %= MOD;
						dp[r][s] -= dp[r][s + (1 << i)];
						dp[r][s] %= MOD;
					}
				}
			}
			for(int s = 0; s < (1 << 16); s++) {
				dp[a][s] += tmp[s];
			}
		}
		if(S[m] == '|' || S[m] == '?') {
			for(int i = 0; i < 16; i++) {
				for(int s = 0; s < (1 << 16); s++) {
					if(s & (1 << i)) {
						dp[l][s] += dp[l][s - (1 << i)];
						dp[l][s] %= MOD;
						dp[r][s] += dp[r][s - (1 << i)];
						dp[r][s] %= MOD;
					}
				}
			}
			for(int s = 0; s < (1 << 16); s++) {
				tmp[s] = (ll(dp[l][s]) * ll(dp[r][s])) % MOD;
			}
			for(int i = 0; i < 16; i++) {
				for(int s = 0; s < (1 << 16); s++) {
					if(s & (1 << i)) {
						tmp[s] -= tmp[s - (1 << i)];
						tmp[s] %= MOD;
						dp[l][s] -= dp[l][s - (1 << i)];
						dp[l][s] %= MOD;
						dp[r][s] -= dp[r][s - (1 << i)];
						dp[r][s] %= MOD;
					}
				}
			}
			for(int s = 0; s < (1 << 16); s++) {
				dp[a][s] += tmp[s];
			}
		}
		for(int s = 0; s < (1 << 16); s++) {
			dp[a][s] %= MOD;
			if(dp[a][s] < 0) dp[a][s] += MOD;
		}
	}
}

int main() {
	ios_base::sync_with_stdio(0);
	cin >> S;
	L = int(strlen(S));

	dfs(0, L - 1);
	int N; cin >> N;
	int msk = 0;
	int val = 0;
	for(int i = 0; i < N; i++) {
		int a, b, c, d, v;
		cin >> a >> b >> c >> d >> v;
		msk |= (1 << (8 * a + 4 * b + 2 * c + d));
		val |= (v << (8 * a + 4 * b + 2 * c + d));
	}
	ll res = 0;
	for(int v = 0; v < (1 << 16); v++) {
		if((v & msk) == val) {
			res += dp[0][v];
		}
	}
	res %= MOD;
	if(res < 0) res += MOD;
	cout << res << '\n';
	return 0;
}