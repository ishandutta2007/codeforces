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
using namespace std;
typedef long long LL;
typedef unsigned long long ULL;
#define MEM(a,b) memset((a),(b),sizeof(a))
const LL INF = 1e9 + 7;
const int N = 50 + 10;
LL a[N];
int dp[N][N];
int main()
{
	//freopen("input.txt", "r", stdin);
	//freopen("output.txt", "w", stdout);
	LL mask = 0;
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) cin >> a[i];
	for (int o = 60; o >= 0; o--)
	{
		mask |= 1LL << o;
		MEM(dp, 0);
		dp[0][0] = 1;
		for (int i = 1; i <= k; i++)
		{
			for (int j = 1; j <= n; j++)
			{
				LL sum = 0;
				for (int t = j; t >= 1; t--)
				{
					sum += a[t];
					if (((sum&mask) == mask) && dp[i - 1][t - 1] == 1)
					{
						dp[i][j] = 1;
						break;
					}
				}
			}
		}
		if (dp[k][n] == 0) mask ^= 1LL << o;
	}
	cout << mask << endl;
	return 0;
}