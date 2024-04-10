#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <iomanip>
typedef long long ll;
using namespace std;

const ll mod = 1e9 + 7;
const int M = 2e5 + 128;
vector<vector<ll> > dp(10, vector<ll>(M, -1));
ll calc(ll d, ll steps)
{
	if (!steps) return 1;
	if (dp[d][steps] != -1) return dp[d][steps];
	if (d < 9) dp[d][steps] = calc(d + 1, steps - 1);
	else dp[d][steps] = (calc(0, steps - 1) + calc(1, steps - 1)) % mod;
	return dp[d][steps];
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string n;
		int m;
		cin >> n >> m;
		vector<ll> f(10, 0);
		for (char i : n) f[i - '0'] ++;
		ll ans = 0;
		for (int i = 0; i < 10; i++)
		{
			ans += (f[i] * calc(i, m)) % mod;
			ans %= mod;
		}
		cout << ans << "\n";
	}
	return 0;
}