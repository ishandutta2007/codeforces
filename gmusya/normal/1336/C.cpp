#include <iostream>
#include <vector>
#include <string>

typedef long long ll;

using namespace std;

const ll MOD = 998244353;
const ll MOD1 = 1e9 + 123;
const ll MOD2 = 1e9 + 321;
const ll P = 31;

vector <ll> p, h;

int main() {
	string S, T;
	cin >> S >> T;
	int n = S.size(), m = T.size();
	vector <ll> h(m);
	vector <ll> p(m + 1);
	p[0] = 1;
	for (int i = 1; i <= m; i++)
		p[i] = (p[i - 1] * P) % MOD1;
	h[0] = (T[0] - 'a' + 1);
	for (int i = 1; i < m; i++)
		h[i] = (h[i - 1] + p[i] * (T[i] - 'a' + 1)) % MOD1;
	vector <vector <ll>> dp(n + 1, vector <ll>(n + 2));
	dp[0][0] = 1;
	for (int i = 0; i <= n; i++)
		dp[0][i] = 1;
	vector <int> a(n + 1);
	for (int i = 1; i <= n; i++) {
		for (int j = 0; j <= n; j++) {
			int newchar = i + j - 1;
			if (newchar >= m || S[i - 1] == T[newchar]) 
				dp[i][j] = (dp[i][j] + dp[i - 1][j]) % MOD;
		}
		for (int j = 0; j <= n; j++) 
			if (j >= m || S[i - 1] == T[j]) dp[i][j] = (dp[i][j] + dp[i - 1][j + 1]) % MOD;
	}
	long long ans = 0;
	for (int i = m; i <= n; i++) 
		ans = (ans + dp[i][0]) % MOD;
	cout << ans;
	return 0;
}