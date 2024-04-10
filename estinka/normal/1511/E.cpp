#include <iostream>
#include <vector>
#include <string>
#include <algorithm>
#include <queue>
#include <map>
#include <iomanip>
typedef long long ll;
using namespace std;

const ll mod = 998244353;
ll w = 0;
ll pwr2(ll x)
{
	if (!x) return 1;
	ll h = pwr2(x >> 1);
	h = (h * h) % mod;
	if (x & 1) h = (h << 1) % mod;
	return h;
}
ll inv2 = pwr2(mod - 2), w2;
ll solve(string s)
{
	ll ans = 0;
	vector<vector<ll> > dp(s.size() + 1, vector<ll>(2, 0));
	dp[0][1] = 1; ll myw2 = w2;
	for (int i = 0; i < s.size(); i++)
	{
		if (s[i] == '*') dp[i + 1][1] = (dp[i][0] + dp[i][1]) % mod;
		else
		{
			myw2 = (myw2 * inv2) % mod;
			dp[i + 1][0] = dp[i][1]; 
			dp[i + 1][0] %= mod;
			dp[i + 1][1] += dp[i][1] + dp[i][0];
			dp[i + 1][1] += dp[i][0]; 
			dp[i + 1][1] %= mod;
			ans += (dp[i][0] * myw2) % mod; ans %= mod;
		}
	}
	return ans;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int n, m;
	cin >> n >> m;
	vector<string> s(n);
	for (int i = 0; i < n; i++) cin >> s[i], w += count(s[i].begin(), s[i].end(), 'o');
	w2 = pwr2(w);
	ll ans = 0;
	for (int i = 0; i < n; i++) ans = (ans + solve(s[i])) % mod;
	for (int i = 0; i < m; i++)
	{
		string s2;
		for (int j = 0; j < n; j++) s2.push_back(s[j][i]);
		ans = (ans + solve(s2)) % mod;
	}
	cout << ans << "\n";
	return 0;
}