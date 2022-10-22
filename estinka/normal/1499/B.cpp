#include <iostream>
#include <string>
#include <set>
#include <bitset>
#include <vector>
#include <algorithm>
#include <cmath>
#include <array>
#include <queue>
typedef long long ll;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	int t;
	cin >> t;
	while (t--)
	{
		string s;
		cin >> s;
		int n = s.size();
		vector<vector<int> > dp(n + 1, vector<int>(2, 0));
		dp[0][0] = true;
		for (int i = 1; i <= n; i++)
		{
			for (int last = max(0, i - 2); last <= i - 1; last++)
			{
				for (int di = 0; di <= (s[i - 1] - '0'); di++)
				{
					dp[i][s[i - 1] - '0'] |= dp[last][di];
				}
			}
		}
		bool good = dp[n - 1][s[n - 2] - '0'] | dp[n][s[n - 1] - '0'];
		cout << (good ? "YES" : "NO") << "\n";
	}
	return 0;
}