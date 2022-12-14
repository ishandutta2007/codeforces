#include <iostream>
#include <vector>
#include <algorithm>
#include <set>
#include <map>
#include <string>
typedef long long ll;
using namespace std;

const ll mod = 998244353;
void add(int& a, int b)
{
	a += b;
	if (a >= mod) a -= mod;
}
int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<int> dp(n + 2, 0), dp2(n + 2, 0);
		dp[0] = 1;
		for (int i = 0; i < n; i++)
		{
			int a;
			cin >> a;

			add(dp[a + 1], dp[a + 1]);
			add(dp2[a + 1], dp2[a + 1]);
			
			if (a)
			{
				add(dp2[a - 1], dp2[a - 1]);
				add(dp2[a - 1], dp[a - 1]);
			}

			add(dp[a + 1], dp[a]);
		}
		int ans = 0;
		for (int i = 0; i < n + 2; i++)
		{
			add(ans, dp[i]);
			add(ans, dp2[i]);
		}
		cout << (ans + mod - 1) % mod << "\n";
	}
	return 0;
}