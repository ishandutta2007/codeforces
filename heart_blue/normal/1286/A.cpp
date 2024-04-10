#include <cstdlib>
#include <cctype>
#include <cstring>
#include <cstdio>
#include <cmath>
#include <algorithm>
#include <vector>
#include <string>
#include <iostream>
#include <sstream>
#include <map>
#include <set>
#include <queue>
#include <stack>
#include <fstream>
#include <numeric>
#include <iomanip>
#include <bitset>
#include <list>
#include <stdexcept>
#include <functional>
#include <utility>
#include <ctime>
#include <random>
#include <cassert>
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 1e2 + 10;
int dp[N][N][N][2];
int a[N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	int n;
	cin >> n;
	map<int, int> mc;
	for (int i = 1; i <= n; i++) mc[i] = 1;
	for (int i = 1; i <= n; i++)
	{
		cin >> a[i];
		mc.erase(a[i]);
	}
	MEM(dp, 0x3f);
	int odd, even;
	odd = 0, even = 0;
	for (auto& p : mc)
	{
		if (p.first & 1)
			odd++;
		else
			even++;
	}
	if (a[1] == 0)
	{
		if (odd) dp[1][1][0][1] = 0;
		if (even) dp[1][0][1][0] = 0;
	}
	else
	{
		dp[1][0][0][a[1] & 1] = 0;
	}
	int tot = 0;
	if (a[1] == 0) tot++;
	for (int i = 2; i <= n; i++)
	{
		if (a[i] == 0) tot++;
		for (int j = 0; j <= odd; j++)
		{
			for (int k = 0; k <= even; k++)
			{
				for (int o = 0; o < 2; o++)
				{
					if (a[i] == 0)
					{
						for (int s = 0; s < 2; s++)
						{
							int& tmp = dp[i][j + (s == 1)][k + (s == 0)][s];
							tmp = min(tmp, dp[i - 1][j][k][o] + (o != s));
						}
					}
					else
					{
						int& tmp = dp[i][j][k][a[i] & 1];
						tmp = min(tmp, dp[i - 1][j][k][o] + (o != (a[i] & 1)));
					}
				}
			}
		}
	}
	cout << min(dp[n][odd][even][1], dp[n][odd][even][0]) << '\n';
	return 0;
}