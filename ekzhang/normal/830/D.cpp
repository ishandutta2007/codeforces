#include <bits/stdc++.h>
using namespace std;

#define error(args...) { vector<string> _v = split(#args, ','); err(_v.begin(), args); }
vector<string> split(const string& s, char c) { vector<string> v; stringstream ss(s); string x; while (getline(ss, x, c)) v.push_back(move(x)); return move(v); }
void err(vector<string>::iterator it) {}
template<typename T, typename... Args> void err(vector<string>::iterator it, T a, Args... args) { cerr << it->substr((*it)[0] == ' ', it->length()) << " = " << a << '\n'; err(++it, args...); }

const int MOD = (1e9+7);
#define MAXK 403
typedef long long LL;
int K;
LL dp[MAXK][MAXK];

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(0);

	// freopen("input.txt", "r", stdin);

	cin >> K;

	dp[0][0] = 1;
	for (int i = 1; i <= K; i++) {
		dp[i][0] = 1;
		for (int j = 1; j <= K - i + 1; j++) {
			// don't use top
			for (int k = 0; k <= j; k++) {
				dp[i][j] += dp[i-1][k] * dp[i-1][j-k];
				dp[i][j] %= MOD;
			}
			// top connected to nothing
			for (int k = 0; k <= j - 1; k++) {
				dp[i][j] += dp[i-1][k] * dp[i-1][j-1-k];
				dp[i][j] %= MOD;
			}
			// top connected to beginning or end of a path in either subtree
			for (int k = 0; k <= j; k++) {
				dp[i][j] += ((2 * j * dp[i-1][k]) % MOD) * dp[i-1][j-k];
				dp[i][j] %= MOD;
			}
			// top is in the middle of a path in either subtree
			for (int k = 0; k <= j + 1; k++) {
				dp[i][j] += ((2 * k * (k-1) * dp[i-1][k]) % MOD) * dp[i-1][j+1-k];
				dp[i][j] %= MOD;
			}
			// top is in the middle of a path between subtrees
			for (int k = 0; k <= j + 1; k++) {
				dp[i][j] += ((2 * k * (j+1-k) * dp[i-1][k]) % MOD) * dp[i-1][j+1-k];
				dp[i][j] %= MOD;
			}
		}
	}

	cout << dp[K][1] << endl;
	return 0;
}