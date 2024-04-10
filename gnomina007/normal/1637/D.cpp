#include <iostream>
#include<string>
#include<vector>
#include<set>
#include<algorithm>
#include<cassert>
#include<queue>
#include<fstream>
#include<iomanip>

using namespace std;

using ll = long long;
using ull = unsigned long long;
int MX = 101;
void solve(istream& cin = std::cin, ostream& cout = std::cout)
{
	int t;
	cin >> t;
	for (int tt = 0; tt < t; tt++)
	{
		int n;
		cin >> n;
		long long ans = 0, allsum = 0;
		vector<vector<int>>dp(n + 1, vector<int>(MX * n + 1));
		vector<int>aa(n), bb(n);
		for (int i = 0; i < n; i++)
			cin >> aa[i];
		for (int i = 0; i < n; i++)
			cin >> bb[i];
		dp[0][0] = 1;
		for (int i = 1; i <= n; i++)
		{
			int a=aa[i-1], b=bb[i-1];
			ans += (n - 2) *1LL* (a * a + b * b);
			//cout << "CURANS " << ans << endl;
			allsum += a + b;
			for (int j = 0; j < MX * n + 1; j++)
			{
				if (dp[i - 1][j] == 1)
				{
					dp[i][j + a] = 1;
					dp[i][j + b] = 1;
				}
			}
		}
		for (int k = allsum/2; k >=0; k--)
		{
			if (dp[n][k] == 1)
			{
				ans += k * k + (allsum - k) * (allsum - k);
				break;
			}
		}
		cout << ans << endl;
	}
}


int main()
{	
	solve();
}