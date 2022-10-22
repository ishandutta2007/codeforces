#include <bits/stdc++.h>
#define PB push_back
#define ST first
#define ND second
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
//mt19937 rng(chrono::high_resolution_clock::now().time_since_epoch().count());

using namespace std;

using ll = long long;
using pi = pair<int,int>;
using vi = vector<int>;

const int nax = 110;
int n, m, k, p;
int dp[nax][nax][nax];
int bi[nax][nax];


int main() {_
	cin >> n >> m >> k >> p;
	bi[0][0] = 1;
	for(int i = 1; i <= n; ++i) {
		for(int j = 0; j <= i; ++j) {
			if(j == 0 || j == i) {
				bi[i][j] = 1;
			} else {
				bi[i][j] = (bi[i - 1][j] + bi[i - 1][j - 1]) % p;
			}
		}
	}
	for(int i = 0; i <= n; ++i) {
		dp[0][i][0] = 1;
	}
	m--;
	for(int len = 1; len <= n; ++len) {
		for(int a = 0; a + len <= n; ++a) {
			for(int g = 0; g <= min(k, len); ++g) {
				for(int pos = 1; pos <= len; ++pos) {
					if(a + 1 + max(pos - 1, len - pos) > n) continue;
					//g - k1 <= len - pos
					for(int k1 = max(0, g - len + pos - 1); k1 <= min(g, pos - 1); ++k1) {
						if(a == m) {
							if(k1 < g) {
								dp[len][a][g] = (dp[len][a][g] + ((ll)dp[pos - 1][a + 1][k1] * dp[len - pos][a + 1][g - k1 - 1]%p) * bi[len - 1][pos - 1])%p;
							}
						} else {
							dp[len][a][g] = (dp[len][a][g] + ((ll)dp[pos - 1][a + 1][k1] * dp[len - pos][a + 1][g - k1] % p) * bi[len - 1][pos - 1])%p;
						}
					}
				}
				if(a + len < m) {
					g = len + 1;
				}
			}
		}
	}
	cout << dp[n][0][k];
	
	
}