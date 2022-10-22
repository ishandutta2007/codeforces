#include <iostream>
#include <vector>
#include <algorithm>
#include <cmath>
#include <string>
#include <iomanip>
#include <set>
#include <map>
#include <queue>
#include <bitset>
#include <random>
#include <chrono>
#include <numeric>
//#define DEBUG
//#define RANDOM
typedef long long ll;
typedef long double ld;
using namespace std;

int main()
{
	ios::sync_with_stdio(false);
	cin.tie(0);
	cout.tie(0);
	int n;
	cin >> n;
	vector<int> v;
	int last1 = -1;
	for (int i = 0; i < n; i++)
	{
		int c;
		cin >> c;
		if (c)
		{
			v.push_back(i - last1 - 1);
			last1 = i;
		}
	}
	v.push_back(n - last1 - 1);
	int m = v.size();
	vector<int> p = v;
	partial_sum(p.begin(), p.end(), p.begin());
	int ***dp = new int** [3279];
	for (int i = 0; i <= (n * (n + 1)) / 2; i++)
	{
		dp[i] = new int *[81];
		for (int j = 0; j <= n; j++)
		{
			dp[i][j] = new int [81];
			for (int k = 0; k <= n; k++)
			{
				dp[i][j][k] = 1000000;
			}
		}
	}
	dp[0][0][0] = 0;
	for (int i = 0; i < m; i++)
	{
		for (int swaps = 0; swaps <= (n * (n - 1)) / 2; swaps++)
		{
			for (int sum = 0; sum <= p.back(); sum++)
			{
				if (dp[swaps][sum][i] >= 1000000)
				{
					continue;
				}
				//cout << dp[swaps][sum][i] << " ";
				for (int nw = sum; nw <= p.back(); nw++)
				{
					dp[swaps + abs(p[i] - nw)][nw][i + 1] = min(dp[swaps + abs(p[i] - nw)][nw][i + 1], dp[swaps][sum][i] + (nw - sum) * (nw - sum));
				}
			}
			//cout << "\n";
		}
		//cout << "\n";
	}
	int mx = 0;
	for (int i = 0; i <= (n * (n - 1)) / 2; i++)
	{
		mx = max(mx, (((p[m - 1] * p[m - 1]) - dp[i][p[m - 1]][m]) >> 1));
		cout << mx << " ";
	}
	cout << "\n";
	return 0;
}